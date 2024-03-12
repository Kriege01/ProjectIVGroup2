#pragma once

class TicTacToeState {
public:
    TicTacToeState();
    void reset();
    void makeMove(int row, int col);
    bool checkWin() const;
    bool checkDraw() const;
    char getCurrentPlayer() const;
    bool isGameOver() const;
    char getWinner() const;
    char getCellValue(int row, int col) const;

private:
    char board[3][3];
    char currentPlayer;
    bool gameOver;
    char winner;
};