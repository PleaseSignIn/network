#include"UDSServerBase.h"

int UDSServerBase::run()
{
    int listenSocket = socket(AF_UNIX, SOCK_STREAM, 0);
    if(listenSocket == -1)
    {
        cout<<"socket error"<<endl;
        return -1;
    }

    sockaddr_un sun;
    memset(&sun, 0, sizeof(sockaddr_un));
    sun.sun_family = AF_UNIX;
    strncpy(sun.sun_path, socket_name.c_str(), sizeof(sun.sun_path) - 1); 

    if(access(socket_name.c_str(), F_OK) == 0)
    {
        remove(socket_name.c_str());
    }

    if(bind(listenSocket, (sockaddr*)&sun, sizeof(sun))==-1)
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

    int connectedSocket = accept(listenSocket, nullptr, nullptr);
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
