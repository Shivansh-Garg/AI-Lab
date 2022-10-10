#include <bits/stdc++.h>
using namespace std;

#define COMPUTER 1
#define HUMAN 2

void showBoard(char board[3][3])
{

    cout << board[0][0] << " | " << board[0][1] << " | " << board[0][2] << endl;
    cout << "-----------\n";
    cout << board[1][0] << " | " << board[1][1] << " | " << board[1][2] << endl;
    cout << "-----------\n";
    cout << board[2][0] << " | " << board[2][1] << " | " << board[2][2] << endl;
}

void showStartingBoard()
{
    cout << " 1 | 2 | 3 \n";
    cout << "-----------\n";
    cout << " 4 | 5 | 6 \n";
    cout << "-----------\n";
    cout << " 7 | 8 | 9 \n";
}

void initialise(char board[][3])
{
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
            board[i][j] = ' ';
    }
}

bool isWin(char board[3][3])
{
    for (int i = 0; i < 3; i++)
    {
        if (board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][0] != ' ')
            return (true);
    }

    for (int i = 0; i < 3; i++)
    {
        if (board[0][i] == board[1][i] && board[1][i] == board[2][i] && board[0][i] != ' ')
            return (true);
    }

    if (board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[0][0] != ' ')
        return (true);

    if (board[0][2] == board[1][1] && board[1][1] == board[2][0] && board[0][2] != ' ')
        return (true);

    return (false);
}

bool gameOver(char board[3][3])
{
    return isWin(board);
}

int minimax(char board[3][3], int depth, bool isAI)
{
    int score = 0;
    int bestScore = 0;
    if (gameOver(board) == true)
    {
        if (isAI == true)
            return -1;
        if (isAI == false)
            return +1;
    }
    else
    {
        if (depth < 9)
        {
            if (isAI == true)
            {
                bestScore = -9999;
                for (int i = 0; i < 3; i++)
                {
                    for (int j = 0; j < 3; j++)
                    {
                        if (board[i][j] == ' ')
                        {
                            board[i][j] = 'O';
                            score = minimax(board, depth + 1, false);
                            board[i][j] = ' ';
                            if (score > bestScore)
                            {
                                bestScore = score;
                            }
                        }
                    }
                }
                return bestScore;
            }
            else
            {
                bestScore = 9999;
                for (int i = 0; i < 3; i++)
                {
                    for (int j = 0; j < 3; j++)
                    {
                        if (board[i][j] == ' ')
                        {
                            board[i][j] = 'X';
                            score = minimax(board, depth + 1, true);
                            board[i][j] = ' ';
                            if (score < bestScore)
                            {
                                bestScore = score;
                            }
                        }
                    }
                }
                return bestScore;
            }
        }
        else
        {
            return 0;
        }
    }
}

int bestMove(char board[3][3], int moveIndex)
{
    int x = -1, y = -1;
    int score = 0, bestScore = -9999;
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (board[i][j] == ' ')
            {
                board[i][j] = 'O';
                score = minimax(board, moveIndex + 1, false);
                board[i][j] = ' ';
                if (score > bestScore)
                {
                    bestScore = score;
                    x = i;
                    y = j;
                }
            }
        }
    }
    return x * 3 + y;
}

void playTicTacToe(int whoseTurn)
{
    char board[3][3];
    int moveIndex = 0, x = 0, y = 0;

    initialise(board);

    while (!gameOver(board) && moveIndex != 9)
    {
        int n;
        if (whoseTurn == COMPUTER)
        {
            n = bestMove(board, moveIndex);
            x = n / 3;
            y = n % 3;
            board[x][y] = 'O';
            cout << "COMPUTER has put a " << 'O' << " in cell " << n + 1 << "\n\n";
            showBoard(board);
            moveIndex++;
            whoseTurn = HUMAN;
        }

        else if (whoseTurn == HUMAN)
        {
            cout << "\n\nEnter the position = ";
            cin >> n;
            n--;
            x = n / 3;
            y = n % 3;
            if (board[x][y] == ' ' && n < 9 && n >= 0)
            {
                board[x][y] = 'X';
                showBoard(board);
                moveIndex++;
                whoseTurn = COMPUTER;
            }
            else if (board[x][y] != ' ' && n < 9 && n >= 0)
            {
                cout << "\nPosition is occupied, select any one place from the available places\n\n";
            }
            else if (n < 0 || n > 8)
            {
                cout << "Invalid position\n";
            }
        }
    }
    if (gameOver(board) == false && moveIndex == 9)
    {
        cout << "It's a draw\n";
    }
    else
    {
        if (whoseTurn == COMPUTER)
        {
            cout << "YOU WON" << endl;
        }
        else if (whoseTurn == HUMAN)
        {
            cout << "COMPUTER WON" << endl;
        }
    }
}

int main()
{
    cout << "\n-------------------------------------------------------------------\n\n";
    cout << "\t\t\t Tic-Tac-Toe\n";
    cout << "\n-------------------------------------------------------------------\n\n";
    showStartingBoard();
    char conti = 'y';
    do
    {
        char choice;
        cout << "Do you want to start first?(y/n) : ";
        cin >> choice;

        if (choice == 'n')
        {
            playTicTacToe(COMPUTER);
        }
        else if (choice == 'y')
        {
            playTicTacToe(HUMAN);
        }
        else
        {
            cout << "Invalid choice\n";
        }

        cout << "\nDo you want to quit(y/n) : ";
        cin >> conti;

    } while (conti == 'n');

    return (0);
}#include <bits/stdc++.h>
using namespace std;

