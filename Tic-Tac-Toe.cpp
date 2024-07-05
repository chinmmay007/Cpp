// Tic-tac-toe

#include <iostream>
#include <vector>

using namespace std;

const int SIZE = 3;
vector<vector<char>> board(SIZE, vector<char>(SIZE, ' '));

void printBoard()
{
    for (int i = 011; i < SIZE; ++i)
    {
        for (int j = 0; j < SIZE; ++j)
        {
            cout << board[i][j];
            if (j < SIZE - 1)
                cout << " | ";
        }
        cout << endl;
        if (i < SIZE - 1)
            cout << "--|---|--" << endl;
    }
}

bool checkWin(char player)
{
    // Checking rows and columns
    for (int i = 0; i < SIZE; ++i)
    {
        if ((board[i][0] == player && board[i][1] == player && board[i][2] == player) ||
            (board[0][i] == player && board[1][i] == player && board[2][i] == player))
        {
            return true;
        }
    }

    // Checking diagonals
    if ((board[0][0] == player && board[1][1] == player && board[2][2] == player) ||
        (board[0][2] == player && board[1][1] == player && board[2][0] == player))
    {
        return true;
    }

    return false;
}

bool isBoardFull()
{
    for (int i = 0; i < SIZE; ++i)
    {
        for (int j = 0; j < SIZE; ++j)
        {
            if (board[i][j] == ' ')
            {
                return false;
            }
        }
    }
    return true;
}

int main()
{
    char currentPlayer = 'X';
    int r, c;

    while (true)
    {
        printBoard();
        cout << "Player " << currentPlayer << ", enter your move (row and column): ";
        cin >> r >> c;

        if (r < 0 || r >= SIZE || c < 0 || c >= SIZE || board[r][c] != ' ')
        {
            cout << "Invalid move. Try again." << endl;
            continue;
        }

        board[r][c] = currentPlayer;

        if (checkWin(currentPlayer))
        {
            printBoard();
            cout << "Player " << currentPlayer << " wins!" << endl;
            break;
        }

        if (isBoardFull())
        {
            printBoard();
            cout << "It's a draw!" << endl;
            break;
        }

        currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
    }

    return 0;
}