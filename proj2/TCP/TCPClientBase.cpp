#include"TCPClientBase.h"

int TCPClientBase::run()
{
    int clientSocket = socket(AF_INET,SOCK_STREAM,0);
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

    if(connect(clientSocket, (sockaddr*)&serverAddress, sizeof(serverAddress))!=0)
    {
        cout<<"connect error\n";
        return -1;
    }

    clientFunction(clientSocket); 

    close(clientSocket);
    return 0;
}


