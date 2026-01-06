// 0/1 KNAPSACK PROBLEM

#include<bits/stdc++.h>
using namespace std;

int f(int index, int weight, int max_weight, vector< vector<int> > arr){
    if(index == 0) return 0;
    int take = INT_MIN;
    if(weight+arr[0][index-1] <= max_weight) take = f(index-1,weight+arr[0][index-1],max_weight,arr) + arr[1][index-1];
    int not_take = f(index-1,weight,max_weight,arr);
    return max(take,not_take);
}

int f_memo(int index, int weight, int max_weight, vector< vector<int> > arr, vector< vector<int> > &dp){
    if(index == 0) return 0;
    if(dp[index][weight] != -1) return dp[index][weight];
    int take = INT_MIN;
    if(weight+arr[0][index-1] <= max_weight) take = f_memo(index-1,weight+arr[0][index-1],max_weight,arr,dp) + arr[1][index-1];
    int not_take = f_memo(index-1,weight,max_weight,arr,dp);
    return dp[index][weight] = max(take,not_take);
}

int f_tab(int n, vector< vector<int> > arr, int w){
    vector< vector<int> > dp(n+1,vector<int>(w+1,0));
    for(int i = 0; i <= w; i++) dp[0][i] = 0;
    for(int ind = 1; ind <= n; ind++){
        for(int weight = 0; weight <= w; weight++){
            int take = INT_MIN;
            if(weight+arr[0][ind-1] <= w) take = dp[ind-1][weight+arr[0][ind-1]] + arr[1][ind-1];
            int not_take = dp[ind-1][weight];
            dp[ind][weight] = max(take,not_take);
        }
    }
    return dp[n][0];
}

int f_tab_so(int n, vector< vector<int> > arr, int w){
    vector<int> prev(w+1,0);
    for(int ind = 1; ind <= n; ind++){
        for(int weight = 0; weight <= w; weight++){
            int take = INT_MIN;
            if(weight+arr[0][ind-1] <= w) take = prev[weight+arr[0][ind-1]] + arr[1][ind-1];
            int not_take = prev[weight];
            prev[weight] = max(take,not_take);
        }
    }
    return prev[0];
}

int knapsack(int n, vector< vector<int> > arr, int w){
    vector< vector<int> > dp(n+1,vector<int>(w+1,-1));
    return f_memo(n,0,w,arr,dp);
}

int main(){
    int n;
    cin >> n;
    vector< vector<int> > arr(2,vector<int>(n));
    for(int i = 0; i < arr.size(); i++){
        for(int j = 0; j < arr[i].size(); j++){
            cin >> arr[i][j];
        }
    }
    int w;
    cin >> w;
    cout << f(n,0,w,arr) << "\n";
    cout << knapsack(n,arr,w) << "\n";
    cout << f_tab(n,arr,w) << "\n";
    cout << f_tab_so(n,arr,w) << "\n";

    return 0;
}