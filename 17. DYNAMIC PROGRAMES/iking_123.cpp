// PRINT SHORTEST COMMON SUPERSEQUENCE

#include<bits/stdc++.h>
using namespace std;

string shortestCommonSuperSeq(string s1, string s2){
    vector< vector<int> > dp(s1.size()+1,vector<int>(s2.size()+1,0));
    for(int i = 0; i <= s1.size(); i++) dp[i][0] = 0;
    for(int j = 0; j <= s2.size(); j++) dp[0][j] = 0;
    for(int i = 1; i <= s1.size(); i++){
        for(int j = 1; j <= s2.size(); j++){
            if(s1[i-1] == s2[j-1]) dp[i][j] = 1 + dp[i-1][j-1];
            else dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
        }
    }
    string ans = "";
    int i = s1.size(), j = s2.size();
    while(i > 0 and j > 0){
        if(s1[i-1] == s2[j-1]){
            ans = s1[i-1] + ans;
            i--,j--;
        }
        else{
            if(dp[i-1][j] > dp[i][j-1]){
                ans = s1[i-1] + ans;
                i--;
            }
            else{
                ans = s2[j-1] + ans;
                j--;
            }
        }
    }
    while(i > 0){
        ans = s1[i-1] + ans;
        i--;
    } 
    while(j > 0){
        ans = s2[j-1] + ans;
        j--;
    }
    return ans;
}

int main(){
    string s1, s2;
    cin >> s1 >> s2;
    cout << shortestCommonSuperSeq(s1,s2) << "\n";
    return 0;
}