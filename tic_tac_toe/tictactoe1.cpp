#include <bits/stdc++.h>
using namespace std;

class Board
{
    vector<int> board;
    int turn;

public:
    Board()
    {
        board.resize(10, 2);
        turn = 1;
    }

    int getTurn()
    {
        return turn;
    }

    int isCellEmpty(int i)
    {
        return board[i] == 2;
    }

    void clearMove(int i)
    {
        if (board[i] != 2)
        {
            board[i] = 2;
            turn--;
        }
    }

    void clearBoard()
    {
        for (int i = 1; i <= 9; i++)
        {
            board[i] = 2;
        }
        turn = 1;
    }

    int findBlank()
    {
        for (int i = 1; i <= 9; i++)
        {
            if (board[i] == 2)
            {
                return i;
            }
        }
        return 0;
    }

    int findEdge()
    {
        for (int i = 2; i <= 8; i += 2)
            if (board[i] == 3)
                return i;
        if (board[5] == 3)
            return 5;
        return 0;
    }

    int findCorner()
    {
        int corner = 0;
        for (int i = 1; i <= 9; i += 2)
            if (i != 5 && board[i] == 3)
                corner = i;
        if (!corner)
            return 0;
        int edge = findEdge();
        if (!edge)
            return 0;
        if (corner == 1 && edge == 6)
            return 3;
        if (corner == 1 && edge == 8)
            return 7;
        if (corner == 3 && edge == 4)
            return 1;
        if (corner == 3 && edge == 8)
            return 9;
        if (corner == 7 && edge == 2)
            return 1;
        if (corner == 7 && edge == 6)
            return 9;
        if (corner == 9 && edge == 2)
            return 3;
        if (corner == 9 && edge == 4)
            return 7;
        if (corner == 9 && edge == 5)
            return 3;
    }

    int findCornerEdge()
    {
        if (board[2] == 3 && board[4] == 3)
            return 1;
        if (board[2] == 3 && board[6] == 3)
            return 3;
        if (board[2] == 3 && board[8] == 3)
            return 1;
        if (board[8] == 3 && board[4] == 3)
            return 7;
        if (board[8] == 3 && board[6] == 3)
            return 9;
        if (board[4] == 3 && board[6] == 3)
            return 1;
        return 0;
    }

    void printBoard()
    {
        for (int i = 1; i <= 9; i++)
        {
            if (board[i] == 2)
                cout << ".";
            else if (board[i] == 3)
                cout << "X";
            else
                cout << "O";
            if (i % 3 == 0)
                cout << endl;
            else
                cout << "|";
        }
        cout << endl;
    }

    int make2()
    {
        if (board[5] == 2)
            return 5;
        int move = 0;
        for (int i = 2; i <= 8; i += 2)
            if (board[i] == 2)
            {
                return i;
            }
        return 0;
    }

    void go(int i)
    {
        if (i > 0 && i <= 9)
        {
            if (board[i] != 2)
            {
                cout << "Invalid move" << endl;
                return;
            }
            board[i] = turn % 2 ? 3 : 5;
            turn++;
        }
        else
        {
            cout << "Invalid move" << endl;
            return;
        }
    }

    int possWin(char player)
    {
        int move = 0;
        int pdt = player == 'X' ? 18 : 50;

        for (int i = 1; i <= 7; i += 3)
        {
            if (board[i] * board[i + 1] * board[i + 2] == pdt)
            {
                if (board[i] == 2)
                    move = i;
                else if (board[i + 1] == 2)
                    move = i + 1;
                else if (board[i + 2] == 2)
                    move = i + 2;
                return move;
            }
        }

        for (int i = 1; i <= 3; i++)
        {
            if (board[i] * board[i + 3] * board[i + 6] == pdt)
            {
                if (board[i] == 2)
                    move = i;
                else if (board[i + 3] == 2)
                    move = i + 3;
                else if (board[i + 6] == 2)
                    move = i + 6;
                return move;
            }
        }

        if (board[1] * board[5] * board[9] == pdt)
        {
            if (board[1] == 2)
                move = 1;
            else if (board[5] == 2)
                move = 5;
            else if (board[9] == 2)
                move = 9;
            return move;
        }

        if (board[3] * board[5] * board[7] == pdt)
        {
            if (board[3] == 2)
                move = 3;
            else if (board[5] == 2)
                move = 5;
            else if (board[7] == 2)
                move = 7;
            return move;
        }

        return move;
    }

    int checkWin()
    {
        for (int i = 1; i <= 7; i += 3)
            if (board[i] * board[i + 1] * board[i + 2] == 27)
                return 1;
            else if (board[i] * board[i + 1] * board[i + 2] == 125)
                return 2;

        for (int i = 1; i <= 3; i++)
            if (board[i] * board[i + 3] * board[i + 6] == 27)
                return 1;
            else if (board[i] * board[i + 3] * board[i + 6] == 125)
                return 2;

        if (board[1] * board[5] * board[9] == 27)
            return 1;
        if (board[1] * board[5] * board[9] == 125)
            return 2;

        if (board[3] * board[5] * board[7] == 27)
            return 1;
        if (board[3] * board[5] * board[7] == 125)
            return 2;

        return 0;
    }
};

