// PASS BY VALUE
// IF WE WANT TO GIVE ONLY VALUE TO FORMAL VARIABLES OF THE FUNCTION SO WE WILL BE USING INT z WITHOUT AMPERSANT OPERATOR

#include<iostream>
using namespace std;

void changeValue(int z){
    z=100;
}
int main(){                          // HERE ANOTHER COPY OF VARIABLE IS MADE
    int a=5;
    changeValue(a);                  // IN THIS PARAMETER VALUE IS COPIED TO ANOTHER VARIABLE                      
    cout<<a;                         // HERE 5 WILL BE PRINTED NOT 100
}
// IN changeValue(a) FUNCTION THERE WILL BE WORK ON ANY OTHER VARIABLE STORED AT ANY OTHER MEMORY OTHER THAN MEMORY OF VARIBLE a
// SO VALUE OF a WILL REMAIN UNCHANGED