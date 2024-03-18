//#include <iostream>
//#include <cstring>
//#include <winsock2.h>
//#include <ws2tcpip.h>
//#include <string>
//
//#pragma comment(lib, "ws2_32.lib")
//
//using namespace std;
//
//// Define message types
//const string MENU_SELECTION = "MENU_SELECTION";
//const string TIC_TAC_TOE_MOVE = "TIC_TAC_TOE_MOVE";
//const string TIC_TAC_TOE_STATE_UPDATE = "TIC_TAC_TOE_STATE_UPDATE";
//const string CHECKERS_MOVE = "CHECKERS_MOVE";
//const string CHECKERS_STATE_UPDATE = "CHECKERS_STATE_UPDATE";
//const string GAME_START_SIGNAL = "GAME_START_SIGNAL";
//const string GAME_OVER = "GAME_OVER";
//const string CHAT_MESSAGE = "CHAT_MESSAGE";
//
//// Function to send a message to the server
//void sendMessage(SOCKET socket, const string& message) {
//    send(socket, message.c_str(), message.size(), 0);
//}
//
//// Function to receive a message from the server
//string receiveMessage(SOCKET socket) {
//    char buffer[4096];
//    int bytesReceived = recv(socket, buffer, sizeof(buffer), 0);
//    if (bytesReceived == SOCKET_ERROR || bytesReceived == 0) {
//        cerr << "Server disconnected" << endl;
//        closesocket(socket);
//        WSACleanup();
//        exit(-1);
//    }
//    buffer[bytesReceived] = '\0';
//    return string(buffer);
//}
//
//// Function to send game selection signal to the server
//void sendGameSelection(SOCKET socket, int gameChoice) {
//    string message = MENU_SELECTION + ":" + to_string(gameChoice);
//    send(socket, message.c_str(), message.size(), 0);
//}
//
//// Function to wait for game start signal from the server
//void waitForGameStart(SOCKET socket) {
//    char buffer[4096];
//    int bytesReceived;
//
//    // Loop until a game start signal is received
//    while (true) {
//        // Print "Waiting for another player" message
//        std::cout << "Waiting for another player..." << endl;
//
//        // Receive a message from the server
//        bytesReceived = recv(socket, buffer, sizeof(buffer), 0);
//        if (bytesReceived == SOCKET_ERROR || bytesReceived == 0) {
//            cerr << "Server disconnected" << endl;
//            closesocket(socket);
//            WSACleanup();
//            exit(-1);
//        }
//        buffer[bytesReceived] = '\0';
//
//        // Parse the message to check for a game start signal
//        string message(buffer);
//        string messageType = message.substr(0, message.find(":"));
//
//        if (messageType == GAME_START_SIGNAL) {
//            // Game start signal received, exit the function
//            break;
//        }
//
//        // If not a game start signal, continue waiting
//    }
//}
//
//
////int main() {
////    // Initialize Winsock
////    WSADATA wsaData;
////    if (WSAStartup(MAKEWORD(2, 2), &wsaData) != 0) {
////        cerr << "WSAStartup failed" << endl;
////        return -1;
////    }
////
////    // Create a TCP socket
////    SOCKET tcpSocket = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
////    if (tcpSocket == INVALID_SOCKET) {
////        cerr << "Can't create socket: " << WSAGetLastError() << endl;
////        WSACleanup();
////        return -1;
////    }
////
////    // Set up server address structure
////    sockaddr_in serverAddr;
////    serverAddr.sin_family = AF_INET;
////    serverAddr.sin_port = htons(15000);
////
////    // Get server IP address from user input
////    string serverIP;
////    std::cout << "Enter server IP address: ";
////    std::cin >> serverIP;
////
////    // Convert IP address to binary form
////    if (inet_pton(AF_INET, serverIP.c_str(), &serverAddr.sin_addr) <= 0) {
////        cerr << "Invalid address/Address not supported" << endl;
////        closesocket(tcpSocket);
////        WSACleanup();
////        return -1;
////    }
////
////    // Connect to the server
////    if (connect(tcpSocket, (sockaddr*)&serverAddr, sizeof(serverAddr)) == SOCKET_ERROR) {
////        cerr << "Connection failed: " << WSAGetLastError() << endl;
////        closesocket(tcpSocket);
////        WSACleanup();
////        return -1;
////    }
////
////    std::cout << "Connected to server" << endl;
////
////    // Send menu selection to server
////    std::cout << "Choose a game:" << endl;
////    std::cout << "1. Tic Tac Toe" << endl;
////    std::cout << "2. Checkers" << endl;
////    int gameChoice;
////    std::cin >> gameChoice;
////    sendGameSelection(tcpSocket, gameChoice);
////
////    // Wait for the game start signal from the server
////    waitForGameStart(tcpSocket);
////
////    // Game loop
////    while (true) {
////        // Receive message from server
////        string message = receiveMessage(tcpSocket);
////
////        // Extract message type
////        string messageType = message.substr(0, message.find(":"));
////        string messageData = message.substr(message.find(":") + 1);
////
////        // Handle message based on type
////        if (messageType == TIC_TAC_TOE_STATE_UPDATE) {
////            // Display Tic Tac Toe board
////            std::cout << "Tic Tac Toe Board:" << endl;
////            std::cout << " " << messageData[0] << " | " << messageData[1] << " | " << messageData[2] << endl;
////            std::cout << "-----------" << endl;
////            std::cout << " " << messageData[3] << " | " << messageData[4] << " | " << messageData[5] << endl;
////            std::cout << "-----------" << endl;
////            std::cout << " " << messageData[6] << " | " << messageData[7] << " | " << messageData[8] << endl;
////
////            // Check if game over
////            if (messageData[9] == '1') {
////                std::cout << "Game Over!" << endl;
////                if (messageData[10] == 'X') {
////                    std::cout << "X wins!" << endl;
////                }
////                else if (messageData[10] == 'O') {
////                    std::cout << "O wins!" << endl;
////                }
////                else {
////                    std::cout << "It's a draw!" << endl;
////                }
////                break;
////            }
////
////            // Make a move
////            std::cout << "Enter row and column to make a move (e.g., 1 2): ";
////            int row, col;
////            std::cin >> row >> col;
////            sendMessage(tcpSocket, TIC_TAC_TOE_MOVE + ":" + to_string(row) + "," + to_string(col));
////        }
////        else if (messageType == CHECKERS_STATE_UPDATE) {
////            // Display Checkers board
////            std::cout << "Checkers Board:" << endl;
////            // Display Checkers board
////            // Display Checkers board
////            for (int i = 0; i < 8; ++i) {
////                for (int j = 0; j < 8; ++j) {
////                    std::cout << messageData[i * 8 + j] << " ";
////                }
////                std::cout << endl;
////            }
////
////            // Check if game over
////            if (messageData[64] == '1') {
////                std::cout << "Game Over!" << endl;
////                if (messageData[65] == 'R') {
////                    std::cout << "Red wins!" << endl;
////                }
////                else if (messageData[65] == 'B') {
////                    std::cout << "Black wins!" << endl;
////                }
////            }
////        }
////    }