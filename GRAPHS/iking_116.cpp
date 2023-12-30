// CHECK WHETHER A GRAPH IS BIPARTITE OR NOT USING BFS

#include<bits/stdc++.h>
using namespace std;

bool bfs(int src, vector< list<int> > graph, vector<int> &color){
    queue<int> q;
    q.push(src);
    while(not q.empty()){
        int ele = q.front();
        q.pop();
        for(auto neighbour : graph[ele]){
            if(color[neighbour] == -1){
                q.push(neighbour);
                color[neighbour] = not(color[ele]);
            }
            else{
                if(color[neighbour] == color[ele])
                    return false;
            }
        }
    }
    return true;
}

bool isBipartite(vector< list<int> > graph){
    vector<int> color(graph.size(),-1);
    for(int i = 0; i < graph.size(); i++){
        if(color[i] == -1){
            bool check = bfs(i,graph,color);
            if(not check) return false;
            cout<<"hi\n";
        }
    }
    return true;
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
        graph[v].push_back(u);
    }

    for(int ele = 0; ele < graph.size(); ele++){
        cout << ele << " -> ";
        for(auto neighbour : graph[ele]){
            cout << neighbour << " ";
        }
        cout << "\n";
    }

    if(isBipartite(graph)){
        cout << "The graph is Bipartite\n";
    }
    else{
        cout << "The graph is not Bipartite\n";
    }

    return 0;
}