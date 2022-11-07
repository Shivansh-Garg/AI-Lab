#include<bits/stdc++.h>
using namespace std;


int main(){
    vector<vector<int>> graph = {{0,6,3,1,0,0,0,0,0,0},
                                {6,0,2,6,3,4,0,0,0,0},
                                {3,2,0,0,4,5,0,0,0,0},
                                {1,6,0,0,7,8,9,0,0,0},
                                {0,3,4,7,0,6,9,9,0,0},
                                {0,4,5,8,6,0,8,9,0,0},
                                {0,0,0,9,9,8,0,11,12,14},
                                {0,0,0,0,9,9,11,0,14,15},
                                {0,0,0,0,0,0,12,14,0,0},
                                {0,0,0,0,0,0,14,15,0,0}
                                };
    vector<int> heuristic = {15, 13 , 13, 12, 10, 9, 7, 6, 5, 0};
    vector<pair<int,int>> open_list;
    vector<int> closed_list;

    open_list.push_back(make_pair(0,15));
    int arr_check[] = {1,0,0,0,0,0,0,0,0,0};

    while(true){
        if(open_list.size() == 0){
            break;
        }
        int min_value = INT_MAX;
        int cans = -1;
        for(int i=0;i<open_list.size();i++){
            if(open_list[i].second < min_value){
                min_value = open_list[i].second;
                cans = open_list[i].first;
            }
        }
        closed_list.push_back(cans); // path is updated
        if(heuristic[cans] == 0){
            break; // goal node is found.
        }
        for(int j=0;j<10;j++){
            if(graph[cans][j] != 0){
               if(arr_check[j] == 0){
                    open_list.push_back(make_pair(j,graph[cans][j]+heuristic[j]));
                    arr_check[j] = 1;// means edge is present and node is not in either closed or open list.
               }
                else{
                    //left.
                }
            }
        }
    }
    for(int i=0;i<closed_list.size();i++){
        char temp = 97 + closed_list[i];
        cout<<temp<<"--->";
    }
    return 0;
}
