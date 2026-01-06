// BEST TIME TO BUY AND SELL THE STOCK FOLLOW UP 4TH

#include<bits/stdc++.h>
using namespace std;

int f(int index, int transNo, vector<int> prices, int n, int k){
    if(index == n or transNo == 2*k) return 0;
    if(transNo % 2 == 0){
        return max(f(index+1,transNo+1,prices,n,k)-prices[index],f(index+1,transNo,prices,n,k));
    }
    else{
        return max(f(index+1,transNo+1,prices,n,k)+prices[index],f(index+1,transNo,prices,n,k));
    }
}

int f_memo(int index, int transNo, vector<int> prices, int n, int k, vector< vector<int> > dp){
    if(index == n or transNo == 2*k) return 0;
    if(dp[index][transNo] != -1) return dp[index][transNo];
    if(transNo % 2 == 0){
        return dp[index][transNo] = max(f_memo(index+1,transNo+1,prices,n,k,dp)-prices[index],f_memo(index+1,transNo,prices,n,k,dp));
    }
    else{
        return dp[index][transNo] = max(f_memo(index+1,transNo+1,prices,n,k,dp)+prices[index],f_memo(index+1,transNo,prices,n,k,dp));
    }
}

int f_tab(vector<int> prices, int k){
    vector< vector<int> > dp(prices.size()+1,vector<int>(2*k+1,0));
    for(int index = prices.size()-1; index >= 0; index--){
        for(int transNo = 2*k-1; transNo >= 0; transNo--){
            if(transNo % 2 == 0) dp[index][transNo] = max(dp[index+1][transNo+1]-prices[index],dp[index+1][transNo]);
            else dp[index][transNo] = max(dp[index+1][transNo+1]+prices[index],dp[index+1][transNo]);
        }
    }
    return dp[0][0];
}

int f_tab_so(vector<int> prices, int k){
    vector<int> curr(2*k + 1, 0), next(2*k + 1, 0);
    for(int index = prices.size()-1; index >= 0; index--){
        for(int transNo = 2*k-1; transNo >= 0; transNo--){
            if(transNo % 2 == 0) curr[transNo] = max(next[transNo+1]-prices[index],next[transNo]);
            else curr[transNo] = max(next[transNo+1]+prices[index],next[transNo]);
        }
        next = curr;
    }
    return curr[0];
}

int maxProfit4(vector<int> prices, int k){
    vector< vector<int> > dp(prices.size(),vector<int>(2*k,-1));
    return f_memo(0,0,prices,prices.size(),k,dp);
}

int main(){
    int n;
    cin >> n;
    vector<int> v(n);
    for(int i = 0; i < n; i++) cin >> v[i];
    int k;
    cin >> k;
    cout << f(0,0,v,v.size(),k) << "\n";
    cout << maxProfit4(v,k) << "\n";
    cout << f_tab(v,k) << "\n";
    cout << f_tab_so(v,k) << "\n";
    return 0;
}