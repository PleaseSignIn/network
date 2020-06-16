#include"ThreadPool.h"
#include<iostream>
#include<unistd.h>

void * taskRoutine(void* arg)
{
    pthread_t tid = pthread_self();
    int taskId = *reinterpret_cast<int *>(arg);
    delete reinterpret_cast<int*>(arg);
    std::cerr<<"Thread " << tid << " working in task " << taskId << "\n" << std::flush;
    usleep(100);
    return NULL;
}

int main()
{
    int taskCount = 100, threadCount = 10;
    ThreadPool pool = ThreadPool(threadCount);
    for(int i = 0; i<taskCount; i++)
    {
        int* arg = new int;
        *arg = i;
        pool.AddTask(taskRoutine, reinterpret_cast<void *>(arg));
    }
}