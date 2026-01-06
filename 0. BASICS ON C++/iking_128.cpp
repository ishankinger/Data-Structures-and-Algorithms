// REVERSE THE DIGITS OF A NUMBER

#include<iostream>
using namespace std;

int main(){
    int n=848456;
    int newNumb=0;
    while(n>0){
        int lastDig = n%10;
        newNumb= newNumb*10 +lastDig;
        n=n/10;
    }
    cout<<newNumb;
    return 0;
}