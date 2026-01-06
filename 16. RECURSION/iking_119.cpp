// FROG JUMP
// COST=|HI-HJ| AND FROG CAN JUMP TO I+1 OR I+2 SO WE HAVE TO CALCULATE MINIMUM COST

#include<bits/stdc++.h>
using namespace std;

int minCost(int arr[],int n,int idx){
    if(idx==n-1||idx==n) return 0;
    if(idx==n-2) return abs(arr[idx]-arr[idx+1])+minCost(arr,n,idx+1);
    int k;
    if(abs(arr[idx]-arr[idx+1])<abs(arr[idx]-arr[idx+2])) k=1;
    else k=2;
    return abs(arr[idx]-arr[idx+k])+minCost(arr,n,idx+k);
}

int main(){
    int n; cin>>n;
    int arr[n];
    for(int i=0;i<n;i++) cin>>arr[i];
    cout<<minCost(arr,n,0)<<"\n";
    return 0;
}