#include"TCPClientBase.h"

class myTCPClient : public TCPClientBase
{
private:
    void clientFunction(int socket);
public:
    myTCPClient(int port, string address):TCPClientBase(port, address) {};
    ~myTCPClient() {};
};
