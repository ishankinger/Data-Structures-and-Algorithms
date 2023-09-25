// TO GET NTH FIBONNACI NUMBER

#include<bits/stdc++.h>
using namespace std;

int fibNum(int n){
    if(n==0) return 0;
    else if(n==1) return 1;
    return fibNum(n-1)+fibNum(n-2);
}

int main(){
    cout<<fibNum(9);
    return 0;
}