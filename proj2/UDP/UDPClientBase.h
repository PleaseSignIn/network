#include<netinet/in.h>
#include<arpa/inet.h>
#include<memory.h>
#include<unistd.h>
#include<iostream>
#include<string>

using namespace std;

class UDPClientBase
{
protected:
    int port;
    string address;
    virtual void clientFunction(int socket, sockaddr_in* serverAddress) = 0;
public:
    UDPClientBase(int port, string address):port(port), address(address) {};
    virtual ~UDPClientBase() {};

    int run();
};
