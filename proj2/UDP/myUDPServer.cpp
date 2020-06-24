#include"myUDPServer.h"

void myUDPServer::serverFunction(int socket)
{
    sockaddr_in clientAddress;
    socklen_t clientAddressLength = sizeof(sockaddr_in);
    char buffer[40] = {'\0'};
    cout<< "this is a UDP server and recive message from UDP client.\n";
    while(buffer[0] != 'q' || buffer[1] != '\0')
    {
        recvfrom(socket, buffer, 40, 0, (sockaddr*)&clientAddress, &clientAddressLength);
        cout<<buffer<<endl;
    }
}

int main()
{
    myUDPServer server(30000);
    server.run();
}