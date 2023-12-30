// BELLMAN FORD ALGORITHM

#include<bits/stdc++.h>
using namespace std;

vector<int> bellmanFordAlgo(vector< vector< pair<int,int> > > graph){
    vector<int> dist(graph.size(),INT_MAX);
    dist[0] = 0;
    int u, v, wt;
    for(int i = 0; i < graph.size()-1; i++){
        for(int j = 0; j < graph.size(); j++){
            for(int k = 0; k < graph[j].size(); k++){
                u = j;
                v = graph[j][k].first;
                wt = graph[j][k].second;
                if(dist[u] != INT_MAX and dist[u] + wt < dist[v]){
                    dist[v] = dist[u] + wt;
                }
            }
        }
    }
    return dist;
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
    }

    for(int i = 0; i < graph.size(); i++){
        cout << i << " -> ";
        for(int j = 0; j < graph[i].size(); j++){
            cout << "(" << graph[i][j].first << "," << graph[i][j].second << ") ";
        }
        cout << "\n";
    }

    vector<int> shortestArr = bellmanFordAlgo(graph);
    for(int i = 0; i < shortestArr.size(); i++){
        cout << shortestArr[i] << " ";
    }

    return 0;
}