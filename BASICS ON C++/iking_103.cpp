// SWAPPING OF TWO NUMBERS

#include<iostream>
using namespace std;

int main(){
    int a,b;                                         // DEFINING TWO VARIABLE OF SAME TYPE
    cin>>a>>b;                                       // TAKING INPUT FOR BOTH FROM USER
    int c;
    c=a;                                             // AT SPACE OF C VALUE OF A IS PUT
    a=b;                                             // AT SPACE OF A VALUE OF B IS PUT
    b=c;                                             // AT SPACE OF B VALUE OF C IS PUT WHICH IS A
    cout<<"value of a : "<<a<<endl;                  // NOW A AND B WILL HAVE NEW VALUES SWAPPED
    cout<<"value of b : "<<b<<endl;
    return 0;
}
// ***** SWAP WITHOT TEMPORARY VARIABLES *****

// firstNumber = firstNumber - secondNumber;
// secondNumber = firstNumber + secondNumber;
// firstNumber = secondNumber - firstNumber;