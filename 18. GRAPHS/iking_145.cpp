// KRUSKAL'S ALGORITHM
// ANOTHER ALGORITHM TO GET THE MINIMUM SPANNING TREE USING DISJOINT SET DATASTRUCTURE

#include<bits/stdc++.h>
using namespace std;

// function of disjoint sets are used
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


// function to get minimum spanning tree using kruskal's algorithm
int spanningTree(vector< vector< pair<int,int> > > graph){
    
    // convert our adjacency list to edges
    vector< pair< int,pair<int,int> > > edges;
    for(int i = 0; i < graph.size(); i++){
        for(int j = 0; j < graph[i].size(); j++){
            edges.push_back({graph[i][j].second,{i,graph[i][j].first}});
        }
    }

    // then sort the edges according to the weights
    sort(edges.begin(),edges.end());

    // sum and mst list to store information of minimum spanning tree
    int sum = 0;
    vector< pair<int,int> > mstList;

    // parent and rank vectors defined
    vector<int> parent, rank;

    // initialise parent and rank
    for(int i = 0; i <= graph.size(); i++){
        parent.push_back(i);
        rank.push_back(0);
    }

    // treaverse through all the edges
    for(int i = 0; i < edges.size(); i++){
        // extract the data of the edge
        int u = edges[i].second.first;
        int v = edges[i].second.second;
        int wt = edges[i].first;
        // if the nodes are in different graph then union them and store the edge in our anser
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