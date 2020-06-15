#include"myClient.h"


void myClient::clientFunction(int socket)
{
    char buffer[20];

    read(socket, buffer, 20);

    cout<<buffer<<endl;
}

int main()
{
    myClient client(30001, "127.0.0.1");
    client.run();
}