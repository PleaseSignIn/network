#include<vector>
#include"TimeWheel.h“

class TimeDriver
{
private:
   std::vector<TimeWheel*> wheels;
   void * new
public:
   TimeDriver() {};
   ~TimeDriver() {};
   void mountTimerWheel(TimeWheel* timeWheel);
   void start();
   int totalWheels;
};
