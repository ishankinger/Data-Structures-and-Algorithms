// MINIMUM PATH SUM

#include<bits/stdc++.h>
using namespace std;

int f(int i, int j, vector< vector<int> > grid){
    if(i == 0 and j == 0) return grid[i][j];
    if(i < 0 or j < 0) return 100000;
    int up = f(i-1,j,grid) + grid[i][j];
    int left = f(i,j-1,grid) + grid[i][j];
    return min(up,left);
}

int f_memo(int i, int j, vector< vector<int> > grid, vector< vector<int> > &dp){
    if(i == 0 and j == 0) return grid[i][j];
    if(i < 0 or j < 0) return 100000;
    if(dp[i][j] != -1) return dp[i][j];
    int up = f_memo(i-1,j,grid,dp) + grid[i][j];
    int left = f_memo(i,j-1,grid,dp) + grid[i][j];
    return dp[i][j] = min(up,left);
}

int f_tab(vector< vector<int> > grid){
    int n = grid.size();
    int m = grid[0].size();
    int up, left;
    vector< vector<int> > dp(n,vector<int>(m,0));
    for(int i = 0; i < n; i++){
        up = 0, left = 0;
        for(int j = 0; j < m; j++){
            if(i == 0 and j == 0){
                dp[i][j] = grid[i][j];
            }
            else{
                up = grid[i][j];
                if(i > 0) up += dp[i-1][j];
                else up = 100000;
                left = grid[i][j];
                if(j > 0) left += dp[i][j-1];
                else left = 100000;
                dp[i][j] = min(up,left);
            }
        }
    }
    return dp[n-1][m-1]; 
}

int f_tab_so(vector< vector<int> > grid){
    int n = grid.size();
    int m = grid[0].size();
    int up, left;
    vector<int> prev(m,0);
    prev[0] = grid[0][0];
    for(int i = 0; i < n; i++){
        vector<int> curr(m,0);
        for(int j = 0; j < m; j++){
            if(i == 0 and j == 0){
                curr[j] = grid[i][j];
            }
            else{
                up = grid[i][j];
                if(i > 0) up += prev[j];
                else up = 100000;
                left = grid[i][j];
                if(j > 0) left += curr[j-1];
                else left = 100000;
                curr[j] = min(up,left);
            }
        }
        prev = curr;
    }
    return prev[m-1];
}

int minPathSum(vector< vector<int> > grid){
    int n = grid.size();
    int m = grid[0].size();
    vector< vector<int> > dp(n,vector<int>(m,-1));
    return f_memo(n-1,m-1,grid,dp);
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
    cout << f(n-1,m-1,grid) << "\n";
    cout << minPathSum(grid) << "\n";
    cout << f_tab(grid) << "\n";
    cout << f_tab_so(grid) << "\n";

    return 0;
}