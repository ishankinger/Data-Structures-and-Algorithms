// TRIANGULAR MINIMUM PATH SUM PROBLEM

#include<bits/stdc++.h>
using namespace std;

int f(int i, int j, int n, vector< vector<int> > tri){
    if(i == n-1) return tri[n-1][j];
    int down = tri[i][j] + f(i+1,j,n,tri);
    int diag = tri[i][j] + f(i+1,j+1,n,tri);
    return min(down,diag);
}

int f_memo(int i, int j, int n, vector< vector<int> > tri, vector< vector<int> > &dp){
    if(i == n-1) return tri[n-1][j];
    if(dp[i][j] != -1) return dp[i][j];
    int down = tri[i][j] + f_memo(i+1,j,n,tri,dp);
    int diag = tri[i][j] + f_memo(i+1,j+1,n,tri,dp);
    return dp[i][j] = min(down,diag);
}

int f_tab(vector< vector<int> > tri){
    int n = tri.size();
    vector< vector<int> > dp(n,vector<int>(n,0));
    for(int j = 0; j < n; j++) dp[n-1][j] = tri[n-1][j];
    int down,diag;
    for(int i = n-2; i >= 0; i--){
        for(int j = i; j >= 0; j--){
            down = tri[i][j] + dp[i+1][j];
            diag = tri[i][j] + dp[i+1][j+1];
            dp[i][j] = min(down,diag);
        }
    }
    return dp[0][0];
}

int f_tab_so(vector< vector<int> > tri){
    int n = tri.size();
    vector<int> prev(n);
    vector<int> curr(n);
    for(int i = 0; i < n; i++) prev[i] = tri[n-1][i];
    int down, diag;
    for(int i = n-2; i >= 0; i--){
        for(int j = i; j >=0; j--){
            down = tri[i][j] + prev[j];
            diag = tri[i][j] + prev[j+1];
            curr[j] = min(down,diag);
        }
        prev = curr;
    }
    return prev[0];
}

int triMinPathSum(vector< vector<int> > tri){
    int n = tri.size();
    vector< vector<int> > dp(n,vector<int>(n,-1));
    return f_memo(0,0,n,tri,dp);
}

int main(){
    int n;
    cin >> n;
    vector< vector<int> > tri(n);
    for(int i = 0; i < n; i++){
        for(int j = 0; j <= i; j++){
            int ele;
            cin >> ele;
            tri[i].push_back(ele);
        }
    }

    cout << f(0,0,n,tri) << "\n";
    cout << triMinPathSum(tri) << "\n";
    cout << f_tab(tri) << "\n";
    cout << f_tab_so(tri) << "\n";

    return 0;
}