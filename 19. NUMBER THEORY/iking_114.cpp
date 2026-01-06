// GIVEN A STRING IN WHICH ELEMENTS MAY NOT BE ALL DISTINCT U HAVE TO TELL ALL THE POSSIBLE ANAGRAMS FOR THE STRINGS POSSIBLE
// STRING LENTH IN RANGE OF 500 AND ANSWER MAY BE LARGE SO (OUTPUT % 1E9+7)

#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll M = 1e9+7;
const int N = 500;
ll fac[N+10];

ll binExp(ll a, ll b, ll M){
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
    fac[0]=1;
    for(int i=1;i<=N+10;i++){
        fac[i] = (fac[i-1]*i) % M;
    }
    
    int t; cin>>t;
    while(t--){
        string s; cin>>s;
        map<char,int>m;
        for(int i=0;i<s.size();i++) m[s[i]]++;
        ll num = (fac[s.size()]%M);
        ll den = 1;
        for(auto itr:m){
            den = (den*fac[itr.second])%M;
        }
        cout<<((num%M)*(binExp(den,M-2,M)%M))%M<<"\n";
    }
    return 0;
}