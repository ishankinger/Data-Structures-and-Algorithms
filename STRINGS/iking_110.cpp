// STRING HASH and RABIN KARP ALGORITHM

// a-1 , b-2, c-3, d-4, ........ z-26  assigning characters some integer values
// Hash fun(string) = summation((string[i].value)*(31^i))
// Hash fun("apna") = 1*31^0 + 16*31^1 + ...
// Also Hash fun("na") = (1/(31^2)) * ( fun("apna") - fun("ap"))
// Also these numbers grows expoentially so we will do modulo with 1e9 + 7

// FIND ALL THE OCCURENCES OF THE PAT IN THE TXT

#include<bits/stdc++.h>
#include<iostream>
using namespace std;

int main(){
    string pat, txt;
    cin >> pat >> txt;

    int m = 1e9 + 7;
    int p = 31;
    int N = 1e5 + 7;
    vector<long long> power(N);
    power[0] = 1;
    for(int i = 1; i < N; i++){
        power[i] = (power[i-1]*p) % m;
    }

    vector<long long> hashText(txt.size()+1,0);
    for(int i = 0; i < txt.size(); i++){
        hashText[i+1] = (hashText[i] + (txt[i]-'a'+1)*power[i]) % m;
    }

    long long hashPat = 0;
    for(int i = 0; i < pat.size(); i++){
        hashPat = (hashPat + (pat[i]-'a'+1)*power[i]) % m;
    }

    vector<int> ans;
    for(int i = 0; i < txt.size() - pat.size() + 1; i++){
        long long cur_h = (hashText[i+pat.size()] - hashText[i] + m) % m;
        if(cur_h == (hashPat * power[i]) % m){
            ans.push_back(i);
        }
    }

    for(int i = 0; i < ans.size(); i++) cout << ans[i] << " ";
    cout << "\n";

    return 0;
}