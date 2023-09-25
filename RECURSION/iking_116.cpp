// SUM OF N NATURAL NUMBERS BUT WITH ALTERNATE SIGN

#include<bits/stdc++.h>
using namespace std;

int sumOfNum(int n){
    if(n==0) return 0;
    int k;
    if(n%2==0) k=-n;
    else k=n;
    return sumOfNum(n-1)+k;
}

int main(){
    cout<<sumOfNum(5);
    return 0;
}