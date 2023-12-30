// KRUSKAL'S ALGORITHM

#include<bits/stdc++.h>
using namespace std;

int findUParent(int node,vector<int> &rank, vector<int> &parent){
    if(node == parent[node]){
        return node;
    }
    return parent[node] = findUParent(parent[node],rank,parent);
}

int unionByRank(int u, int v,vector<int> &rank, vector<int> &parent){
    int ulp_u = findUParent(u,rank,parent);
    int ulp_v = findUParent(v,rank,parent);
    if(ulp_u == ulp_v) return 0;
    if(rank[ulp_v] < rank[ulp_v]){
        parent[ulp_u] = ulp_v;
    }
    else if(rank[ulp_u] < rank[ulp_v]){
        parent[ulp_v] = ulp_u;
    }
    else{
        parent[ulp_v] = ulp_u;
        rank[ulp_u]++;
    }
    return 1;
}


int spanningTree(vector< vector< pair<int,int> > > graph){
    vector< pair< int,pair<int,int> > > edges;
    for(int i = 0; i < graph.size(); i++){
        for(int j = 0; j < graph[i].size(); j++){
            edges.push_back({graph[i][j].second,{i,graph[i][j].first}});
        }
    }
    sort(edges.begin(),edges.end());
    int sum = 0;
    vector< pair<int,int> > mstList;
    vector<int> parent, rank;
    for(int i = 0; i <= graph.size(); i++){
        parent.push_back(i);
        rank.push_back(0);
    }
    for(int i = 0; i < edges.size(); i++){
        int u = edges[i].second.first;
        int v = edges[i].second.second;
        int wt = edges[i].first;
        if(unionByRank(u,v,rank,parent)){
            mstList.push_back({u,v});
            sum += wt;
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

    cout << spanningTree(graph);

    return 0;
}