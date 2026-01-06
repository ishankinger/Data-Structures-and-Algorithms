// COUNT THE NUMBER OF DIGIT FOR GIVEN NUMBER

#include<iostream>
using namespace std;

int main(){
    int n=34587683;
    int digits=0;
    while(n>0){
        digits++;                                    // WHEN WE GO IN LOOP DIGIT COUNTING STARTS
        n= n/10;                                     // n IS DEFINED AS INT SO WHEN DIVIDED BY 10 IT WILL GIVE ONE DIGINT LESS NUMBER N
    }                                                // LAST ONE WILL BE 0 SO WE WILL LEAVE THE LOOP AND THEN DIGITS WILL BE PRINTED
    cout<<digits;
    return 0;
}

