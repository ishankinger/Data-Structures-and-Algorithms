// SHORTEST PATH IN AN UNDIRECTED GRAPH USING BFS
// APPLY SIMPLE BFS AND MAINTAIN A DISTANCE ARRAY WHICH WILL BE UPDATING WHILE TRAVERSING THROUGH NEIGHBOURS OF THE GIVEN NODE

#include<bits/stdc++.h>
using namespace std;

vector<int> shortestDistArr(vector< vector<int> > graph){
    
    vector<int> dist(graph.size(),0);
    vector<int> visited(graph.size(),0);
    queue<int> q;

    q.push(0);
    dist[0] = 0;
    visited[0] = 1;
    
    while(not q.empty()){
        int ele = q.front();
        q.pop();
        for(auto neighbour : graph[ele]){
            if(not visited[neighbour]){
                dist[neighbour] = dist[ele] + 1;
                visited[neighbour] = 1;
                q.push(neighbour);
            }
        }
    }
    return dist;
}

int main(){
    int v;
    cin >> v;
    vector< vector<int> > graph(v,vector<int>());
    int e;
    cin >> e;
    while(e--){
        int u,v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    vector<int> dist = shortestDistArr(graph);
    for(int i = 0; i < dist.size(); i++){
        cout << dist[i] << " ";
    }

    return 0;
}
