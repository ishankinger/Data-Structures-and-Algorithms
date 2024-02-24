// DISTINCT SUBSEQUENCES

#include<bits/stdc++.h>
using namespace std;

int f(int i, int j, string s1, string s2){
    if(j < 0) return 1;
    if(i < 0) return 0;
    if(s1[i] == s2[j]) return f(i-1,j-1,s1,s2) + f(i-1,j,s1,s2);
    else return f(i-1,j,s1,s2);
}

int f_memo(int i, int j, string s1, string s2, vector< vector<int> > dp){
    if(j < 0) return 1;
    if(i < 0) return 0;
    if(dp[i][j] != -1) return dp[i][j];
    if(s1[i] == s2[j]) return dp[i][j] = f_memo(i-1,j-1,s1,s2,dp) + f_memo(i-1,j,s1,s2,dp);
    else return dp[i][j] = f_memo(i-1,j,s1,s2,dp);
}

int f_tab(string s1, string s2){
    vector< vector<int> > dp(s1.size()+1,vector<int>(s2.size()+1,0));
    for(int j = 0; j < s2.size(); j++)dp[0][j] = 0;
    for(int i = 0; i < s1.size(); i++) dp[i][0] = 1;
    for(int i = 1; i <= s1.size(); i++){
        for(int j = 1; j <= s2.size(); j++){
            if(s1[i-1] == s2[j-1]) dp[i][j] = dp[i-1][j-1] + dp[i-1][j];
            else dp[i][j] = dp[i-1][j];
        }
    }
    return dp[s1.size()][s2.size()];
}

int f_tab_so(string s1, string s2){
    vector<int> prev(s2.size()+1,0);
    prev[0] = 1;
    for(int i = 1; i <= s1.size(); i++){
        for(int j = s2.size(); j >= 1; j--){
            if(s1[i-1] == s2[j-1]) prev[j] = prev[j-1] + prev[j];
            else prev[j] = prev[j];
        }
    }
    return prev[s2.size()];
}

int distinctSubseq(string s1, string s2){
    vector< vector<int> > dp(s1.size(),vector<int>(s2.size(),-1));
    return f_memo(s1.size()-1,s2.size()-1,s1,s2,dp);
}

int main(){
    string s1, s2;
    cin >> s1 >> s2;
    cout << f(s1.size(),s2.size(),s1,s2) << "\n";
    cout << distinctSubseq(s1,s2) << "\n";
    cout << f_tab(s1,s2) << "\n";
    cout << f_tab_so(s1,s2) << "\n";
    return 0;
}