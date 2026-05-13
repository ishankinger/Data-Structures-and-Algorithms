// POINTERS IN C++
// POINTERS ARE A SPECIAL TYPE OF DATATYPES WHICH STORES ADDRESSES OF OTHER VARIABLES

#include<iostream>
using namespace std;

int main(){
    
    int x=11;
    int y=0;

    cout<<&x<<endl;                     // THIS WILL PRINT US THE ADDRESS OF THE VARIABLE IN THE MEMORY
    cout<<&y<<endl;                     // EACH VARIABLE WILL HAVE IT'S DIFFERENT ADDRESSES IN THE MEMORY
    
    return 0;
}