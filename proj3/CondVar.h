#include"MutexLock.h"

class CondVar
{
private:
    pthread_cond_t cond;
public:
    CondVar();
    ~CondVar();
    int Wait(MutexLock& lock);
    int Signal();
    int Broadcast();
};
