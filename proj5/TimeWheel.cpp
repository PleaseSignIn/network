#include"TimeWheel.h"

void TimeWheel::mountTimer(Timer** point, Timer* timer)
{
    timer->setNext(*point);
    *point = timer;
}

void TimeWheel::addTimer(Timer* timer)
{
    pthread_mutex_lock(&mutex);
    mountTimer(wheel+ (timer->getTimeSpan() / frequence + wheelPos) % wheelSize, timer); 
    pthread_mutex_unlock(&mutex);
    timerCount++;
    timer->regist();
}

int TimeWheel::totalTimers()
{
    return timerCount;
}

void TimeWheel::run()
{
    wheelPos = (wheelPos + 1) % wheelSize;  //到下一个位置

    Timer * temp;
    pthread_mutex_lock(&mutex);    //时间轮加锁
    while(wheel[wheelPos])
    {
        wheel[wheelPos]->callback();  //调用回调函数
        temp = wheel[wheelPos];  //去除这个timer
        wheel[wheelPos] = temp->getNext();
        if(temp->needRepeat())  //如果需要重复，再添加到timewheel
        {
            mountTimer(wheel + (temp->getTimeSpan() / frequence + wheelPos) % wheelSize, temp); 
        }
        else  //否则停止该timer
        {
            temp->stop();
            timerCount--;
        }
    }
    pthread_mutex_unlock(&mutex);  //时间轮解锁
}