#include"myTCPClient.h"


void myTCPClient::clientFunction(int socket)
{
    string input;
    cout<<"This is a TCP client. Input to send to server. Input 'q' to quit:\n";
    while(input != "q")
    {
        getline(cin, input, '\n');
        write(socket, input.c_str(), input.length()+1);
    }
}

int main()
{
    myTCPClient client(30001, "127.0.0.1");
    client.run();
}