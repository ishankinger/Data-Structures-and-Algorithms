// GIVEN AN ARRAY OF N INTEGERS
// WE HAVE TO ANSWER Q QUERIES IN WHICH EACH QUERY GIVES US TWO INTEGERS P AND Q
// WE HAVE TO TELL THE TOTAL NUMBERS OF INTEGERS IN THE ARRAY DIVISIBLE BY P AND Q

#include<bits/stdc++.h>
using namespace std;
const int N = 2e5+10;

int hsh[N];
int multiples_ct[N];

int main(){
    int n; cin>>n;
    for(int i=0;i<n;i++){                                         // WILL STORE THE COUNT OF ELEMENT PRESENT IN THE GIVEN ARRAY
        int x; cin>>x;
        hsh[x]++;
    }
    for(int i=1;i<N;i++){                                         // USING SEIVE CONCEPT GOING IN MULTIPLES OF N NUMBERS AND STORING THE
        for(int j=i;j<N;j+=i){                                    // COUNT OF MULTIPLES PRESENT WITH THE HELP OF HASH ARRAY SO FORMED
            multiples_ct[i] += hsh[j];
        }
    }
    int Q; cin>>Q;                                                // GIVEN Q QUERIES AND WE HAVE TO ANSWER THEM
    while(Q--){
        int p,q;                                                  // TAKE INPUT OF P AND Q
        cin>>p>>q;
        long long ans = multiples_ct[p] + multiples_ct[q];        // P AND Q MULTIPLES
        long long lcm = p*1LL*q / __gcd(p,q);                     // GET LCM
        if(lcm<N) ans-=multiples_ct[lcm];                         // IF LCM LESS THEN N THEN ONLY SUBTRACT MULTIPLES HAVING BOTH DIVISIBLE
        cout<<ans<<"\n";                                          // PRINT ANSWER
    }

    return 0;
}