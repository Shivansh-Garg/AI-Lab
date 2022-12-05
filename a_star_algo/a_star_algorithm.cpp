#include <bits/stdc++.h>
using namespace std;

map<int, char> a = {{1, 'A'}, {2, 'B'}, {3, 'C'}, {4, 'D'}, {5, 'E'}, {6, 'F'}, {7, 'G'}, {8, 'H'}, {9, 'I'}, {10, 'J'}};
multimap<int, pair<int, int>> open; // first one is f_value and the second one is vertex, parent
map<int, int> parent;
vector<int> costOfVertex(11, 9999);
vector<pair<int, int>> closed; // vertx and parent

const int goal = 10;
const int start = 1;
vector<vector<int>> graph
    // 0   A   B   C   D   E   F   G   H   I   J
    {
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},    // 0
        {0, 0, 6, 3, 1, 0, 0, 0, 0, 0, 0},    // A
        {0, 6, 0, 2, 6, 3, 4, 0, 0, 0, 0},    // B
        {0, 3, 2, 0, 0, 4, 5, 0, 0, 0, 0},    // C
        {0, 1, 6, 0, 0, 7, 8, 9, 0, 0, 0},    // D
        {0, 0, 3, 4, 7, 0, 6, 9, 9, 0, 0},    // E
        {0, 0, 4, 5, 8, 6, 0, 8, 9, 0, 0},    // F
        {0, 0, 0, 0, 9, 9, 8, 0, 11, 12, 14}, // G
        {0, 0, 0, 0, 0, 9, 9, 11, 0, 14, 15}, // H
        {0, 0, 0, 0, 0, 0, 0, 12, 14, 0, 0},  // I
        {0, 0, 0, 0, 0, 1, 0, 14, 15, 0, 0},  // J
    };
vector<int> H = {9999, 15, 13, 13, 12, 10, 9, 7, 6, 5, 0};

void printCosts()
{
    for(int i =1; i<costOfVertex.size(); i++)
    {
        cout<<a[i] << " " << costOfVertex[i]<<endl;
    }
}


void printPath()
{
    vector<int> path;
    int node = goal;
    while (node != start)
    {
        path.push_back(node);
        node = parent[node];
    }
    path.push_back(start);
    cout << "The path from the start to goal is as : ";
    reverse(path.begin(), path.end());
    for (auto val : path)
    {
        if (val != goal)
            cout << a[val] << " -> ";
        else
            cout << a[val]<<endl;
    }
}
bool presentInClosed(int node)
{
    for (int i = 0; i < closed.size(); i++)
    {
        if (closed[i].first == node)
        {
            return true;
        }
    }
    return false;
}

void putSuccessors(int node, int cost)
{
    for (int i = 1; i < graph[0].size(); i++)
    {
        if (graph[node][i] != 0 && !presentInClosed(i))
        {
            open.insert({cost + graph[node][i] + H[i], {i, node}});
            // parent[i] = node;
            // cout<<"Inserted : "<< cost + graph[node][i] + H[i]<< " "<<a[i]<<endl;
        }
    }
}

bool aStar(int root_node)
{
    bool m = false;
    putSuccessors(root_node, 0);
    while (!open.empty())
    {
        auto it = open.begin();
        closed.push_back({it->second.first, it->second.second});
        open.erase(it);
        int cost = it->first - H[it->second.first];
        if (costOfVertex[it->second.first] > cost)
        {
            parent[it->second.first] = it->second.second;
            costOfVertex[it->second.first] = cost ;
        }
        else
        {
            continue;
        }
        if (it->second.first == goal)
        {
            m = true;
            cout << "Solution Found !" << endl;
            cout << "The cost is : " << it->first << endl;
            printPath();
            // return true;
        }
        putSuccessors(it->second.first, cost);
    }
    if(m == false)
        return false;
    else
        return true;
}

int main()
{
    bool found;
    found = aStar(start);
    if (found)
        printPath();
    else
        cout << "Not Found a path" << endl;
    
    // printCosts();
    return 0;
}
