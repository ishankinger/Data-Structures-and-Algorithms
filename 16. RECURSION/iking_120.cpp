// LINEAR SEARCH IN ARRAY FOR ELEMENT X

#include<bits/stdc++.h>
using namespace std;

bool elePresent(int arr[],int idx,int n,int x){
    if(idx==n) return false;
    if(arr[idx]==x) cout<<"position of ele->"<<idx+1<<"\n";
    return arr[idx]==x || elePresent(arr,idx+1,n,x);
}

int main(){
    int n; cin>>n;
    int arr[n];
    for(int i=0;i<n;i++) cin>>arr[i];
    int x; cin>>x;
    if(elePresent(arr,0,n,x)) cout<<"Element is present"<<"\n";
    else cout<<"Element is not present"<<"\n";

    return 0;
}