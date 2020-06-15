#include"TimeWheel.h"

void TimeWheel::mountTimer(Timer** point, Timer* timer)
{
    timer->setNext(*point);
    *point = timer;
}

void TimeWheel::addTimer(Timer* timer)
{
    pthread_mutex_lock(mutex);
    mountTimer(wheel+ (timer->getTimeSpan() / frequence + wheelPos) % wheelSize, timer); 
    pthread_mutex_unlock(mutex);
    timerCount++;
    timer->regist();
}

int TimeWheel::totalTimers()
{
    return timerCount;
}

void TimeWheel::run()
{
    wheelPos = (wheelPos + 1) % wheelSize;

    Timer * temp;
    pthread_mutex_lock(mutex);
    while(wheel[wheelPos])
    {
        wheel[wheelPos]->callback();
        temp = wheel[wheelPos];
        wheel[wheelPos] = temp->getNext();
        if(wheel[wheelPos]->needRepeat())
        {
            mountTimer(wheel + (temp->getTimeSpan() / frequence + wheelPos) % wheelSize, temp); 
        }
        else
        {
            temp->stop();
            timerCount--;
        }
    }
    pthread_mutex_unlock(mutex);
}