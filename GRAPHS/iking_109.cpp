// ROTTEN ORANGES

#include<bits/stdc++.h>
using namespace std;

int orangesRotten( vector<vector<int>> &grid){
    int n = grid.size();
    int m = grid[0].size();

    queue< pair< pair<int,int>, int>> q;
    vector<vector<int>> vis(n,vector<int>(m));
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(grid[i][j] == 2){
                q.push({{i,j},0});
                vis[i][j] = 2;
            }
            else{
                vis[i][j] = 0;
            }
        }
    }

    int delRow[] = {-1, 0 , +1, 0};
    int delCol[] = {0, +1 , 0, -1};
    int tm = 0;
    while(not q.empty()){
        int r = q.front().first.first;
        int c = q.front().first.second;
        int t = q.front().second;
        tm = max(tm,t);
        q.pop();
        for(int i = 0; i < 4; i++){
            int nrow = r + delRow[i];
            int ncol = c + delCol[i];
            if(nrow >= 0 and nrow < n and ncol >= 0 and ncol < m
                and vis[nrow][ncol] != 2 and grid[nrow][ncol] == 1){
                    q.push({{nrow,ncol},t + 1});
                    vis[nrow][ncol] = 2;
            }
        }
    }

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(vis[i][j] != 2 and grid[i][j] == 1){
                return -1;
            }
        }
    }
    
    return tm;
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

    cout<<orangesRotten(grid);

    return 0;
}