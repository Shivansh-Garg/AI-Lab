#include<bits/stdc++.h>
#include<chrono>
using namespace std::chrono;
using namespace std;

int m;
int n;
int count_ans = 0;


void display(vector<vector<int>> board){
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            if(board[i][j] == 3){
                cout<<"K ";
            }
            else{
                cout<<". ";
            }
        }
        cout<<endl;
    }
}

bool can_place(vector<vector<int>> board, int ci, int cj){
    if(board[ci][cj] == 3 || board[ci][cj] == 1){
        return false;
    }
    return true;
}

int count_empty(vector<vector<int>> board){
    int empty_space = 0;
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            if(board[i][j] == 1){
                empty_space += 1;
            }
        }
    }
    //cout<<"empty_space : "<<empty_space<<endl;
    return empty_space;
}

vector<vector<int>> place_board(vector<vector<int>> board, int ci, int cj){
    board[ci][cj] = 3;
    if(ci-2 >=0 && cj-1 >=0){
        board[ci-2][cj-1] = 1; // 1 is for placed knight and 3 is for attacked position.
    }
    if(ci-1 >=0 && cj-2 >=0){
        board[ci-1][cj-2] = 1;
    }
    if(ci+2 < m && cj-1 >=0){
        board[ci+2][cj-1] = 1;
    }
    if(ci-2 >=0 && cj+1 <n){
        board[ci-2][cj+1] = 1;
    }
    if(ci+1 < m && cj-2 >=0){
        board[ci+1][cj-2] = 1;
    }
    if(ci+1 <m && cj+2 <n){
        board[ci+1][cj+2] = 1;
    }
    if(ci-1 >=0 && cj+2 < n){
        board[ci-1][cj+2] = 1;
    }
    if(ci+2 < m && cj+1 < n){
        board[ci+2][cj+1] = 1;
    }
    return board;
}

void knight(vector<vector<int>> board, int k, int st_i, int st_j){
    if(k==0){
        display(board);
        count_ans += 1;
        cout<<endl;
        return;
    }
    else{
       // if(count_empty(board) < 2*k){
         //       cout<<"true"<<endl;
           // return ;
        //}
        for(int i=st_i;i<=m-1;i++){
            for(int j=st_j; j<=n-1;j++){
                if(can_place(board,i,j)){
                    vector<vector<int>> board_temp;
                    board_temp = place_board(board,i,j);
                    knight(board_temp,k-1,i,j);
                }
            }
            st_j = 0;
        }
    }
}
int main(){
    cout<<"Enter the size of the chess board mxn"<<endl;
    cin>>m>>n;
    int k;
    cout<<"Enter the number of knights to be placed"<<endl;
    cin>>k;
    vector<vector<int>> board(m,vector<int>(n,0));
    auto start = high_resolution_clock::now();
    knight(board,k,0,0);
    auto stop = high_resolution_clock::now();
    cout<<"The total no. of solutions are : "<<count_ans<<endl;
    auto duration= duration_cast<microseconds>(stop-start);
    cout<<"Time taken is : "<< duration.count()<<" microseconds"<<endl;
    return 0;
}
