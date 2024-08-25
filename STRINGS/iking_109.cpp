// FINDING ALL THE OCCURENCE OF THE STRING PAT IN STRING TXT 
// KMP ALGORITHM

#include<bits/stdc++.h>
using namespace std;

// brute force way to get the occurence of the pat in the txt
vector<int> strStr(string txt, string pat) {
    vector<int> ans;
    // int ops = 0;
    for(int i = 0; i < txt.size(); i++){
        int count = 0;
        for(int j = i; j < txt.size(); j++){
            // ops++;
            if(pat[j-i] == txt[j]) count++;
            else break;
        }
        if(count == pat.size()) ans.push_back(i);
    }
    // cout << ops << "\n";
    return ans;
}

// prefix[i] is the length of the longest string which is proper prefix (whole string not regarded as proper prefix)
// of subString[0...i] and also suffix of this subString, prefix[0] = 0 by definition
// Time Complexity = O(n^3)
vector<int> lps(string s){
    int n = s.size();
    vector<int> pi(n);
    pi[0] = 0;
    for(int i = 1; i < n; i++){
        for(int k = 0; k <= i; k++){
            // prefix == suffix
            if(s.substr(0,k) == s.substr(i-k+1,k)) pi[i] = k;
        }
    }
    return pi;
}

// Time complexity - O(n)
vector<int> lps_optimise(string s){
    int n = s.size();
    vector<int> pi(n,0);
    for(int i = 1; i < n; i++){
        // max match of prefix and suffix till i-1 is stored in j
        int j = pi[i-1];
        while(j > 0 and s[i] != s[j]) j = pi[j-1];
        // if next character are also equal then increase the prefix size
        if(s[i] == s[j]) j++;
        pi[i] = j;
    }
    return pi;
}

// kmp search alogrithm function
vector<int> kmp(string pat, string txt){
    vector<int> ans;
    vector<int> lps = lps_optimise(pat);
    int i = 0, j = 0;
    // int ops = 0;
    while(i < txt.size()){
        // ops++;
        if(txt[i] == pat[j]){
            j++;
            i++;
        }
        else{
            if(j != 0) j = lps[j-1];
            else i++;
        }
        if(j == pat.size()){
            ans.push_back(i-pat.size());
        }
    }
    // cout << ops << "\n";
    return ans;
}


int main(){
    // test case - "aaabaaaaabaab", "aaab"
    // get the difference between the computational operations between both functions strStr and kmp
    
    string str = "AACECAAAA";
    string as = str;
    reverse(as.begin(),as.end());
    str = str + '#' + as;

    vector<int> v1 = lps(str), v2 = lps_optimise(str);
    for(int i = 0; i < v1.size(); i++) cout << v1[i] << " ";
    cout << "\n";
    for(int i = 0; i < v2.size(); i++) cout << v2[i] << " ";
    cout << "\n";

    string a, b;
    cin >> a >> b;

    vector<int> ans = kmp(a,b);
    for(int i = 0; i < ans.size(); i++) cout << ans[i] << " ";
    cout << "\n";

    vector<int> ans2 = strStr(b,a);
    for(int i = 0; i < ans2.size(); i++) cout << ans2[i] << " ";
    cout << "\n";
}

// FOLLOW UP QUESTION - MINIMUM INSERTIONS OF ELEMENTS TO MAKE IT A PALLINDROME

int solve(string A) {
    string s = A;
    reverse(A.begin(),A.end());
    s = s + '#' + A; 
    int n = s.size();
    vector<int> pi(n,0);
    for(int i = 1; i < n; i++){
        int j =pi[i-1];
        while(j > 0 && s[i]!=s[j]){
            j = pi[j-1];
        }
        if(s[i]==s[j]){
            j++;
        }
        pi[i]=j;
    }
    return A.size()-pi[n-1];
}
