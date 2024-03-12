#pragma once
#include <iostream>
#include <winsock2.h>
#include <vector>
#include <mutex>
#include <cstring>
#include <ws2tcpip.h>
#include <map>
#include <string>
#include <thread>
#include <fstream> 
#include "TicTacToeState.h"
#include "CheckersState.h"
#include "Protocol.h"

extern SOCKET serverSocket;
extern std::vector<SOCKET> clients;
extern std::mutex mtx;

//server utility functions
void sendMessage(SOCKET clientSocket, const std::string& message);
void handleClient(SOCKET clientSocket, TicTacToeState& ticTacToeState, CheckersState& checkersState);
void logMessage(const std::string& direction, const std::string& message);