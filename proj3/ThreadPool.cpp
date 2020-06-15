#include<iostream>
#include"ThreadPool.h"

ThreadPool::~ThreadPool()
{
    if(quit)
    {
        return;
    }

    lock.Lock();

    quit = true;

    if(threadCount)
    {
        if(idleThreads)
        {
            cond.Broadcast();
        }

        while (threadCount)
        {
            cond.Wait(lock);
        }
    }
    lock.UnLock();
}

void ThreadRoutine::Run()
{
    std::cout<<"Thread " << GetTid() << " starting.\n";

    while (true)
    {
        pool->lock.Lock();
        pool->idleThreads++;

        while (pool->first==NULL && pool->quit==false)
        {
            std::cout<<"Thread " << GetTid() << " waiting.\n";
            pool->cond.Wait(pool->lock);
        }
        pool->idleThreads--;

        if(pool->first)
        {
            task *tk = pool->first;
            pool->first = tk->next;

            pool->lock.UnLock();

            tk->run(tk->arg);
            delete(tk);
            pool->lock.Lock();
        }

        if(pool->quit && pool->first==NULL)
        {
            pool->threadCount--;
            if(pool->threadCount == 0)
            {
                pool->cond.Signal();
            }
            pool->lock.UnLock();
            break;
        }

        pool->lock.UnLock();
    }
    std::cout<<"Thread " << GetTid() << " exiting.\n";
}

void ThreadPool::AddTask(TASK run, void* arg)
{
    
}

