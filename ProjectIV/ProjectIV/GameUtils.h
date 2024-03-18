#pragma once


#include <string>
#include "TicTacToeState.h"
#include "CheckersState.h"

// Declare utility functions
std::string serializeTicTacToeState(const TicTacToeState& state);
std::string serializeCheckersState(const CheckersState& state);