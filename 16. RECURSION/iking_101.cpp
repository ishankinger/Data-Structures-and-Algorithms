// SUM OF FIRST N NATURAL NUMBERS

#include<bits/stdc++.h>
using namespace std;

int sumNumbers(int n){
    if(n==1) return 1;
    return sumNumbers(n-1)+n;
}

int main(){
    cout<<sumNumbers(5)<<"\n";
    return 0;
}