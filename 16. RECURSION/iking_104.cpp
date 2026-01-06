// GIVEN AN INTEGER , GET THE SUM OF DIGITS OF THE INTEGERS

#include<bits/stdc++.h>
using namespace std;

int sumOfDig(int n){
    if(n==0) return 0;
    return sumOfDig(n/10)+(n%10);
}

int main(){
    cout<<sumOfDig(653);
    return 0;
}