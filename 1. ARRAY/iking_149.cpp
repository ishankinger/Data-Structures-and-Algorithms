// ******** SET MATRIX ZEROS **********

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    // optimal solution using space complexity of O(1)
    void setZeroes(vector<vector<int>>& matrix) {
        
        // instead of storing the flag arrays separately to know whether the row or column contains 0 or not
        // we will be taking the first row and first column of the 2-d array as our flag arrays
        // and one intersection is there between two arrays so for 0th column flag we have taken a 'col' variable
        int col = 1;

        // first traverse in the 2-d matrix and when we get 0 then mark the flag as 0
        for(int i = 0; i < matrix.size(); i++){
            for(int j = 0; j < matrix[i].size(); j++){
                if(matrix[i][j] == 0){
                    if(j == 0) col = 0;
                    else matrix[0][j] = 0;
                    matrix[i][0] = 0;
                }
            }
        }

        // first traverse the n-1 * n-1 matrix excluding the 0th row and 0th column as if we change their values 
        // then the whole 2-d array values will be disturbed. If any row or col flag is 0 then mark that ele as 0
        for(int i = 1; i < matrix.size(); i++){
            for(int j = 1; j < matrix[i].size(); j++){
                if(matrix[i][0] == 0 or matrix[0][j] == 0){
                    matrix[i][j] = 0;
                }
            }
        }

        // now first check for the 0th row as if we check 0th column first then value of row can change
        if(matrix[0][0] == 0){
            for(int j = 0; j < matrix[0].size(); j++) matrix[0][j] = 0;
        }
        
        // thus at last check for the 0th column flag and finally we got our answer 2-d array
        if(col == 0){
            for(int i = 0; i < matrix.size(); i++) matrix[i][0] = 0;
        }
    }
};