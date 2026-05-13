// **************** 2D VECTORS ******************
// ( VECTOR<VECTOR<INT>>NAME(ROWS, COLS--> THAT IS A VECTOR<INT>(NUMBER OF COLS)))
// THESE ARE VECTORS OF VECTOR DATATYPE

#include<iostream>
#include<vector>
using namespace std;
 
int main(){
 
    vector<vector<int>>vec(3,vector<int>(4));                  // (ROWS,COLUMNS)
    vec={{1,2,3,4},{5,6,7},{9,11}};                            // DEFINING THE ELEMENTS OF THE VECTOR
    for(int i=0;i<vec.size();i++){                             // SIMILAR PROCESS TO PRINT THE 2D ARRAYS
        for(int j=0;j<vec[i].size();j++){
            cout<<vec[i][j]<<" ";
        }
        cout<<endl;
    }
    
    vector<int>v1={1,2,3};                            // DEFINING THE 1D VECTORS
    vector<int>v2={4,5,6};
    vector<int>v3={7,8,9};
 
    vector<vector<int>>newVec={v1,v2,v3};             // COMPILATION OF 1D ARRAYS TO GET ONE 2D ARRAY
    for(int i=0;i<3;i++){                             // THEN PRINTING
        for(int j=0;j<3;j++){
            cout<<newVec[i][j]<<" ";
        }
        cout<<endl;
    }
}
