class Timer
{
private:
    int timeSpan;    //时间间隔
    bool needRestart;  //重复
    Timer * next = nullptr;  //指向同一时间的下一个timer
    bool registed = false;   //已注册到时间轮
    bool stopped = false;
public:
    Timer() {};
    Timer(int timeSpan, bool needRestart):
    timeSpan(timeSpan),
    needRestart(needRestart) {};
    ~Timer() {};

    void stop();
    bool isRegisted();
    int getTimeSpan();
    void setTimeSpan(int timeSpan);
    bool needRepeat();
    void setNext(Timer* timer);
    void regist();
    Timer* getNext();

    virtual void callback() = 0;
};
