// GET TRANSPOSE FOR GIVEN 2D ARRAY( ROWS BECOMES COLS AND COLS BECOMES ROWS )

#include<iostream>
using namespace std;

int main(){
     int n=3;
     int m=3;
     int arr[m][n]={{1,2,3},
                    {4,5,6},
                    {7,8,9}};

    for(int i=0;i<m;i++){                             // SIMPLY JUST CHANGE FINAL VALUE OF I AND J
        for(int j=0;j<n;j++){
            cout<<arr[j][i]<<" ";                     // AND HERE REVERSE THE I AND J
        }
        cout<<endl;                                   // WE WILL GET TRANSPOSE
    }
}
