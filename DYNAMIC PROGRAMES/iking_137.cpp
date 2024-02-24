// NUMBER OF LONGEST INCREASING SUB SEQUENCES

#include<bits/stdc++.h>
using namespace std;

int countLongestIncreasingSubSequences(vector<int> nums){
    vector<int> dp(nums.size(),1);
    vector<int> count(nums.size(),1);
    int maxi = INT_MIN;
    for(int i = 0; i < nums.size(); i++){
        for(int prev = 0; prev < i; prev++){
            if(nums[prev] < nums[i] and dp[prev] + 1 > dp[i]){
                dp[i] = 1 + dp[prev];
                count[i] = count[prev];
            }
            else if(nums[prev] < nums[i] and dp[prev] + 1 == dp[i]){
                count[i] += count[prev];
            }
        }
        maxi = max(maxi,dp[i]);
    }

    int ans = 0;
    for(int i = 0; i < dp.size(); i++){
        if(dp[i] == maxi) ans += count[i];
    }
    return ans;
}

int main(){
    int n;
    cin >> n;
    vector<int> v(n);
    for(int i = 0; i < n; i++) cin >> v[i];
    cout << countLongestIncreasingSubSequences(v) << "\n";
    return 0;
}