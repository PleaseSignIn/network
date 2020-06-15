#include"serverBase.h"

class myServer : public serverBase
{
private:
    void serverFunction(int socket);
public:
    myServer(int port):serverBase(port) {};
    ~myServer() {};
};