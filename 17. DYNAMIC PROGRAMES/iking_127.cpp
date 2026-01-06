// BEST TIME TO BUY AND SELL THE STOCK

#include<bits/stdc++.h>
using namespace std;

int maxProfit(vector<int> price){
    int cost = 0, profit = 0, minimum = price[0];
    for(int i = 1; i < price.size(); i++){
        cost = price[i] - minimum;
        profit = max(profit,cost);
        minimum = min(minimum,price[i]);
    }
    return profit;
}

int main(){
    int n;
    cin >> n;
    vector<int> prices(n);
    for(int i = 0; i < n; i++) cin >> prices[i];
    cout << maxProfit(prices);
    return 0;
}