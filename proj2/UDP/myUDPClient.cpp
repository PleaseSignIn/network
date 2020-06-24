#include"myUDPClient.h"

void myUDPClient::clientFunction(int socket, sockaddr_in* serverAddress)
{
    string input;
    cout<<"This is a UDP client. Input to send to server. Input 'q' to quit:\n";
    while(input != "q")
    {
        getline(cin, input, '\n');
        sendto(socket, input.c_str(), input.length()+1, 0, (sockaddr*)serverAddress, sizeof(*serverAddress));
    }
}

int main()
{
    myUDPClient client(30000, "127.0.0.1");
    client.run();
}