#include"myServer.h"

void myServer::serverFunction(int socket)
{
    write(socket, "Hello World\n", 13);
}

int main()
{
    myServer server(30001);
    server.run();
}