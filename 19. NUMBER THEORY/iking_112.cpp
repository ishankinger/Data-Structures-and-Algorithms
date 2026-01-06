// MODULAR ARITHEMETIC

// >> (a+b) % M = (a % M + b % M) % M
// >> (a * b) % M = ((a % M) * (b % M)) % M
// >> (a-b) % M = ((a % M) - (b % M) + M) % M
// >> (a/b) % M = ((a % M) * ((b^-1) % M)) % M  --> THIS CASE IS DONE IN NEXT FILE

#include<bits/stdc++.h>
using namespace std;
#define ll long long
const long long M = 1e9+7;
// >> MAX VALUE OF INT IS 1E9 ROUGHLY, SO CLOSER TO IT
// >> MULTIPICATIVE INVERSE, SO M-1 IN EULER'S THEOREM

int main(){
    int n; cin>>n;
    long long fact = 1;
    for(int i=2; i<=n ; i++ ){
        fact = ((fact % M) * (i % M)) % M;
    }
    cout<<fact<<"\n";

    return 0;
}