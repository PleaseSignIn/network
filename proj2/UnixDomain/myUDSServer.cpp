#include"myUDSServer.h"

void myUDSServer::serverFunction(int socket)
{
    char buffer[40] = {'\0'};
    cout<< "this is a UNIX Domain server and recive message from UNIX Domain client.\n";
    while(buffer[0] != 'q' || buffer[1] != '\0')
    {
        read(socket, buffer, 40);

        cout<<buffer<<endl;
    }
}


int main()
{
    myUDSServer server(30002, "/tmp/connection-uds-fd");
    server.run();
}