#include <iostream>
#include <vector>
using namespace std;

int func(int ind, int sum, int tight, string &k, int d, int M, int n, vector<vector<vector<int>>> &dp){
    
    if(ind == n)
        return (sum % d == 0);
    
    if(dp[ind][sum][tight] != -1)
        return dp[ind][sum][tight];

    int cnt = 0;
    int upper_bound = (tight == 1) ? (k[ind] - '0') : 9;

    for(int digit = 0; digit <= upper_bound; digit++)
        cnt = (cnt + func(ind + 1, (sum + digit) % d, tight && (digit == upper_bound), k, d, M, n, dp)) % M;

    return dp[ind][sum][tight] = cnt;
}

int main(){

    string k;
    cin >> k;

    int d;
    cin >> d;

    int n = k.size();
    int M = 1e9 + 7;

    vector<vector<vector<int>>> dp(n, vector<vector<int>>(d+1, vector<int>(2, -1)));
    cout << (func(0, 0, 1, k, d, M, n, dp) - 1 + M) % M << "\n";

    return 0;
}