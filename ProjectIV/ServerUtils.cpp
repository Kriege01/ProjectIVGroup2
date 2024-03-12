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
map<string, int> playersWaitingCount;

//mutex for synchronizing access to playersWaitingCount
mutex playersWaitingCountMutex;

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
        //receive message from client
        char buffer[4096];
        int bytesReceived = recv(clientSocket, buffer, sizeof(buffer), 0);
        if (bytesReceived == SOCKET_ERROR || bytesReceived == 0) {
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
        buffer[bytesReceived] = '\0';
        string message(buffer);
        recievedMessage = message;  // message IN
        logMessage("IN", recievedMessage);

        //print received message
        cout << "Received message from client: " << message << endl;

        //extract message type
        string messageType = message.substr(0, message.find(":"));

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
                    moveBuffer[moveBytesReceived] = '\0';
                    string moveMessage(moveBuffer);
                    //extract move coordinates
                    int row = stoi(moveMessage.substr(0, moveMessage.find(",")));
                    int col = stoi(moveMessage.substr(moveMessage.find(",") + 1));
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
                    moveBuffer[moveBytesReceived] = '\0';
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
