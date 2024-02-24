// LONGEST INCREASING SUBSEQUENCE 

#include<bits/stdc++.h>
using namespace std;

int f(int index, int prev, vector<int> nums){
    if(index == nums.size()) return 0;
    int not_take = f(index+1,prev,nums);
    int take = 0;
    if(prev == -1 or nums[index] > nums[prev]) take = 1 + f(index+1,index,nums);
    return max(take,not_take);
}

int f_memo(int index, int prev, vector<int> nums, vector< vector<int> > &dp){
    if(index == nums.size()) return 0;
    if(dp[index][prev+1] != -1) return dp[index][prev+1];
    int not_take = f_memo(index+1,prev,nums,dp);
    int take = 0;
    if(prev == -1 or nums[index] > nums[prev]) take = 1 + f_memo(index+1,index,nums,dp);
    return dp[index][prev+1] = max(take,not_take);
}

int f_tab(vector<int> nums){
    vector< vector<int> > dp(nums.size()+1,vector<int>(nums.size()+1,0));
    for(int index = nums.size()-1; index >= 0; index--){
        for(int prev = index-1; prev >= -1; prev--){
            int not_take = dp[index+1][prev+1];
            int take = 0;
            if(prev == -1 or nums[index] > nums[prev]) take = 1 + dp[index+1][index+1];
            dp[index][prev+1] = max(take,not_take);
        }
    }
    return dp[0][0];
}

int f_tab_so(vector<int> nums){
    vector<int> curr(nums.size()+1,0);
    vector<int> next(nums.size()+1,0);
    for(int index = nums.size()-1; index >= 0; index--){
        for(int prev = index-1; prev >= -1; prev--){
            int not_take = next[prev+1];
            int take = 0;
            if(prev == -1 or nums[index] > nums[prev]) take = 1 + next[index+1];
            curr[prev+1] = max(take,not_take);
        }
        next = curr;
    }
    return curr[0];
}

int f_tab_opt(vector<int> nums){
    vector<int> dp(nums.size(),1);
    for(int i = 0; i < nums.size(); i++){
        for(int prev = 0; prev < i; prev++){
            if(nums[prev] < nums[i]){
                dp[i] = max(dp[i],1+dp[prev]);
            }
        }
    }
    int ans = INT_MIN;
    for(int i = 0; i < dp.size(); i++) ans = max(ans,dp[i]);
    return ans;
}

void printLongestIncreasingSeq(vector<int> nums){
    vector<int> dp(nums.size(),1);
    vector<int> hash(nums.size());
    int maxi = 1, lastIndex = 0;
    for(int i = 0; i < nums.size(); i++){
        hash[i] = i;
        for(int prev = 0; prev < i; prev++){
            if(nums[prev] < nums[i] and 1+dp[prev] > dp[i]){
                dp[i] = 1 + dp[prev];
                hash[i] = prev;
            }
        }
        if(dp[i] > maxi){
            maxi = dp[i];
            lastIndex = i;
        }
    }

    vector<int> lsi;
    lsi.push_back(nums[lastIndex]);
    while(hash[lastIndex] != lastIndex){
        lastIndex = hash[lastIndex];
        lsi.push_back(nums[lastIndex]);
    }
    reverse(lsi.begin(),lsi.end());

    for(int i = 0; i < lsi.size(); i++) cout << lsi[i] << " ";
    cout << "\n";
}

int longestIncreasing(vector<int> nums){
    vector< vector<int> > dp(nums.size(),vector<int>(nums.size()+1,-1));
    return f_memo(0,-1,nums,dp);
}

int main(){
    int n;
    cin >> n;
    vector<int> v(n);
    for(int i = 0; i < n; i++) cin >> v[i];
    cout << f(0,-1,v) << "\n";
    cout << longestIncreasing(v) << "\n";
    cout << f_tab(v) << "\n";
    cout << f_tab_so(v) << "\n";
    cout << f_tab_opt(v) << "\n";
    printLongestIncreasingSeq(v);
    return 0;
}