// REPLACE O'S WITH X'S
// A GRID OF O'S AND X'S IS GIVEN TO US AND WE HAVE TO CONVERT ALL THE GROUP OF MAXIAMAL ZEROS WHICH SURROUNDED BY X'S FROM ALL THE SIDES
// SO SIMPLE CONCEPT USED HERE IS THAT WE WILL BE DOING DFS ON ALL THE ZEROS WHICH ARE PRESENT ON THE BOUNDARY OF THE GRID
// THEN SIMPLY WE WILL MARK ALL THE ZEROS AS X WHICH CAN BE VISITED FROM THAT ZEROS
// THIS IS SO BECAUSE THOSE GROUP OF ZEROS WHICH ARE CONNECTED TO BOUNDARY ZEROS CAN'T BE SURROUNDED BY THE X'S SO CAN'T BE CONVERTED INTO X'S

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
        // only thing is valid condition to check
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

    // do dfs on all the boundary zeros which are unvisited
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if( (i == 0 || i == n-1 || j == 0 || j == m-1)
                && grid[i][j] == 'o' && not visited[i][j]){
                    visited[i][j] = 1;
                    dfs(i,j,grid,visited);
            }
        }
    }
    
    // make final ans by converting into x and o
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
