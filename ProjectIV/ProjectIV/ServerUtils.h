#pragma once
#include <iostream>
#include <winsock2.h>
#include <vector>
#include <mutex>
#include <cstring>
#include <ws2tcpip.h>
#include <string>
#include <thread>
#include <fstream> // Include header for file operations
#include "TicTacToeState.h"
#include "CheckersState.h"
#include "Protocol.h"

extern SOCKET serverSocket;
extern std::vector<SOCKET> clients;
extern std::mutex mtx;

// Server utility functions
void handleClient(SOCKET clientSocket, TicTacToeState& ticTacToeState, CheckersState& checkersState);
void logMessage(const std::string& direction, const std::string& message); // Add the declaration for logging function
