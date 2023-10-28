// ***************** SUB-ARRAY HAVING MAX NUMBER OF PERFECT NUMBERS HAVING SIZE K *********************
// GIVEN AN ARRAY AND WE HAVE TO CALCULATE THE MAX NO. OF PERFECT NUMBERS IN SUB-ARRAY OF SIZE K

#include<bits/stdc++.h>
using namespace std;

bool isPerf(int n){
    int sum=1;
    for(int i=2;i<sqrt(n);i++){
        if(n%i==0){
            if(i==(n/i)) sum+=i;
            else sum+=i+(n/i);
        }
    }
    if(sum==n && n!=1) return true;
    else return false;
}

int main(){
    int n; cin>>n;
    vector<int>v(n);
    for(auto &ele:v) cin>>ele;
    int k; cin>>k;
    for(int i=0;i<n;i++){
        if(isPerf(v[i])) v[i]=1;
        else v[i]=0;
    }
    int sum=0;
    int ans=0;
    for(int i=0;i<k;i++) sum+=v[i];
    ans=sum;
    for(int i=k;i<n;i++){
        sum=sum+v[i]-v[i-k];
        ans=max(sum,ans);
    }
    cout<<ans<<"\n";

    return 0;
}
