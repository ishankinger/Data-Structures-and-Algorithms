// COUNT SUBSETS WITH SUM K

#include<bits/stdc++.h>
using namespace std;

int f_memo(int index, int k, vector<int> arr, vector< vector<int> > dp){
    if(k == 0) return 1;
    if(index == 0){
        if(k == arr[0]) return 1;
        else return 0;
    }
    if(dp[index][k] != -1) return dp[index][k];
    int take = 0;
    if(k >= arr[index]) take = f_memo(index-1,k-arr[index],arr,dp);
    int not_take = f_memo(index-1,k,arr,dp);
    return dp[index][k] = not_take + take;
}

int f_tab(int k, vector<int> arr){
    vector< vector<int> > dp(arr.size(),vector<int>(k+1,0));
    for(int i = 0; i < arr.size(); i++) dp[i][0] = 1;
    dp[0][arr[0]] = 1;
    for(int ind = 1; ind < arr.size(); ind++){
        for(int tar = 0; tar <= k; tar++){
            int not_take = dp[ind-1][tar];
            int take = 0;
            if(tar >= arr[ind]) take = dp[ind-1][tar-arr[ind]];
            dp[ind][tar] = not_take + take;
        }
    }
    return dp[arr.size()-1][k];
}

int countSubsetsSumK(vector<int> arr, int k){
    int index = arr.size()-1;
    vector< vector<int> > dp(arr.size(),vector<int>(k+1,-1));
    return f_memo(index,k,arr,dp);
}

int partitionWithGivenDiff_Disjoint(vector<int> arr, int d){
    int index = arr.size()-1;
    int k = 0;
    for(int i = 0; i < arr.size(); i++) k += arr[i];
    k -= d;
    if(k % 2 != 0) return 0;
    k = k/2;
    vector< vector<int> > dp(arr.size(),vector<int>(k+1,-1));
    return f_memo(index,k,arr,dp);
}

int partitionWithGivenDiff_Joint(vector<int> arr, int d){
    int target = 0;
    for(int i = 0; i < arr.size(); i++) target += arr[i];
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
    vector<int> sumArr;
    for(int i = 0; i < prev.size(); i++){
        if(prev[i]) sumArr.push_back(i);
    }
    int count = 0;
    for(int i = 0; i < sumArr.size(); i++){
        for(int j = i+1; j < sumArr.size(); j++){
            if(sumArr[j] - sumArr[i] == d) count++;
        }
    }
    return count;
}


int main(){
    int n;
    cin >> n;
    vector<int> arr(n);
    for(int i = 0; i < arr.size(); i++) cin >> arr[i];
    int k;
    cin >> k;
    int d;
    cin >> d;

    cout << countSubsetsSumK(arr,k) << "\n";
    cout << f_tab(k,arr) << "\n";
    cout << partitionWithGivenDiff_Disjoint(arr,d) << "\n";
    cout << partitionWithGivenDiff_Joint(arr,d) << "\n";

    return 0;
}