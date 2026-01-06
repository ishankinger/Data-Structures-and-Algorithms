// WRITE A PROGRAM TO CHECK POWER OF TWO

// IMPORTANT OBSERVATION --
// n=6 0110     FROM RIGHT MOST ONE TO END FLIP ALL THE BITS
// n=5 0101     THEN WE WILL GET N-1 NUMBER
// ALSO IF WE TAKE (N & (N-1)) THEN IT WILL HAVE SAME BITS AS N EXCEPT THE RIGHTMOST SET BIT

// USING ABOVE CONCEPT ON N=8 1000
// N-1 = 0111 
// NOW BY TAKING AND WE WILL GET ZERO HENCE POWER OF 2 

#include<bits/stdc++.h>
using namespace std;

bool isPowerOf2(int n){
    return (n && !(n & (n-1)));   // AND WITH DUE TO CORNER CASE OF N=0
}

int main(){
    int n; cin>>n;
    cout<<isPowerOf2(n);

    return 0;
}