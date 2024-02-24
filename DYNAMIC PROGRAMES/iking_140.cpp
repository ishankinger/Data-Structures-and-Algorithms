// BURST BALLOONS

#include<bits/stdc++.h>
using namespace std;

int f(int i, int j, vector<int> a){
    if(i > j) return 0;
    int maxCost = INT_MIN;
    for(int ind = i; ind <= j; ind++){
        maxCost = max(maxCost, a[i-1]*a[ind]*a[j+1] + f(i,ind-1,a) + f(ind+1,j,a));
    }
    return maxCost;
}

int f_memo(int i, int j, vector<int> a, vector< vector<int> > &dp){
    if(i > j) return 0;
    if(dp[i][j] != -1) return dp[i][j];
    int maxCost = INT_MIN;
    for(int ind = i; ind <= j; ind++){
        maxCost = max(maxCost, a[i-1]*a[ind]*a[j+1] + f_memo(i,ind-1,a,dp) + f_memo(ind+1,j,a,dp));
    }
    return dp[i][j] = maxCost;
}

int f_tab(vector<int> a){
    vector< vector<int> > dp(a.size(),vector<int>(a.size(),0));
    int maxCost = INT_MIN;
    for(int i = a.size()-2; i >= 1; i--){
        for(int j = i; j <= a.size()-2; j++){
            maxCost = INT_MIN;
            for(int ind = i; ind <= j; ind++){
                maxCost = max(maxCost,a[i-1]*a[ind]*a[j+1]+dp[i][ind-1]+dp[ind+1][j]);
            }
            dp[i][j] = maxCost;
        }
    }
    return dp[1][a.size()-2];
}

int burstBalloons(vector<int> a){
    vector< vector<int> > dp(a.size()-1,vector<int>(a.size()-1,-1));
    return f_memo(1,a.size()-2,a,dp);
}

int main(){
    int n;
    cin >> n;
    vector<int> v(n);
    for(int i = 0; i < n; i++) cin >> v[i];

    v.push_back(1);
    v.insert(v.begin(),1);

    cout << f(1,n,v) << "\n";
    cout << burstBalloons(v) << "\n";
    cout << f_tab(v) << "\n";

    return 0;
}