// TOTAL UNIQUE PATHS

#include<bits/stdc++.h>
using namespace std;

int f(int i, int j){
    if(i == 0 and j == 0) return 1;
    if(i < 0 or j < 0) return 0;
    int up = f(i-1,j);
    int left = f(i,j-1);
    return up + left;
}

int f_memo(int i, int j, vector< vector<int> > &dp){
    if(i == 0 and j == 0) return 1;
    if(i < 0 or j < 0) return 0;
    if(dp[i][j] != -1) return dp[i][j];
    int up = f_memo(i-1,j,dp);
    int left = f_memo(i,j-1,dp);
    return dp[i][j] = up + left;
}

int f_tab(int n, int m){
    vector< vector<int> > dp(n,vector<int>(m,0));
    int up,left;
    for(int i = 0; i < n; i++){
        up = 0, left = 0;
        for(int j = 0; j < m; j++){
            if(i == 0 and j == 0){
                dp[i][j] = 1;
            }
            else{
                if(i > 0) up = dp[i-1][j];
                if(j > 0) left = dp[i][j-1];
                dp[i][j] = up + left;
            }
        }
    }
    return dp[n-1][m-1];
}

int f_tab_so(int n, int m){
    vector<int> prev(m,0);
    prev[0] = 1;
    for(int i = 0; i < n; i++){
        vector<int> curr(m,0);
        for(int j = 0; j < m; j++){
            if(j == 0) curr[j] = prev[j];
            else curr[j] = prev[j] + curr[j-1];
        }
        prev = curr;
    }
    return prev[m-1];
}

int uniquePaths(int n, int m){
    vector< vector<int> > dp(n,vector<int>(m,-1));
    return f_memo(n-1,m-1,dp);
}

int main(){
    int n, m;
    cin >> n >> m;
    cout << f(n-1,m-1) << "\n";
    cout << uniquePaths(n,m) << "\n";
    cout << f_tab(n,m) << "\n";
    cout << f_tab_so(n,m) << "\n";
    return 0;
}