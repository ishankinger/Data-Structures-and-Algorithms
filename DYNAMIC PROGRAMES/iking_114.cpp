// MINIMUM NUMBER OF COINS

#include<bits/stdc++.h>
using namespace std;

int f(int index, int target, vector<int> denom){
    if(index == 0){
        if(target % denom[0] == 0) return target/denom[0];
        else return 10000000;
    }
    int not_take = 0 + f(index-1,target,denom);
    int take = INT_MAX;
    if(denom[index] <= target) take = 1 + f(index,target-denom[index],denom);
    return min(take,not_take);
}

int f_memo(int index, int target, vector<int> denom, vector< vector<int> > &dp){
    if(index == 0){
        if(target % denom[0] == 0) return target/denom[0];
        else return 10000000;
    }
    if(dp[index][target] != -1) return dp[index][target];
    int not_take = 0 + f_memo(index-1,target,denom,dp);
    int take = INT_MAX;
    if(denom[index] <= target) take = 1 + f_memo(index,target-denom[index],denom,dp);
    return dp[index][target] = min(take,not_take);
}

int f_tab(int n, vector<int> denom, int target){
    vector< vector<int> > dp(n,vector<int>(target+1,0));
    for(int i = 0; i <= target; i++){
        if(i % denom[0] == 0) dp[0][i] = i/denom[0];
        else dp[0][i] = 10000000;
    }
    for(int ind = 1; ind <= n-1; ind++){
        for(int tar = 0; tar <= target; tar++){
            int not_take = 0 + dp[ind-1][tar];
            int take = INT_MAX;
            if(denom[ind] <= tar) take = 1 + dp[ind][tar-denom[ind]];
            dp[ind][tar] = min(take,not_take);
        }
    }
    return dp[n-1][target];
}

int f_tab_so(int n, vector<int> denom, int target){
    vector<int> prev(target+1,0);
    for(int i = 0; i <= target; i++){
        if(i % denom[0] == 0) prev[i] = i/denom[0];
        else prev[i] = 10000000;
    }
    vector<int> curr(target+1,0);
    for(int ind = 1; ind <= n-1; ind++){
        for(int tar = 0; tar <= target; tar++){
            int not_take = 0 + prev[tar];
            int take = INT_MAX;
            if(denom[ind] <= tar) take = 1 + curr[tar-denom[ind]];
            curr[tar] = min(take,not_take);
        }
        prev = curr;
    }
    return prev[target];
}

int minimumCoins(int n, vector<int> denom, int target){
    vector< vector<int> > dp(n,vector<int>(target+1,-1));
    return f_memo(n-1,target,denom,dp);
}

int main(){
    int n;
    cin >> n;
    vector<int> denom(n);
    for(int i = 0; i < n; i++) cin >> denom[i];
    int target;
    cin >> target;

    cout << f(n-1,target,denom) << "\n";
    cout << minimumCoins(n,denom,target) << "\n";
    cout << f_tab(n,denom,target) << "\n";
    cout << f_tab_so(n,denom,target) << "\n";

    return 0;
}