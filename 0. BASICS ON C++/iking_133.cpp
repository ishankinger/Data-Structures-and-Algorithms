// STANDARD LIBRARY FUNCTIONS

#include<iostream>                            // SOME FUNTIONS ARE ALREADY DEFINED IN C++
#include<cmath>                               // WRITE THIS TO USE THE FUNCTIONS
using namespace std;

int main(){
    cout<<pow(2,3)<<endl;                      // PRINT 2 RAISE TO POWER 3
    cout<<sqrt(24)<<endl;                      // RETURN SQUARE ROOT AND RETURN IN DOUBLE DATATYPE
    
    int ans=floor(sqrt(24));                   // FLOOR WILL ACT LIKE LOWEST INTEGER FUNCTION                  
    int ans2=ceil(sqrt(24));                   // CEIL WILL ACT LIKE GREATEST INTEGER FUNCTION
    cout<<ans<<"\n";                               
    cout<<ans2;
    return 0;
}