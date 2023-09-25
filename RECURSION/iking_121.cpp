// PRINTING SUM OF ALL THE SUB-SETS FOR THE GIVEN SET

#include<bits/stdc++.h>
using namespace std;

void printSumSubSet(vector<int>&v,int arr[],int n,int idx,int sum){
    if(idx==n){
        v.push_back(sum);
        return;
    }
    printSumSubSet(v,arr,n,idx+1,sum+arr[idx]);
    printSumSubSet(v,arr,n,idx+1,sum);
}

int main(){
    int n; cin>>n;
    int arr[n];
    for(int i=0;i<n;i++) cin>>arr[i];
    vector<int>v;
    printSumSubSet(v,arr,n,0,0);
    for(int i=0;i<v.size();i++) cout<<v[i]<<"\n";
    return 0;
}