#include"UDSClientBase.h"

class myUDSClient : public UDSClientBase
{
private:
    void clientFunction(int socket);
public:
    myUDSClient(int port, string address):UDSClientBase(port, address) {};
    ~myUDSClient() {};
};
