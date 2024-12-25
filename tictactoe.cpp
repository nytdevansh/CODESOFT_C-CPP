#include <iostream>
using namespace std;

char board[3][3];
char currentPlayer;

// Function to reset the board
void resetBoard() {
    char startValue = '1';
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            board[i][j] = startValue++;
        }
    }
    currentPlayer = 'X'; // Reset to starting player
}

// Function to display the board
void displayBoard() {
    cout << "\n";
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cout << board[i][j] << " ";
        }
        cout << "\n";
    }
    cout << "\n";
}

// Function to check if a player has won
bool checkWin() {
    // Check rows and columns
    for (int i = 0; i < 3; i++) {
        if (board[i][0] == board[i][1] && board[i][1] == board[i][2]) return true; // Row
        if (board[0][i] == board[1][i] && board[1][i] == board[2][i]) return true; // Column
    }
    // Check diagonals
    if (board[0][0] == board[1][1] && board[1][1] == board[2][2]) return true;
    if (board[0][2] == board[1][1] && board[1][1] == board[2][0]) return true;

    return false;
}

// Function to check if the board is full
bool checkDraw() {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (board[i][j] != 'X' && board[i][j] != 'O') return false;
        }
    }
    return true;
}

// Function to make a move
bool makeMove(int choice) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (board[i][j] == choice + '0') {
                board[i][j] = currentPlayer;
                return true;
            }
        }
    }
    return false;
}

int main() {
    char playAgain = 'y';

    cout << "Welcome to Tic Tac Toe!\n";

    while (playAgain == 'y' || playAgain == 'Y') {
        resetBoard();
        displayBoard();

        while (true) {
            int choice;
            cout << "Player " << currentPlayer << ", enter your choice (1-9): ";
            cin >> choice;

            // Validate the move
            if (choice < 1 || choice > 9 || !makeMove(choice)) {
                cout << "Invalid move. Try again.\n";
                continue;
            }

            displayBoard();

            // Check for win or draw
            if (checkWin()) {
                cout << "Player " << currentPlayer << " wins!\n";
                break;
            } else if (checkDraw()) {
                cout << "It's a draw!\n";
                break;
            }

            // Switch player
            currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
        }

        cout << "Do you want to play again? (y/n): ";
        cin >> playAgain;

        if (playAgain != 'y' && playAgain != 'Y') {
            cout << "Thank you for playing! Goodbye!\n";
        }
    }

    return 0;
}