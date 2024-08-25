// ENUM

#include<iostream>
using namespace std;

int main(){
    enum Meal {breakfast, lunch, dinner};          // DEFINED LIKE AN ARRAY

    cout<<breakfast<<endl;                         // PRINT THE INDEX OF THE VARIABLE ( TAKE IT AS ZERO INDEXED )
    cout<<lunch<<endl;                             // PRINT 1
    cout<<dinner<<endl;                            // PRINT 2
    
    Meal m1=breakfast;                             
    cout<<m1<<endl;

    Meal m2=lunch;
    cout<<m2<<endl;
    
    cout<<(m1==2)<<endl;                           // PRINT FALSE

    
    return 0;
}