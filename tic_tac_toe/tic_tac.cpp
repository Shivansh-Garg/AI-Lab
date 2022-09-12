#include<iostream>
#include<vector>
using namespace std;
void display(int board[]){
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
}
int check_win(int num, int board[]){
    vector<vector<int>> moves = {{-1,-1,-1},
                                  {1,2,3},
                                  {4,5,6},
                                  {7,8,9},
                                  {1,4,7},
                                  {2,5,8},
                                  {3,6,9},
                                  {1,5,9},
                                  {3,5,7}};
    for(auto it = moves.begin()+1;it<moves.end();it++){
        if(board[(*it)[0]]*board[(*it)[1]]*board[(*it)[2]] == num*num*num){
            return 1;
        }
    }
    return -1;
}

int poswin_2(int num, int board[]){
    vector<vector<int>> moves = { {-1,-1,-1},
                                  {1,2,3},
                                  {4,5,6},
                                  {7,8,9},
                                  {1,4,7},
                                  {2,5,8},
                                  {3,6,9},
                                  {1,5,9},
                                  {3,5,7}};
    for(auto it = moves.begin()+1;it<moves.end();it++){
        if(board[(*it)[0]]*board[(*it)[1]]*board[(*it)[2]] == num*num*2){
            for(int i=0;i<3;i++){
                if(board[(*it)[i]] == 2){
                    return (*it)[i];
                }
            }
        }
        return 0;
    }
}
int poswin(int num, int board[]){
	if(board[1]*board[2]*board[3] == num*num*2){
		int temp = -1;
		for(int i=1;i<=3;i++){
			if(board[i] == 2){
				temp = i;
				return temp;
			}
		}
	}
	if(board[4]*board[5]*board[6] == num*num*2){
		int temp = -1;
		for(int i=4;i<=6;i++){
			if(board[i] == 2){
				temp = i;
				return temp;
			}
		}
	}
	if(board[7]*board[8]*board[9] == num*num*2){
		int temp = -1;
		for(int i=7;i<=9;i++){
			if(board[i] == 2){
				temp = i;
				return temp;
			}
		}
	}
	if(board[4]*board[1]*board[7] == num*num*2){
		if(board[1] == 2){
			return 1;
		}
		if(board[4] == 2){
			return 4;
		}
		if(board[7] == 2){
			return 7;
		}
	}
	if(board[5]*board[2]*board[8] == num*num*2){
		if(board[2] == 2){
			return 2;
		}
		if(board[5] == 2){
			return 5;
		}
		if(board[8] == 2){
			return 8;
		}
	}
	if(board[6]*board[3]*board[9] == num*num*2){
		if(board[3] == 2){
			return 3;
		}
		if(board[6] == 2){
			return 6;
		}
		if(board[9] == 2){
			return 9;
		}
	}
	if(board[5]*board[1]*board[9] == num*num*2){
		if(board[1] == 2){
			return 1;
		}
		if(board[5] == 2){
			return 5;
		}
		if(board[9] == 2){
			return 9;
		}
	}
	if(board[5]*board[3]*board[7] == num*num*2){
		if(board[3] == 2){
			return 3;
		}
		if(board[5] == 2){
			return 5;
		}
		if(board[7] == 2){
			return 7;
		}
	}
	return 0;
}

int make2(int board[] ){
	if(board[5] == 2){
		return 5;
	}else if(board[2] == 2){
		return 2;
	}else if(board[4] == 2){
		return 4;
	}else if(board[6] == 2){
		return 6;
	}else if(board[8] == 2){
		return 8;
	}
	return 0;
}

void go(int box, int board[], int &turn){
	if(turn%2 == 0){
		board[box] = 5;
	}else{
		board[box] = 3;
	}
	turn = turn+1;
}

int main(){
	cout<<"Enter 1 to choose X and 2 to choose O"<<endl;
	int sturn;
	int user = -1;
	cin>>sturn;
	int board[10];
	int turn = 1;
	for(int i=1;i<=9;i++){
		board[i] = 2;
	}
	if(sturn == 2){
		go(1,board,turn);
		display(board);
		cout<<"Your turn, Enter the valid position where you want to put O "<<endl;
		cin>>user;
		go(user,board,turn);
		if(board[9] == 2){
			go(9,board,turn);
		}else{
			go(3,board,turn);
		}
		display(board);
		cout<<"Your turn, Enter the valid position where you want to put O "<<endl;
		cin>>user;
		go(user,board,turn);
		if(poswin(3, board) != 0){
			go(poswin(3,board),board,turn);
			cout<<"Computer won !!!!!!!"<<endl;
			display(board);
			return 0;
		}else if(poswin(5, board) != 0){
			go(poswin(5, board),board,turn);
		}else if(board[7] == 2){
			go(7,board,turn);
		}else{
			go(3,board,turn);
		}
		display(board);
		cout<<"Your turn, Enter the valid position where you want to put O "<<endl;
		cin>>user;
		go(user,board,turn);
		if(poswin(3, board) != 0){
			go(poswin(3, board),board,turn);
			display(board);
			cout<<"Computer won !!!!!!!"<<endl;
			return 0;
		}else if(poswin(5,board) != 0){
			go(poswin(5, board),board,turn);
		}else{
			go(make2(board),board,turn);
		}
		display(board);
		cout<<"Your turn, Enter the valid position where you want to put O "<<endl;
		cin>>user;
		go(user,board,turn);
		if(poswin(3, board) != 0){
			go(poswin(3, board),board,turn);
			cout<<"Computer won !!!!!!!"<<endl;
		}else if(poswin(5,board) != 0){
			go(poswin(5,board),board,turn);
		}else{
			go(make2(board),board,turn);
		}
		display(board);
	}
	if(sturn == 1){
        display(board);
		cout<<"Your turn, Enter the valid position where you want to put X "<<endl;
		cin>>user;
		go(user,board,turn);
		if(board[5] == 2){
			go(5,board,turn);
		}else{
			go(1,board,turn);
		}
		display(board);
		cout<<"Your turn, Enter the valid position where you want to put X "<<endl;
		cin>>user;
		go(user,board,turn);
		if(poswin(3,board) != 0){
			go(poswin(3,board),board,turn);
		}else{
			go(make2(board),board,turn);
		}
		display(board);
		cout<<"Your turn, Enter the valid position where you want to put X "<<endl;
		cin>>user;
		go(user,board,turn);
		if(poswin(5,board) != 0){
			go(poswin(5,board),board,turn);
			display(board);
			cout<<"Computer won !!!!!!!"<<endl;
			return 0;
		}else if(poswin(3,board) != 0){
			go(poswin(3,board),board,turn);
		}else{
			go(make2(board),board,turn);
		}
		display(board);
		cout<<"Your turn, Enter the valid position where you want to put O "<<endl;
		cin>>user;
		go(user,board,turn);
		if(check_win(3,board)){
            cout<<"user wins"<<endl;
            display(board);
            return 0;
		}
		if(poswin(5,board) != 0){
			go(poswin(5,board),board,turn);
			display(board);
			cout<<"Computer won !!!!!!!"<<endl;
			return 0;
		}else if(poswin(3,board) != 0){
			go(poswin(3,board),board,turn);
		}else{
			go(make2(board),board,turn);
		}
		display(board);
		cout<<"Your turn, Enter the valid position where you want to put O "<<endl;
		cin>>user;
		go(user,board,turn);
		if(check_win(3,board)){
            cout<<"user wins"<<endl;
            display(board);
            return 0;
		}
		display(board);
	}

	return 0;
}
