// QUESTION ON EXPOENTATION
// calculate ab mod 1337 where a is a positive integer and b is an extremely large positive integer given in the form of an array.

// IN THIS QUESTION OUR M IS NOT PRIME SO ETF CAN'T BE REPLACED BY M-1
// WE HAVE TO CALUCULATE IT'S ETF
// ETF OF 1337 IS 1140

#include<bits/stdc++.h>
using namespace std;
const long long M = 1e9+7;

int binExp(long long a, long long b){              
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
    int a; cin>>a;
    int n; cin>>n;
    vector<int>b(n);
    for(int i=0;i<n;i++) cin>>b[i];
    int m = 1140;
    int power=0;
    for(int i=0;i<n;i++){
        power += ((b[n-i-1])*(binExp(10,i)))%m;
    }
    cout<<binExp(a,power)%(1337)<<"\n";
    
    return 0;
}