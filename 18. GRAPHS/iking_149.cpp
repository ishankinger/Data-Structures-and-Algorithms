// NUMBER OF ISLANDS 2
// GIVEN A 2D MATRIX OF SIZE N*M AND INITIALLY ALL CELLS 0 MEANS WATER
// NOW WE WILL GIVE K QUERIES AND IN EACH QUERY ONE CELL TO BE CONVERTED TO LAND 1
// AFTER EACH QUERY WE HAVE TO RETURN THE NUMBER OF ISLANDS

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

vector<int> numOfIslands(int n, int m, vector< vector<int> > &operators) {
    // a disjoint set is created for each cell of the matric giving them num as i,j --> i*m + j
    DisjointSet ds(n*m);
    
    // a visited array is created to keep the track of the land cell
    vector< vector<int> > vis(n,vector<int>(m,0));

    // final count answer array is also created
    vector<int> ans;

    // count variable which we have to update in each query
    int count = 0;

    // dr and dc to take look at adjacent four directional cells
    int dr[4] = {+1,0,-1,0};
    int dc[4] = {0,+1,0,-1};

    // go in the queries
    for(int i = 0; i < operators.size(); i++){

        // extract the row , col and num index in the disjoint set
        int r = operators[i][0];
        int c = operators[i][1];
        int num_cell = r*m + c;

        // if land then nothing will change push count and continue
        if(vis[r][c]){
            ans.push_back(count);
            continue;
        }

        // otherwise make it land and assume disconnected for now so increase count by 1
        vis[r][c] = 1;
        count++;

        // now check the adjacent cells of our main cell
        int nr, nc;
        for(int j = 0; j < 4; j++){

            // adjacent cells row and col values
            nr = r + dr[j];
            nc = c + dc[j];

            // check valid condition on nr and nc
            if(nr >= 0 and nc >= 0 and nr < n and nc < m){
                int num_adj = nr*m + nc;

                // if adjacent is land then check whether they are connected or not
                // if not connected then count will decrease as we are combining two disconnected components to one
                if(vis[nr][nc]){
                    if(ds.findUParent(num_cell) != ds.findUParent(num_adj)){
                        count--;
                        ds.unionByRank(num_cell,num_adj);
                    }
                }
            }
        }

        // so will push our count in the ans array
        ans.push_back(count);
    }

    // and at end we will return the answer array
    return ans;
} 

int main(){

    return 0;
}