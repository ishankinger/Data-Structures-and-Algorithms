// MAXIMUM PATH SUM WITH VARIABLE STARTING AND ENDING POINTS

#include<bits/stdc++.h>
using namespace std;

int f(int i, int j, vector< vector<int> > grid){
    if(i == 0) return grid[i][j];
    if(j < 0 or j >= grid[0].size()) return -1000;
    int up = f(i-1,j,grid) + grid[i][j];
    int diagR = f(i-1,j+1,grid) + grid[i][j];
    int diagL = f(i-1,j-1,grid) + grid[i][j];
    return max(up,max(diagR,diagL));
}

int f_memo(int i, int j, vector< vector<int> > grid, vector< vector<int> > &dp){
    if(i == 0) return grid[i][j];
    if(j < 0 or j == grid[0].size()) return -1000;
    if(dp[i][j] != -1) return dp[i][j];
    int up = f_memo(i-1,j,grid,dp) + grid[i][j];
    int diagR = f_memo(i-1,j+1,grid,dp) + grid[i][j];
    int diagL = f_memo(i-1,j-1,grid,dp) + grid[i][j];
    return dp[i][j] = max(up,max(diagR,diagL));
}

int f_tab(vector< vector<int> > grid){
    int n = grid.size();
    int m = grid[0].size();
    vector< vector<int> > dp(n,vector<int>(m,0));
    for(int i = 0; i < m; i++) dp[0][i] = grid[0][i];
    int up,diagR,diagL;
    for(int i = 1; i < n; i++){
        for(int j = 0; j < m; j++){
            up = diagR = diagL = grid[i][j];
            up += dp[i-1][j];
            if(j+1 < m) diagR += dp[i-1][j+1]; else diagR = -100000;
            if(j-1 >= 0) diagL += dp[i-1][j-1]; else diagL = -100000;
            dp[i][j] = max(up,max(diagR,diagL));
        }
    }
    int maxSum = 0;
    for(int i = 0; i < m; i++){
        maxSum = max(maxSum,dp[n-1][i]);
    }
    return maxSum;
}

int f_tab_so(vector< vector<int> > grid){
    int n = grid.size();
    int m = grid[0].size();
    vector<int> prev(m);
    for(int i = 0; i < m; i++) prev[i] = grid[0][i];
    int up, diagR, diagL;
    for(int i = 1; i < n; i++){
        vector<int> curr(n,0);
        for(int j = 0; j < m; j++){
            up = diagR = diagL = grid[i][j];
            up += prev[j];
            if(j+1 < m) diagR += prev[j+1]; else diagR = -100000;
            if(j-1 >= 0) diagL += prev[j-1]; else diagL = -100000;
            curr[j] = max(up,max(diagR,diagL));
        }
        prev = curr;
    }
    int maxSum = 0;
    for(int i = 0; i < m; i++){
        maxSum = max(maxSum,prev[i]);
    }
    return maxSum;
}

int maxPathSum(vector< vector<int> > grid){
    int n = grid.size();
    int m = grid[0].size();
    vector< vector<int> > dp(n,vector<int>(m,-1));
    int maxSum = 0;
    for(int i = 0; i < m; i++){
        maxSum = max(maxSum,f_memo(n-1,i,grid,dp));
    }
    return maxSum;
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
    int maxSum = 0;
    for(int i = 0; i < m; i++){
        maxSum = max(maxSum,f(n-1,i,grid));
    }
    
    cout << maxSum << "\n";
    cout << maxPathSum(grid) << "\n";
    cout << f_tab(grid) << "\n";
    cout << f_tab_so(grid) << "\n";

    return 0;
}