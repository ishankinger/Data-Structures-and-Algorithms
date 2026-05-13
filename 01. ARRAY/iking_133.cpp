// ******************* 2-D ARRAYS ******************
// ( DATATYPE_NAME_[ROW][COL] )
// 2-D ARRAYS ARE SIMPLY MATRIX OF SIZE ROW*COL HAVING TOTAL ELEMENTS N*M

#include<iostream>
using namespace std;

int main(){
    int n,m;                                           // TWO INTEGERS VARIABLES TO BE
    cin>>n>>m;                                         // TAKEN AS AN INPUT

    int arr[n][m];                                     // DEFINING A 2D ARRAY OF ROWS N AND COLS M
    
    for(int i=0;i<n;i++){                              // SIMILAR TO PRINTING OF A RECTANGULAR PATTERN WE CAN RELATE SAME FUNDA HERE ALSO
        for(int j=0;j<m;j++){
            cin>>arr[i][j];                            // ARRAY AT I,J OF THE GRAPH HAVING I AND J STARTING FROM THE 0
        }                                              // i=> ROWS AND j=> COLS
    }
    cout<<"Matrix is "<< endl;

    for(int i=0;i<n;i++){                              // NOW SIMILARLY WE CAN TAKE OUTPUT OF OUT 2D ARRAY
        for(int j=0;j<m;j++){
            cout<<arr[i][j]<<" ";
        }
        cout<<endl;                                    // TO GIVE NEXT LINE TO THE PRINTING
    }
}
// MULTIDIMENSIONAL ARRAYS --> ARRAY OF ARRAYS
// DATATYPE[][][][]....[N] WILL GIVE N DIMENSIONAL ARRAY
// THEY ARE USED IN REPRESENTING GRIDS
// FASTER AND SIMILAR ACCESS
// PREDEFINED SIZE
