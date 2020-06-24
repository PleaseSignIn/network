#include<sys/un.h>
#include<sys/socket.h>
#include<memory.h>
#include<unistd.h>
#include<iostream>
#include<string>

using namespace std;

class UDSClientBase
{
protected:
    int port;
    string socket_name;
    virtual void clientFunction(int socket) = 0;
public:
    UDSClientBase(int port, string socket_name):port(port), socket_name(socket_name) {};
    ~UDSClientBase() {};

    int run();    
};