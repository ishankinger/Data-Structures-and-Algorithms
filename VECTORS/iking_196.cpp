// PASCAL'S TRIANGLE PROBLEM ( CAN BE WRITTEN IN THE FORM OF iCj WHERE i=ROWS AND j=COLS )

#include<iostream>
#include<vector>
using namespace std;

int factorial(int n){
    int factorial=1;
    for(int i=n;i>=1;i--){
        factorial *= i;
    }
    return factorial;
}

int element(int i, int j){
    int factorialOfI=factorial(i);
    int factorialOfJ=factorial(j);
    int factorialOfDiff=factorial(i-j);
    int denominator=factorialOfJ*factorialOfDiff;
    int numerator=factorialOfI;
    return numerator/denominator;
}

int main(){
    for(int i=0;i<=6;i++){
        for(int j=1;j<=7-i;j++){
            cout<<" ";
        }
        for(int j=0;j<=i;j++){
            cout<<element(i,j)<<" ";
        }
        cout<<endl;
    }
    
    // ANOTHER APPROACH OF THE ABOVE QUESTION( ELE[I][J]= ELE[I-1][J]+ELE[I-1])[J-1] )
    

















    return 0;
}
  