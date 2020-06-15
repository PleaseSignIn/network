#include<pthread.h>

class ThreadBase
{
private:
    pthread_t t_id;

    static void* ThreadFunc(void* arg);

public:
    ThreadBase() {};
    int Start();
    int Join();

    pthread_t GetTid();

    virtual void Run() = 0;
    virtual ~ThreadBase() {};
};