// MODULAR MULTIPICATIVE INVERSE

// FERMET'S THEOREM => A^(M-2) = ((A^(-1)) % M)
// A^(M-2) CAN BE CALCULATED FROM BINEXP
// SO FROM THIS WE CAN GET VALUE OF (a/b) % M = ((a % M) * ((b^-1) % M)) % M 

// CALCULATING nCr USING ABOVE CONCEPT 

// // A LANGUAGE HAS K ENGLISH ALPHABETS
// // WE HAVE TO DECODE A PASSWORD HAVING N CHARACTERS BELONGING TO K CHARACTERS AND AT MAX ONCE IS USED
// // TOTOAL NUMBER OF DISTINCT STRINGS MODULO 1E9 +7

// // SO IN THIS QUESTION FIRST WE HAVE TO CHOOSE N CHARACTERS FROM K CHARACTERS AND THEN MAKE ALL THE GIVEN PERMUTATIONS FROM THAT NUMBER
// // SO FOR PICKING OF ELEMENTS KCN WILL BE USED AND TO MAKE ALL POSSIBILITIES WE HAVE TO MULTIPLY IT WITH N!
// // SO IT'S LIKE KPN = K!/(K-N)!

#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll M = 1e6 + 10;
ll fac[M];
const ll N = 1e+9 + 7;
const ll N2 = 998244353;

ll binExp(ll a, ll b, ll M){                         // BINARY EXPOTENTITION FUNCTION
    ll ans=1;
    while(b>0){
        if(b & 1){
            ans = ((ans)*(a)) % M;
        }
        a = (a*a) % M;
        b >>= 1;
    }
    return ans%M;
}

int main(){
    fac[0]=1;                                          // PRE-COMPUTING FACTORIAL FUNCTION
    for(ll i=1;i<M;i++){
        fac[i] = (fac[i-1]*i)%N;
    }
    int q; cin>>q;
    while(q--){
        ll n,k; cin>>n>>k;
        ll ans = fac[n];
        ll den = (fac[n-k]*fac[k])%N;
        //cout<<mod_div(ans,den,N)<<"\n";;
        cout<<((ans%N)*(binExp(den,N-2,N)%N))%N<<"\n";
    }

    return 0;
}

// MODULO ARITHEMETIC FUNCTIONS CONCLUDED FOR DIRECT USE

ll expo(ll a, ll b, ll mod = LONG_LONG_MAX)
{
   ll res = 1;
   while (b > 0)
   {
      if (b & 1)
         res = (res * a) % mod;
      a = (a * a) % mod;
      b = b >> 1;
   }
   return res;
}
ll mminvprime(ll a, ll b) { return expo(a, b - 2, b); }

ll mod_add(ll a, ll b, ll m = N){
   a = a % m;
   b = b % m;
   return (((a + b) % m) + m) % m;
}

ll mod_mul(ll a, ll b, ll m = N){
   a = a % m;
   b = b % m;
   return (((a * b) % m) + m) % m;
}

ll mod_sub(ll a, ll b, ll m = N){
   a = a % m;
   b = b % m;
   return (((a - b) % m) + m) % m;
}

ll mod_div(ll a, ll b, ll m = N){
   a = a % m;
   b = b % m;
   return (mod_mul(a, mminvprime(b, m), m) + m) % m;
}
