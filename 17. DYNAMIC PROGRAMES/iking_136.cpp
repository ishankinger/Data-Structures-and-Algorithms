// LONGEST BITONIC SUB SEQUENCES

#include<bits/stdc++.h>
using namespace std;

int longestBitonicSubSequence(vector<int> nums){

    vector<int> dp1(nums.size(),1);
    for(int i = 0; i < nums.size(); i++){
        for(int prev = 0; prev < i; prev++){
            if(nums[prev] < nums[i]){
                dp1[i] = max(dp1[i],1+dp1[prev]);
            }
        }
    }

    reverse(nums.begin(),nums.end());

    vector<int> dp2(nums.size(),1);
    for(int i = 0; i < nums.size(); i++){
        for(int prev = 0; prev < i; prev++){
            if(nums[prev] < nums[i]){
                dp2[i] = max(dp2[i],1+dp2[prev]);
            }
        }
    }

    int ans = INT_MIN;
    for(int i = 0; i < nums.size(); i++){
        ans = max(ans,dp1[i]+dp2[i]-1);
    }

    return ans;
}

int main(){
    int n;
    cin >> n;
    vector<int> v(n);
    for(int i = 0; i < n; i++) cin >> v[i];
    cout << longestBitonicSubSequence(v) << "\n";
    return 0;
}