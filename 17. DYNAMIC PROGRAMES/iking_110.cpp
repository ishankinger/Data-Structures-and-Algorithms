// SUBSET SUM EQUALS TO THE TARGET

#include<bits/stdc++.h>
using namespace std;

int f(int ind, int target, vector<int> arr){
    if(target == 0) return true;
    if(ind == 0) return (arr[0] == target);
    bool notTake = f(ind-1,target,arr);
    bool take = false;
    if(target >= arr[ind]) take = f(ind-1,target-arr[ind],arr);
    return notTake | take;
}

int f_memo(int ind, int target, vector<int> arr, vector< vector<int> > &dp){
    if(target == 0) return true;
    if(ind == 0) return (arr[0] == target);
    if(dp[ind][target] != -1) return dp[ind][target];
    bool notTake = f_memo(ind-1,target,arr,dp);
    bool take = false;
    if(target >= arr[ind]) take = f_memo(ind-1,target-arr[ind],arr,dp);
    return dp[ind][target] = (notTake | take);
}

int f_tab(vector<int> arr, int target){
    int n = arr.size();
    vector< vector<bool> > dp(n,vector<bool>(target+1,false));
    for(int i = 0; i <= n-1; i++) dp[i][0] = true;
    dp[0][arr[0]] = true;
    for(int ind = 1; ind < n; ind++){
        for(int tar = 1; tar <= target; tar++){
            bool notTake = dp[ind-1][tar];
            bool take = false;
            if(tar >= arr[ind]) take = dp[ind-1][tar-arr[ind]];  
            dp[ind][tar] = notTake | take;
        }
    }
    return dp[n-1][target];
}

int f_tab_so(vector<int> arr, int target){
    int n = arr.size();
    vector<int> prev(target+1,0);
    prev[arr[0]] = 1;
    vector<int> curr(target+1,0);
    prev[0] = 1, curr[0] = 1;
    for(int ind = 1; ind < n; ind++){
        for(int tar = 1; tar <= target; tar++){
            bool notTake = prev[tar];
            bool take = false;
            if(tar >= arr[ind]) take = prev[tar-arr[ind]];
            curr[tar] = notTake | take;
        }
        prev = curr;
    }
    return prev[target];
}

int targetSum(vector<int> arr, int target){
    vector< vector<int> > dp(arr.size(),vector<int>(target+1,-1));
    return f_memo(arr.size()-1,target,arr,dp);
}

int partitionEqualsSubsetSum(vector<int> arr){
    int sum = 0;
    for(int i = 0; i < arr.size(); i++) sum += arr[i];
    if(sum % 2 != 0) return 0;
    int target = sum / 2;
    vector< vector<int> > dp(arr.size(),vector<int>(target+1,-1));
    return f_memo(arr.size()-1,target,arr,dp);
}

int main(){

    int n;
    cin >> n;
    vector<int> arr(n);
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
    int target;
    cin >> target;
    
    cout << f(n-1,target,arr) << "\n";
    cout << targetSum(arr,target) << "\n";
    cout << f_tab(arr,target) << "\n";
    cout << f_tab_so(arr,target) << "\n";
    cout << partitionEqualsSubsetSum(arr) << "\n";

    return 0;
}