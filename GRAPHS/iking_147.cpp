// NUMBER OF OPERATIONS TO MAKE NETWORK CONNECTED
// OPERATION - REMOVE AN EDGE FROM ANY TWO VERTICES AND ATTACH TO ANTOHER VERTICES 
// MINIMUM OPERATIONS TO MAKE THE GRAPH CONNECTED

#include<bits/stdc++.h>
using namespace std;

class DisjointSet{
        vector<int> rank,parent,size;
    public:
        DisjointSet(int n){
            rank.resize(n+1,0);
            parent.resize(n+1);
            for(int i = 0; i <= n; i++){
                parent[i] = i;
            }
            size.resize(n+1,1);
        }

        int findUParent(int node){
            if(node == parent[node]){
                return node;
            }
            return parent[node] = findUParent(parent[node]);
        }

        void unionByRank(int u, int v){
            int ulp_u = findUParent(u);
            int ulp_v = findUParent(v);
            if(ulp_u == ulp_v) return;
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
        }

        void unionBySize(int u, int v){
            int ulp_u = findUParent(u);
            int ulp_v = findUParent(v);
            if(ulp_u == ulp_v) return;
            if(size[ulp_v] < size[ulp_v]){
                parent[ulp_u] = ulp_v;
                size[ulp_v] += size[ulp_u];
            }
            else{
                parent[ulp_v] = ulp_u;
                size[ulp_u] += size[ulp_v];
            }
        }
};

// funtion to give minimum operations to make graph connected
int makeNetworkConnected(vector< vector<int> > graph, int V){
    DisjointSet ds(V);
    
    // first we will count extra edges
    // if two nodes have same parent means they are already connected to each other
    // again if any edge comes between them means it is extra and is of no need so count
    int extraEdges = 0;
    for(int i = 0; i < V; i++){
        for(int j = 0; j < graph[i].size(); j++){
            if(ds.findUParent(i) == ds.findUParent(j)) extraEdges++;
            ds.unionBySize(i,graph[i][j]);
        }
    }

    // count the total no. of disconnected components
    // we will be requiring n-1 edges to attach n disconnected components
    int count =  0;
    for(int i = 0; i < V; i++){
        if(ds.findUParent(i) == i) count++;
    }
    
    // if we have enough extra edges to connect the diconnected components then return count-1
    // else we can't make the graph connected
    if(extraEdges >= (count-1)) return count-1;
    else return -1; 
}

int main(){
    int v;
    cin >> v;
    vector< vector< int > > graph(v,vector< int >());
    int e;
    cin >> e;
    while(e--){
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    for(int i = 0; i < graph.size(); i++){
        cout << i << " -> ";
        for(int j = 0; j < graph[i].size(); j++){
            cout << graph[i][j] << " ";
        }
        cout << "\n";
    }
    cout << makeNetworkConnected(graph,v);
    return 0;
}