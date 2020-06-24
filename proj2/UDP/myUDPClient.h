#include"UDPClientBase.h"

class myUDPClient : public UDPClientBase
{
private:
    void clientFunction(int socket, sockaddr_in* serverAddress);
public:
    myUDPClient(int port, string address):UDPClientBase(port, address) {};
    ~myUDPClient() {};
};
