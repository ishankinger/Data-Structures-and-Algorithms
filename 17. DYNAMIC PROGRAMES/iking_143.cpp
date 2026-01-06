//  PARTITION ARRAY FOR MAXIMUM SUM

#include<bits/stdc++.h>
using namespace std;

int f(int ind, vector<int> v, int k){
    if(ind == v.size()) return 0;
    int n = v.size();
    int max_sum = INT_MIN;
    int maxEle = v[ind];
    for(int j = ind; j < min(n,ind+k); j++){
        maxEle = max(maxEle,v[j]);
        max_sum = max(max_sum,maxEle*(j-ind+1) + f(j+1,v,k));
    }
    return max_sum;
}

int f_memo(int ind, vector<int> v, int k, vector<int> &dp){
    if(ind == v.size()) return 0;
    if(dp[ind] != -1) return dp[ind];
    int n = v.size();
    int max_sum = INT_MIN;
    int maxEle = v[ind];
    for(int j = ind; j < min(n,ind+k); j++){
        maxEle = max(maxEle,v[j]);
        max_sum = max(max_sum,maxEle*(j-ind+1) + f_memo(j+1,v,k,dp));
    }
    return dp[ind] = max_sum;
}

int f_tab(vector<int> v, int k){
    int n = v.size();
    vector<int> dp(v.size()+1,0);
    for(int ind = v.size()-1; ind >= 0; ind--){
        int max_sum = INT_MIN;
        int maxEle = v[ind];
        for(int j = ind; j < min(n,ind+k); j++){
            maxEle = max(maxEle,v[j]);
            max_sum = max(max_sum, maxEle*(j-ind+1) + dp[j+1]);
        }
        dp[ind] = max_sum;
    }
    return dp[0];
}

int parititionArrMaxSum(vector<int> v, int k){
    vector< int > dp(v.size(),-1);
    return f_memo(0,v,k,dp);
}

int main(){
    int n;
    cin >> n;
    vector<int> v(n);
    for(int i = 0; i < n; i++) cin >> v[i];
    int k;
    cin >> k;

    cout << f(0,v,k) << "\n";
    cout << parititionArrMaxSum(v,k) << "\n";
    cout << f_tab(v,k) << "\n";



    return 0;
}