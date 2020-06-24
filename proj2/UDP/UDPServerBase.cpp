#include"UDPServerBase.h"

int UDPServerBase::run()
{
    int listenSocket = socket(AF_INET, SOCK_DGRAM, 0);
    if(listenSocket == -1)
    {
        cout<<"socket error"<<endl;
        return -1;
    }

    sockaddr_in serverAddress;
    memset(&serverAddress, 0, sizeof(sockaddr_in));
    serverAddress.sin_family = AF_INET;
    serverAddress.sin_addr.s_addr = htonl(INADDR_ANY);
    serverAddress.sin_port = htons(this->port);

    if(bind(listenSocket, (sockaddr*)&serverAddress, sizeof(sockaddr_in))==-1)
    {
        cout<<"bind error"<<endl;
        return -1;
    }
    
    serverFunction(listenSocket);

    return 0;
}