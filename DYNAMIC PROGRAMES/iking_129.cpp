// BEST TIME TO BUY AND SELL THE STOCK FOLLOW UP 3RD

#include<bits/stdc++.h>
using namespace std;

int f(int index, int buy, int cap, vector<int> prices){
    if(cap == 2) return 0;
    if(index == prices.size()) return 0;
    int profit = 0;
    if(buy) profit = max(f(index+1,0,cap,prices)-prices[index],f(index+1,1,cap,prices));
    else profit = max(f(index+1,1,cap+1,prices)+prices[index],f(index+1,0,cap,prices));
    return profit;
}

int f_memo(int index, int buy, int cap, vector<int> prices, vector< vector< vector<int> > > &dp){
    if(cap == 2) return 0;
    if(index == prices.size()) return 0;
    if(dp[index][buy][cap] != -1) return dp[index][buy][cap];
    int profit = 0;
    if(buy) profit = max(f_memo(index+1,0,cap,prices,dp)-prices[index],f_memo(index+1,1,cap,prices,dp));
    else profit = max(f_memo(index+1,1,cap+1,prices,dp)+prices[index],f_memo(index+1,0,cap,prices,dp));
    return dp[index][buy][cap] = profit;
}

int f_tab(vector<int> prices){
    vector< vector< vector<int> > > dp(prices.size()+1,vector< vector<int> >(2,vector<int>(3,0)));
    for(int i = 0; i < 2; i++){
        for(int j = 0; j < 3; j++){
            dp[prices.size()][i][j] = 0;
        }
    }
    for(int index = prices.size()-1; index >= 0; index--){
        int profit = 0;
        for(int buy = 0; buy <= 1; buy++){
            for(int cap = 0; cap <= 2; cap++){
                profit = 0;
                if(buy == 0 and cap+1 > 2){
                    dp[index][buy][cap] = 0;
                    continue;
                }
                if(buy) profit = max(dp[index+1][0][cap]-prices[index],dp[index+1][1][cap]);
                else profit = max(dp[index+1][1][cap+1]+prices[index],dp[index+1][0][cap]);
                dp[index][buy][cap] = profit;
            }
        } 
    }
    return dp[0][1][0];
}

int f_tab_so(vector<int> prices){
    vector< vector<int> > next(2,vector<int>(3,0));
    vector< vector<int> > curr(2,vector<int>(3,0));
    for(int i = 0; i < 2; i++){
        for(int j = 0; j < 3; j++){
            next[i][j] = 0;
        }
    }
    for(int index = prices.size()-1; index >= 0; index--){
        int profit = 0;
        for(int buy = 0; buy <= 1; buy++){
            for(int cap = 0; cap <= 2; cap++){
                profit = 0;
                if(buy == 0 and cap+1 > 2){
                    curr[buy][cap] = 0;
                    continue;
                }
                if(buy) profit = max(next[0][cap]-prices[index],next[1][cap]);
                else profit = max(next[1][cap+1]+prices[index],next[0][cap]);
                curr[buy][cap] = profit;
            }
        }
        next = curr; 
    }
    return curr[1][0];
}

int maxProfit3(vector<int> prices){
    vector< vector< vector<int> > > dp(prices.size(),vector< vector<int> >(2,vector<int>(3,-1)));
    return f_memo(0,1,0,prices,dp);
}

int main(){
    int n;
    cin >> n;
    vector<int> v(n);
    for(int i = 0; i < n; i++) cin >> v[i];
    cout << f(0,1,0,v) << "\n";
    cout << maxProfit3(v) << "\n";
    cout << f_tab(v) << "\n";
    cout << f_tab_so(v) << "\n";
    return 0;
}