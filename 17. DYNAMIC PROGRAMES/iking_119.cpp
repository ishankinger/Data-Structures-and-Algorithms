// LONGEST COMMON SUBSEQUENCE

#include<bits/stdc++.h>
using namespace std;

int f(int ind1, int ind2, string s1, string s2){
    if(ind1 < 0 or ind2 < 0) return 0;
    if(s1[ind1] == s2[ind2]){
        return 1 + f(ind1-1,ind2-1,s1,s2);
    }
    return max(f(ind1-1,ind2,s1,s2),f(ind1,ind2-1,s1,s2));
}

int f_memo(int ind1, int ind2, string s1, string s2, vector< vector<int> > dp){
    if(ind1 < 0 or ind2 < 0) return 0;
    if(dp[ind1][ind2] != -1) return dp[ind1][ind2];
    if(s1[ind1] == s2[ind2]){
        return 1 + f_memo(ind1-1,ind2-1,s1,s2,dp);
    }
    return dp[ind1][ind2] = max(f_memo(ind1-1,ind2,s1,s2,dp),f_memo(ind1,ind2-1,s1,s2,dp));
}

int f_tab(string s1, string s2){
    vector< vector<int> > dp(s1.size()+1,vector<int>(s2.size()+1,0));
    for(int i = 0; i <= s1.size(); i++) dp[i][0] = 0;
    for(int j = 0; j <= s2.size(); j++) dp[0][j] = 0;
    for(int i = 1; i <= s1.size(); i++){
        for(int j = 1; j <= s2.size(); j++){
            if(s1[i-1] == s2[j-1]) dp[i][j] = 1 + dp[i-1][j-1];
            else dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
        }
    }
    return dp[s1.size()][s2.size()];
}

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

int longestCommonSubSequence(string s1, string s2){
    vector< vector<int> > dp(s1.size(),vector<int>(s2.size(),-1));
    return f_memo(s1.size()-1,s2.size()-1,s1,s2,dp);
}

int minOperationsConversion(string s1, string s2){
    vector< vector<int> > dp(s1.size(),vector<int>(s2.size(),-1));
    return s1.size() + s2.size() - 2 * f_memo(s1.size()-1,s2.size()-1,s1,s2,dp);
}

int main(){
    string s1, s2;
    cin >> s1 >> s2;

    cout << f(s1.size()-1, s2.size()-1, s1, s2) << "\n";
    cout << longestCommonSubSequence(s1,s2) << "\n";
    cout << f_tab(s1,s2) << "\n";
    cout << f_tab_so(s1,s2) << "\n";
    cout << minOperationsConversion(s1,s2) << "\n";

    return 0;
}