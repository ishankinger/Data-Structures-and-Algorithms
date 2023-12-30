// FIND EVENTUAL STATE USING BFS

#include<bits/stdc++.h>
using namespace std;

int numOfSafeNodes(vector< vector<int> > graph){
    vector< vector<int> > graph_transpose(graph.size(),vector<int>());
    for(int i = 0; i < graph.size(); i++){
        for(int j = 0; j < graph[i].size(); j++){
            graph_transpose[graph[i][j]].push_back(i);
        }
    }
    vector<int> indegree(graph.size(),0);
    for(int i = 0; i < graph_transpose.size(); i++){
        for(int j = 0; j < graph_transpose[i].size(); j++){
            indegree[graph_transpose[i][j]]++;
        }
    }
    queue<int> q;
    for(int i = 0; i < indegree.size(); i++){
        if(indegree[i] == 0) q.push(i);
    }
    vector<int> topo;
    while(not q.empty()){
        int ele = q.front();
        q.pop();
        topo.push_back(ele);
        for(int i = 0; i < graph_transpose[ele].size(); i++){
            indegree[graph_transpose[ele][i]]--;
            if(indegree[graph_transpose[ele][i]] == 0)
                q.push(graph_transpose[ele][i]);
        }
    }
    return topo.size();
}

int main(){
    int v;
    cin >> v;
    vector< vector<int> > graph(v,vector<int>());
    int e;
    cin >> e;
    while(e--){
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
    }

    for(int i = 0; i < graph.size(); i++){
        cout << i << " -> ";
        for(int j = 0; j < graph[i].size(); j++){
            cout<<graph[i][j]<<" ";
        }
        cout<<"\n";
    }

    cout<<numOfSafeNodes(graph);
    return 0;
}