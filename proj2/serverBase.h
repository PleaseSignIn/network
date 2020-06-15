#include<netinet/in.h>
#include<unistd.h>
#include<memory.h>
#include<iostream>
#include<string>

using namespace std;
class serverBase
{
protected:
    int port;
    string address;
    virtual void serverFunction(int socket) = 0;
public:
    serverBase(int port):port(port) {};
    ~serverBase() {}
    int run();
};