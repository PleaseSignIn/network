#include"Timer.h"
#include"pthread.h"

#define wheelSize 1000

class TimeWheel
{
private:
    const int frequence = 100;  //100ms
    int timerCount = 0;
    int wheelPos = 0;
    Timer* wheel[wheelSize] = {nullptr};
    pthread_mutex_t mutex;

    void mountTimer(Timer** point, Timer* timer);

    static void* runTimers(void * arg);
public:
    TimeWheel() {
        pthread_mutex_init(&mutex, 0);
    };
    ~TimeWheel() {};
    void addTimer(Timer* timer);
    void run();
    int totalTimers();
};