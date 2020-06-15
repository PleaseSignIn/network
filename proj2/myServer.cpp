#include"myServer.h"

void myServer::serverFunction(int socket)
{
    char buffer[40] = {'\0'};
    while(buffer[0] != 'q' || buffer[1] != '\0')
    {
        read(socket, buffer, 40);

        cout<<buffer<<endl;
    }
}

int main()
{
    myServer server(30001);
    server.run();
}