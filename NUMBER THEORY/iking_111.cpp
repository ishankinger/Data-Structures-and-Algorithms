// LARGE EXPOENTATION VARIATION

#include<bits/stdc++.h>
using namespace std;
const long long M = 1e9 + 7;
const long long ML = 1e18 + 7;

// >> WHEN A IS VERY LARGE

// (a^b) % M = ((a % M)^b) % M
// WE HAVE TO DO A%M OTHERWISE IN FUNCTION VALUE MAY OVERFLOW FROM LONG LONG RANGE

int binExpA(long long a, long long b){
    a %= M;                                 // WITHOUT USING THIS WE WILL GET NEGATIVE VALUE
    long long ans=1;                        
    while(b>0){
        if(b & 1){
            ans = ((ans)*(a)) % M;
        }
        a = (a*a) % M;
        b >>= 1;
    }
    return ans;
}

// >> WHEN M IS VERY LARGE

// IN THIS WE WILL BE USING BINARY MULTIPICATION FUNCTION
// IN THIS WHILE DOING %M VALUE WILL BE IN RANGE OF 10^18 BUT WHILE SOLVING A*A IT CAN OVERFLOW
// SO TO PREVENT THAT WE HAVE TO CALCULATE A*A USING BINARY MULTIPICATION FUNCTION
// IN THIS FUNCTION WE ARE USING SIMILAR LOGIC OF BINARY EXPOENTATION ONLY THING IS THERE WE NEED A^B HERE WE NEED A*B
// SO IN EXP. WE NEED TO MULTIPLY HERE WE NEED TO ADD

long long binMult(long long a, long long b){
    long long ans = 0;
    while(b>0){
        if(b & 1){
            ans = (ans + a) % ML;
        }
        a = (a + a) % ML;
        b >>= 1;
    }
    return ans;
}
long long binExpM(long long a, long long b){         // NOW IT'S TIME COMPLEXITY WILL O(LOG(N))^2                         
    long long ans=1;                        
    while(b>0){
        if(b & 1){
            ans = binMult(ans,a);
        }
        a = binMult(a,a);
        b >>= 1;
    }
    return ans;
} 

// >> WHEN B IS VERY LARGE

// IN THIS WE WILL BE USING EULER'S THEOREM
// ((a^b) % M) = ( a^(b % (M-1)) ) % M

long long binExpB(long long a, long long b, long long M){
    long long ans=1;
    while(b>0){
        if(b & 1){
            ans = ((ans)*(a)) % M;
        }
        a = (a*a) % M;
        b >>= 1;
    }
    return ans;
}

int main(){
    cout<<binExpA(138542356345463,83554)<<"\n";
    cout<<binExpM(3364398,337881)<<"\n";
    cout<<binExpB(50,binExpB(64,32,M-1),M)<<"\n";
    return 0;
}