// SWAPPING TWO NUMBERS USING XOR OPERATOR

#include<bits/stdc++.h>
using namespace std;

int main(){
    int a,b;
    a=4,b=6;
    a=a^b;
    b=b^a;
    a=a^b;
    // b= b^(a^b) = b^b^a = a
    // a= (a^b)^b = a^a^b = b
    // x ^ y ^ z == x ^ z ^ y == y ^ x ^ z  --> ASSOSCIATIVE PROPERTY 
    cout<<a<<" "<<b;
    return 0;
}