class Timer
{
private:
    int timeSpan;
    bool needRestart;
    Timer * next = nullptr;
    bool registed = false;
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
