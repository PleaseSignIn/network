#include"myUDSClient.h"


void myUDSClient::clientFunction(int socket)
{
    string input;
    cout<<"This is a UNIX Domain client. Input to send to server. Input 'q' to quit:\n";
    while(input != "q")
    {
        getline(cin, input, '\n');
        write(socket, input.c_str(), input.length()+1);
    }
}

int main()
{
    myUDSClient client(30002, "/tmp/connection-uds-fd");
    client.run();
}