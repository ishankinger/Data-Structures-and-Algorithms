// DETECTING A CYCLE IN AN UNDIRECTED GRAPH USING DFS
// THE SAME CONCEPT USED AS THAT OF IN BFS ONLY DIFFERENCE IS IN RECURSION

#include<bits/stdc++.h>
using namespace std;

bool dfs(vector<list<int>> graph, vector<int> &visited, int src, int parent){
    visited[src] = 1;
    // similar concept used in dfs code also
    for(auto neighbour : graph[src]){
        if(neighbour != parent){
            if(visited[neighbour]){
                return true;
            }
            else{
                visited[neighbour] = 1;
                if(dfs(graph,visited,neighbour,src)) return true;
            }
        }
    }
    return false;
}

bool isCycle(vector<list<int>> graph){
    vector<int> visited(graph.size(),0);
    // traversing in all the elements to check all the disconnected components
    for(int ele = 0; ele < graph.size(); ele++){
        if(not visited[ele]){
            visited[ele] = 1;
            bool check = dfs(graph,visited,ele,-1);
            if(check){
                return true;
            }
        }
    }
    return false;
}

int main(){
    vector<list<int>> graph;
    int v;
    cin >> v;
    graph.resize(v,list<int>());
    int e;
    cin >> e;
    while(e--){
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    for(int ele = 0; ele < graph.size(); ele++){
        cout << ele << " -> ";
        for(auto neighbour : graph[ele]){
            cout << neighbour << " ";
        }
        cout << "\n";
    }

    if(isCycle(graph)) cout << "Cycle is Present\n";
    else cout << "Cycle is not Present\n";

    return 0;
}
