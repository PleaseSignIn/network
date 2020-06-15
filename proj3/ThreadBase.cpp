#include"ThreadBase.h"

ThreadBase::ThreadBase() {}

ThreadBase::~ThreadBase()
{

}

ThreadBase::getTid()
{
    return id;
}

ThreadBase::start()
{
    return pthread_create(&id, NULL, start_func, (void*)this);
}

ThreadBase::