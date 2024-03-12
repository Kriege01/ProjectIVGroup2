#include <iostream>
#include <cstring>
#include <winsock2.h>
#include <ws2tcpip.h>
#include <string>

#pragma comment(lib, "ws2_32.lib")

using namespace std;

//define message types
const string MENU_SELECTION = "MENU_SELECTION";
const string TIC_TAC_TOE_MOVE = "TIC_TAC_TOE_MOVE";
const string TIC_TAC_TOE_STATE_UPDATE = "TIC_TAC_TOE_STATE_UPDATE";
const string CHECKERS_MOVE = "CHECKERS_MOVE";
const string CHECKERS_STATE_UPDATE = "CHECKERS_STATE_UPDATE";
const string GAME_START_SIGNAL = "GAME_START_SIGNAL";
const string GAME_OVER = "GAME_OVER";
const string CHAT_MESSAGE = "CHAT_MESSAGE";

//function to send a message to the server
void sendMessage(SOCKET socket, const string& message) {
    send(socket, message.c_str(), message.size(), 0);
}

//function to receive a message from the server
string receiveMessage(SOCKET socket) {
    char buffer[4096];
    int bytesReceived = recv(socket, buffer, sizeof(buffer), 0);
    if (bytesReceived == SOCKET_ERROR || bytesReceived == 0) {
        cerr << "Server disconnected" << endl;
        closesocket(socket);
        WSACleanup();
        exit(-1);
    }
    buffer[bytesReceived] = '\0';
    return string(buffer);
}

//function to send game selection signal to the server
void sendGameSelection(SOCKET socket, int gameChoice) {
    string message = MENU_SELECTION + ":" + to_string(gameChoice);
    send(socket, message.c_str(), message.size(), 0);
}

//function to wait for game start signal from the server
void waitForGameStart(SOCKET socket, const string& expectedGame) {
    char buffer[4096];
    int bytesReceived;

    //print "Waiting for another player" message
    cout << "Waiting for another player..." << endl;

    //loop until a game start signal is received
    while (true) {

        //receive a message from the server
        bytesReceived = recv(socket, buffer, sizeof(buffer), 0);
        if (bytesReceived == SOCKET_ERROR || bytesReceived == 0) {
            cerr << "Server disconnected" << endl;
            closesocket(socket);
            WSACleanup();
            exit(-1);
        }
        buffer[bytesReceived] = '\0';

        //parse the message to check for a game start signal
        string message(buffer);
        string messageType = message.substr(0, message.find(":"));

        if (messageType == GAME_START_SIGNAL) {
            //print that the game start signal is received
            cout << "Received game start signal for " << expectedGame << endl;

            //extract game name from the message
            string gameName = message.substr(message.find(":") + 1);
            if (gameName == expectedGame) {
                //game start signal received for the expected game, exit the function
                cout << "Exiting waitForGameStart function..." << endl;
                break;
            }
        }

        //if not a game start signal, continue waiting
    }
}


int main() {
    // Initialize Winsock
    WSADATA wsaData;
    if (WSAStartup(MAKEWORD(2, 2), &wsaData) != 0) {
        cerr << "WSAStartup failed" << endl;
        return -1;
    }

    // Create a TCP socket
    SOCKET tcpSocket = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
    if (tcpSocket == INVALID_SOCKET) {
        cerr << "Can't create socket: " << WSAGetLastError() << endl;
        WSACleanup();
        return -1;
    }

    // Set up server address structure
    sockaddr_in serverAddr;
    serverAddr.sin_family = AF_INET;
    serverAddr.sin_port = htons(15000);

    // Get server IP address from user input
    string serverIP;
    cout << "Enter server IP address: ";
    cin >> serverIP;

    // Convert IP address to binary form
    if (inet_pton(AF_INET, serverIP.c_str(), &serverAddr.sin_addr) <= 0) {
        cerr << "Invalid address/Address not supported" << endl;
        closesocket(tcpSocket);
        WSACleanup();
        return -1;
    }

    // Connect to the server
    if (connect(tcpSocket, (sockaddr*)&serverAddr, sizeof(serverAddr)) == SOCKET_ERROR) {
        cerr << "Connection failed: " << WSAGetLastError() << endl;
        closesocket(tcpSocket);
        WSACleanup();
        return -1;
    }

    cout << "Connected to server" << endl;
    cout << "Socket number: " << tcpSocket << endl; //print the socket number

    //send menu selection to server
    cout << "Choose a game:" << endl;
    cout << "1. Tic Tac Toe" << endl;
    cout << "2. Checkers" << endl;
    int gameChoice;
    cin >> gameChoice;
    sendGameSelection(tcpSocket, gameChoice);

    //wait for the game start signal from the server
    string expectedGame = (gameChoice == 1) ? "TicTacToe" : "Checkers";
    waitForGameStart(tcpSocket, expectedGame);

    //game loop
    while (true) {
        //receive message from server
        string message = receiveMessage(tcpSocket);

        // Print received message
        cout << "Received message from server: " << message << endl;

        //extract message type
        string messageType = message.substr(0, message.find(":"));
        string messageData = message.substr(message.find(":") + 1);

        //handle message based on type
        if (messageType == TIC_TAC_TOE_STATE_UPDATE) {
            //display Tic Tac Toe board
            cout << "Tic Tac Toe Board:" << endl;
            cout << " " << messageData[0] << " | " << messageData[1] << " | " << messageData[2] << endl;
            cout << "-----------" << endl;
            cout << " " << messageData[3] << " | " << messageData[4] << " | " << messageData[5] << endl;
            cout << "-----------" << endl;
            cout << " " << messageData[6] << " | " << messageData[7] << " | " << messageData[8] << endl;

            //check if game over
            if (messageData[9] == '1') {
                cout << "Game Over!" << endl;
                if (messageData[10] == 'X') {
                    cout << "X wins!" << endl;
                }
                else if (messageData[10] == 'O') {
                    cout << "O wins!" << endl;
                }
                else {
                    cout << "It's a draw!" << endl;
                }
                break;
            }

            //make a move
            cout << "Enter row and column to make a move (e.g., 1 2): ";
            int row, col;
            cin >> row >> col;
            sendMessage(tcpSocket, TIC_TAC_TOE_MOVE + ":" + to_string(row) + "," + to_string(col));
        }
        else if (messageType == CHECKERS_STATE_UPDATE) {
            //display Checkers board
            cout << "Checkers Board:" << endl;
            for (int i = 0; i < 8; ++i) {
                for (int j = 0; j < 8; ++j) {
                    cout << messageData[i * 8 + j] << " ";
                }
                cout << endl;
            }

            //check if game over
            if (messageData[64] == '1') {
                cout << "Game Over!" << endl;
                if (messageData[65] == 'R') {
                    cout << "Red wins!" << endl;
                }
                else if (messageData[65] == 'B') {
                    cout << "Black wins!" << endl;
                }
                else {
                    cout << "It's a draw!" << endl;
                }
                break;
            }

            //make a move
            cout << "Enter start row, start column, end row, and end column to make a move (e.g., 2 1 3 2): ";
            int startRow, startCol, endRow, endCol;
            cin >> startRow >> startCol >> endRow >> endCol;
            sendMessage(tcpSocket, CHECKERS_MOVE + ":" + to_string(startRow) + "," + to_string(startCol) + "," + to_string(endRow) + "," + to_string(endCol));
        }
    }

    //close the socket
    closesocket(tcpSocket);
    WSACleanup();
    return 0;
}

