// ?????????????? FIND EVENTUAL SAFE NODES

#include<bits/stdc++.h>
using namespace std;

bool dfs(int src, vector< list<int> > graph, vector<int> &vis,
         vector<int> &path_vis, vector<int> &safe){
    vis[src] = 1;
    path_vis[src] = 1;
    safe[src] = 0;
    for(auto neighbour : graph[src]){
        if(not vis[neighbour]){
            if(dfs(neighbour,graph,vis,path_vis,safe)){
                safe[src] = 0;
                return true;
            }
        }
        else if(path_vis[neighbour]){
            safe[src] = 0;
            return true;
        }
    }
    path_vis[src] = 0;
    safe[src] = 1;
    return false;
}

vector<int> safeNodes(vector< list<int> > graph){
    vector<int> safe(graph.size(),0);
    vector<int> vis(graph.size(),0);
    vector<int> path_vis(graph.size(),0);
    for(int i = 0; i < graph.size(); i++){
        if(not vis[i]){
            dfs(i,graph,vis,path_vis,safe);
        }
    }
    vector<int> ans;
    for(int i = 0; i < safe.size(); i++){
        if(safe[i]) ans.push_back(i);
    }
    return ans;
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

    vector<int> ans = safeNodes(graph);
    for(int i = 0; i < ans.size(); i++){
        cout<<ans[i]<<" ";
    }
}