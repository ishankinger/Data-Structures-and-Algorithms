// **************** TARGET SUM PROBLEM USING TWO POINTER CONCEPT GIVEN ARRAY IS SORTED ***************

// GIVEN A SORTED ARRAY AND WE HAVE TO GET TWO ELEMENTS HAVING SUM EQUAL TO K
// ALSO IF NOT SORTED ARRAY THEN WE CAN SORT IT USING O(NLOG(N)) WHICH WILL BE BETTER THEN TWO NESTED LOOPS
// KEEPING OUR MAIN FOCUS TO WRITE AN EFFICIENT CODE FOR A PROBLEM THIS SMALL VARIATION OF SORTING WILL HELP US IN WRITTING 
// CODE IN O(N) INSTEAD OF USING BRUTE FORCE METHOD OF O(N2) (TARGET SUM PAIR)

#include<bits/stdc++.h>
using namespace std;

int main(){
    int n; cin>>n;
    int arr[n];
    for(int i=0;i<n;i++) cin>>arr[i];
    int k; cin>>k;
    int pt1=0,pt2=n-1;
    while(pt1<pt2){                               // TWO POINTERS ONE FROM END AND OTHER FROM START 
        int sum=arr[pt1]+arr[pt2];                // GET THEIR SUM
        if(sum==k) break;                         // ACCORDING TO COMPARANCE WITH GIVEN SUM MOVE ONE OF THEM
        else if(sum>k) pt2--;
        else pt1++;
    }
    cout<<arr[pt1]<<" "<<arr[pt2]<<"\n";

// GIVEN A SORTED ARRAY AND WE HAVE TO GET THREE ELEMENTS TO GET SUM EQUAL TO K
// DONE WITH O(N^2) INSTEAD OF USING THREE NESTED LOOPS
   
   int n; cin>>n;
   int arr[n];
   for(int i=0;i<n;i++) cin>>arr[i];
   int k; cin>>k;

   for(int i=0;i<n;i++){
        int sum=k-arr[i];                                  // THREE SUM PROBLEM CONVERTED INTO TWO SUM PROBLEM
        int pt1=i+1,pt2=n-1;                               // SO TIME COMPLEXITY WILL BE O(N^2)
        bool check=false;
        while(pt1<pt2){
            int currSum=arr[pt1]+arr[pt2];
            if(sum==currSum){
                check=true;
                break;
            }
            else if(sum>currSum) pt1++;
            else pt2--;
        }
        if(check){
            cout<<i<<" "<<pt1<<" "<<pt2<<"\n";
            break;
        }
   }
    return 0;
}

// ABOVE THREE SUM PROBLEM RETURNING ONLY UNIQUE SUBSETS

vector<vector<int>> threeSum(vector<int>& nums) {
    vector< vector<int> > finalAns;
    sort(nums.begin(),nums.end());
    for(int i = 0; i < nums.size(); i++){
        // EQUAL ELEMENTS SO CONTIUE
        if (i > 0 && nums[i] == nums[i - 1]) continue;
        int front = i+1, back = nums.size()-1;
        while(front < back){
            if(nums[i] + nums[front] + nums[back] == 0){
                finalAns.push_back({nums[i],nums[front],nums[back]});
                front++, back--;
                // LOOP TILL WE DONOT GET UNEQUAL ELEMENT
                while (front < back && nums[front] == nums[front - 1]) front++;
                while (front < back && nums[back] == nums[back + 1]) back--;
            }
            else if(nums[i] + nums[front] + nums[back] < 0){
                front++;
            }
            else if(nums[i] + nums[front] + nums[back] > 0){
                back--;
            }
        }
    }
    return finalAns;
}

// ****** 4 SUM PROBLEM *********

vector<vector<int>> fourSum(vector<int>& nums, int target) {
    //size of the array
    int n = nums.size(); 
    vector<vector<int>> ans;

    // sort the given array:
    sort(nums.begin(), nums.end());

    //calculating the quadruplets:
    for (int i = 0; i < n; i++) {
        // avoid the duplicates while moving i:
        if (i > 0 && nums[i] == nums[i - 1]) continue;
        for (int j = i + 1; j < n; j++) {
            // avoid the duplicates while moving j:
            if (j > i + 1 && nums[j] == nums[j - 1]) continue;

            // 2 pointers:
            int k = j + 1;
            int l = n - 1;
            while (k < l) {
                long long sum = nums[i];
                sum += nums[j];
                sum += nums[k];
                sum += nums[l];
                if (sum == target) {
                    vector<int> temp = {nums[i], nums[j], nums[k], nums[l]};
                    ans.push_back(temp);
                    k++; l--;

                    //skip the duplicates:
                    while (k < l && nums[k] == nums[k - 1]) k++;
                    while (k < l && nums[l] == nums[l + 1]) l--;
                }
                else if (sum < target) k++;
                else l--;
            }
        }
    }
    return ans;
}