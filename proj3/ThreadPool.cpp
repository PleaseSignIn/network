#include<iostream>
#include"ThreadPool.h"

ThreadPool::~ThreadPool()
{
    lock.Lock();  //上锁

    quit = true;  //退出

    if(threadCount)  //还有存活线程
    {
        //唤醒所有空闲线程，使之结束
        if(idleThreads)
        {
            cond.Broadcast();
        }
        //如果还有存活线程，等待线程结束
        while (threadCount)
        {
            cond.Wait(lock);
        }
    }
    lock.UnLock();  //解锁
    //删除所有线程，释放空间
    for(auto thread : threads)
    {
        delete(thread);
    }
}

void ThreadRoutine::Run()
{
    //std::cerr<<"Thread " << GetTid() << " starting.\n" << std::flush;

    while (true)
    {
        pool->lock.Lock();           //上锁
        pool->idleThreads++;         //空闲线程加一

        while (pool->first==NULL && pool->quit==false)
        {
            //std::cerr<<"Thread " << GetTid() << " waiting.\n" << std::flush;
            pool->cond.Wait(pool->lock); //如果队列为空且现在不退出，等待任务出现
        }
        pool->idleThreads--;  //接到任务或准备退出，空闲线程减一

        if(pool->first)       //任务队列非空
        {
            task *tk = pool->first;
            pool->first = tk->next;  //取队列头的任务

            pool->lock.UnLock();  //任务队列解锁

            tk->run(tk->arg);  //执行任务
            delete(tk);
            pool->lock.Lock(); //上锁
        }
        //如果准备退出且任务队列为空
        if(pool->quit && pool->first==NULL)
        {
            pool->threadCount--;  //线程数量减一
            if(pool->threadCount == 0)
            {
                pool->cond.Signal();  //发送信号，已经没有存活线程
            }
            pool->lock.UnLock();    //解锁
            break;                //退出循环
        }
        pool->lock.UnLock();      //解锁
    }
    //std::cerr<<"Thread " << GetTid() << " exiting.\n" << std::flush;
}

void ThreadPool::AddTask(TASK run, void* arg)
{
    task* t = new task;  //新建任务并设置参数
    t->run = run;
    t->arg = arg;
    t->next = NULL;

    lock.Lock();         //任务队列上锁

    if(first)            //任务队列非空，加到队列末尾
    {
        last->next = t;
    }
    else                 //任务队列为空，加到队列头
    {
        first = t;
    }
    last = t;

    if(idleThreads>0)    //有空闲线程，唤醒执行
    {
        cond.Signal();
    }
    else if(threadCount < maxThreads)  //无空闲线程且线程数未超过限制
    {
        ThreadRoutine* thread = new ThreadRoutine(this); //新建线程
        threads.push_back(thread);
        thread->Start();       //开始执行
        threadCount++;
    }
    lock.UnLock();        //任务队列解锁
}
