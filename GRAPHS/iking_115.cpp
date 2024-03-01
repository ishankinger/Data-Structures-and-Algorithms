// NUMBER OF DISTINCT ISLANDS
// IN THIS WE WANT THE SIZE OF SET OF ISLANDS IN A GRID OF O-1 MATRIX
// ALSO NOTE THAT SET HAS DISTINCT ELEMETNS SO IF WE GET SIMILAR KINDS OF ELEMETNS THEN WE WILL COUNT IT AS ONE ONLY    
// WE WILL STORE DIFFERENT ISLANDS IN THE FORM OF THE LIST ( LIST OF COORDINATES OF ELEMENTS PRESENT IN THAT PARTICULAR ISLANDS ) 
// THAT LIST WILL STORE DIFFERENCE OF THAT COORDINATE WITH THE SOURCE COORDINATE SO TO GET SIMILARITY IN ISLANDS IF ANY

#include<bits/stdc++.h>
using namespace std;

void dfs(int sr, int sc, vector< vector<int> > grid, vector< vector<int> > &visited, vector< pair<int,int> > &list, int sr0, int sc0){
    // same code as done before to get an island
    int n = grid.size();
    int m = grid[0].size();

    visited[sr][sc] = 1;

    int delRow[] = {0,+1,0,-1};
    int delCol[] = {+1,0,-1,0};

    for(int i = 0; i < 4; i++){
        int nr = sr + delRow[i];
        int nc = sc + delCol[i];

        if(nr >= 0 and nr < n and nc >= 0 and nc < m and grid[nr][nc] == 1 and not visited[nr][nc]){
                visited[nr][nc] = 1;

                // here also we are pushing the difference of main source node and new node for the set to check similarity
                list.push_back({nr-sr0,nc-sc0});
                 
                dfs(nr,nc,grid,visited,list,sr0,sc0);
        }
    }
}

vector< pair<int,int> > dfs_list(int sr, int sc, vector< vector<int> > grid, vector< vector<int> > &visited){
    vector< pair<int,int> > list;

    // initially 0,0 for sr,sc coordinate as we are doing difference in the coordinates
    list.push_back({0,0});

    dfs(sr,sc,grid,visited,list,sr,sc);
    
    return list;
}

int numOfDistIslands(vector<vector<int>> grid){
    int n = grid.size();
    int m = grid[0].size();

    // visited 2-d array
    vector< vector<int> > visited(n,vector<int>(m,0));

    // set in which list of different islands will be stored
    set< vector< pair<int,int> > > s;

    // list for a particular island
    vector< pair<int,int> > list;

    // we will traverse in the whole 2-d array and will do dfs on that 1's which are still not visited
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(grid[i][j] == 1 and not visited[i][j]){

                // dfs_list will give particular island list
                list = dfs_list(i,j,grid,visited);

                // that list will be stored in the set
                s.insert(list);
                // if there is any similarity in the lists then set will eliminate that
            }
        }
    }

    // at end size of the set is returned
    return s.size();
}

int main(){
    int n, m; 
    cin >> n >> m;
    vector<vector<int>> grid(n,vector<int>(m));
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> grid[i][j];
        }
    }
    cout<<numOfDistIslands(grid);
    return 0;
}
