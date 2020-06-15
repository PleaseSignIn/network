#include"myClient.h"


void myClient::clientFunction(int socket)
{
    string input;
    cout<<"input to send to server:\n";
    while(input != "q")
    {
        getline(cin, input, '\n');
        write(socket, input.c_str(), input.length()+1);
    }
}

int main()
{
    myClient client(30001, "127.0.0.1");
    client.run();
}