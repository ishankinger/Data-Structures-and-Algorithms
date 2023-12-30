// KAHN'S ALGORITHM ( TOPOLOGICAL SORT USING BFS )

#include<bits/stdc++.h>
using namespace std;

void topologicalSort(vector< vector<int> > graph){
    vector<int> indegree(graph.size(),0);
    for(int i = 0; i < graph.size(); i++){
        for(int j = 0; j < graph[i].size(); j++){
            indegree[graph[i][j]]++;
        }
    }
    queue<int> q;
    for(int i = 0; i < graph.size(); i++){
        if(indegree[i] == 0){
            q.push(i);
        }
    }

    while(not q.empty()){
        int ele = q.front();
        cout<<ele<<" ";
        q.pop();
        for(auto neighbour : graph[ele]){
            indegree[neighbour]--;
            if(indegree[neighbour] == 0) 
                q.push(neighbour);
        }
    }
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