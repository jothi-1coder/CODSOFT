#include <iostream>
using namespace std;
void resetBoard(char board[3][3]) {
    char v = '1';
    for (int i = 0; i < 3; ++i)
        for (int j = 0; j < 3; ++j)
            board[i][j] = v++;
}

void displayBoard(const char board[3][3]) {
    cout << "\n";
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            cout << " " << board[i][j] << " ";
            if (j < 2) cout << "|";
        }
        cout << "\n";
        if (i < 2) cout << "---|---|---\n";
    }
    cout << "\n";
}

bool makeMove(char board[3][3], int choice, char symbol) {
    if (choice < 1 || choice > 9) {
        cout << "Enter a number from 1 to 9.\n";
        return false;
    }
    int row = (choice - 1) / 3;
    int col = (choice - 1) % 3;

    if (board[row][col] != 'X' && board[row][col] != 'O') {
        board[row][col] = symbol;
        return true;
    } else {
        cout << "That square is already filled. Try again.\n";
        return false;
    }
}

bool checkWin(const char board[3][3], char s) {
    for (int i = 0; i < 3; ++i)
        if (board[i][0] == s && board[i][1] == s && board[i][2] == s) return true;
    for (int j = 0; j < 3; ++j)
        if (board[0][j] == s && board[1][j] == s && board[2][j] == s) return true;
    if (board[0][0] == s && board[1][1] == s && board[2][2] == s) return true;
    if (board[0][2] == s && board[1][1] == s && board[2][0] == s) return true;

    return false;
}

bool checkDraw(const char board[3][3]) {
    for (int i = 0; i < 3; ++i)
        for (int j = 0; j < 3; ++j)
            if (board[i][j] != 'X' && board[i][j] != 'O') return false;
    return true;
}
int main() {
    char board[3][3];
    char playAgain;

    do {
        resetBoard(board);
        char current = 'X';
        bool over = false;

        while (!over) {
            displayBoard(board);

            cout << "Player " << current << ", enter your move (1-9): ";
            int choice;
            if (!(cin >> choice)) {
                cout << "Please enter a valid number.\n";
                cin.clear();
                cin.ignore(10000, '\n');
                continue;
            }

            if (!makeMove(board, choice, current)) {
                continue; 
            }

            if (checkWin(board, current)) {
                displayBoard(board);
                cout << "Player " << current << " wins the Game !\n";
                over = true;
            } else if (checkDraw(board)) {
                displayBoard(board);
                cout << "It's a draw match!\n";
                over = true;
            } else {
                current = (current == 'X') ? 'O' : 'X';
            }
        }

        cout << "You want to Play again? (y/n): ";
        cin >> playAgain;
    } while (playAgain == 'y' || playAgain == 'Y');

    cout << "Thanks for playing the Game. Come again to play!\n";
    return 0;
}


