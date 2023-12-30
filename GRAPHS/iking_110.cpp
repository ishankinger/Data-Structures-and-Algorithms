// DETECT A CYCLE IN AN UNDIRECTED GRAPH USING BFS

#include<bits/stdc++.h>
using namespace std;

bool bfs(vector<list<int>> graph, vector<int> &visited,int src){
    queue< pair<int,int> > q;
    q.push({src,-1});
    while(not q.empty()){
        int ele = q.front().first;
        int ele_parent = q.front().second;
        q.pop();
        for(auto neighbour : graph[ele]){
            if(neighbour != ele_parent){
                if(visited[neighbour]){
                    return true;
                }
                else{
                    visited[neighbour] = 1;
                    q.push({neighbour,ele});
                }
            }
        }
    }
    return false;
}

bool isCycle(vector<list<int>> graph){
    vector<int> visited(graph.size(),0);
    for(int ele = 0; ele < graph.size(); ele++){
        if(not visited[ele]){
            cout<<"hi\n";
            visited[ele] = 1;
            bool check = bfs(graph,visited,ele);
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