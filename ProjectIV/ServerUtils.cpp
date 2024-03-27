#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <map>
#include <mutex>
#include <fstream>
#include <winsock2.h>
#include <algorithm>

#include "ServerUtils.h"
#include "GameUtils.h"
#include "TicTacToeState.h"
#include "CheckersState.h"
#include "UserManagement.h"
#include "Protocol.h"

using namespace std;

//define global variables
SOCKET serverSocket;
std::vector<SOCKET> clients;
std::mutex mtx;

//define the number of players required to start a game
const int PLAYERS_REQUIRED_TO_START = 2;
const int MAX_AUTH_ATTEMPTS = 3;

//maintain a map to track the number of players waiting for each game
std::map<std::string, int> playersWaitingCount;
std::mutex playersWaitingCountMutex;

void sendMessage(SOCKET clientSocket, const string& message) {
    //send message to client
    int bytesSent = send(clientSocket, message.c_str(), message.length(), 0);
    if (bytesSent == SOCKET_ERROR) {
        cerr << "Error sending message to client" << endl;
    }
}

// logging functionality
void logMessage(const std::string& direction, const std::string& message) {
    std::ofstream logFile("logfile.txt", std::ios::app); // Open the log file in append mode
    if (logFile.is_open()) {
        logFile << "[" << direction << "] " << message << std::endl;
        logFile.close(); // Close the file after writing
    }
    else {
        // Failed to open the log file
        std::cerr << "Error: Failed to open log file." << std::endl;
    }
}

