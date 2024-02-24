// MAXIMUM SUM OF NON - ADJACENT ELEMENTS

#include<bits/stdc++.h>
using namespace std;

int f_memo(int ind, vector<int> nums, vector<int> &dp){
    if(ind < 0) return 0;
    if(ind == 0) return nums[ind];

    if(dp[ind] != -1) return dp[ind];

    int pick = nums[ind] + f_memo(ind-2,nums,dp);
    int nonPick = 0 + f_memo(ind-1,nums,dp);

    return dp[ind] = max(pick,nonPick);
}

int f_tab(vector<int> nums){
    int n = nums.size();
    int prev = nums[0];
    int prev2 = 0;
    int curr;
    for(int i = 1; i < n; i++){
        int take = nums[i] + prev2;
        int non_take = 0 + prev;
        curr = max(take,non_take);
        prev2 = prev;
        prev = curr;
    }
    return prev;
}

int maximumNonAdjSum(vector<int> &nums){
    int n = nums.size();
    vector<int> dp(n+1,-1);
    return f_memo(n-1,nums,dp)-f_tab(nums);
}

int main(){
    int n;
    cin >> n;
    vector<int> nums(n);
    for(int i = 0; i < n; i++){
        cin >> nums[i];
    }
    cout << maximumNonAdjSum(nums);
    return 0;
}