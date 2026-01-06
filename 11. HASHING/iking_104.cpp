// GIVEN A SERIES OF STRING PRINT THE UNIQUES STRINGS WITH THEIR RESPECTIVE FREQUENCIES

#include<bits/stdc++.h>
using namespace std;

int main(){
    map<string,int>m;
    int n; cin>>n;
    for(int i=0;i<n;i++){
        string s; cin>>s;
        m[s]++;                                      // MAP WILL STORE ONLY DISTINCT KEY'S VALUE
    }                                                
    for(auto pr:m){
        cout<<pr.first<<" "<<pr.second<<"\n";
    }
    return 0;
}

// IF HERE STRING SIZE IS LARGE (10^5) THEN IT SHOULD BE DONE VIA MAPS AS IT WILL EXCEED THE TIME LIMIT