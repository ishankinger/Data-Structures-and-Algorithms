// *********** UNIQUE PATHS ************

// Most optimal solution using Combinatorics
// Observation : to reach at corner we have to take n-1 steps down and m-1 steps right for grid n*m
// Total m + n - 2 steps to be needed and place m - 1 as R and n - 1 as D
// so ans = (m+n-2)C(m-1) or (m+n-2)C(n-1)

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int uniquePaths(int m, int n) {
        int N = n + m - 2;
        int r = m - 1; 
        double res = 1;
        
        for (int i = 1; i <= r; i++) res = res * (N - r + i) / i;
        return (int)res;
    }
};