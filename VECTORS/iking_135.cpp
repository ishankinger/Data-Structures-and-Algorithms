// *************** SPIRAL ORDER TRAVERSAL IN 2D ARRAY MATRIX ******************

#include<iostream>
using namespace std;

int main(){
   
    int n=3;
    int m=3;
    int arr[3][3]={{1,2,3},                                     // A 2D ARRAY IS DEFINED
                   {4,5,6},
                   {7,8,9}};                    

    int row_start=0;                                            // FOUR VARIABLES WHICH HELP TO TRAVERSE IN THE LOOP
    int row_end=n-1;
    int col_start=0;
    int col_end=m-1;

    while(row_start<=row_end && col_start<=col_end){

        for(int i=col_start; i<=col_end;i++){                   // FOR FIRST WE WILL TRAVERSE IN FIRST ROW THAT IS KEEPING I=0
            cout<<arr[row_start][i]<<" ";                       // MOVING THE COLUMN FROM 0 TO N-1
        }
        row_start++;                                            // AND NOW WE JUMP TO ANOTHER ROW

        for(int i=row_start;i<=row_end;i++){                    // NOW KEEPING COLUMN SAME THAT IS N-1 WE TRAVERSE DOWN BY INCREASING ROW
            cout<<arr[i][col_end]<<" ";                         // PRINTING THE LAST COLUMN
        }
        col_end--;                                              // NOW WE JUMP TO ANOTHER COLUMN

        for(int i=col_end;i>=col_start;i--){                    // KEEPING I SAME WE MOVE IN THE ROW BY DECREASING COL VARIABLE
            cout<<arr[row_end][i]<<" ";
        }
        row_end--;                                              // NOW MAKING A JUMP TO ANOTHER ROW

        for(int i=row_end;i>=row_start;i--){                    // KEEPING COLUMN SAME DECREASING ROW NO. TO TRAVERSE
            cout<<arr[i][col_start]<<" ";
        }
        col_start++;                                            // AND NOW JUMPING TO ANOTHER COLUMN
    }
    return 0;
}
