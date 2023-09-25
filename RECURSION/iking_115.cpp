// PRINT K MULTIPLES OF A NUMBER N

#include<bits/stdc++.h>
using namespace std;

void printMult(int n,int k){
    if(k==0) return;
    printMult(n,k-1);
    cout<<n*k<<" ";
}

int main(){
    printMult(5,4);
    return 0;
}