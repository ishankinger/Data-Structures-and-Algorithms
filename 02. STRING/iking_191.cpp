// LONGEST COMMON SUBSTRING HAVING ALL CHARACTERS DISTINCT

#include<bits/stdc++.h>
using namespace std;

int main(){
    string s; cin>>s;
    vector<int>dict(256,-1);
    int maxLne=0,start=-1;
    for(int i=0;i<s.size();i++){
        if(dict[s[i]]>start) start=dict[s[i]];
        dict[s[i]]=i;
        maxLne=max(maxLne,i-start);
    }
    cout<<maxLne<<"\n";

    return 0;
}