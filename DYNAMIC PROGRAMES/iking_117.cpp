// UNBOUNDED KNAPSACK

#include<bits/stdc++.h>
using namespace std;

int f(int index, int max_weight, vector<int> weight, vector<int> value){
    if(index == 0){
        return (max_weight/weight[0])*value[0];
    }
    int not_take = 0 + f(index-1,max_weight,weight,value);
    int take = 0;
    if(max_weight >= weight[index]) take = value[index] + f(index,max_weight-weight[index],weight,value);
    return max(take,not_take);
}

int f_memo(int index, int max_weight, vector<int> weight, vector<int> value, vector< vector<int> > &dp){
    if(index == 0){
        return (max_weight/weight[0])*value[0];
    }
    if(dp[index][max_weight] != -1) return dp[index][max_weight];
    int not_take = 0 + f_memo(index-1,max_weight,weight,value,dp);
    int take = 0;
    if(max_weight >= weight[index]) take = value[index] + f_memo(index,max_weight-weight[index],weight,value,dp);
    return dp[index][max_weight] = max(take,not_take);
}

int f_tab(int n, vector<int> weight, vector<int> value, int max_weight){
    vector< vector<int> > dp(n,vector<int>(max_weight+1,0));
    for(int i = 0; i <= max_weight; i++) dp[0][i] = (i/weight[0])*value[0];
    for(int ind = 1; ind < n; ind++){
        for(int tar = 0; tar <= max_weight; tar++){
            int not_take = dp[ind-1][tar];
            int take = 0;
            if(tar >= weight[ind]) take = value[ind] + dp[ind][tar-weight[ind]];
            dp[ind][tar] = max(take,not_take);
        }
    }
    return dp[n-1][max_weight];
}

int f_tab_so(int n, vector<int> weight, vector<int> value, int max_weight){
    vector<int> prev(max_weight+1,0);
    for(int i = 0; i <= max_weight; i++) prev[i] = (i/weight[0])*value[0];
    for(int ind = 1; ind < n; ind++){
        for(int tar = 0; tar <= max_weight; tar++){
            int not_take = prev[tar];
            int take = 0;
            if(tar >= weight[ind]) take = value[ind] + prev[tar-weight[ind]];
            prev[tar] = max(take,not_take);
        }
    }
    return prev[max_weight];
}



int unboundedKnapsack(int n, vector<int> weight, vector<int> value,int max_weight){
    vector< vector<int> > dp(n,vector<int>(max_weight+1,-1));
    return f_memo(n-1,max_weight,weight,value,dp);
}

int main(){
    int n;
    cin >> n;
    vector<int> weight(n), value(n);
    for(int i = 0; i < n; i++) cin >> weight[i];
    for(int i = 0; i < n; i++) cin >> value[i];
    int max_weight;
    cin >> max_weight;

    cout << f(n-1,max_weight,weight,value) << "\n";
    cout << unboundedKnapsack(n,weight,value,max_weight) << "\n";
    cout << f_tab(n,weight,value,max_weight) << "\n";
    cout << f_tab_so(n,weight,value,max_weight) << "\n";
    
    return 0;
}