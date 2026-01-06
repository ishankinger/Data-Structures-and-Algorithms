// PALLINDROME PARTITION - 2

#include<bits/stdc++.h>
using namespace std;

bool isPallindrome(string s){
    for(int i = 0; i < s.size(); i++){
        if(s[i] != s[s.size()-i-1]) return false;
    }
    return true;
}

int f(int i, string s){
    if(i == s.size()) return 0;
    string temp = "";
    int min_cost = INT_MAX;
    for(int j = i; j < s.size(); j++){
        temp += s[j];
        if(isPallindrome(temp)){
            min_cost = min(min_cost,1 + f(j+1,s));
        }
    }
    return min_cost;
}

int f_memo(int i, string s, vector<int> &dp){
    if(i == s.size()) return 0;
    if(dp[i] != -1) return dp[i];
    string temp = "";
    int min_cost = INT_MAX;
    for(int j = i; j < s.size(); j++){
        temp += s[j];
        if(isPallindrome(temp)){
            min_cost = min(min_cost,1 + f_memo(j+1,s,dp));
        }
    }
    return dp[i] = min_cost;
}

int f_tab(string s){
    vector<int> dp(s.size()+1,0);
    int min_cost;
    for(int i = s.size()-1; i >= 0; i--){
        min_cost = INT_MAX;
        string temp = "";
        for(int j = i; j < s.size(); j++){
            temp += s[j];
            if(isPallindrome(temp)){
                min_cost = min(min_cost,1 + dp[j+1]);
            }
        }
        dp[i] = min_cost;
    }
    return dp[0]-1;
}

int pallindromePartition_2(string s){
    vector<int> dp(s.size(),-1);
    return f_memo(0,s,dp);
}

int main(){
    string s;
    cin >> s;
    cout << f(0,s)-1<< "\n";
    cout << pallindromePartition_2(s)-1 << "\n";
    cout << f_tab(s) << "\n";
    return 0;
}