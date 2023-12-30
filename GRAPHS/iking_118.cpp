// DETECT A CYCLE IN A DIRECTED GRAPH USING DFS 

#include<bits/stdc++.h>
using namespace std;

bool dfs(int src, vector< list<int> > graph, vector<int> &vis, vector<int> &path_vis){
    vis[src] = 1;
    path_vis[src] = 1;
    for(auto neighbour : graph[src]){
        if(not vis[neighbour]){
            if(dfs(neighbour,graph,vis,path_vis)){
                return true;
            }
            else{
                path_vis[neighbour] = 0;
            }
        }
        else{
            if(path_vis[neighbour]){
                return true;
            }
        }
    }
    return false;
}

bool isCycle(vector< list<int> > graph){
    vector<int> vis(graph.size(),0);
    vector<int> path_vis(graph.size(),0);
    for(int i = 0; i < graph.size(); i++){
        if(not vis[i]){
            bool check = dfs(i,graph,vis,path_vis);
            if(check) return true;
        }
    }
    return false;
}

int main(){
    vector< list<int> > graph;
    int v;
    cin >> v;
    graph.resize(v,list<int>());
    int e;
    cin >> e;
    while(e--){
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
    }

    for(int ele = 0; ele < graph.size(); ele++){
        cout << ele << " -> ";
        for(auto neighbour : graph[ele]){
            cout << neighbour << " ";
        }
        cout << "\n";
    }

    if(isCycle(graph)){
        cout<<"The graph has a cycle\n";
    }
    else{
        cout<<"The graph doesnot have a cycle\n";
    }

    return 0;
}