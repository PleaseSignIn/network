#include"myTCPServer.h"

void myTCPServer::serverFunction(int socket)
{
    char buffer[40] = {'\0'};
    cout<< "this is a TCP server and recive message from TCP client.\n";
    while(buffer[0] != 'q' || buffer[1] != '\0')
    {
        read(socket, buffer, 40);

        cout<<buffer<<endl;
    }
}

int main()
{
    myTCPServer server(30001);
    server.run();
}