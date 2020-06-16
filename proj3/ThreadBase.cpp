#include"ThreadBase.h"

pthread_t ThreadBase::GetTid()
{
    return t_id;
}

int ThreadBase::Start()
{
    return pthread_create(&t_id, NULL, ThreadFunc, this);
}

void* ThreadBase::ThreadFunc(void * arg)
{
    ThreadBase *ptr = (ThreadBase*) arg;
    ptr->Run();
    pthread_exit(0);
}

int ThreadBase::Join()
{
    return pthread_join(t_id, NULL);
}