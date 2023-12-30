// PRINTING SHORTEST PATH FROM 0 TO N-1 ( SECOND METHOD )

#include<bits/stdc++.h>
using namespace std;

vector<int> minDistArr(vector< vector< pair<int,int> > > graph){
    vector<int> dist(graph.size(), INT_MAX);
    priority_queue< pair<int,int> > pq;
    vector<int> parent(graph.size());
    for(int i = 0; i < parent.size(); i++){
        parent[i] = i;
    }
    pq.push({0,0});
    dist[0] = 0;
    while(not pq.empty()){
        int node = pq.top().second;
        int len = pq.top().first;
        pq.pop();
        for(auto neighbour : graph[node]){
            if(dist[neighbour.first] > len + neighbour.second){
                dist[neighbour.first] = len + neighbour.second;
                pq.push({len + neighbour.second,neighbour.first});
                parent[neighbour.first] = node;
            }
        }
    }

    vector<int> shortestPath;
    shortestPath.push_back(graph.size()-1);
    int par = parent[graph.size()-1];
    while(par != parent[par]){
        shortestPath.push_back(par);
        par = parent[par];
    }
    shortestPath.push_back(par);
    reverse(shortestPath.begin(),shortestPath.end());
    return shortestPath;
}

int main(){
    int v;
    cin >> v;
    vector< vector< pair<int,int> > > graph(v,vector< pair<int,int> >());
    int e;
    cin >> e;
    while(e--){
        int u, v, wt;
        cin >> u >> v >> wt;
        graph[u].push_back({v,wt});
        graph[v].push_back({u,wt});
    }

    for(int i = 0; i < graph.size(); i++){
        cout << i << " -> ";
        for(int j = 0; j < graph[i].size(); j++){
            cout << "(" << graph[i][j].first << "," << graph[i][j].second << ")";
        }
        cout << "\n";
    }

    vector<int> distArr = minDistArr(graph);
    for(int i = 0; i < distArr.size(); i++){
        cout << distArr[i] << " ";
    }

    return 0;
}