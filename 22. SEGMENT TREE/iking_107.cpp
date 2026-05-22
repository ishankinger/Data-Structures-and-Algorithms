// leetcode 3721 - https://leetcode.com/problems/longest-balanced-subarray-ii/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    void buildSegTree(int ind, int l, int r, vector<int> &arr, vector<int> &segTreeMin, vector<int> &segTreeMax){
        if(l == r){
            segTreeMin[ind] = 0;
            segTreeMax[ind] = 0;
            return;
        }

        int mid = (l + r) / 2;
        buildSegTree(2 * ind + 1, l, mid, arr, segTreeMin, segTreeMax);
        buildSegTree(2 * ind + 2, mid + 1, r, arr, segTreeMin, segTreeMax);

        segTreeMin[ind] = min(segTreeMin[2 * ind + 1], segTreeMin[2 * ind + 2]);
        segTreeMax[ind] = max(segTreeMax[2 * ind + 1], segTreeMax[2 * ind + 2]);
    }

    void rangeUpdateTree(int ind, int l, int r, int start, int end, int val, vector<int> &segTreeMin, vector<int> &segTreeMax, vector<int> &lazyTree){
        int mid = (l + r) / 2;

        segTreeMin[ind] += lazyTree[ind];
        segTreeMax[ind] += lazyTree[ind];
        if(l != r){
            lazyTree[2 * ind + 1] += lazyTree[ind];
            lazyTree[2 * ind + 2] += lazyTree[ind];
        }
        lazyTree[ind] = 0;
        
        if(l > end || r < start)
            return;

        if(l >= start && r <= end){
            segTreeMin[ind] += val;
            segTreeMax[ind] += val;
            if(l != r){
                lazyTree[2 * ind + 1] += val;
                lazyTree[2 * ind + 2] += val;
            }
            return;
        }

        rangeUpdateTree(2 * ind + 1, l, mid, start, end, val, segTreeMin, segTreeMax, lazyTree);
        rangeUpdateTree(2 * ind + 2, mid + 1, r, start, end, val, segTreeMin, segTreeMax, lazyTree);

        segTreeMin[ind] = min(segTreeMin[2 * ind + 1], segTreeMin[2 * ind + 2]);
        segTreeMax[ind] = max(segTreeMax[2 * ind + 1], segTreeMax[2 * ind + 2]);
    }

    int getLeftMostZero(int ind, int l, int r, vector<int> &segTreeMin, vector<int> &segTreeMax, vector<int> &lazyTree){
        int mid = (l + r) / 2;

        segTreeMin[ind] += lazyTree[ind];
        segTreeMax[ind] += lazyTree[ind];
        if(l != r){
            lazyTree[2 * ind + 1] += lazyTree[ind];
            lazyTree[2 * ind + 2] += lazyTree[ind];
        }
        lazyTree[ind] = 0;

        if(segTreeMin[ind] > 0 || segTreeMax[ind] < 0)
            return -1;

        if(l == r){
            if(segTreeMin[ind] == 0 && segTreeMax[ind] == 0)
                return l;
            return -1;
        }

        int leftInd = getLeftMostZero(2 * ind + 1, l, mid, segTreeMin, segTreeMax, lazyTree);
        if(leftInd != -1)
            return leftInd;

        return getLeftMostZero(2 * ind + 2, mid + 1, r, segTreeMin, segTreeMax, lazyTree);
    }

public:
    int longestBalanced(vector<int>& nums) {
        int n = nums.size();

        vector<int> segTreeMin(4 * n);
        vector<int> segTreeMax(4 * n);
        vector<int> lazyTree(4 * n);
        buildSegTree(0, 0, n - 1, nums, segTreeMin, segTreeMax);

        unordered_map<int, int> lastInd;
        int ans = 0;
        for(int i = 0; i < n; i++){

            int val = (nums[i] % 2 == 0) ? 1 : -1;
            rangeUpdateTree(0, 0, n - 1, 0, i, val, segTreeMin, segTreeMax, lazyTree);

            if(lastInd.find(nums[i]) != lastInd.end())
                rangeUpdateTree(0, 0, n - 1, 0, lastInd[nums[i]], -val, segTreeMin, segTreeMax, lazyTree);

            int ind = getLeftMostZero(0, 0, n - 1, segTreeMin, segTreeMax, lazyTree);
            if(ind != -1)
                ans = max(ans, i - ind + 1);

            lastInd[nums[i]] = i;
        }

        return ans;
    }
};