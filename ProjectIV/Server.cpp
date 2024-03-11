#include <iostream>
#include <winsock2.h>
#include <ws2tcpip.h>
#include "TicTacToeState.h"
#include "CheckersState.h"
#include "Protocol.h"
#include "ServerUtils.h"

#pragma comment(lib, "ws2_32.lib")

using namespace std;

int main() {
    //initialize Winsock
    WSADATA wsaData;
    int result = WSAStartup(MAKEWORD(2, 2), &wsaData);
    if (result != 0) {
        cerr << "WSAStartup failed: " << result << endl;
        return -1;
    }

    //create a TCP socket
    SOCKET serverSocket = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
    if (serverSocket == INVALID_SOCKET) {
        cerr << "Can't create socket: " << WSAGetLastError() << endl;
        WSACleanup();
        return -1;
    }

    //set up server address structure
    sockaddr_in serverAddr;
    serverAddr.sin_family = AF_INET;
    inet_pton(AF_INET, "127.0.0.1", &serverAddr.sin_addr); //specify server IP address
    serverAddr.sin_port = htons(15000);

    //bind the socket to the server address
    result = bind(serverSocket, (sockaddr*)&serverAddr, sizeof(serverAddr));
    if (result == SOCKET_ERROR) {
        cerr << "Bind failed: " << WSAGetLastError() << endl;
        closesocket(serverSocket);
        WSACleanup();
        return -1;
    }

    //start listening for connections
    result = listen(serverSocket, SOMAXCONN);
    if (result == SOCKET_ERROR) {
        cerr << "Listen failed: " << WSAGetLastError() << endl;
        closesocket(serverSocket);
        WSACleanup();
        return -1;
    }

    cout << "Server is running and listening on port 15000" << endl;

    //game states
    TicTacToeState ticTacToeState;
    CheckersState checkersState;

    //game loop
    while (true) {
        //accept incoming connections
        SOCKET clientSocket = accept(serverSocket, NULL, NULL);
        if (clientSocket == INVALID_SOCKET) {
            cerr << "Accept failed: " << WSAGetLastError() << endl;
            closesocket(serverSocket);
            WSACleanup();
            return -1;
        }

        cout << "Client connected" << endl;

        //add client socket to list
        mtx.lock();
        clients.push_back(clientSocket);
        mtx.unlock();

        //create a thread to handle the client
        thread clientThread(handleClient, clientSocket, ref(ticTacToeState), ref(checkersState));
        clientThread.detach(); //detach thread to run independently
    }

    //close the server socket
    closesocket(serverSocket);
    WSACleanup();
    return 0;
}

