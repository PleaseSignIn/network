#include"TimeDriver.h"
#include<iostream>

pthread_mutex_t lock;

class myTimer : public Timer
{
private:
    int num;
public:
    myTimer(int timeSpan, bool needRestart, int num):Timer(timeSpan, needRestart),num(num) {};
    ~myTimer();
    void callback()
    {
        pthread_mutex_lock(&lock);
        std::cout<<"This is Timer " << num << std::endl;
        pthread_mutex_unlock(&lock);
    }
};

int main()
{
    myTimer* timer1 = new myTimer(1000, true, 1);
    myTimer* timer2 = new myTimer(3000, true, 2);
    myTimer* timer3 = new myTimer(4500, false, 3);

    TimeWheel* wheel1 = new TimeWheel();
    TimeWheel* wheel2 = new TimeWheel();
    TimeWheel* wheel3 = new TimeWheel();

    wheel1->addTimer(timer1);
    wheel2->addTimer(timer2);
    wheel3->addTimer(timer3);

    TimeDriver* driver = new TimeDriver();
    driver->mountTimerWheel(wheel1);
    driver->mountTimerWheel(wheel2);
    driver->mountTimerWheel(wheel3);

    driver->start();
}