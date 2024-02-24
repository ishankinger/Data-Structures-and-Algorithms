// LONGEST STRING CHAIN

#include<bits/stdc++.h>
using namespace std;

bool compare(string a, string b){
    if(a.size()-b.size() != 1) return false;
    int unmatched = 0;
    int ptr1 = 0, ptr2 = 0;
    while(ptr1 < a.size()){
        if(a[ptr1] == b[ptr2]) ptr1++, ptr2++;
        else ptr1++;
    }
    if(ptr1 == a.size() and ptr2 == b.size()) return true;
    else return false;
}

void longestStringChain(vector<string> words){
    vector<int> dp(words.size(),1);
    vector<int> hash(words.size());
    int maxi = 1, lastIndex = 0;
    for(int i = 0; i < words.size(); i++){
        hash[i] = i;
        for(int prev = 0; prev < i; prev++){
            if(compare(words[i],words[prev]) and 1+dp[prev] > dp[i]){
                dp[i] = 1 + dp[prev];
                hash[i] = prev;
            }
        }
        if(dp[i] > maxi){
            maxi = dp[i];
            lastIndex = i;
        }
    }
    vector<string> lsc;
    lsc.push_back(words[lastIndex]);
    while(hash[lastIndex] != lastIndex){
        lastIndex = hash[lastIndex];
        lsc.push_back(words[lastIndex]);
    }
    reverse(lsc.begin(),lsc.end());

    for(int i = 0; i < lsc.size(); i++){
        for(int j = 0; j < lsc[i].size(); j++){
            cout << lsc[i][j];
        }
        cout << " ";
    }
    cout << "\n";
}

bool comp(string &s1, string &s2){
    return s1.size() < s2.size();
}

int main(){
    int n;
    cin >> n;
    vector<string> words(n);
    for(int i = 0; i < n; i++) cin >> words[i];
    sort(words.begin(),words.end(),comp);
    longestStringChain(words);
    return 0;
}