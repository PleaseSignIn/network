#include<netinet/in.h>
#include<arpa/inet.h>
#include<memory.h>
#include<unistd.h>
#include<iostream>
#include<string>

using namespace std;

class TCPClientBase
{
protected:
    int port;
    string address;
    virtual void clientFunction(int socket) = 0;
public:
    TCPClientBase(int port, string address):port(port), address(address) {};
    ~TCPClientBase() {};

    int run();
};