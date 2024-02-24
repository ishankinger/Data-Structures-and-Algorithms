// FIBONACCI SERIES

#include<bits/stdc++.h>
using namespace std;

// memoization way (top down dp)
int fib(int n, vector<int> dp){
    if(n <= 1) return n;
    if(dp[n] != -1) return dp[n];
    return dp[n] = fib(n-1,dp) + fib(n-2,dp);
}

// A tail recursive function to
// calculate n th fibonacci number
int fib_tail_rec(int n, int a = 0, int b = 1)
{
    if (n == 0)
        return a;
    if (n == 1)
        return b;
    return fib_tail_rec(n - 1, b, a + b);
}

int main(){
    int n;
    cin >> n;
    vector<int> dp(n+1,-1);
    cout << fib(n,dp);

// tabulation way (bottom up dp)
    int prev2 = 0;
    int prev = 1;
    int curr;
    for(int i = 2; i <= n; i++){
        curr = prev + prev2;
        prev2 = prev;
        prev = curr;
    }
    cout << curr;

    return 0;
}