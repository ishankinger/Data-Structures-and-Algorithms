// TARGET SUM

#include<bits/stdc++.h>
using namespace std;

int f(int index, int target, vector<int> v){
    if(index == 0){
        if(target == 0 and v[0] == 0) return 2;
        if(target + v[0] == 0 || target - v[0] == 0) return 1;
        else return 0;
    }
    int pos = f(index-1,target-v[index],v);
    int neg = f(index-1,target+v[index],v);
    return pos + neg;
}

int f_memo(int index, int target, vector<int> v, vector< vector<int> > &dp, int trim){
    if(index == 0){
        if(target == 0 and v[0] == 0) return 2;
        if(target + v[0] == 0 || target - v[0] == 0) return 1;
        else return 0;
    }
    if(dp[index][target-trim] != -1) return dp[index][target-trim];
    int pos = f_memo(index-1,target-v[index],v,dp,trim);
    int neg = f_memo(index-1,target+v[index],v,dp,trim);
    return dp[index][target-trim] = pos + neg;
}

int targetSumWays(int n, vector<int> v, int target){
    int sum = 0;
    for(int i = 0; i < n; i++) sum += v[i];
    vector< vector<int> > dp(n,vector<int>(2*sum + 1,-1));
    int trim = (sum*(-1)) + target;
    int ans = f_memo(n-1,target,v,dp,trim);
    return ans;
}

int main(){
    int n;
    cin >> n;
    vector<int> v(n);
    for(int i = 0; i < n; i++) cin >> v[i];
    int target;
    cin >> target;

    cout << f(n-1,target,v) << "\n";
    cout << targetSumWays(n,v,target) << "\n";
    return 0;
}