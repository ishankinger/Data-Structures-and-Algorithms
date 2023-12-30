// NUMBER OF ISLANDS

#include<bits/stdc++.h>
using namespace std;

void bfs(int i, int j, vector<vector<int>> &visited, vector<vector<int>> grid){
    visited[i][j] = 1;
    queue<pair<int,int>> q;
    q.push({i,j});

    while(not q.empty()){
        int row = q.front().first;
        int col = q.front().second;
        q.pop();
        for(int dr = -1 ; dr <= 1; dr++){
            for(int dc = -1; dc <= 1; dc++){
                int nrow = row + dr;
                int ncol = col + dc;
                if(nrow < visited.size() and nrow >=0 and ncol < visited[0].size() and ncol >= 0
                    and grid[nrow][ncol] == 1 && not visited[nrow][ncol]){
                        visited[nrow][ncol] = 1;
                        q.push({nrow,ncol});
                }
            }
        }
    }
}
int numOfIslands(int n, int m,vector<vector<int>> grid){
    int count = 0;
    vector<vector<int>> visited(n,vector<int>(m,0));
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m;i++){
            if(not visited[i][j] and grid[i][j] == 1){
                bfs(i,j,visited,grid);
                count++;
            }
        }
    }
    return count;
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
    cout << numOfIslands(n,m,grid) << "\n";
    return 0;
}