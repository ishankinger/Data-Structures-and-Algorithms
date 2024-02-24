// EDIT DISTANCE 

#include<bits/stdc++.h>
using namespace std;

int f(int i, int j, string s1, string s2){
    if(i < 0) return j+1;
    if(j < 0) return i+1;
    if(s1[i] == s2[j]) return f(i-1,j-1,s1,s2);
    else return min(1 + f(i,j-1,s1,s2), min(1 + f(i-1,j-1,s1,s2), 1 + f(i-1,j,s1,s2)));
}

int f_memo(int i, int j, string s1, string s2, vector< vector<int> > dp){
    if(i < 0) return j+1;
    if(j < 0) return i+1;
    if(dp[i][j] != -1) return dp[i][j];
    if(s1[i] == s2[j]) return dp[i][j] = f_memo(i-1,j-1,s1,s2,dp);
    else return dp[i][j] = min(1 + f_memo(i,j-1,s1,s2,dp), min(1 + f_memo(i-1,j-1,s1,s2,dp), 1 + f_memo(i-1,j,s1,s2,dp)));
}

int f_tab(string s1, string s2){
    vector< vector<int> > dp(s1.size()+1,vector<int>(s2.size()+1,0));
    for(int i = 0; i <= s1.size(); i++) dp[i][0] = i;
    for(int j = 0; j <= s2.size(); j++) dp[0][j] = j;
    for(int i = 1; i <= s1.size(); i++){
        for(int j = 1; j <= s2.size(); j++){
            if(s1[i-1] == s2[j-1]) dp[i][j] = dp[i-1][j-1];
            else dp[i][j] = min(1+dp[i-1][j], min(1+dp[i-1][j-1], 1+dp[i][j-1]));
        }
    }
    return dp[s1.size()][s2.size()];
}

int f_tab_so(string s1, string s2){
    vector<int> prev(s2.size()+1,0);
    vector<int> curr(s2.size()+1,0);
    for(int j = 0; j <= s2.size(); j++) prev[j] = j;
    for(int i = 1; i <= s1.size(); i++){
        curr[0] = i;
        for(int j = 1; j <= s2.size(); j++){
            if(s1[i-1] == s2[j-1]) curr[j] = prev[j-1];
            else curr[j] = min(1+prev[j], min(1+prev[j-1], 1+curr[j-1]));
        }
        prev = curr;
    }
    return prev[s2.size()];
}

int editDistance(string s1, string s2){
    vector< vector<int> > dp(s1.size(),vector<int>(s2.size(),-1));
    return f_memo(s1.size()-1,s2.size()-1,s1,s2,dp);
}

int main(){
    string s1, s2;
    cin >> s1 >> s2;
    cout << f(s1.size(),s2.size(),s1,s2) << "\n";
    cout << editDistance(s1,s2) << "\n";
    cout << f_tab(s1,s2) << "\n";
    cout << f_tab_so(s1,s2) << "\n";
    return 0;
}