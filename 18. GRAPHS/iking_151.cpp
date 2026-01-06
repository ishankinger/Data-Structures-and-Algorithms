// MOST STONES REMOVED FROM SAME ROW OR COLUMNS

#include<bits/stdc++.h>
using namespace std;

// Implementation of the Disjoint set
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
};

// we assume each row and each col as a node and rows are numbered from 0 to n-1 and columns are numbered from n to n+m-1
// now for every stone location we will union these nodes
// a connected component of this graph depicts that all stones containing in row and col can be removed from each other
// so at the end only one stone will left thus for k sized connected component maximum stones that can be removed are k-1
// supposes there are t connected components then stones that can be removed are  (k1 - 1) + (k2 - 1) + (k3 - 1) +... (kt - 1)
// (k1 + k2 + k3 + k4 ....) - (1 + 1 + 1.. t times)
// so final answer will be (all stones) - (no. of Connected Components)

class Solution {
public:
    int removeStones(vector<vector<int>>& stones) {
        int n = 0, m = 0;
        for(int i = 0; i < stones.size(); i++){
            n = max(n,stones[i][0]+1);
            m = max(m,stones[i][1]+1);
        }

        DisjointSet ds(n+m);                        // disjoint set for n+m nodes
        unordered_map<int,int> mp;                  // map stores the rows and cols where stones are present
        for(int i = 0; i < stones.size(); i++){
            int u = stones[i][0];
            int v = stones[i][1] + n;
            ds.unionByRank(u,v);                    // union the row and col
            mp[u] = 1;
            mp[v] = 1;
        }

        // now count the connected componenets from the given graph
        int connComp = 0;
        for(auto it = mp.begin(); it != mp.end(); it++){
            if(ds.findUParent((*it).first) == (*it).first){
                connComp++;
            }
        }

        return stones.size() - connComp;
    }
};

