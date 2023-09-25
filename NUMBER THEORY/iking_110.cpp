// BINARY EXPONENTATION

#include<bits/stdc++.h>
using namespace std;
const long long M = 1e9 + 7;

// MAIN APPROACH USED HERE IS TO BREAK B INTO B/2 EACH TIME AND WHILE RETURNING MULTIPLY ACCORDING TO EVEN AND ODD

int binExpRec(long long a, long long b){               // DONE IN O(LOG(N)) USING RECURSIVE WAY
    if(b==0) return 1;
    long long rest = binExpRec(a,b/2);
    if(b & 1) return ( a* ( rest*rest )% M) % M;       // b & 1 IS 0 IF B IS EVEN ELSE 1 FOR ODD
    else return (rest*rest) % M;

}

// MAIN APPROACH USED HERE IS TO BREAK B INTO POWERS OF 2 AND THEN SOLVE BY SIMPLY MULTIPLYING 
// TO BREAK INTO POWER OF TWO BEST METHOD IS TO USE BINARY REPRESENTATION AND BIT MANIPULATION

int binExpIter(long long a, long long b){              // ALSO DONE IN O(LOG(N)) IN ITERATIVE WAY
    long long ans=1;
    while(b>0){                                        // TILL ALL THE SET BITS OF B ARE NOT 0 WE WILL TRAVERSE
        if(b & 1){                                     // IF WE GET ANY SET BIT THEN MULTIPLY THAT WITH A THAT IS UPDATED AT THAT TIME
            ans = ((ans)*(a)) % M;
        }
        a = (a*a) % M;                                 // AND UPDATE A EACH TIME FOR MULTIPICATION IN ANS
        b >>= 1;                                       // AND SHIFT EACH TIME A BIT TO RIGHT           
    }
    return ans;
}

int main(){
    cout<<binExpRec(15,134)<<"\n";
    cout<<binExpIter(15,134)<<"\n";
    return 0;
}

