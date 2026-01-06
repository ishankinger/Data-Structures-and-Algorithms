// ************** BINARY SEARCH IN 2-D MATRIX ****************
// FOR SIMPLE TIME COMPLEXITY WILL BE N.M
// BUT WE WANT TO DO BETTER SO,..
//          |<X| |X|
//               |>X|

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int main(){
     int arr[4][4]= {{1,4,7,11},{2,5,8,12},{3,6,9,16},{10,13,14,17}};  // CREATING A SORTED ARRAY ROWWISE
     for(int i=0;i<4;i++){                                             // PRINTING THE ARRAY 
        for(int j=0;j<4;j++){
            cout<<arr[i][j]<<" ";
        }
        cout<<endl;
     }
     int r=0, c=3;                                                     // MAKING ROW AND COLUMN VARIABLE INTIALISING IT WITH THE CORNER ONE ON UPPER RIGHT                                                
     int target=5;                                                     // ELEMENT TO FOUND IN THE 2D ARRAY                                               
     bool found=false;                                                 // VARIABLE TO CHECK WHETHER ELEMENT IS PRESENT OR NOT
     while(r<4){                                                       // TILL R=3 THIS WILL MOVE
        if(arr[r][c]== target){
            found=true;
            break;
        }
        else if(arr[r][c]>target){                                      // IF IT IS GREATER THEN
            c--;                                                        // WE WILL MOVE UP TO THE COL WHICH WILL BE SHORTER
        }
        else{                                                           // IF IT IS GREATER THEN
            r++;                                                        // THEN MOVE FURTHER IN THE ROW WHICH IS GREATER
        }
     }
     if(found){
        cout<<"elemet found";
     }else{
        cout<<"element not found";
     }
}

// ********** SEARCH IN A 2-D MATRIX ***********

bool searchMatrix(vector<vector<int>>& matrix, int target) {
    int n = matrix.size();
    int m = matrix[0].size();
    int low = 0;
    int high = n*m - 1;
    int mid, i_mid, j_mid;
    while(low <= high){
        mid = (low + high)/2;
        i_mid = mid / m;
        j_mid = mid % m;
        if(matrix[i_mid][j_mid] > target){
            high = mid - 1;
        }
        else if(matrix[i_mid][j_mid] < target){
            low = mid + 1;
        }
        else return true;
    }
    return false;
}