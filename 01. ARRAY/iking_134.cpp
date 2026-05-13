// ***************** SEARCHING FOR THE NUMBER IN 2D ARRAY *******************

#include<iostream>
using namespace std;

int main(){
    int n=3;
    int m=3;
    int arr[3][3]={{1,2,3},{4,5,6},{7,8,9}};         // ANOTHER WAY TO DEFINE A 2D ARRAYS BY GIVING VALUE OUTPUTS ITSELF
                                                     // ONE CURLY BRACKET MEANS FIRST ROW AND THEN ANOTHER ROW
    int x=4;                                         // THIS TO FIND IN THE 2D ARRAY
    
    for(int i=0;i<n;i++){                            // TRAVERSING IN THE 2D ARRAY
        for(int j=0;j<m;j++){
            if(arr[i][j]==x){                        // CONDITION THAT IF SAME THEN PRINT I,J
                cout<<"given number is present at"<<"("<<i<<","<<j<<")"<<endl;
                break;
            }
        }
    }
}
