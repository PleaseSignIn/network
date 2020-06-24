#include"UDSServerBase.h"

class myUDSServer : public UDSServerBase
{
private:
    void serverFunction(int socket);
public:
    myUDSServer(int port, string socket_name):UDSServerBase(port, socket_name) {};
    ~myUDSServer() {};
};

