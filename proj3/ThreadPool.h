#include"ThreadBase.h"
#include"CondVar.h"

typedef void* (*TASK) (void*);

struct task
{
    TASK run;
    void* arg;
    task* next;
};

class ThreadPool
{
private:
    CondVar cond;
    MutexLock lock;
    task* first = NULL;
    task* last = NULL;
    int threadCount = 0;
    int idleThreads = 0;
    int maxThreads;
    bool quit = false;
public:
    ThreadPool(int maxThreads):maxThreads(maxThreads) {};
    ~ThreadPool();
    void AddTask(TASK run, void* arg);
    friend class ThreadRoutine;
};

class ThreadRoutine : public ThreadBase
{
private:
    ThreadPool* pool;
public:
    ThreadRoutine(ThreadPool* pool):pool(pool) {};
    ~ThreadRoutine() {};

    void Run();
};

