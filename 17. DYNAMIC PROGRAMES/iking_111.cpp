// PARTITION SUBSETS SUCH THAT ABSOLUTE DIFFERENCE OF SUM OF SUBSETS IS MINIMUM

#include<bits/stdc++.h>
using namespace std;

int partitionSubsetsMinimumDifference(vector<int> arr){
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
    int ans = INT_MAX;
    for(int i = 0; i < prev.size(); i++){
        if(prev[i]) ans = min(ans,abs(i - (target - i)));
    }
    return ans;
}

int main(){

    int n;
    cin >> n;
    vector<int> arr(n);
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
    cout << partitionSubsetsMinimumDifference(arr) << "\n";

    return 0;
}