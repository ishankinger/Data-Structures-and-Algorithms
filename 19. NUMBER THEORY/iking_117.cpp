// VARIATION IN SIEVE ALGORITHM

#include<bits/stdc++.h>
using namespace std;

int main(){
    int n=1e5+10;
    vector<bool>isPrime(n,true);
    isPrime[0]=isPrime[1]=false;

// >> TO GET THE LOWEST PRIME FACTOR AND HIGHEST PRIME FACTOR IN PRIME FACTORISATION

    vector<int>lp(n),hp(n);                               // TWO VECTORS FOR STORING HIGHEST AND LOWEST PRIME FACTORS ARE DEFINED
    for(int i=2;i<n;i++){                           
        if(isPrime[i]){
            hp[i]=lp[i]=i;                                // THIS IS FOR PRIME NUMBERS
            for(int j=2*i;j<n;j+=i){
                isPrime[j]=false;
                hp[j]=i;                                  // WHENEVER HP[J] COMES THEN IT WILL REPLACE WITH GREATER I (FOR 6 FIRST 2 AND THEN 3)
                if(lp[j]==0) lp[j]=i;                     // IN THIS IT WILL STORE THE VERY FIRST OCCURENCE
            }
        }
    }
// >> TO GET PRIME FACTORISATION OF ANY NUMBER N

    vector<int>primefactors;
    int num; cin>>num;
    while(num>1){
        int primeFact= hp[num];                           // THIS WILL GIVE ME A PRIME NUMBER WHICH DIVIDE NUMBER
        while(num%primeFact==0){
            num/=primeFact;
            primefactors.push_back(primeFact);
        }
    }
    
    for(int i=0;i<primefactors.size();i++) cout<<primefactors[i]<<" ";

    return 0;
}