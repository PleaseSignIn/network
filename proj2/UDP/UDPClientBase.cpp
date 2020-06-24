#include"UDPClientBase.h"

int UDPClientBase::run()
{
    int clientSocket = socket(AF_INET,SOCK_DGRAM,0);
    if(clientSocket==-1)
    {
        cout<<"socket error"<<endl;
        return -1;
    }

    sockaddr_in serverAddress;
    memset(&serverAddress, 0, sizeof(sockaddr_in));
    serverAddress.sin_family = AF_INET;
    if(inet_pton(AF_INET, this->address.c_str(), &serverAddress.sin_addr)!= 1)
    {
        cout<<"inet_pton error\n";
        return -1;
    }

    serverAddress.sin_port=htons(this->port);

    clientFunction(clientSocket, &serverAddress); 

    return 0;
}