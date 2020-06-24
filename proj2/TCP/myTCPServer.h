#include"TCPServerBase.h"

class myTCPServer : public TCPServerBase
{
private:
    void serverFunction(int socket);
public:
    myTCPServer(int port):TCPServerBase(port) {};
    ~myTCPServer() {};
};