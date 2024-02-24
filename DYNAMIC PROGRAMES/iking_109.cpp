// NINJA AND HIS FRIENDS

#include<bits/stdc++.h>
using namespace std;

int f(int i, int j1, int j2, int n, int m, vector< vector<int> > grid){
    if(j1 < 0 or j1 >= m or j2 < 0 or j2 >= m) return -10000;
    if(i == n-1){
        if(j1 == j2) return grid[i][j1];
        else return grid[i][j1] + grid[i][j2];
    } 
    int maxi = 0;
    for(int dj1 = -1; dj1 <= 1; dj1++){
        for(int dj2 = -1; dj2 <= 1; dj2++){
            if(j1 == j2){
                maxi = max(maxi,grid[i][j1] + f(i+1, j1 + dj1, j2 + dj2, n, m, grid));
            }
            else{
                maxi = max(maxi,grid[i][j1] + f(i+1, j1 + dj1, j2 + dj2, n, m, grid) + grid[i][j2]);
            }
        }
    }
    return maxi;
}

int f_memo(int i, int j1, int j2, int n, int m, vector< vector<int> > grid, vector< vector< vector<int> > > &dp){
    if(j1 < 0 or j1 >= m or j2 < 0 or j2 >= m) return -10000;
    if(i == n-1){
        if(j1 == j2) return grid[i][j1];
        else return grid[i][j1] + grid[i][j2];
    }
    if(dp[i][j1][j2] != -1) return dp[i][j1][j2];
    int maxi = 0;
    for(int dj1 = -1; dj1 <= 1; dj1++){
        for(int dj2 = -1; dj2 <= 1; dj2++){
            if(j1 == j2){
                maxi = max(maxi,grid[i][j1] + f_memo(i+1, j1 + dj1, j2 + dj2, n, m, grid,dp));
            }
            else{
                maxi = max(maxi,grid[i][j1] + f_memo(i+1, j1 + dj1, j2 + dj2, n, m, grid,dp) + grid[i][j2]);
            }
        }
    }
    return dp[i][j1][j2] = maxi;   
}

int f_tab(vector< vector<int> > grid){
    int n = grid.size();
    int m = grid[0].size();
    vector< vector< vector<int> > > dp(n,vector< vector<int> >(m,vector<int>(m,0)));
    for(int j1 = 0; j1 < m; j1++){
        for(int j2 = 0; j2 < m; j2++){
            if(j1 == j2) dp[n-1][j1][j2] = grid[n-1][j1];
            else dp[n-1][j1][j2] = grid[n-1][j1] + grid[n-1][j2];
        }
    }
    for(int i = n-2; i >= 0; i--){
        for(int j1 = m-1; j1 >= 0; j1--){
            for(int j2 = m-1; j2 >= 0; j2--){
                int maxi = 0;
                for(int dj1 = -1; dj1 <= 1; dj1++){
                    for(int dj2 = -1; dj2 <= 1; dj2++){
                        if(j1 == j2){
                            if(j1 + dj1 >= 0 and j1 + dj1 < m and j2 + dj2 >= 0 and j2 + dj2 < m){
                                maxi = max(maxi,grid[i][j1] + dp[i+1][j1 + dj1][j2 + dj2]);
                            }
                        }
                        else{
                            if(j1 + dj1 >= 0 and j1 + dj1 < m and j2 + dj2 >= 0 and j2 + dj2 < m){
                                maxi = max(maxi,grid[i][j1] + dp[i+1][j1 + dj1][j2 + dj2] + grid[i][j2]);
                            }
                        }
                    }
                }
                dp[i][j1][j2] = maxi;
            }
        }
    }
    return dp[0][0][m-1];
}

int ninjaAndFriends(vector< vector<int> > grid){
    int n = grid.size();
    int m = grid[0].size();
    vector< vector< vector< int> > > dp(n,vector< vector<int> > (m,vector<int>(m,-1)));
    return f_memo(0,0,m-1,n,m,grid,dp);
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

    cout << f(0,0,m-1,n,m,grid) << "\n";
    cout << ninjaAndFriends(grid) << "\n";
    cout << f_tab(grid) << "\n";

    return 0;
}