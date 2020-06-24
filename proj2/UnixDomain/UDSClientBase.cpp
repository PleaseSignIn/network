#include"UDSClientBase.h"

int UDSClientBase::run()
{
    int clientSocket = socket(AF_UNIX,SOCK_STREAM,0);
    if(clientSocket==-1)
    {
        cout<<"socket error"<<endl;
        return -1;
    }

    sockaddr_un sun;
    memset(&sun, 0, sizeof(sockaddr_un));
    sun.sun_family = AF_UNIX;
    strncpy(sun.sun_path, socket_name.c_str(), sizeof(sun.sun_path) - 1);

    if(connect(clientSocket, (sockaddr*)&sun, sizeof(sun))!=0)
    {
        cout<<"connect error\n";
        return -1;
    }

    clientFunction(clientSocket); 

    close(clientSocket);
    return 0;
}


