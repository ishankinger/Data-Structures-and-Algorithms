// CHEAPEST FLIGH WITH ATMOST K STOPS

#include<bits/stdc++.h>
using namespace std;

int cheapestFlight(vector< vector< pair<int,int> > > graph, int src, int dest, int k){
    queue< pair< int,pair<int,int> > > q;
    vector<int> dist(graph.size(),INT_MAX);
    q.push({0,{src,0}});
    dist[src] = 0;
    while(not q.empty()){
        int node =  q.front().second.first;
        int len = q.front().second.second;
        int stop = q.front().first;
        q.pop();
        if(stop > k) continue;
        for(auto neighbour : graph[node]){
            if(neighbour.second + len < dist[neighbour.first] and stop <=k){
                dist[neighbour.first] = neighbour.second + len;
                q.push({stop+1,{neighbour.first,dist[neighbour.first]}});
            }
        }
    }
    if(dist[dest] == INT_MAX) return -1;
    else return dist[dest];
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
    int src, dest, k;
    cin >> src >> dest >> k;

    for(int i = 0; i < graph.size(); i++){
        cout << i << " -> ";
        for(int j = 0; j < graph[i].size(); j++){
            cout << "(" << graph[i][j].first << "," << graph[i][j].second << ") ";
        }
        cout << "\n";
    }

    cout << cheapestFlight(graph,src,dest,k);

    return 0;
}