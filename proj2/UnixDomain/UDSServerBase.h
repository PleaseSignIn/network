#include<sys/un.h>
#include<sys/socket.h>
#include<unistd.h>
#include<memory.h>
#include<iostream>
#include<string>

using namespace std;

class UDSServerBase
{
protected:
    int port;
    string socket_name;
    virtual void serverFunction(int socket) = 0;
public:
    UDSServerBase(int port, string socket_name):port(port), socket_name(socket_name) {};
    virtual ~UDSServerBase() {};
    int run();
};