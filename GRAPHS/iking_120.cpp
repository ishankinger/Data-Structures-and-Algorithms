// TOPOLOGICAL SORT

#include<bits/stdc++.h>
using namespace std;

void dfs(int src, vector< list<int> > graph, vector<int> &vis, stack<int> &st){
    vis[src] = 1;
    for(auto neighbour : graph[src]){
        if(not vis[neighbour]){
            dfs(neighbour,graph,vis,st);
        }
    }
    st.push(src);
    return;
}

void topologicalSort(vector< list<int> > graph){
    stack<int> st;
    vector<int> vis(graph.size(),0);
    for(int i = 0; i < graph.size(); i++){
        if(not vis[i]){
            dfs(i,graph,vis,st);
            cout<<"hi\n";
        }
    }
    while(not st.empty()){
        cout<<st.top()<<" ";
        st.pop();
    }
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
    topologicalSort(graph);
    return 0;
}

