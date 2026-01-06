// MINIMUM COST TO CUT A STICK

#include<bits/stdc++.h>
using namespace std;

int f(int i, int j, vector<int> cuts){
    if(i > j) return 0;
    int mini = INT_MAX;
    for(int ind = i; ind <= j; ind++){
        int cost = cuts[j+1] - cuts[i-1] + f(i,ind-1,cuts) + f(ind+1,j,cuts);
        mini = min(mini,cost);
    }
    return mini;
}

int f_memo(int i, int j, vector<int> cuts, vector< vector<int> > &dp){
    if(i > j) return 0;
    if(dp[i][j] != -1) return dp[i][j];
    int mini = INT_MAX;
    for(int ind = i; ind <= j; ind++){
        int cost = cuts[j+1] - cuts[i-1] + f_memo(i,ind-1,cuts,dp) + f_memo(ind+1,j,cuts,dp);
        mini = min(mini,cost);
    }
    return dp[i][j] = mini;
}

int f_tab(int n, int c, vector<int> cuts){
    vector< vector<int> > dp(c+2,vector<int>(c+1,0));
    int minCost;
    for(int i = c; i >= 1; i--){
        for(int j = i; j <= c; j++){
            minCost = INT_MAX;
            for(int k = i; k <= j; k++){
                minCost = min(minCost,cuts[j+1] - cuts[i-1] + dp[i][k-1] + dp[k+1][j]);
            }
            dp[i][j] = minCost;
        }
    }
    return dp[1][c];
}

int rodCutting(int n, int c, vector<int> cuts){
    vector< vector<int> > dp(c+1,vector<int>(c+1,-1));
    return f_memo(1,c,cuts,dp);
}

int main(){
    int n;
    cin >> n;
    int c;
    cin >> c;
    vector<int> v(c);
    for(int i = 0; i < c; i++) cin >> v[i];

    v.push_back(n);
    v.insert(v.begin(),0);
    sort(v.begin(),v.end());

    cout << f(1,c,v) << "\n";
    cout << rodCutting(n,c,v) << "\n";
    cout << f_tab(n,c,v) << "\n";

    return 0;
}