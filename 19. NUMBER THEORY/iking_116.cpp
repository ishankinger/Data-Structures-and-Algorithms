// SIEVE ALGORITHM FOR OPTIMISATION FOR PRIMES
// TIME COMPLEXITY=> N*LOG(LOG(N))

#include<bits/stdc++.h>
using namespace std;

int main(){
    int n=1e5+10;
    vector<bool>isPrime(n,true);                    // A VECTOR IS COMPUTED TO TELL FOR A NUMBER IS PRIME OR NOT
    isPrime[0]=isPrime[1]=false;                    // INITAILLY BOTH 0 AND 1 FALSE (NOT PRIME)
    for(int i=2;i<n;i++){                           // WE WILL TRAVERSE IN THE BOOLEAN VECTOR
        if(isPrime[i]){
            for(int j=2*i;j<n;j+=i){                // ALL THE NUMBER WHICH ARE MULTIPLES OF GIVEN PRIME NUMBER WILL GET FALSE
                isPrime[j]=false;
            }
        }
    }                                               // AT END WE WILL LEFT WITH ONLY PRIME NUMBERS
    int k; cin>>k;
    if(isPrime[k]) cout<<"It is a prime number\n";
    else cout<<"It is not a prime number\n";

    return 0;
}