// ********* NEXT GREATER PERMUTATION *********

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        bool check_increasing = true;
        int break_increasing = -1;
        for(int i = nums.size()-1; i >= 1; i--){
            if(nums[i] > nums[i-1]){
                check_increasing = false;
                break_increasing = i;
                break;
            }
        }
        if(check_increasing){
            reverse(nums.begin(),nums.end());
            return;
        }
        int just_greater = INT_MAX;
        int just_greater_index = -1;
        for(int i = break_increasing; i < nums.size(); i++){
            if(nums[i] > nums[break_increasing-1]){
                if(just_greater > nums[i]){
                    just_greater = nums[i];
                    just_greater_index = i;
                }
            }
        }
        swap(nums[just_greater_index], nums[break_increasing - 1]);
        sort(nums.begin() + break_increasing, nums.end());
    }
};