#include"CondVar.h"

CondVar::CondVar()
{
    pthread_cond_init(&cond, NULL);
}

CondVar::~CondVar()
{
    pthread_cond_destroy(&cond);
}

int CondVar::Wait(MutexLock& lock)
{
    return pthread_cond_wait(&cond, &lock.GetLock());
}

int CondVar::Signal()
{
    return pthread_cond_signal(&cond);
}

int CondVar::Broadcast()
{
    return pthread_cond_broadcast(&cond);
}