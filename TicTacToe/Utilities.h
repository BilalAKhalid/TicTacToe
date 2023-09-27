#pragma once
#include <iostream>
#include <Windows.h>
using namespace std;

void displayBoard(char board[3][3]) 
{
    cout << "Game Board\n\n";
    cout << "-------------\n";
    for (int i = 0; i < 3; i++) 
    {
        cout << "| ";
        for (int j = 0; j < 3; j++) 
        {
            cout << board[i][j] << " | ";
        }
        cout << "\n-------------\n";
    }
}

bool checkWin(char board[3][3], char player) 
{
    for (int i = 0; i < 3; i++) 
    {
        if (board[i][0] == player && board[i][1] == player && board[i][2] == player)
            return true;
        if (board[0][i] == player && board[1][i] == player && board[2][i] == player)
            return true;
    }
    if (board[0][0] == player && board[1][1] == player && board[2][2] == player)
        return true;
    if (board[0][2] == player && board[1][1] == player && board[2][0] == player)
        return true;
    return false;
}

bool checkDraw(char board[3][3]) 
{
    for (int i = 0; i < 3; i++) 
    {
        for (int j = 0; j < 3; j++) 
        {
            if (board[i][j] == ' ')
                return false;
        }
    }
    return true;
}

void Move(int row, int col, char currentPlayer, char board[3][3])
{
    bool validMove = false;

    while (!validMove) 
    {
        cout << "\nPlayer " << currentPlayer << ", enter your move (row and column): ";
        cin >> row >> col;

        if (row < 1 || row > 3 || col < 1 || col > 3 || board[row - 1][col - 1] != ' ') 
        {
            cout << "\nInvalid move. Try again.\n";
        }
        else {
            validMove = true;
        }
    }

    board[row - 1][col - 1] = currentPlayer;
}

bool GameEnd(char currentPlayer, char board[3][3])
{
    if (checkWin(board, currentPlayer)) {
        displayBoard(board);
        cout << "\nPlayer " << currentPlayer << " wins! Congratulations!\n";
        Sleep(5000);
        return true;
    }
    else if (checkDraw(board)) {
        system("CLS");
        displayBoard(board);
        cout << "\nIt's a draw! Well played!\n";    
        Sleep(5000);
        return true;
    }
}

void Restart(char playAgain, char currentPlayer, bool gameOver, char board[3][3])
{
    if (playAgain == 'y' || playAgain == 'Y') {
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                board[i][j] = ' ';
            }
        }
        currentPlayer = 'X';
        gameOver = false;
    }
    else {
        cout << "\nThanks for playing! Goodbye!\n";
    }
}