#include<iostream>
#include<list>
#include<iterator>
#include<queue>
#include<stack>

using namespace std;

void add_edge(list<int> adj_list[],int ep1, int ep2){
    adj_list[ep1].push_back(ep2);
    adj_list[ep2].push_back(ep1);
}

void beam_const(list<int> adj_list[],int si, int size_q, int visited[]){
    queue<int> q;
    q.push(si);
    visited[si] = 1;

    while(!q.empty()){
        int temp;
        temp = q.front();
        q.pop();
        cout<<temp<<" ";
        list<int> :: iterator it;
        for(it = adj_list[temp].begin();it != adj_list[temp].end(); ++it){
            if(visited[*it] == 0 && q.size() < size_q ){
                q.push(*it);
                visited[*it] = 1;
            }
        }
    }
    cout<<endl;
}

void beam_disperse(list<int> adj_list[],int si, int c_size, int visited[]){
    queue<int> q;
    q.push(si);
    visited[si] = 1;
    while(!q.empty()){
        int temp;
        temp = q.front();
        q.pop();
        cout<<temp<<" ";
        list<int> :: iterator it;
        int count_c = 0;
        for(it = adj_list[temp].begin();it != adj_list[temp].end(); ++it){
            if(visited[*it] == 0 && count_c < c_size ){
                q.push(*it);
                visited[*it] = 1;
                count_c += 1;
            }
        }
    }
    cout<<endl;
}

int main(){

    int num,si;
    cout<<"Enter the starting index"<<endl;
    cin>>si;
    for(int k=1;k<=5;k++){
        vector<vector<int>> graph_1 ={{0, 1, 1, 0, 0, 1, 0, 0, 0, 0},
                                {1, 0, 1, 1, 0, 0, 0, 0, 0, 0},
                                {1, 1, 0, 0, 1, 0, 0, 1, 0, 0},
                                {0, 1, 0, 0, 1, 0, 1, 0, 1, 0},
                                {0, 0, 1, 1, 0, 1, 1, 0, 0, 0},
                                {1, 0, 0, 0, 1, 0, 0, 0, 0, 1},
                                {0, 0, 0, 1, 1, 0, 0, 1, 0, 0},
                                {0, 0, 1, 0, 0, 0, 1, 0, 0, 0},
                                {0, 0, 0, 1, 0, 0, 0, 0, 0, 1},
                                {0, 0, 0, 0, 0, 1, 0, 0, 1, 0}};
    list<int> adj_list_1[10];

    for(int i=0;i<10;i++){
        for(int j=0;j<10;j++){
            if(graph_1[i][j] == 1){
                adj_list_1[i].push_back(j);
            }
        }
    }
    int visited_1[10];
    for(int i=0;i<10;i++){
        visited_1[i] = 0;
    }
    cout<<"The width size is : "<<k<<endl;
    //beam_const(adj_list_1,si,k,visited_1);
    beam_disperse(adj_list_1,si,k,visited_1);
    }

return  0;
}
