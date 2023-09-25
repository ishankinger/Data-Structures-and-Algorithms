// GETTING THE TARGET ELEMENT IN THE GIVEN SORTED ROTATED ARRAY

#include<bits/stdc++.h>
using namespace std;

int binSortRecursive(int arr[],int low,int high,int k,bool &check){           // FUNCTION TO FIND ELEMENT IN THE ARRAY
    if(low>high){
        check=false;
        return -1;
    }
    int mid=low+(high-low)/2;
    if(arr[mid]==k){
        check=true;
        return mid;
    }
    else if(arr[mid]<k) return binSortRecursive(arr,mid+1,high,k,check);
    else return binSortRecursive(arr,low,mid-1,k,check);
}
int findMin(int arr[],int n){
    int low=0,high=n-1;
    if(n==1) return low;                                          // IF ONLY ELEMENT THEN THAT WILL BE THE ANSWER
    if(arr[low]<arr[high]) return low;                            // MEANS ARRAY IS NOT ROTATED ONLY SORTED SO FIRST ELEMENT AS OUR ANSWER
    while(low<=high){                                             // USING BINARY SEARCH AND GOING IN THE LOOP
        int mid=(low+high)/2;                                     
        if(arr[mid]>arr[mid+1]) return mid+1;
        else if(arr[mid]<arr[mid-1]) return mid;
        if(arr[mid]>arr[low]) low=mid+1;
        else high=mid-1;
    }
}
int main(){
    int n; cin>>n;
    int arr[n];
    for(int i=0;i<n;i++) cin>>arr[i];
    int k; cin>>k;

    int minInd=findMin(arr,n);

    bool check1=false;
    bool check2=false;

    int k1=binSortRecursive(arr,0,minInd-1,k,check1);
    int k2=binSortRecursive(arr,minInd,n-1,k,check2);
    
    if(check1) cout<<k1;
    else if(check2) cout<<k2;
    else cout<<"Element not present\n";

    return 0;
}