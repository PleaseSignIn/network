#include"ThreadBase.h"
#include"CondVar.h"
#include<vector>

typedef void* (*TASK) (void*);

struct task
{
    TASK run;  //指向任务函数的指针
    void* arg; //任务函数的参数
    task* next;//指向下一个任务
};

class ThreadRoutine;

class ThreadPool
{
private:
    CondVar cond;          //条件变量
    MutexLock lock;        //互斥锁
    task* first = NULL;    //指向任务链表头节点
    task* last = NULL;     //指向任务链表尾节点
    int threadCount = 0;   //当前线程池中的线程数
    int idleThreads = 0;   //当前空闲的线程
    int maxThreads;        //线程池中最大线程数
    bool quit = false;     //当设为true时，任务执行完后线程池退出
    std::vector<ThreadRoutine*> threads;  //指向线程池中的线程
public:
    ThreadPool(int maxThreads):maxThreads(maxThreads) {};
    ~ThreadPool();
    void AddTask(TASK run, void* arg);  //向线程池中添加任务
    friend class ThreadRoutine;
};

class ThreadRoutine : public ThreadBase
{
private:
    ThreadPool* pool;  //指向线程池的指针
public:
    ThreadRoutine(ThreadPool* pool):pool(pool) {};
    ~ThreadRoutine() {};

    void Run();       //从任务队列中取出任务并执行
};

