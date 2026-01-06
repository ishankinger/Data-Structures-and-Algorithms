// LONGEST PALLINDROMIC SUBSEQUECE

#include<bits/stdc++.h>
using namespace std;

int f_tab_so(string s1, string s2){
    vector<int> prev(s2.size()+1);
    for(int i = 0; i <= s1.size(); i++) prev[0] = 0;
    prev[0] = 0;
    vector<int> curr(s2.size()+1);
    for(int i = 1; i <= s1.size(); i++){
        for(int j = 1; j <= s2.size(); j++){
            if(s1[i-1] == s2[j-1]) curr[j] = 1 + prev[j-1];
            else curr[j] = max(prev[j],curr[j-1]);
        }
        prev = curr;
    }
    return prev[s2.size()];
}

int minInsertionsPallindrome(string s){
    string t = s;
    reverse(s.begin(),s.end());
    return s.size() - f_tab_so(s,t);
}

int main(){
    string s1, s2;
    cin >> s1;
    s2 = s1;
    reverse(s1.begin(),s1.end());
    cout << f_tab_so(s1,s2) << "\n";
    cout << minInsertionsPallindrome(s1) << "\n";
    return 0;
}