#include "GameUtils.h"

std::string serializeTicTacToeState(const TicTacToeState& state) {
    std::string serializedState = "";
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            serializedState += state.getCellValue(i, j);
        }
    }
    serializedState += state.getCurrentPlayer();
    serializedState += state.isGameOver() ? "1" : "0";
    serializedState += state.getWinner();
    return serializedState;
}

std::string serializeCheckersState(const CheckersState& state) {
    std::string serializedState = "";
    for (int i = 0; i < 8; ++i) {
        for (int j = 0; j < 8; ++j) {
            serializedState += state.getCellValue(i, j);
        }
    }
    serializedState += state.getCurrentPlayer();
    serializedState += state.isGameOver() ? "1" : "0";
    serializedState += state.getWinner();
    return serializedState;
}
