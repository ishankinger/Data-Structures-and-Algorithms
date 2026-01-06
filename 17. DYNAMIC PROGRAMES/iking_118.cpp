// ROD CUTTING PROBLEM

#include<bits/stdc++.h>
using namespace std;

int f(int index, int rod_len, vector<int> lenths){
    if(index == 0){
        return rod_len * lenths[0];
    }
    int not_take = f(index-1,rod_len,lenths);
    int take = 0;
    if(rod_len >= index + 1) take = f(index,rod_len-index-1,lenths) + lenths[index];
    return max(take,not_take);
}

int f_memo(int index, int rod_len, vector<int> lenths,vector< vector<int> > &dp){
    if(index == 0){
        return rod_len * lenths[0];
    }
    if(dp[index][rod_len] != -1) return dp[index][rod_len];
    int not_take = f_memo(index-1,rod_len,lenths,dp);
    int take = 0;
    if(rod_len >= index + 1) take = f_memo(index,rod_len-index-1,lenths,dp) + lenths[index];
    return dp[index][rod_len] = max(take,not_take);
}

int f_tab(int n, vector<int> lenths, int rod_len){
    vector< vector<int> > dp(n,vector<int>(rod_len+1,0));
    for(int i = 0; i <= rod_len; i++) dp[0][i] = i * lenths[0];
    for(int ind = 1; ind < n; ind++){
        for(int tar = 0; tar <= rod_len; tar++){
            int not_take = dp[ind-1][tar];
            int take = 0;
            if(tar >= ind + 1) take = dp[ind][tar-ind-1] + lenths[ind];
            dp[ind][tar] = max(take,not_take);
        }
    }
    return dp[n-1][rod_len];
}

int f_tab_so(int n, vector<int> lenths, int rod_len){
    vector<int> prev(rod_len+1,0);
    for(int i = 0; i <= rod_len; i++) prev[i] = i * lenths[0];
    for(int ind = 1; ind < n; ind++){
        for(int tar = 0; tar <= rod_len; tar++){
            int not_take = prev[tar];
            int take = 0;
            if(tar >= ind + 1) take = prev[tar-ind-1] + lenths[ind];
            prev[tar] = max(take,not_take);
        }
    }
    return prev[rod_len];
}

int rodCutting(int n, vector<int> v, int rod_len){
    vector< vector<int> > dp(n,vector<int>(rod_len+1,-1));
    return f_memo(n-1,rod_len,v,dp);
}

int main(){
    int n;
    cin >> n;
    vector<int> v(n);
    for(int i = 0; i < n; i++) cin >> v[i];
    int rod_len;
    cin >> rod_len;

    cout << f(n-1,rod_len,v) << "\n";
    cout << rodCutting(n,v,rod_len) << "\n";
    cout << f_tab(n,v,rod_len) << "\n";
    cout << f_tab_so(n,v,rod_len) << "\n";

    return 0;
}