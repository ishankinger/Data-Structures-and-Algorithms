// *************** SLIDING WINDOW CHALLENGES ****************
// GIVEN AN ARRAY WITH TWO INTEGERS K AND X AND WE HAVE TO FIND MAX SUM SUB-ARRAY OF SIZE K HAVING SUM LESS THAN X

#include<bits/stdc++.h>
using namespace std;

int main(){
    int n; cin>>n;
    vector<int>v(n);
    for(auto &ele:v) cin>>ele;
    int x,k; cin>>x>>k;
    int ans=0;
    int sum=0;
    for(int i=0;i<k;i++) sum+=v[i];
    if(sum<x) ans=sum;
    for(int i=k;i<n;i++){
        sum+=v[i]-v[i-k];
        if(sum<x) ans=max(sum,ans);
    }
    cout<<ans<<"\n";

    return 0;
}
