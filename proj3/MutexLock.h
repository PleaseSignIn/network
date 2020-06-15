#include<pthread.h>

class MutexLock
{
private:
    pthread_mutex_t lock;
public:
    MutexLock();
    ~MutexLock();
    int Lock();
    int UnLock();
    pthread_mutex_t GetLock();
};

