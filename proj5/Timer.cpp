#include"Timer.h"

void Timer::stop()
{
    needRestart = false;
    stopped = true;
}

bool Timer::isRegisted()
{
    return registed;
}

int Timer::getTimeSpan()
{
    return timeSpan;
}

void Timer::setTimeSpan(int timeSpan)
{
    this->timeSpan = timeSpan;
}

bool Timer::needRepeat()
{
    return needRestart;
}

void Timer::setNext(Timer* timer)
{
    next = timer;
}

void Timer::regist()
{
    registed = true;
}

Timer* Timer::getNext()
{
    return next;
}