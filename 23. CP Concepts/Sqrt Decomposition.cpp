// Square Root Decomposition (Sqrt Decomposition)
// Square Root Decomposition is a technique where we divide an array into blocks of size approximately N
// and store some precomputed information for each block.
// The goal is to answer range queries faster than O(N) while keeping updates reasonably efficient.

// https://leetcode.com/problems/number-of-pairs-after-increment/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> numberOfPairs(vector<int>& nums1, vector<int>& num2, vector<vector<int>>& queries) {
        int n = nums1.size();
        int m = num2.size();
        int q = queries.size();

        int block_size = sqrt(m);
        int num_blocks = (m + block_size - 1) / block_size;

        vector<long long> nums2(m);
        vector<unordered_map<long long, int>> freqArr(num_blocks);
        for(int i = 0; i < m; i++){
            nums2[i] = num2[i];
            freqArr[i / block_size][nums2[i]]++;
        }

        vector<long long> toAdd(num_blocks);
        vector<int> qAns;
        for(int i = 0; i < q; i++){
            if(queries[i][0] == 1){
                int l = queries[i][1];
                int r = queries[i][2];
                int val = queries[i][3];

                int block_l = l / block_size;
                int block_r = r / block_size;

                if(block_l != block_r && m >= 100){
                    for(int j = l; j < (block_l + 1) * block_size; j++){
                        if(--freqArr[block_l][nums2[j]] == 0)
                            freqArr[block_l].erase(nums2[j]);
                        nums2[j] += val;
                        freqArr[block_l][nums2[j]]++;
                    }
                    for(int j = block_r * block_size; j <= r; j++){
                        if(--freqArr[block_r][nums2[j]] == 0)
                            freqArr[block_r].erase(nums2[j]);
                        nums2[j] += val;
                        freqArr[block_r][nums2[j]]++;
                    }
                    for(int j = block_l + 1; j <= block_r - 1; j++)
                        toAdd[j] += val;
                }
                else{
                    for(int j = l; j <= r; j++){
                        if(--freqArr[j / block_size][nums2[j]] == 0)
                            freqArr[j / block_size].erase(nums2[j]);
                        nums2[j] += val;
                        freqArr[j / block_size][nums2[j]]++;
                    }
                }
            }
            else{
                int ans = 0;
                for(int j = 0; j < n; j++){
                    long long need = queries[i][1] - nums1[j];
                    for(int k = 0; k < num_blocks; k++){
                        auto it = freqArr[k].find(need - toAdd[k]);
                        if(it != freqArr[k].end())
                            ans += it->second;
                    }
                }
                qAns.push_back(ans);
            }
        }

        return qAns;
    }
};