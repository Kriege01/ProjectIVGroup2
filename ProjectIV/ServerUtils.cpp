#include "ServerUtils.h"
#include "GameUtils.h"
#include "TicTacToeState.h"
#include "CheckersState.h"

using namespace std;

//define global variables
SOCKET serverSocket;
std::vector<SOCKET> clients;
std::mutex mtx;

//define the number of players required to start a game
const int PLAYERS_REQUIRED_TO_START = 2;

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

void handleClient(SOCKET clientSocket, TicTacToeState& ticTacToeState, CheckersState& checkersState) {
    while (true) {
        std::string recievedMessage; // message IN
        // Receive message from client
        char buffer[4096];
        int bytesReceived = recv(clientSocket, buffer, sizeof(buffer), 0);
        if (bytesReceived == SOCKET_ERROR || bytesReceived == 0) {
            std::cerr << "Client disconnected" << std::endl;
            // Remove client socket from the list
            mtx.lock();
            clients.erase(std::remove(clients.begin(), clients.end(), clientSocket), clients.end());
            mtx.unlock();
            closesocket(clientSocket);
            return;
        }
        if (bytesReceived < sizeof(buffer)) {
            buffer[bytesReceived] = '\0';
        }
        else {
            cerr << "Received message is larger than the buffer size" << endl;
            return;
        }

        string message(buffer);

        //log received message
        recievedMessage = message;  // message IN
        logMessage("IN", recievedMessage);

        //print received message
        cout << "Received message from client: " << message << endl;

        //extract message type
        string messageType = message.substr(0, message.find(":"));
        cout << "Message type: " << messageType << endl;

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
                        closesocket(clientSocket);
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
                        closesocket(clientSocket);
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