class Computer
{
    int move;
    void setComputerMove(int move)
    {
        this->move = move;
    }

public:
    Computer()
    {
        move = 0;
    }

    int getComputerMove()
    {
        return move;
    }

    void makeMove(Board &board)
    {
        int move = 0;
        switch (board.getTurn())
        {
        case 1:
            board.go(1);
            setComputerMove(1);
            break;
        case 2:
            if (board.isCellEmpty(5))
            {
                board.go(5);
                setComputerMove(5);
            }
            else
            {
                board.go(1);
                setComputerMove(1);
            }
            break;
        case 3:
            if (board.isCellEmpty(9))
            {
                board.go(9);
                setComputerMove(9);
            }
            else
            {
                board.go(3);
                setComputerMove(3);
            }
            break;
        case 4:
            move = board.possWin('X');
            if (move)
            {
                board.go(move);
                setComputerMove(move);
            }
            else
            {
                move = board.make2();
                board.go(move);
                setComputerMove(move);
            }
            break;
        case 5:
            move = board.possWin('X');
            if (move)
            {
                board.go(move);
                setComputerMove(move);
                break;
            }
            move = board.possWin('O');
            if (move)
            {
                board.go(move);
                setComputerMove(move);
            }
            else if (board.isCellEmpty(7))
            {
                board.go(7);
                setComputerMove(7);
            }
            else
            {
                board.go(3);
                setComputerMove(3);
            }
            break;
        case 6:
            move = board.possWin('O');
            if (move)
            {
                board.go(move);
                setComputerMove(move);
                break;
            }
            move = board.possWin('X');
            if (move)
            {
                board.go(move);
                setComputerMove(move);
                break;
            }
            move = board.make2();
            if (move)
            {
                board.go(move);
                setComputerMove(move);
                break;
            }
            else
            {
                move = board.findBlank();
                board.go(move);
                setComputerMove(move);
            }
            break;
        case 7:
        case 9:
            move = board.possWin('X');
            if (move)
            {
                board.go(move);
                setComputerMove(move);
                break;
            }
            move = board.possWin('O');
            if (move)
            {
                board.go(move);
                setComputerMove(move);
            }
            else
            {
                move = board.findBlank();
                board.go(move);
                setComputerMove(move);
            }
            break;
        case 8:
            move = board.possWin('O');
            if (move)
            {
                board.go(move);
                setComputerMove(move);
                break;
            }
            move = board.possWin('X');
            if (move)
            {
                board.go(move);
                setComputerMove(move);
            }
            else
            {
                move = board.findBlank();
                board.go(move);
                setComputerMove(move);
            }
            break;
        default:
            break;
        }
    }
};

class ComputerModified
{
    int move;
    void setComputerMove(int move)
    {
        this->move = move;
    }

public:
    ComputerModified()
    {
        move = 0;
    }

    int getComputerMove()
    {
        return move;
    }

    void makeMove(Board &board)
    {
        int move = 0;
        switch (board.getTurn())
        {
        case 1:
            board.go(1);
            setComputerMove(1);
            break;
        case 2:
            if (board.isCellEmpty(5))
            {
                board.go(5);
                setComputerMove(5);
            }
            else
            {
                board.go(1);
                setComputerMove(1);
            }
            break;
        case 3:
            if (board.isCellEmpty(9))
            {
                board.go(9);
                setComputerMove(9);
            }
            else
            {
                board.go(3);
                setComputerMove(3);
            }
            break;
        case 4:
            move = board.possWin('X');
            if (move)
            {
                board.go(move);
                setComputerMove(move);
                break;
            }
            move = board.findCorner();
            if (move)
            {
                board.go(move);
                setComputerMove(move);
                break;
            }
            move = board.findCornerEdge();
            if (move)
            {
                board.go(move);
                setComputerMove(move);
            }
            else
            {
                move = board.make2();
                board.go(move);
                setComputerMove(move);
            }
            break;
        case 5:
            move = board.possWin('X');
            if (move)
            {
                board.go(move);
                setComputerMove(move);
                break;
            }
            move = board.possWin('O');
            if (move)
            {
                board.go(move);
                setComputerMove(move);
            }
            else if (board.isCellEmpty(7))
            {
                board.go(7);
                setComputerMove(7);
            }
            else
            {
                board.go(3);
                setComputerMove(3);
            }
            break;
        case 6:
            move = board.possWin('O');
            if (move)
            {
                board.go(move);
                setComputerMove(move);
                break;
            }
            move = board.possWin('X');
            if (move)
            {
                board.go(move);
                setComputerMove(move);
                break;
            }
            move = board.make2();
            if (move)
            {
                board.go(move);
                setComputerMove(move);
                break;
            }
            else
            {
                move = board.findBlank();
                board.go(move);
                setComputerMove(move);
            }
            break;
        case 7:
        case 9:
            move = board.possWin('X');
            if (move)
            {
                board.go(move);
                setComputerMove(move);
                break;
            }
            move = board.possWin('O');
            if (move)
            {
                board.go(move);
                setComputerMove(move);
            }
            else
            {
                move = board.findBlank();
                board.go(move);
                setComputerMove(move);
            }
            break;
        case 8:
            move = board.possWin('O');
            if (move)
            {
                board.go(move);
                setComputerMove(move);
                break;
            }
            move = board.possWin('X');
            if (move)
            {
                board.go(move);
                setComputerMove(move);
            }
            else
            {
                move = board.findBlank();
                board.go(move);
                setComputerMove(move);
            }
            break;
        default:
            break;
        }
    }
};

