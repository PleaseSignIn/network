#include"TimeDriver.h"

int TimeDriver::totalWheels()
{
    return wheels.size();
}

void TimeDriver::mountTimerWheel(TimeWheel* timeWheel)
{
    pthread_t tid;
    wheels.push_back(timeWheel);  //添加时间轮
    bind* b = new bind;
    b->cond = &cond;
    b->wheel = timeWheel;    //制作bind结构
    pthread_create(&tid, nullptr, runTimeWheel, reinterpret_cast<void*>(b)); //启动时间轮线程
}

void TimeDriver::start()
{
    while (true)
    {
        usleep(100000); //等待100ms
        pthread_cond_broadcast(&cond);  //唤醒所有时间轮线程
    }
}

void * TimeDriver::runTimeWheel(void * arg)
{
    pthread_mutex_t lock;
    pthread_mutex_init(&lock, 0);
    bind * b = reinterpret_cast<bind *>(arg);
    while(true)
    {
        pthread_mutex_lock(&lock);
        pthread_cond_wait(b->cond, &lock);  //等待被driver唤醒
        b->wheel->run();                    //时间轮前进一格
        pthread_mutex_unlock(&lock);
    }
}
 