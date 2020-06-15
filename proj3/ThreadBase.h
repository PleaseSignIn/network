#include<pthread.h>

class ThreadBase
{
private:
    pthread_t id;

    void* start_func(void* arg);

public:
    ThreadBase();
    int start();
    int join();
    int quit();

    pthread_t getTid();

    virtual void task() = 0;
    virtual ~ThreadBase();
};