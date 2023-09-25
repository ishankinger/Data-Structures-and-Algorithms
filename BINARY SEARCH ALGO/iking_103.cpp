// GETTING FIRST OCCURENCE OF X IN THE SORTED ARRAY

#include<iostream>
using namespace std;

void binSortRecursive(int arr[],int n,int low,int high,int k,int &ans){
    if(low>high) return;
    int mid=low+(high-low)/2;
    if(arr[mid]==k){                                                     // VERY MINUTE CHANGE THAT HERE WE WILL FURTHER CHECK AT BACK 
        high=mid-1;                                                      // THAT WHETHER SIMILAR KIND OF ELEMENT IS PRESENT OR NOT
        ans=mid;                                                         // ALSO WE WILL MAKE ONE ANS VARIABLE TO STORE OUR FINAL ANSWER
    }
    else if(arr[mid]<k)  binSortRecursive(arr,n,mid+1,high,k,ans);
    else  binSortRecursive(arr,n,low,mid-1,k,ans);
}

int main(){
    int n; cin>>n;
    int arr[n];
    for(int i=0;i<n;i++) cin>>arr[i];
    int k; cin>>k;
    int low=0;
    int high=n-1;
    int ans=0;
    binSortRecursive(arr,n,low,high,k,ans);
    cout<<ans<<"\n";
    return 0;
}