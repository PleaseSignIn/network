#include"TCPServerBase.h"

int TCPServerBase::run()
{
    int listenSocket = socket(AF_INET, SOCK_STREAM, 0);
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
        close(listenSocket);
        return -1;
    }

    if(listen(listenSocket, 23)==-1)
    {
        cout<<"listen error"<< endl;
        close(listenSocket);
        return -1;
    }

    sockaddr_in clientAddress;
    socklen_t clientAddressLength = sizeof(sockaddr_in);
    int connectedSocket = accept(listenSocket, (sockaddr*)&clientAddress, &clientAddressLength);
    if(connectedSocket == -1)
    {
        cout<< "accept error"<< endl;
        close(listenSocket);
        return -1;
    }
    
    serverFunction(connectedSocket);

    close(connectedSocket);
    close(listenSocket);
    return 0;
}
