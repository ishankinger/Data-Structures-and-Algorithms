// BEST TIME TO BUY AND SELL THE STOCK 2ND

#include<bits/stdc++.h>
using namespace std;

int f(int index, int buy, vector<int> prices){
    if(index == prices.size()) return 0;
    int profit = 0;
    if(buy) profit = max(f(index+1,0,prices)-prices[index],f(index+1,1,prices));
    else profit = max(f(index+1,1,prices)+prices[index],f(index+1,0,prices));
    return profit;
}

int f_memo(int index, int buy, vector<int> prices, vector< vector<int> > &dp){
    if(index == prices.size()) return 0;
    if(dp[index][buy] != -1) return dp[index][buy]; 
    int profit = 0;
    if(buy) profit = max(f_memo(index+1,0,prices,dp)-prices[index],f_memo(index+1,1,prices,dp));
    else profit = max(f_memo(index+1,1,prices,dp)+prices[index],f_memo(index+1,0,prices,dp));
    return dp[index][buy] = profit;
}

int f_tab(vector<int> prices){
    vector< vector<int> > dp(prices.size()+1,vector<int>(2,0));
    dp[prices.size()][0] = 0, dp[prices.size()][1] = 0;
    int profit = 0;
    for(int index = prices.size()-1; index >= 0; index--){
        for(int buy = 0; buy <= 1; buy++){
            profit = 0;
            if(buy) profit = max(dp[index+1][0]-prices[index],dp[index+1][1]);
            else profit = max(dp[index+1][1]+prices[index],dp[index+1][0]);
            dp[index][buy] = profit;
        }
    } 
    return dp[0][1];
}

int f_tab_so(vector<int> prices){
    vector<int> next(2);
    vector<int> curr(2); 
    int profit = 0;
    for(int index = prices.size()-1; index >= 0; index--){
        for(int buy = 0; buy <= 1; buy++){
            profit = 0;
            if(buy) profit = max(next[0]-prices[index],next[1]);
            else profit = max(next[1]+prices[index],next[0]);
            curr[buy] = profit;
        }
        next = curr;
    }
    return curr[1];
}

int maxProfit2(vector<int> prices){
    vector< vector<int> > dp(prices.size(),vector<int>(2,-1));
    return f_memo(0,1,prices,dp);
}

int main(){
    int n;
    cin >> n;
    vector<int> v(n);
    for(int i = 0; i < n; i++) cin >> v[i];
    cout << f(0,1,v) << "\n";
    cout << maxProfit2(v) << "\n";
    cout << f_tab(v) << "\n";
    cout << f_tab_so(v) << "\n";
    return 0;
}