#include<netinet/in.h>
#include<unistd.h>
#include<memory.h>
#include<iostream>
#include<string>

using namespace std;

class UDPServerBase
{
protected:
    int port;
    string address;
    virtual void serverFunction(int socket) = 0;
public:
    UDPServerBase(int port):port(port) {};
    virtual ~UDPServerBase() {};
    int run();
};