void printmoves(vector<int> moves)
{
    for (int i = 0; i < moves.size(); i++)
        cout << moves[i] << " ";
    cout << endl;
}

void allMoves(Board &board, Computer &computer, int turn = 1, vector<int> moves = {})
{
    int win = 0;
    for (int i = 1; i <= 9; i++)
    {
        if (board.isCellEmpty(i))
        {
            board.go(i);
            moves.push_back(i);
            win = board.checkWin();
            if (win == turn)
            {
                printmoves(moves);
                board.clearMove(i);
                moves.pop_back();
                continue;
            }
            if (board.getTurn() > 9)
            {
                board.clearMove(i);
                moves.pop_back();
                continue;
            }

            computer.makeMove(board);
            int move = computer.getComputerMove();
            moves.push_back(move);
            win = board.checkWin();
            if (win != 0)
            {
                board.clearMove(move);
                moves.pop_back();
                board.clearMove(i);
                moves.pop_back();
                continue;
            }
            allMoves(board, computer, turn, moves);
            board.clearMove(move);
            moves.pop_back();
            board.clearMove(i);
            moves.pop_back();
        }
    }
}

void allMovesModified(Board &board, ComputerModified &computer, int turn = 1, vector<int> moves = {})
{
    int win = 0;
    for (int i = 1; i <= 9; i++)
    {
        if (board.isCellEmpty(i))
        {
            board.go(i);
            moves.push_back(i);
            win = board.checkWin();
            if (win == turn)
            {
                printmoves(moves);
                board.clearMove(i);
                moves.pop_back();
                continue;
            }
            if (board.getTurn() > 9)
            {
                board.clearMove(i);
                moves.pop_back();
                continue;
            }

            computer.makeMove(board);
            int move = computer.getComputerMove();
            moves.push_back(move);
            win = board.checkWin();
            if (win != 0)
            {
                board.clearMove(move);
                moves.pop_back();
                board.clearMove(i);
                moves.pop_back();
                continue;
            }
            allMovesModified(board, computer, turn, moves);
            board.clearMove(move);
            moves.pop_back();
            board.clearMove(i);
            moves.pop_back();
        }
    }
}

int main()
{
    Board board;
    Computer computer;
    ComputerModified computerModified;
    cout << "Do you want to play first? (Y/N)" << endl;
    char choice;
    cin >> choice;
    cout << "You're playing as " << (choice == 'Y' ? 'X' : 'O') << endl;
    if (choice == 'Y')
    {
        while (board.getTurn() < 10)
        {
            if (board.getTurn() % 2 == 1)
            {
                int move;
                cout << "Enter your move: (between 1 and 9)" << endl;
                cin >> move;
                board.go(move);
            }
            else
            {
                cout << "Computer's turn: " << endl;
                computer.makeMove(board);
            }
            board.printBoard();
            int win = board.checkWin();
            if (win == 1)
            {
                cout << "You win!" << endl;
                break;
            }
            else if (win == 2)
            {
                cout << "Computer wins!" << endl;
                break;
            }
        }
    }
    else if (choice == 'N')
    {
        while (board.getTurn() < 10)
        {
            if (board.getTurn() % 2 == 0)
            {
                int move;
                cout << "Enter your move: (between 1 and 9)" << endl;
                cin >> move;
                board.go(move);
            }
            else
            {
                cout << "Computer's turn: " << endl;
                computer.makeMove(board);
            }
            board.printBoard();
            int win = board.checkWin();
            if (win == 2)
            {
                cout << "You win!" << endl;
                break;
            }
            else if (win == 1)
            {
                cout << "Computer wins!" << endl;
                break;
            }
        }
    }
    else if (choice == 'A')
    {
        allMoves(board, computer);
    }
    else if (choice == 'M')
    {
        allMovesModified(board, computerModified);
    }
    else
    {
        cout << "Invalid input" << endl;
    }
}