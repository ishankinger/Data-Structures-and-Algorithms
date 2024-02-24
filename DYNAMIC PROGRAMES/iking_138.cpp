// MATRIX CHAIN MULTIPICATION

#include<bits/stdc++.h>
using namespace std;

int f(int i, int j, vector<int> arr){
    if(i == j) return 0;
    int minSteps = INT_MAX;
    for(int k = i; k <= j-1; k++){
        minSteps = min(minSteps,(arr[i-1]*arr[k]*arr[j]) + f(i,k,arr) + f(k+1,j,arr));
    }
    return minSteps;
}

int f_memo(int i, int j, vector<int> arr, vector< vector<int> > &dp){
    if(i == j) return 0;
    if(dp[i][j] != -1) return dp[i][j];
    int minSteps = INT_MAX;
    for(int k = i; k <= j-1; k++){
        minSteps = min(minSteps,(arr[i-1]*arr[k]*arr[j]) + f(i,k,arr) + f(k+1,j,arr));
    }
    return dp[i][j] = minSteps;
}

int f_tab(vector<int> arr){
    vector< vector<int> > dp(arr.size(),vector<int>(arr.size(),0));
    int minSteps = 0;
    for(int i = arr.size()-1; i >= 1; i--){
        for(int j = i + 1; j <= arr.size()-1; j++){
            minSteps = INT_MAX; 
            for(int k = i; k < j; k++){
                minSteps = min(minSteps, ((arr[i-1] * arr[k] * arr[j]) + dp[i][k] + dp[k+1][j]));
            }
            dp[i][j] = minSteps;
        }
    }
    return dp[1][arr.size()-1];
}

int mcm(vector<int> v){
    vector< vector<int> > dp(v.size(),vector<int>(v.size(),-1));
    return f_memo(1,v.size()-1,v,dp);
}

int main(){
    int n;
    cin >> n;
    vector<int> v(n);
    for(int i = 0; i < n; i++) cin >> v[i];
    cout << f(1,n-1,v) << "\n";
    cout << mcm(v) << "\n";
    cout << f_tab(v) << "\n";
    return 0;
}