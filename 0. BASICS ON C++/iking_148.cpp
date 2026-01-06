// POINTER ARITHEMETIC
// TWO TYPES OF OPERATION ==> INCREMENT AND DECREMENT
// THESE ARE DIFFERENT FROM INTEGER ARITHEMETIC

// 1. INCREMENT ==> THIS REFERS TO SHIFT IN MEMORY LOCATION THAT POINTER IS LOCATED TO AND SHIFT IS DEPENDENT ON THE SIZE OF DATATYPE
// SO ACCORDING TO DATATYPE THAT ONE WITH MULTIPICATION OF SIZE IS ADDED
// 2. DECREMENT ==> SIMILAR IS THE CASE FOR THE DECREMENT

#include<iostream>
using namespace std;

int main(){
    int x=10;
    int *ptr= &x;          
    cout<<ptr<<endl;                // ADDRESS WILL BE PRINTED
    ptr++;                          // INCREMENT WILL OCCUR IN HEXADECIMAL MANNER ( 1,2,3,.....9,a,b,c,d,......z)
    cout<<ptr<<endl;                // NOW PRINT WILL OCCUR AFTER THE 4 ADDITION OF MEMORY AS INT HAS 4 BYTS MEMORY

    double doc=9.8;
    double *ptr1=&doc;
    cout<<ptr1<<endl;
    cout<<*ptr1<<endl;               // WILL PRINT 9.8 AS IT IS ON CORRECT ADDRESS
    ptr1  += 2;                      // DOUBLE HAS MEMORY OF 8 BYTES SO IT WILL GIVE RESULT AS 2*(8 BYTES)
    cout<<ptr1<<endl;
    cout<<*ptr1<<endl;               // WILL NOT PRINT 9.8 AS IT IS NOT ON CORRECT ADDRESS AND IT IS INCREASED BY 2*(8 BYTES)
    ptr1 = ptr1-1;
    cout<<ptr1<<endl;
    return 0;
}