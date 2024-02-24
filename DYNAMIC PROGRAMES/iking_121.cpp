// LONGEST COMMON SUB-STRING

#include<bits/stdc++.h>
using namespace std;

int f_tab(string s1, string s2){
    vector< vector<int> > dp(s1.size()+1,vector<int>(s2.size()+1,0));
    int longest = -1;
    for(int i = 1; i <= s1.size(); i++){
        for(int j = 1; j <= s2.size(); j++){
            if(s1[i-1] == s2[j-1]) dp[i][j] = 1 + dp[i-1][j-1];
            longest = max(longest,dp[i][j]);
        }
    }
    return longest;
}

int main(){
    string s1, s2;
    cin >> s1 >> s2;
    cout << f_tab(s1,s2) << " ";
    return 0;
}