#include <bits/stdc++.h>
using namespace std;

#define COMPUTER 1
#define HUMAN 2

int player = 3, opponent = 5;
int count_times = 0;
void showBoard(int board[]){
    for(int i=1;i<=9;i++){
        if(board[i] == 2){
            cout<<"_ ";
        }
        if(board[i] == 3){
            cout<<"X ";
        }
        if(board[i] == 5){
            cout<<"O ";
        }
        if(i % 3 == 0){
            cout<<endl;
        }
    }
    cout<<endl;
}

void showStartingBoard()
{
    cout << " 1 | 2 | 3 \n";
    cout << " 4 | 5 | 6 \n";
    cout << " 7 | 8 | 9 \n";
}

void initialise(int board[10])
{
    for (int i = 1; i <=9; i++)
    {
        board[i] = 2;
    }
}

bool isWin(int board[])
{
    for (int row = 0; row<3; row++)
	{
		if (board[1+3*row]== board[2+3*row] && board[2+3*row] == board[3+3*row] && board[1+3*row] != 2)
		{
            return true;
		}
	}

	for (int col = 0; col<3; col++)
	{
		if (board[1+col]== board[4+col] && board[4+col]==board[7+col] && board[1+col] != 2)
		{
            return true;
		}
	}

	if (board[1]==board[5] && board[5]==board[9] && board[5] != 2)
	{
		return true;
	}

	if (board[3]==board[5] && board[5]==board[7] && board[5] != 2)
	{
		return true;
	}

    return (false);
}

bool gameOver(int board[])
{
    return isWin(board);
}

int minimax(int board[], int depth, bool isAI, int edepth)
{
    int score = 0;
    int bestScore = 0;
    count_times = count_times+1;
    if (gameOver(board) == true)
    {
        if (isAI == true)
            return -1;
        if (isAI == false)
            return +1;
    }
    else
    {
        if (depth < edepth)
        {
            if (isAI == true)
            {
                bestScore = -9999;
                for (int i = 1; i <=9 ; i++)
                {
                    if (board[i] == 2)
                    {
                        board[i] = 5;
                        score = minimax(board, depth + 1, false,edepth);
                        board[i] = 2;
                        if(score == 1){
                            return score;
                        }
                        if (score > bestScore)
                        {
                            bestScore = score;
                        }
                    }
                }
                return bestScore;
            }
            else
            {
                bestScore = 9999;
                for (int i = 1; i <= 9; i++)
                {
                    if (board[i] == 2)
                    {
                        board[i] = 3;
                        score = minimax(board, depth + 1, true,edepth);
                        board[i] = 2;
                        if(score == -1){
                            return score;
                        }
                        if (score < bestScore)
                        {
                            bestScore = score;
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

int bestMove(int board[], int moveIndex, int edepth)
{
    int x = -1;
    int score = 0, bestScore = -9999;
    for (int i = 1; i <= 9; i++)
    {
            if (board[i] == 2)
            {
                board[i] = 5;
                score = minimax(board, moveIndex + 1, false, edepth);
                board[i] = 2;
                if (score > bestScore)
                {
                    bestScore = score;
                    x = i;
                }
            }
    }
    return x;
}

void playTicTacToe(int whoseTurn, int edepth)
{
    int board[10];
    int moveIndex = 0;

    initialise(board);

    while (!gameOver(board) && moveIndex != 9)
    {
        int n;
        if (whoseTurn == COMPUTER)
        {
            n = bestMove(board, moveIndex,edepth);
            board[n] = 5;
            showBoard(board);
            moveIndex++;
            whoseTurn = HUMAN;
        }

        else if (whoseTurn == HUMAN)
        {
            cout << "\n\nEnter the position = ";
            cin >> n;
            n;
            if (board[n] == 2 && n <= 9 && n >= 1)
            {
                board[n] = 3;
                showBoard(board);
                moveIndex++;
                whoseTurn = COMPUTER;
            }
            else if (board[n] != 2 && n <= 9 && n >= 1)
            {
                cout << "\nPosition is occupied, select any one place from the available places\n\n";
            }
            else if (n < 1 || n > 9)
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

    cout << "\t Tic-Tac-Toe\n";
    showStartingBoard();
    char conti = 'y';
    do
    {   int edepth;
        char choice;
        cout << "Do you want to start first?(y/n) : ";
        cin >> choice;
        cout<< "Enter the depth between 1 to 9 which you want for the AI: "<<endl;
        cin>> edepth;
        if (choice == 'n')
        {
            playTicTacToe(COMPUTER,edepth);
        }
        else if (choice == 'y')
        {
            playTicTacToe(HUMAN,edepth);
        }
        else
        {
            cout << "Invalid choice\n";
        }

        cout << "\nDo you want to quit(y/n) : ";
        cout<< " number of times mini-max is called is : "<< count_times<<endl;
        cin >> conti;

    } while (conti == 'n');

    return (0);
}
