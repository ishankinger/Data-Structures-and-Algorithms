// SIMPLE EXAMPLE ON POINTERS
// WITHOUT DIRECTLY USING THE VARIBLES WE ARE ADDING THE NUMBERS USING CONCEPT OF DEREFERENCING THE POINTERS

#include<iostream>
#include<cmath>
using namespace std;

int main(){
    
    int x=10;
    int y=20;

    int *ptr1=&x;                        // INT POINTERS ARE DEFINED FOR X AND Y VARIABLES
    int *ptr2=&y;

    int result;
    int *ptrResult =&result;             // INT POINTER FOR THE RESULT

    *ptrResult= *ptr1 + *ptr2;           // NOW WE ARE SIMPLY USING POINTERS IN PLACE OF VARIABLES AS SHOWN

    cout<<result<<endl;                  // AT END RESULT IS PRINTED
    return 0;
}
    


