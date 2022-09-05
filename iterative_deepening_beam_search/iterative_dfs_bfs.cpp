#include<iostream>
#include<bits/stdc++.h>
using namespace std;

void dfs(list<int> adj_list[], int sv, int visited[], int counter, int width){
    int temp = sv;
    int temp2 = 0;
    cout<<temp<<" ";
    if(counter == 1){
        return;
    }
    list<int> :: iterator it;

    visited[sv] = 1;
    for(it = adj_list[temp].begin();it != adj_list[temp].end(); ++it){
        if(visited[*it] == 0 && temp2 < width){
            visited[*it] = 1;
            temp2++;
            dfs(adj_list,*it,visited,counter-1,width);
        }
    }
}


int main(){
     vector<vector<int>> graph_1 ={{0, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0},
{1, 0, 0, 0, 1, 1, 1, 0, 0, 0, 0, 0, 0},
{1, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0},
{1, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0},
{0, 1, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0},
{0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0},
{0, 1, 1, 0, 0, 0, 0, 1, 0, 0, 1, 1, 0},
{0, 0, 1, 1, 0, 0, 1, 0, 0, 0, 0, 1, 0},
{0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1, 1},
{0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0},
{0, 0, 0, 0, 1, 1, 1, 0, 0, 0, 0, 1, 0},
{0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 1, 0, 0},
{0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0}};

    list<int> adj_list_1[14];

    for(int i=1;i<=13;i++){
        for(int j=1;j<=13;j++){
            if(graph_1[i-1][j-1] == 1){
                adj_list_1[i].push_back(j);
            }
        }
    }

    int visited_1[14];
    int width;
    width = 1;
    for(int i=1;i<=3;i++){
        cout<<"w = "<<i<<" and depth = 3"<<endl;
        for(int i=1;i<14;i++){
        visited_1[i] = 0;
        }
        width = i;
        dfs(adj_list_1,1,visited_1,3,width);
        cout<<endl;
        cout<<"*************"<<endl;
    }
}
