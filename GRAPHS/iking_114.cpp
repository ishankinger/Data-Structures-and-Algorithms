// NUMBER OF ENCLAVES

#include<bits/stdc++.h>
using namespace std;

void dfs(int sr, int sc, vector< vector<int> > grid, vector< vector<int> > &visited){
    int n = grid.size();
    int m = grid[0].size();
    visited[sr][sc] = 1;
    int dr[] = {-1,0,+1,0};
    int dc[] = {0,+1,0,-1};
    for(int i = 0; i < 4; i++){
        int nr = sr + dr[i];
        int nc = sc + dc[i];
        if(nr >= 0 and nr < n and nc >= 0 and nc < m 
            and grid[nr][nc] == 1 and not visited[nr][nc]){
                visited[nr][nc] = 1;
                dfs(nr,nc,grid,visited);
        }
    }
}

int numOfEnclaves(vector< vector<int> > grid){
    int n = grid.size();
    int m = grid[0].size();
    vector< vector<int> > visited(n,vector<int>(m,0));
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if((i == 0 || j == 0 || i == n-1 || j == m-1)
                && not visited[i][j] && grid[i][j] == 1){
                    visited[i][j] = 1;
                    dfs(i,j,grid,visited);
            }
        }
    }
    int count = 0;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(not visited[i][j] and grid[i][j] == 1){
                count++;
            }
        }
    }
    return count;
}


int main(){
    int n, m;
    cin >> n >> m;
    vector< vector<int> > grid(n,vector<int>(m));
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> grid[i][j];
        }
    }

    cout<<numOfEnclaves(grid);

    return 0;
}