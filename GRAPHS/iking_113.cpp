// REPLACE O'S WITH X'S

#include<bits/stdc++.h>
using namespace std;

void dfs(int sr,int sc,vector< vector<char> > grid, vector< vector<int> > &visited){
    int n = grid.size();
    int m = grid[0].size();
    visited[sr][sc] = 1;
    int delRow[] = {-1,0,+1,0};
    int delCol[] = {0,+1,0,-1};
    for(int i = 0; i < 4; i++){
        int nr = sr + delRow[i];
        int nc = sc + delCol[i];
        if(nr >= 0 and nr < n and nc >= 0 and nc < m
            and not visited[nr][nc] and grid[nr][nc] == 'o'){
                dfs(nr,nc,grid,visited);
        }
    }
}

vector<vector<char>> replaceOWithX(vector<vector<char>> grid){
    int n = grid.size();
    int m = grid[0].size();
    vector< vector<char> > modifiedGrid(n,vector<char>(m));
    vector< vector<int> > visited(n,vector<int>(m,0));
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if( (i == 0 || i == n-1 || j == 0 || j == m-1) && grid[i][j] == 'o'){
                visited[i][j] = 1;
                dfs(i,j,grid,visited);
            }
        }
    }
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(visited[i][j] == 0){
                modifiedGrid[i][j] = 'x';
            }
            else{
                modifiedGrid[i][j] = 'o';
            }
        }
    }
    return modifiedGrid;
}

int main(){
    int n, m; 
    cin >> n >> m;
    vector<vector<char>> grid(n,vector<char>(m));
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> grid[i][j];
        }
    }

    vector<vector<char>> modifiedGrid = replaceOWithX(grid);

    cout<<"\n\n";
    
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cout<<modifiedGrid[i][j]<<" ";
        }
        cout<<"\n";
    }

    return 0;
}