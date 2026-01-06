// GETTING GCD OF TWO NUMBERS USING RECURSION

#include<bits/stdc++.h>
using namespace std;

int gcd(int a,int b){
    if(a<b) swap(a,b);
    if(b==0) return a;
    gcd(b,a%b);
}

int main(){
    cout<<gcd(5,25)<<"\n";
    return 0;
}