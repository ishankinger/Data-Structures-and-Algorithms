// GIVEN AN ARRAY AND AN INTEGER X AND WE HAVE TO CALCULATE SMALLEST SUB-ARRAY SIZE HAVING SUM > X

#include<bits/stdc++.h>
using namespace std;

int main(){
    int n; cin>>n;
    vector<int>v(n);
    for(auto &ele:v) cin>>ele;
    int x; cin>>x;
    int sum=0;
    int start=0;
    int ans=INT_MAX;
    for(int i=0;i<n;i++){
        if(sum<=x) sum+=v[i];
        else{
            while(sum>x){
                ans=min(ans,i-start);
                sum-=v[start++];
            }
        }
    }
    cout<<ans<<"\n";

    return 0;
}