void handleClient(SOCKET clientSocket, TicTacToeState& ticTacToeState, CheckersState& checkersState, UserManager& userManager) {
    string receivedMessage;
    string messageType;
    string username;
    string password;
    bool isAuthenticated = false;
    int authAttempts = 0;

    // Authentication loop
    while (!isAuthenticated && authAttempts < MAX_AUTH_ATTEMPTS) {
        char buffer[4096] = { 0 };
        int bytesReceived = recv(clientSocket, buffer, sizeof(buffer) - 1, 0);
        if (bytesReceived <= 0) {
            cerr << "Error: Client disconnected or error receiving data." << endl;
            closesocket(clientSocket);
            return;
        }

        buffer[bytesReceived] = '\0';  // Ensure null-terminated string
        string message(buffer);
        logMessage("IN", message);
        cout << "Received message from client: " << message << endl;

        istringstream iss(message);
        string messageType;
        getline(iss, messageType, ':');

        // Handle authentication
        if (messageType == USER_REGISTER || messageType == USER_LOGIN) {
            getline(iss, username, ':');
            getline(iss, password);
            isAuthenticated = (messageType == USER_REGISTER) ?
                userManager.registerUser(username, password) :
                userManager.loginUser(username, password);

            string responseMessage = isAuthenticated ? AUTH_SUCCESS : AUTH_FAILURE;
            sendMessage(clientSocket, responseMessage);
            logMessage("OUT", responseMessage);

            if (!isAuthenticated) {
                authAttempts++;
            }
            else {
                break;  // Exit the loop if authenticated
            }
        }
        else {
            sendMessage(clientSocket, "AUTH_REQUIRED: Please log in or register.");
            logMessage("OUT", "AUTH_REQUIRED: Client tried to skip authentication.");
        }
    }

    // If the client failed to authenticate after MAX_AUTH_ATTEMPTS
    if (!isAuthenticated) {
        // If authentication fails after maximum attempts
        sendMessage(clientSocket, "AUTH_MAX_ATTEMPTS: Maximum authentication attempts reached.");
        logMessage("OUT", "Maximum authentication attempts reached. Disconnecting client.");
        closesocket(clientSocket);
        return; // Disconnect the client
    }

    while (true) {
        char buffer[4096] = { 0 }; // Initialize the buffer to zero
        int bytesReceived = recv(clientSocket, buffer, sizeof(buffer) - 1, 0); // Leave space for null-terminator
        if (bytesReceived <= 0) {
            cerr << "Client disconnected" << endl;
            mtx.lock();
            clients.erase(remove(clients.begin(), clients.end(), clientSocket), clients.end());
            mtx.unlock();
            return;
        }

        // The buffer is already null-terminated based on initialization above
        string message(buffer);
        logMessage("IN", message);

        // Print received message
        cout << "Received message from client: " << message << endl;

        istringstream iss(message);
        getline(iss, messageType, ':');

        // Depending on the message type, extract additional parameters
        if (messageType == TIC_TAC_TOE_MOVE) {
            int row = stoi(message.substr(message.find(":") + 1, message.find(",")));
            int col = stoi(message.substr(message.find(",") + 1));
            cout << "Tic Tac Toe move received: Row=" << row << ", Column=" << col << endl;
        }

        //handle based on type
        if (messageType == MENU_SELECTION) {
            //menu selection
            string gameChoice = message.substr(message.find(":") + 1);
            //start Tic Tac Toe
            if (gameChoice == "1") {
                {
                    lock_guard<mutex> lock(playersWaitingCountMutex);
                    playersWaitingCount["TicTacToe"]++;
                    if (playersWaitingCount["TicTacToe"] == PLAYERS_REQUIRED_TO_START) {
                        //send game start signal to clients waiting for Tic Tac Toe
                        cout << "Sending game start signal for Tic Tac Toe to clients:" << endl;
                        for (SOCKET socket : clients) {
                            sendMessage(socket, GAME_START_SIGNAL + ":" + "TicTacToe");
                            cout << " - Client " << socket << endl;
                        }
                        playersWaitingCount["TicTacToe"] = 0; //reset waiting count
                    }
                }

                //TicTacToe Game loop
                while (!ticTacToeState.isGameOver()) {
                    //send Tic Tac Toe state to client
                    string gameState = TIC_TAC_TOE_STATE_UPDATE + ":" + serializeTicTacToeState(ticTacToeState);
                    send(clientSocket, gameState.c_str(), gameState.size(), 0);
                    //receive move from client
                    char moveBuffer[256];
                    int moveBytesReceived = recv(clientSocket, moveBuffer, sizeof(moveBuffer), 0);
                    if (moveBytesReceived == SOCKET_ERROR || moveBytesReceived == 0) {
                        cerr << "Client disconnected" << endl;
                        mtx.lock();
                        for (auto it = clients.begin(); it != clients.end(); ++it) {
                            if (*it == clientSocket) {
                                clients.erase(it);
                                break;
                            }
                        }
                        mtx.unlock();
                        return;
                    }
                    //ensure moveBuffer is null-terminated
                    moveBuffer[moveBytesReceived] = '\0';

                    //create a string from moveBuffer
                    std::string moveMessage(moveBuffer);

                    //find the position of the comma in moveMessage
                    size_t commaPos = moveMessage.find(",");

                    if (commaPos != std::string::npos) {
                        //comma found, proceed with extracting row and column
                    }
                    else {
                        //comma not found, handle error
                        std::cerr << "Error: Comma not found in move message\n";
                        //exit
                        return;
                    }

                    //find the position of the colon character in the move message
                    size_t colonPos = moveMessage.find(":");
                    if (colonPos == std::string::npos) {
                        std::cerr << "Error: Colon not found in move message\n";
                        return;
                    }

                    //extract the row and column substrings
                    string rowStr = moveMessage.substr(colonPos + 1, commaPos - (colonPos + 1));

                    std::string colStr = moveMessage.substr(commaPos + 1);

                    //verify rowStr contains only numerical characters
                    for (char c : rowStr) {
                        if (!std::isdigit(c)) {
                            //unexpected character found, handle error
                            std::cerr << "Error: Non-numeric character in row value\n";
                            //exit
                            return;
                        }
                    }

                    //verify colStr contains only numerical characters
                    for (char c : colStr) {
                        if (!std::isdigit(c)) {
                            //unexpected character found, handle error
                            std::cerr << "Error: Non-numeric character in column value\n";
                            //exit
                            return;
                        }
                    }

                    //parse row and column values
                    int row, col;
                    try {
                        row = std::stoi(rowStr);
                        col = std::stoi(colStr);
                    }
                    catch (const std::exception& e) {
                        //exception occurred during parsing, handle error
                        std::cerr << "Error: Exception during parsing - " << e.what() << '\n';
                        //exit
                        return;
                    }

                    //make move in Tic Tac Toe
                    ticTacToeState.makeMove(row, col);
                }
            }
            //start Checkers game
            else if (gameChoice == "2") {
                {
                    lock_guard<mutex> lock(playersWaitingCountMutex);
                    playersWaitingCount["Checkers"]++;
                    if (playersWaitingCount["Checkers"] == PLAYERS_REQUIRED_TO_START) {
                        //send game start signal to clients waiting for Checkers
                        cout << "Sending game start signal for Checkers to clients:" << endl;
                        for (SOCKET socket : clients) {
                            sendMessage(socket, GAME_START_SIGNAL + ":" + "Checkers");
                            cout << " - Client " << socket << endl;
                        }
                        playersWaitingCount["Checkers"] = 0; //reset waiting count
                    }
                }

                //Checkers game loop
                while (!checkersState.isGameOver()) {
                    //send Checkers state to client
                    string gameState = CHECKERS_STATE_UPDATE + ":" + serializeCheckersState(checkersState);
                    send(clientSocket, gameState.c_str(), gameState.size(), 0);
                    //receive move from client
                    char moveBuffer[256];
                    int moveBytesReceived = recv(clientSocket, moveBuffer, sizeof(moveBuffer), 0);
                    if (moveBytesReceived == SOCKET_ERROR || moveBytesReceived == 0) {
                        cerr << "Client disconnected" << endl;
                        mtx.lock();
                        for (auto it = clients.begin(); it != clients.end(); ++it) {
                            if (*it == clientSocket) {
                                clients.erase(it);
                                break;
                            }
                        }
                        mtx.unlock();
                        return;
                    }
                    moveBuffer[moveBytesReceived - 1] = '\0';
                    string moveMessage(moveBuffer);
                    //extract move coordinates
                    int startRow = stoi(moveMessage.substr(0, moveMessage.find(",")));
                    moveMessage = moveMessage.substr(moveMessage.find(",") + 1);
                    int startCol = stoi(moveMessage.substr(0, moveMessage.find(",")));
                    moveMessage = moveMessage.substr(moveMessage.find(",") + 1);
                    int endRow = stoi(moveMessage.substr(0, moveMessage.find(",")));
                    moveMessage = moveMessage.substr(moveMessage.find(",") + 1);
                    int endCol = stoi(moveMessage);
                    //make move in Checkers
                    checkersState.makeMove(startRow, startCol, endRow, endCol);
                }
            }
        }
        else if (messageType == TIC_TAC_TOE_MOVE) {
            //handle Tic Tac Toe move
            int row = stoi(message.substr(message.find(":") + 1, message.find(",")));
            int col = stoi(message.substr(message.find(",") + 1));
            ticTacToeState.makeMove(row, col);
        }
        else if (messageType == CHECKERS_MOVE) {
            //handle Checkers move
            int startRow = stoi(message.substr(message.find(":") + 1, message.find(",")));
            int startCol = stoi(message.substr(message.find(",") + 1, message.find(",", message.find(",") + 1)));
            int endRow = stoi(message.substr(message.find(",", message.find(",") + 1) + 1, message.find(",", message.find(",", message.find(",") + 1) + 1)));
            int endCol = stoi(message.substr(message.find(",", message.find(",", message.find(",") + 1) + 1) + 1));
            checkersState.makeMove(startRow, startCol, endRow, endCol);
        }
        std::string responseMessage = "Response to client";  // message out
        logMessage("OUT", responseMessage);
     
    }
}
