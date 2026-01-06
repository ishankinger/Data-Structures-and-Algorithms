// FROG K JUMPS

#include<bits/stdc++.h>
using namespace std;

// using recursion
int f(int n,vector<int> heights){
    if(n == 0) return 0;
    int left = f(n-1,heights) + abs(heights[n]-heights[n-1]);
    int right = INT_MAX;
    if(n > 1) right = f(n-2,heights) + abs(heights[n]-heights[n-2]);
    return min(left,right);
}

// using memoization
int f_memo(int n, vector<int> heights, vector<int> &dp){
    if(n == 0) return 0;
    if(dp[n] != -1) return dp[n];
    int left = f_memo(n-1,heights,dp) + abs(heights[n]-heights[n-1]);
    int right = INT_MAX;
    if(n > 1) right = f_memo(n-2,heights,dp) + abs(heights[n]-heights[n-2]);
    return dp[n] = min(left,right);
}

// using tabulation space optimization
int f_tab(int n, vector<int> &heights){
    int prev2 = 0;
    int prev = 0;
    int curr;
    for(int i = 1; i < n; i++){
        int fs = prev + abs(heights[i]-heights[i-1]);
        int ss = INT_MAX;
        if(i > 1) ss = prev2 + abs(heights[i]-heights[i-2]);
        curr = min(fs,ss);
        prev2 = prev;
        prev = curr;
    }
    return prev;
}

// follow up question for same problem
int f_kJumps(int n, vector<int> &heights, int k, vector<int> &dp){
    if(n == 0) return 0;
    if(dp[n] != -1) return dp[n];
    vector<int> jumps;
    for(int i = 1; i <= k; i++){
        if(n-i < 0) break;
        int jump = f_kJumps(n-i,heights,k,dp) + abs(heights[n]-heights[n-i]);
        jumps.push_back(jump);
    }
    int minJump = INT_MAX;
    for(int i = 0; i < jumps.size(); i++){
        minJump = min(minJump,jumps[i]);
    }
    return dp[n] = minJump;
}

int frogJump(int n, vector<int> &heights){
    vector<int> dp(n+1,-1);
    return f_memo(n-1,heights,dp);
}

int frogKJumps(int n, vector<int> &heights, int k){
    vector<int> dp(n+1,-1);
    return f_kJumps(n-1,heights,k,dp);
}

int main(){
    int n; 
    cin >> n;
    vector<int> heights(n);
    for(int i = 0; i < n; i++){
        cin >> heights[i];
    }
    cout << f(n,heights) << "\n";
    cout << frogJump(n,heights) << "\n";
    cout << frogKJumps(n,heights,2) << "\n";

    return 0;
}