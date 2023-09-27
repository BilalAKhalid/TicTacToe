#include <iostream>
#include "Utilities.h"
using namespace std;

int main() {
    char board[3][3] = { { ' ', ' ', ' ' }, { ' ', ' ', ' ' }, { ' ', ' ', ' ' } };
    char currentPlayer = 'X';
    bool gameOver = false;
    int row = 0, col = 0;

    cout << "Welcome to Tic-Tac-Toe!\n\n";

    while (!gameOver) 
    {
        displayBoard(board);
        Move(row, col, currentPlayer, board);
        gameOver = GameEnd(currentPlayer, board);
        currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
        system("CLS");
    }

    cout << "\nDo you want to play again? (y/n): ";
    char playAgain;
    cin >> playAgain;

    Restart(playAgain, currentPlayer, gameOver, board);

    return 0;
}
