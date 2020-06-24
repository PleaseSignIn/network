#include<netinet/in.h>
#include<unistd.h>
#include<memory.h>
#include<iostream>
#include<string>

using namespace std;
class TCPServerBase
{
protected:
    int port;
    string address;
    virtual void serverFunction(int socket) = 0;
public:
    TCPServerBase(int port):port(port) {};
    virtual ~TCPServerBase() {}
    int run();
};