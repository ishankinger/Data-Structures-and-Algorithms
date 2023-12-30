// PRINTING THE SHORTEST PATH FROM 1 TO N

#include<bits/stdc++.h>
using namespace std;

vector<int> minDistPath(vector< vector< pair<int,int> > > graph){
    vector<int> dist(graph.size(),INT_MAX);
    priority_queue< pair< int,vector<int> > > pq;
    pq.push({0,{0}});
    dist[0] = 0;
    vector<int> ans;
    int minPathLen = INT_MAX;
    while(not pq.empty()){
        vector<int> path = pq.top().second;
        vector<int> newPath;
        int node = path[path.size()-1];
        int pathLen = pq.top().first;
        pq.pop();
        if(node == graph.size()-1){
            if(pathLen < minPathLen){
                minPathLen = pathLen;
                ans = path;
            }
        }
        for(auto neighbour : graph[node]){
            if(dist[neighbour.first] > pathLen + neighbour.second){
                dist[neighbour.first] = pathLen + neighbour.second;
                newPath = path;
                newPath.push_back(neighbour.first);
                pq.push({pathLen + neighbour.second,newPath});
            }
        }
    }

    return ans;
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
            cout << "(" << graph[i][j].first << "," << graph[i][j].second << ") ";
        }
        cout << "\n";
    }

    vector<int> shortestPath = minDistPath(graph);
    for(int i = 0; i < shortestPath.size(); i++){
        cout << shortestPath[i] << " ";
    }

}