#define COMPUTER 1
#define HUMAN 2

void showBoard(char board[3][3])
{

    cout << board[0][0] << " | " << board[0][1] << " | " << board[0][2] << endl;
    cout << "-----------\n";
    cout << board[1][0] << " | " << board[1][1] << " | " << board[1][2] << endl;
    cout << "-----------\n";
    cout << board[2][0] << " | " << board[2][1] << " | " << board[2][2] << endl;
}

void showStartingBoard()
{
    cout << " 1 | 2 | 3 \n";
    cout << "-----------\n";
    cout << " 4 | 5 | 6 \n";
    cout << "-----------\n";
    cout << " 7 | 8 | 9 \n";
}

void initialise(char board[][3])
{
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
            board[i][j] = ' ';
    }
}

bool isWin(char board[3][3])
{
    for (int i = 0; i < 3; i++)
    {
        if (board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][0] != ' ')
            return (true);
    }

    for (int i = 0; i < 3; i++)
    {
        if (board[0][i] == board[1][i] && board[1][i] == board[2][i] && board[0][i] != ' ')
            return (true);
    }

    if (board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[0][0] != ' ')
        return (true);

    if (board[0][2] == board[1][1] && board[1][1] == board[2][0] && board[0][2] != ' ')
        return (true);

    return (false);
}

bool gameOver(char board[3][3])
{
    return isWin(board);
}

int minimax(char board[3][3], int depth, bool isAI)
{
    int score = 0;
    int bestScore = 0;
    if (gameOver(board) == true)
    {
        if (isAI == true)
            return -1;
        if (isAI == false)
            return +1;
    }
    else
    {
        if (depth < 9)
        {
            if (isAI == true)
            {
                bestScore = -9999;
                for (int i = 0; i < 3; i++)
                {
                    for (int j = 0; j < 3; j++)
                    {
                        if (board[i][j] == ' ')
                        {
                            board[i][j] = 'O';
                            score = minimax(board, depth + 1, false);
                            board[i][j] = ' ';
                            if (score > bestScore)
                            {
                                bestScore = score;
                            }
                        }
                    }
                }
                return bestScore;
            }
            else
            {
                bestScore = 9999;
                for (int i = 0; i < 3; i++)
                {
                    for (int j = 0; j < 3; j++)
                    {
                        if (board[i][j] == ' ')
                        {
                            board[i][j] = 'X';
                            score = minimax(board, depth + 1, true);
                            board[i][j] = ' ';
                            if (score < bestScore)
                            {
                                bestScore = score;
                            }
                        }
                    }
                }
                return bestScore;
            }
        }
        else
        {
            return 0;
        }
    }
}

int bestMove(char board[3][3], int moveIndex)
{
    int x = -1, y = -1;
    int score = 0, bestScore = -9999;
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (board[i][j] == ' ')
            {
                board[i][j] = 'O';
                score = minimax(board, moveIndex + 1, false);
                board[i][j] = ' ';
                if (score > bestScore)
                {
                    bestScore = score;
                    x = i;
                    y = j;
                }
            }
        }
    }
    return x * 3 + y;
}

void playTicTacToe(int whoseTurn)
{
    char board[3][3];
    int moveIndex = 0, x = 0, y = 0;

    initialise(board);

    while (!gameOver(board) && moveIndex != 9)
    {
        int n;
        if (whoseTurn == COMPUTER)
        {
            n = bestMove(board, moveIndex);
            x = n / 3;
            y = n % 3;
            board[x][y] = 'O';
            cout << "COMPUTER has put a " << 'O' << " in cell " << n + 1 << "\n\n";
            showBoard(board);
            moveIndex++;
            whoseTurn = HUMAN;
        }

        else if (whoseTurn == HUMAN)
        {
            cout << "\n\nEnter the position = ";
            cin >> n;
            n--;
            x = n / 3;
            y = n % 3;
            if (board[x][y] == ' ' && n < 9 && n >= 0)
            {
                board[x][y] = 'X';
                showBoard(board);
                moveIndex++;
                whoseTurn = COMPUTER;
            }
            else if (board[x][y] != ' ' && n < 9 && n >= 0)
            {
                cout << "\nPosition is occupied, select any one place from the available places\n\n";
            }
            else if (n < 0 || n > 8)
            {
                cout << "Invalid position\n";
            }
        }
    }
    if (gameOver(board) == false && moveIndex == 9)
    {
        cout << "It's a draw\n";
    }
    else
    {
        if (whoseTurn == COMPUTER)
        {
            cout << "YOU WON" << endl;
        }
        else if (whoseTurn == HUMAN)
        {
            cout << "COMPUTER WON" << endl;
        }
    }
}

int main()
{
    cout << "\n-------------------------------------------------------------------\n\n";
    cout << "\t\t\t Tic-Tac-Toe\n";
    cout << "\n-------------------------------------------------------------------\n\n";
    showStartingBoard();
    char conti = 'y';
    do
    {
        char choice;
        cout << "Do you want to start first?(y/n) : ";
        cin >> choice;

        if (choice == 'n')
        {
            playTicTacToe(COMPUTER);
        }
        else if (choice == 'y')
        {
            playTicTacToe(HUMAN);
        }
        else
        {
            cout << "Invalid choice\n";
        }

        cout << "\nDo you want to quit(y/n) : ";
        cin >> conti;

    } while (conti == 'n');

    return (0);
}
