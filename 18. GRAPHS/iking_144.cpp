// DISJOINT SET DATA STRUCTURE

#include<bits/stdc++.h>
using namespace std;

class DisjointSet{
        vector<int> rank,parent,size;
    public:
        // constructor for this class
        DisjointSet(int n){
            // initialise all the arrays
            rank.resize(n+1,0);
            parent.resize(n+1);
            for(int i = 0; i <= n; i++){
                parent[i] = i;
            }
            size.resize(n+1,1);
        }

        // function to find parent node of given node
        int findUParent(int node){

            // if we get parent nodes then return node
            if(node == parent[node]){
                return node;
            }
            
            // while backtracking other nodes parent will also be updated
            return parent[node] = findUParent(parent[node]);
        }

        // function to union two nodes
        void unionByRank(int u, int v){
            
            // get parent of both the nodes
            int ulp_u = findUParent(u);
            int ulp_v = findUParent(v);
            
            // if parent same then nothing to update
            if(ulp_u == ulp_v) return;

            // attach lower rank to higher rank to not to increase the depth of the tree
            if(rank[ulp_v] < rank[ulp_u]){
                parent[ulp_v] = ulp_u;
            }
            else if(rank[ulp_u] < rank[ulp_v]){
                parent[ulp_u] = ulp_v;
            }
            // if equal rank then any one to be attached to other and increase it's size by 1
            else{
                parent[ulp_v] = ulp_u;
                rank[ulp_u]++;
            }
        }

        // function to union two nodes by size
        void unionBySize(int u, int v){
            int ulp_u = findUParent(u);
            int ulp_v = findUParent(v);
            if(ulp_u == ulp_v) return;
            // here smaller size will be attached to larger size
            if(size[ulp_u] < size[ulp_v]){
                parent[ulp_u] = ulp_v;
                size[ulp_v] += size[ulp_u];
            }
            else{
                parent[ulp_v] = ulp_u;
                size[ulp_u] += size[ulp_v];
            }
        }
};

int main(){
    DisjointSet ds(7);
    ds.unionByRank(1,2);
    ds.unionByRank(2,3);
    ds.unionByRank(4,5);
    ds.unionByRank(6,7);
    ds.unionByRank(5,6);
    if(ds.findUParent(3) == ds.findUParent(7)) cout << "Same\n";
    else cout << "Different\n";
    ds.unionByRank(3,7);
    if(ds.findUParent(3) == ds.findUParent(7)) cout << "Same\n";
    else cout << "Different\n";

    return 0;
}