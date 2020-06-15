#include<netinet/in.h>
#include<arpa/inet.h>
#include<memory.h>
#include<unistd.h>
#include<iostream>
#include<string>

using namespace std;

class clientBase
{
protected:
    int port;
    string address;
    virtual void clientFunction(int socket) = 0;
public:
    clientBase(int port, string address):port(port), address(address) {};
    ~clientBase() {};

    int run();    
};