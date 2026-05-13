// LOCAL VARIABLES AND GLOBAL VARIABLES

#include<iostream>
using namespace std;

int p=5;                                  // GLOBAL VARIABLE( ACCESS THROUGHOUT THE WHOLE PROGRAM)

int main(){
    int p=7;                             // LOCAL VARIABLES( ACCESS INSIDE THE FUNCTIONS)
    cout<<p;                             // LOCAL WILL BE PREFFERED OVER GLOBAL
}                                        // IF INT P AS LOCAL VARIABLE NOT PRESENT THEN GLOBAL VARIABLE WILL BE PRINTED