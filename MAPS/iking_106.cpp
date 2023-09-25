// WE ARE TAKING INPUT OF ARRAY NUMBERS AND WE HAVE TO
// OUTPUT ELEMENTS IN DECREASING FREQUENCY TILL WE REACH (K+1)th DISTINCT ELEMENT

#include<bits/stdc++.h>
using namespace std;

int main(){
    int n,k; cin>>n>>k;
    vector<int>v(n);
    for(int i=0;i<n;i++) cin>>v[i];

    map<int,int>m;
    for(int i=0;i<n;i++){
        int presSize=m.size();
        if(m[v[i]]==0 && presSize==k) break;
        m[v[i]]++;
    }

    vector<pair<int,int>> ans;
    for(auto it=m.begin();it!=m.end();it++){
        if((*it).second !=0)
        ans.push_back({(*it).second,(*it).first});
    }

    sort(ans.begin(),ans.end(),greater<pair<int,int>>());
    
    for(auto it=ans.begin();it!=ans.end();it++){
        cout<<(*it).second<<" "<<(*it).first<<"\n";
    }

    return 0;
}