#include "CheckersState.h"
#include <iostream>


CheckersState::CheckersState() {
    reset();
}

void CheckersState::reset() {
    //initialize board
    for (int i = 0; i < 8; ++i) {
        for (int j = 0; j < 8; ++j) {
            if ((i + j) % 2 == 0) {
                if (i < 3) board[i][j] = 'R';
                else if (i > 4) board[i][j] = 'B';
                else board[i][j] = '_';
            }
            else {
                board[i][j] = ' ';
            }
        }
    }
    currentPlayer = 'R';
    gameOver = false;
    winner = '_';
}

void CheckersState::makeMove(int startRow, int startCol, int endRow, int endCol) {
    if (isValidMove(startRow, startCol, endRow, endCol)) {
        board[endRow][endCol] = board[startRow][startCol];
        board[startRow][startCol] = '_';
        //check for promotion
        if ((endRow == 0 && board[endRow][endCol] == 'B') || (endRow == 7 && board[endRow][endCol] == 'R')) {
            //promote
            board[endRow][endCol] = toupper(board[endRow][endCol]);
        }
        //switch player
        currentPlayer = (currentPlayer == 'R') ? 'B' : 'R';
    }
}

bool CheckersState::isValidMove(int startRow, int startCol, int endRow, int endCol) const {
    //check if the end position is empty
    if (board[endRow][endCol] != '_') {
        return false;
    }
    //check if the move is diagonal
    if (abs(startRow - endRow) != 1 || abs(startCol - endCol) != 1) {
        return false;
    }
    //check if the move direction is correct for the player
    if ((currentPlayer == 'R' && endRow < startRow) || (currentPlayer == 'B' && endRow > startRow)) {
        return false;
    }
    return true;
}

bool CheckersState::checkWin() const {
    //check if the opponent has no more pieces
    char opponent = (currentPlayer == 'R') ? 'B' : 'R';
    for (int row = 0; row < 8; ++row) {
        for (int col = 0; col < 8; ++col) {
            if (board[row][col] == opponent) {
                return false;
            }
        }
    }
    return true;
}

char CheckersState::getCurrentPlayer() const {
    return currentPlayer;
}

bool CheckersState::isGameOver() const {
    return gameOver;
}

char CheckersState::getWinner() const {
    return winner;
}

char CheckersState::getCellValue(int row, int col) const {
    return board[row][col];
}
