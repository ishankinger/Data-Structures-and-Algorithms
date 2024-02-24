// WAYS TO MAKE A COIN CHANGE

#include<bits/stdc++.h>
using namespace std;

int f(int index, int target, vector<int> coins){
    if(index == 0){
        if(target % coins[0] == 0) return 1;
        else return 0;
    }
    int not_take = f(index-1,target,coins);
    int take = 0;
    if(coins[index] <= target) take = f(index,target-coins[index],coins);
    return take + not_take;
}

int f_memo(int index, int target, vector<int> coins, vector< vector<int> > &dp){
    if(index == 0){
        if(target % coins[0] == 0) return 1;
        else return 0;
    }
    if(dp[index][target] != -1) return dp[index][target];
    int not_take = f_memo(index-1,target,coins,dp);
    int take = 0;
    if(coins[index] <= target) take = f_memo(index,target-coins[index],coins,dp);
    return dp[index][target] = take + not_take;
}

int f_tab(int n, vector<int> coins, int target){
    vector< vector<int> > dp(n,vector<int>(target+1,0));
    for(int i = 0; i < target+1; i++){
        if(i % coins[0] == 0) dp[0][i] = 1;
    }
    for(int ind = 1; ind < n; ind++){
        for(int tar = 0; tar < target+1; tar++){
            int not_take = dp[ind-1][tar];
            int take = 0;
            if(coins[ind] <= tar) take = dp[ind][tar-coins[ind]];
            dp[ind][tar] = take + not_take;
        }
    }
    return dp[n-1][target];
}

int f_tab_so(int n, vector<int> coins, int target){
    vector<int> prev(target+1,0);
    for(int i = 0; i < target+1; i++){
        if(i % coins[0] == 0) prev[i] = 1;
    }
    vector<int> curr(target+1,0);
    for(int ind = 1; ind < n; ind++){
        for(int tar = 0; tar < target+1; tar++){
            int not_take = prev[tar];
            int take = 0;
            if(coins[ind] <= tar) take = curr[tar-coins[ind]];
            curr[tar] = take + not_take;
        }
        prev = curr;
    }
    return prev[target];
}

int coinChange(int n, vector<int> coins, int target){
    vector< vector<int> > dp(n,vector<int>(target+1,-1));
    return f_memo(n-1,target,coins,dp);
}


int main(){
    int n;
    cin >> n;
    vector<int> v(n);
    for(int i = 0; i < n; i++) cin >> v[i];
    int target;
    cin >> target;

    cout << f(n-1,target,v) << "\n";
    cout << coinChange(n,v,target) << "\n";
    cout << f_tab(n,v,target) << "\n";
    cout << f_tab_so(n,v,target) << "\n";

    return 0;
}