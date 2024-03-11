#include "TicTacToeState.h"

TicTacToeState::TicTacToeState() {
    reset();
}

void TicTacToeState::reset() {
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            board[i][j] = '_';
        }
    }
    currentPlayer = 'X';
    gameOver = false;
    winner = '_';
}

void TicTacToeState::makeMove(int row, int col) {
    if (row >= 0 && row < 3 && col >= 0 && col < 3 && board[row][col] == '_') {
        board[row][col] = currentPlayer;
        if (checkWin()) {
            gameOver = true;
            winner = currentPlayer;
        }
        else if (checkDraw()) {
            gameOver = true;
        }
        else {
            currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
        }
    }
}

bool TicTacToeState::checkWin() const {
    //check rows and columns
    for (int i = 0; i < 3; ++i) {
        if (board[i][0] != '_' && board[i][0] == board[i][1] && board[i][1] == board[i][2]) return true;
        if (board[0][i] != '_' && board[0][i] == board[1][i] && board[1][i] == board[2][i]) return true;
    }
    //check diagonals
    if (board[0][0] != '_' && board[0][0] == board[1][1] && board[1][1] == board[2][2]) return true;
    if (board[0][2] != '_' && board[0][2] == board[1][1] && board[1][1] == board[2][0]) return true;
    return false;
}

bool TicTacToeState::checkDraw() const {
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            if (board[i][j] == '_') return false;
        }
    }
    return true;
}

char TicTacToeState::getCurrentPlayer() const {
    return currentPlayer;
}

bool TicTacToeState::isGameOver() const {
    return gameOver;
}

char TicTacToeState::getWinner() const {
    return winner;
}

char TicTacToeState::getCellValue(int row, int col) const {
    return board[row][col];
}
