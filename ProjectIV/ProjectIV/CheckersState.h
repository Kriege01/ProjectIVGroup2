#pragma once


class CheckersState {
public:
    CheckersState();
    void reset();
    void makeMove(int startRow, int startCol, int endRow, int endCol);
    bool isValidMove(int startRow, int startCol, int endRow, int endCol) const;
    bool checkWin() const;
    char getCurrentPlayer() const;
    bool isGameOver() const;
    char getWinner() const;
    char getCellValue(int row, int col) const;

private:
    char board[8][8];
    char currentPlayer;
    bool gameOver;
    char winner;
};