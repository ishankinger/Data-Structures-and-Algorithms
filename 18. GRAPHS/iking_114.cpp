// NUMBER OF ENCLAVES
// 1 - land cells and 0 - water cells  GRID OF 0 1 IS GIVEN TO US
// WE CAN MOVE ONLY ON THE LAND CELLS AND WE HAVE TO COUNT ALL THE ONE'S FROM WHICH BY MOVING WE CAN'T REACH AT THE END
// SO HERE WE WILL DO DFS ON THE BOUNDARY ONE'S ONLY ALL THE ONE'S WHICH CAN'T BE VISITED WILL BE OUR ANSWER
// VERY SIMILAR AS THAT OF THE LAST QUESTION

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

// more space optimised
int numEnclaves_spaceOptimise(vector<vector<int>>& grid) {
    int n = grid.size();
    int m = grid[0].size();
    vector< vector<int> > visited(n,vector<int>(m,0));
    queue< pair<int,int> > q;

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if((i == 0 || j == 0 || i == n-1 || j == m-1) and grid[i][j] == 1){
                visited[i][j] = 1;
                q.push({i,j});
            }
        }
    }

    int dr[] = {-1,0,+1,0};
    int dc[] = {0,+1,0,-1};
    while(not q.empty()){
        int sr = q.front().first;
        int sc = q.front().second;
        q.pop();

        for(int i = 0; i < 4; i++){
            int nr = sr + dr[i];
            int nc = sc + dc[i];
            if(nr >= 0 and nr < n and nc >= 0 and nc < m 
                and grid[nr][nc] == 1 and not visited[nr][nc]){
                    visited[nr][nc] = 1;
                    q.push({nr,nc});
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
