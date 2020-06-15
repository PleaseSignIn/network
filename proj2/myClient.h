#include"clientBase.h"

class myClient : public clientBase
{
private:
    void clientFunction(int socket);
public:
    myClient(int port, string address):clientBase(port, address) {};
    ~myClient() {};
};
