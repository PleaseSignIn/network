#include"MutexLock.h"

MutexLock::MutexLock()
{
    pthread_mutex_init(&lock, NULL);
}

MutexLock::~MutexLock()
{
    pthread_mutex_destroy(&lock);
}

int MutexLock::Lock()
{
    return pthread_mutex_lock(&lock);
}

int MutexLock::UnLock()
{
    return pthread_mutex_unlock(&lock);
}

pthread_mutex_t MutexLock::GetLock()
{
    return lock;
}