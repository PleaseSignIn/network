#define BOOST_TEST_MODULE threadpooltest

#include"ThreadPool.h"
#include<iostream>
#include<unistd.h>
#include<boost/test/included/unit_test.hpp>

MutexLock lock;

int val=0;

void * taskRoutine(void* arg)
{
    pthread_t tid = pthread_self();
    int taskId = *reinterpret_cast<int *>(arg);
    delete reinterpret_cast<int*>(arg);
    //std::cerr<<"Thread " << tid << " working in task " << taskId << "\n" << std::flush;
    //lock.Lock();
    val++;
    //lock.UnLock();
    usleep(100);
    return NULL;
}

BOOST_AUTO_TEST_SUITE(threadpooltest)

BOOST_AUTO_TEST_CASE(test)
{
    int taskCount = 10000, threadCount = 100;
    ThreadPool pool = ThreadPool(threadCount);
    for(int i = 0; i<taskCount; i++)
    {
        int* arg = new int;
        *arg = i;
        pool.AddTask(taskRoutine, reinterpret_cast<void *>(arg));
    }
    sleep(2);
    std::cout<< val << std::endl;
    BOOST_REQUIRE(val == 10000);
}

BOOST_AUTO_TEST_SUITE_END()