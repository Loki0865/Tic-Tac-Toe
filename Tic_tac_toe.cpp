#include <iostream>
using namespace std;

const int SIZE = 3;
char board[SIZE][SIZE] = {{' ', ' ', ' '},
                          {' ', ' ', ' '},
                          {' ', ' ', ' '}};

void displayBoard()
{
    cout << "  0   1   2" << endl;
    for (int i = 0; i < SIZE; i++)
    {
        cout << i << " ";
        for (int j = 0; j < SIZE; j++)
        {
            cout << board[i][j];
            if (j < SIZE - 1)
            {

                cout << " | ";
            }
        }
        cout << endl;
        if (i < SIZE - 1)
            cout << " ---|---|---" << endl;
    }
    cout << endl;
}

bool placeSymbol(int row, int col, char symbol)
{
    if (row >= 0 && row < SIZE && col >= 0 && col < SIZE && board[row][col] == ' ')
    {
        board[row][col] = symbol;
        return true;
    }
    return false;
}

bool checkWin(char symbol)
{
    for (int i = 0; i < SIZE; i++)
    {

        if ((board[i][0] == symbol && board[i][1] == symbol && board[i][2] == symbol) || (board[0][i] == symbol && board[1][i] == symbol && board[2][i] == symbol))
        {
            return true;
        }
    }

    if ((board[0][0] == symbol && board[1][1] == symbol && board[2][2] == symbol) || (board[0][2] == symbol && board[1][1] == symbol && board[2][0] == symbol))
    {
        return true;
    }
    return false;
}

bool isDraw()
{
    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++)
        {
            if (board[i][j] == ' ')
                return false;
        }
    }
    return true;
}
void resetboard()
{
    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++)
        {
            board[i][j] = ' ';
        }
    }
}

int main()
{
    bool response = true;
    while (response)
    {
        char symbol = 'X';
        bool gamerunning = true;
        cout << endl;
        cout << "!!Welcome to Tic Tac Toe Game!!" << endl;
        resetboard();
        displayBoard();
        cout << endl;
        while (gamerunning)
        {
            int row, col;
            cout << "Player " << symbol << ", enter your row & column: ";
            cin >> row >> col;
            if (placeSymbol(row, col, symbol))
            {

                displayBoard();
                if (checkWin(symbol))
                {

                    cout << "Player " << symbol << " You have won!" << endl;
                    gamerunning = false;
                }
                else if (isDraw())
                {
                    cout << "Its a Draw" << endl;
                    gamerunning = false;
                }
                else
                {
                    symbol = (symbol == 'X') ? 'O' : 'X';
                }
            }
            else
            {
                cout << "Invalid move! ,Try Again";
            }
        }
        int feedback;
        cout << "Do You want to play again" << endl;
        cout << "Enter 1-YES \n      0-NO " << endl;
        cin >> feedback;
        response = (feedback == 1);
    }
    return 0;
}
