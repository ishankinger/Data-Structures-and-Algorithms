// ****** MAJORITY ELEMENT(> N/2) ********

// MOORE'S VOTING ALGORITHM
// In this algorithm we will be keeping track of majority and minority elements count using count
// the most frequent element will increase the count while minority elements will decrease it


#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int majorityElement(vector<int>& v) {
        //size of the given array:
        int n = v.size();
        // count
        int cnt = 0; 
        // Element
        int el; 

        //applying the algorithm:
        for (int i = 0; i < n; i++) {
            if (cnt == 0) {
                cnt = 1;
                el = v[i];
            }
            else if (el == v[i]) cnt++;
            else cnt--;
        }

        //checking if the stored element is the majority element:
        int cnt1 = 0;
        for (int i = 0; i < n; i++) {
            if (v[i] == el) cnt1++;
        }
        if (cnt1 > (n / 2)) return el;
        return -1;
    }
};

// ********* MAJORITY ELEMENTS GREATER THAN N/3 *************


// Extended Boyer Moore’s Voting Algorithm

class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int cnt1 = 0, cnt2 = 0;
        int ele1 = -1, ele2 = -1;
        for(int i = 0; i < nums.size(); i++){
            if(cnt1 == 0 and nums[i] != ele2){
                cnt1 = 1, ele1 = nums[i];
            }
            else if(cnt2 == 0 and nums[i] != ele1){
                cnt2 = 1, ele2 = nums[i];
            }
            else if(nums[i] == ele1){
                cnt1++;
            }
            else if(nums[i] == ele2){
                cnt2++;
            }
            else{
                cnt1--, cnt2--;
            }
        }
        int check1 = 0, check2 = 0;
        for(int i = 0; i < nums.size(); i++){
            if(nums[i] == ele1) check1++;
            else if(nums[i] == ele2) check2++;
        }
        if(check1 > nums.size()/3 and check2 > nums.size()/3) return {ele1,ele2};
        else if(check1 > nums.size()/3) return {ele1};
        else if(check2 > nums.size()/3) return {ele2};
        else return {};
    }
};