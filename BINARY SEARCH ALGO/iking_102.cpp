// RECURSIVE APPROACH

#include<iostream>
using namespace std;

int binSortRecursive(int arr[],int n,int low,int high,int k){
    if(low>high) return -1;
    int mid=low+(high-low)/2;                                             // BETTER WAY TO WRITE A MID
    if(arr[mid]==k) return mid;
    else if(arr[mid]<k) return binSortRecursive(arr,n,mid+1,high,k);
    else return binSortRecursive(arr,n,low,mid-1,k);
}

int main(){
    int n; cin>>n;
    int arr[n];
    for(int i=0;i<n;i++) cin>>arr[i];
    int k; cin>>k;
    int low=0;
    int high=n-1;
    cout<<binSortRecursive(arr,n,low,high,k)<<"\n";
    return 0;
}