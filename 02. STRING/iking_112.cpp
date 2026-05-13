// Z- ALGO
#include <bits/stdc++.h>
using namespace std;
#define ll long long

// Z[I] TELLS HOW MANY CHARACTERS OF S[I....N] AND S[0.....N] ARE MATCHED
vector<ll> zMatch(string s){
    vector<ll> z(s.size(),0);
    ll l = 0, r = 0;
    for(ll i = 1; i < s.size(); i++){
        if(i < r){
            // copy the past value if i is within the range
            z[i] = z[i - l];

            // if it's value exceeded the r then limit it to r
            if(i + z[i] > r) z[i] = r - i;
        }

        // go on expanding the range if possible
        while(i + z[i] < s.size() and s[z[i]] == s[i + z[i]]) z[i]++;

        // if range increased then update it 
        if(i + z[i] > r){
            l = i;
            r = i + z[i];
        }
    }
    return z;
}


// ADD THE GIVEN PATTERN TO THE FRONT OF GIVEN STRING WITH '$' SIGN SEPARATING THEM
// THEN ALL THE Z[I] == SIZE OF PATTERN WILL BE OUR ANSWER WHERE THE STRING HAS OCCURED