// MATRIX MULTIPICATION( {N1*N2} * {N2*N3} == {N1*N3} )

#include<iostream>
using namespace std;

int main(){
    int arr1[3][4]={{1,3,5,7},{2,7,5,4},{3,8,9,5}};                               // FIRST ARRAY
    int arr2[4][5]={{1,6,3,9,3},{9,4,2,5,1},{8,5,2,4,1},{4,7,3,2,2}};             // SECOND ARRAY
    
    for(int i=0;i<3;i++){                                                         // PRINTING OF THE FIRST ARRAY
        for(int j=0;j<4;j++){
            cout<<arr1[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
    
    for(int i=0;i<4;i++){                                                         // PRINTING OF THE SECOND ARRAY
        for(int j=0;j<5;j++){
            cout<<arr2[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<endl;

    int ansArr[3][5];                                                             // MAKING AN ANSWER ARRAY
    for(int i=0;i<3;i++){                                                         // FIRST PRINTING ALL ELEMENTS OF THE ANS TO BE 0
        for(int j=0;j<5;j++){
            ansArr[i][j]=0;
        }
    }

    for(int i=0;i<3;i++){                                                         // FOR ROWS
        for(int j=0;j<5;j++){                                                     // FOR COLS
            for(int k=0;k<4;k++){                                                 // FOR TRAVERSING IN ONE'S ROW AND OTHERS COLS 
                ansArr[i][j] += arr1[i][k]*arr2[k][j];                            // PRINTING OF ADDITTION OF CONSECUTIVE MULTIPICATION
            }
        }
    }

    for(int i=0;i<3;i++){                                                         // THEN PRINTING OF THE ANSWER ARRAY
        for(int j=0;j<5;j++){
            cout<<ansArr[i][j]<<"  ";
        }
        cout<<endl;
    }

    
}