// PRIM'S ALGORITHM 

#include<bits/stdc++.h>
using namespace std;

int primsAlgo(vector< vector< pair<int,int> > > graph){
    
    priority_queue< pair< int,pair<int,int> >, 
    vector<pair< int,pair<int,int> > >,
    greater< pair< int,pair<int,int> > > > pq;
    
    vector<int> vis(graph.size(),0);
    
    vector< pair<int,int> > mstList;
    
    int sum = 0;
    
    pq.push({0,{0,-1}});
    
    while(not pq.empty()){

        int wt = pq.top().first;
        int node = pq.top().second.first;
        int parent = pq.top().second.second;
        pq.pop();

        if(vis[node]) continue;

        vis[node] = 1;

        if(parent != -1){
            mstList.push_back({parent,node});
        }

        sum += wt;

        for(auto neighbour : graph[node]){
            if(not vis[neighbour.first]){
                pq.push({neighbour.second,{neighbour.first,node}});
            }
        }
    }
    for(int i = 0; i < mstList.size(); i++){
        cout << mstList[i].first << " " << mstList[i].second << "\n";
    }
    return sum;
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

    cout << primsAlgo(graph) << "\n";

    return 0;
}