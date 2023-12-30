// NUMBER OF DISTINCT ISLANDS

#include<bits/stdc++.h>
using namespace std;

void dfs(int sr, int sc, vector< vector<int> > grid, vector< vector<int> > &visited,
         vector< pair<int,int> > &list, int sr0, int sc0){
    int n = grid.size();
    int m = grid[0].size();
    visited[sr][sc] = 1;
    int delRow[] = {0,+1,0,-1};
    int delCol[] = {+1,0,-1,0};
    for(int i = 0; i < 4; i++){
        int nr = sr + delRow[i];
        int nc = sc + delCol[i];
        if(nr >= 0 and nr < n and nc >= 0 and nc < m 
            and grid[nr][nc] == 1 and not visited[nr][nc]){
                visited[nr][nc] = 1;
                list.push_back({nr-sr0,nc-sc0});
                dfs(nr,nc,grid,visited,list,sr0,sc0);
        }
    }
}

vector< pair<int,int> > dfs_list(int sr, int sc, vector< vector<int> > grid, vector< vector<int> > &visited){
    vector< pair<int,int> > list;
    list.push_back({0,0});
    dfs(sr,sc,grid,visited,list,sr,sc);
    return list;
}

int numOfDistIslands(vector<vector<int>> grid){
    int n = grid.size();
    int m = grid[0].size();
    vector< vector<int> > visited(n,vector<int>(m,0));
    set< vector< pair<int,int> > > s;
    vector< pair<int,int> > list;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(grid[i][j] == 1 and not visited[i][j]){
                list = dfs_list(i,j,grid,visited);
                s.insert(list);
            }
        }
    }
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