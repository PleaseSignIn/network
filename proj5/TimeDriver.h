#include<vector>
#include<unistd.h>
#include"TimeWheel.h"

struct bind{
   TimeWheel* wheel;
   pthread_cond_t* cond;
};  //需要传入到时间轮线程的数据

class TimeDriver
{
private:
   std::vector<TimeWheel*> wheels;  //时间轮
   static void* runTimeWheel(void* arg);  //时间轮线程
   pthread_cond_t cond;  //条件变量，同于同步唤醒所有线程
public:
   TimeDriver() {
      pthread_cond_init(&cond, 0);
   };
   ~TimeDriver() {};
   void mountTimerWheel(TimeWheel* timeWheel);//添加时间轮
   void start();             //开始驱动
   int totalWheels();        //总的时间轮数量
};
