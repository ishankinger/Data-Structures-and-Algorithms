// PRINT NUMBERS FROM 1-50 EXCEPT MULTIPLE OF 3

#include<iostream>
using namespace std;

int main(){
    for(int i=1; i<=50;i++){
        if(i%3==0){
            continue;                            // CONTINUE KEYWORD WILL SKIP THE ELEMENTS FOLLOWING THE CONDITION
        }                                        // OTHER WILL FOLLOW CODE AS FOLLOW
        cout<<i<<endl;
    }
    return 0;
}