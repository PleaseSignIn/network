#include"Timer.h"
#include"pthread.h"

#define wheelSize 1000

class TimeWheel
{
private:
    const int frequence = 100;
    int timerCount = 0;
    int wheelPos = 0;
    Timer* wheel[wheelSize] = {nullptr};
    pthread_mutex_t mutex;

    void mountTimer(Timer** point, Timer* timer);
public:
    TimeWheel() {
        pthread_mutex_init(mutex);
    };
    ~TimeWheel() {};
    void addTimer(Timer* timer);
    void run();
    int totalTimers();
};