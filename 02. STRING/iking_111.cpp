// REPEATED STRING MATCH
// https://leetcode.com/problems/repeated-string-match/

#include<bits/stdc++.h>
using namespace std;

int Rabin_Karp(string txt, string pat){
        int m = 1e9 + 7;
        int p = 31;
        int N = 1e5;
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
                return i;
            }
        }
        return -1;
    }
    int repeatedStringMatch(string a, string b) {
        if(a == b) return 1;
        int count = 1;
        string txt = a;
        string pat = b;
        while(txt.size() < pat.size()){
            count++;
            txt += a;
        }
        if(txt == pat) return count;
        if(Rabin_Karp(txt,pat) != -1) return count;
        if(Rabin_Karp(txt+a,pat) != -1) return count+1;
        return -1;
    }