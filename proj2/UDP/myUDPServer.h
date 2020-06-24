#include"UDPServerBase.h"

class myUDPServer : public UDPServerBase
{
private:
    void serverFunction(int socket);
public:
    myUDPServer(int port):UDPServerBase(port) {};
    ~myUDPServer() {};
};
