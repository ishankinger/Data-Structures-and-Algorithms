// DISTANCE OF NEAREST CELL HAVING 1

#include<bits/stdc++.h>
using namespace std;

void distanceFromNearestOne(vector<vector<int>> grid, vector<vector<int>> &distArr){
    queue< pair< pair<int,int> , int > > q;
    vector<vector<int>> visited(grid.size(),vector<int>(grid[0].size(),0));
    for(int i = 0; i < grid.size(); i++){
        for(int j = 0; j < grid[0].size(); j++){
            if(grid[i][j] == 1){
                q.push({{i,j},0});
                visited[i][j] = 1;
            }
        }
    }
    int delRow[] = {-1,0,+1,0};
    int delCol[] = {0,+1,0,-1};
    while(not q.empty()){
        int row = q.front().first.first;
        int col = q.front().first.second;
        int dist = q.front().second;
        distArr[row][col] = dist;
        q.pop();
        for(int i = 0; i < 4; i++){
            int nrow = row + delRow[i];
            int ncol = col + delCol[i];
            
            if(nrow >= 0 and nrow < grid.size() and ncol >= 0 and ncol < grid[0].size()
                and grid[nrow][ncol] == 0 and not visited[nrow][ncol]){
                    q.push({{nrow,ncol},dist+1});
                    visited[nrow][ncol] = 1;
            }
        }
    }
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

    vector<vector<int>> distArr(n,vector<int>(m,0));

    distanceFromNearestOne(grid,distArr);

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cout << distArr[i][j] << " ";
        }
        cout << "\n";
    }

    return 0;
}