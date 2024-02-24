// LARGEST DIVISIBLE SUB SET

#include<bits/stdc++.h>
using namespace std;

void printLongestDivisibleSubset(vector<int> nums){
    vector<int> dp(nums.size(),1);
    vector<int> hash(nums.size());
    int maxi = 1, lastIndex = 0;
    for(int i = 0; i < nums.size(); i++){
        hash[i] = i;
        for(int prev = 0; prev < i; prev++){
            if(nums[i] % nums[prev] == 0 and 1+dp[prev] > dp[i]){
                dp[i] = 1 + dp[prev];
                hash[i] = prev;
            }
        }
        if(dp[i] > maxi){
            maxi = dp[i];
            lastIndex = i;
        }
    }

    vector<int> lds;
    lds.push_back(nums[lastIndex]);
    while(hash[lastIndex] != lastIndex){
        lastIndex = hash[lastIndex];
        lds.push_back(nums[lastIndex]);
    }
    reverse(lds.begin(),lds.end());

    for(int i = 0; i < lds.size(); i++) cout << lds[i] << " ";
    cout << "\n";
}


int main(){
    int n;
    cin >> n;
    vector<int> v(n);
    for(int i = 0; i < n; i++) cin >> v[i];
    sort(v.begin(),v.end());
    printLongestDivisibleSubset(v);
    return 0;
}