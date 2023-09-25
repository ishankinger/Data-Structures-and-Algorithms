// ROTATION OF A MATRIX
// GIVEN A SQUARE MATRIX, TURN IT BY 90 DEGREE IN A CLOCKWISE DERECTION WITHOUT USING ANY EXTRA SPACE
// TRANSPOSE OF A MATRIX AND THEN REVERSING ALL THE ROWS

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

void rotateVec(vector<vector<int>>&vec){              // FUNCTION TO PRINT MODIFIED VECTOR THAT'S WHY TAKEN AS VOID
    for(int i=0;i<3;i++){                             // TRAVERSING IN THE VECTOR USING FOR LOOP
        for(int j=0;j<i;j++){                         // CRITICAL POINT TO BE NOTED AS WE HAVE TO CHOOSE ONLY ELEMENTS BELOW DIAGONAL ELEMENTS
            swap(vec[i][j],vec[j][i]);                // WE DO THAT BECAUSE OTHERWISE TWO TIMES SWAPPING WILL OCCUR AND WE WILL GET SAME MATRIX
        }
    }
    for(int i=0;i<3;i++){                             // NOW USING REVERSE FUNCTION WE WILL REVERSE THE ELEMENTS OF VECTOR ROWS
        reverse(vec[i].begin(),vec[i].end());
    }
    for(int i=0;i<3;i++){                             // LOOP TO PRINT THE ROTATED MATRIX
        for(int j=0;j<3;j++){
            cout<<vec[i][j]<<" ";
        }
        cout<<endl;
    }
}
int main(){
    vector<vector<int>> vec;
    vec={{1,2,3},{4,5,6},{7,8,9}};
    
    rotateVec(vec);                                     // JUST CALLING THE FUNCTION FOR THE PRINTING
}