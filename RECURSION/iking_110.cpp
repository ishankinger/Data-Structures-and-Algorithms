// FIND FIRST AND LAST OCCURENCE OF A GIVEN NUMBER IN AN ARRAY

#include<bits/stdc++.h>
using namespace std;

int firstOcc(int arr[],int idx,int n,int k){
    if(arr[idx]==k || n==0) return idx+1;
    firstOcc(arr,idx+1,n-1,k);
}
int lastOcc(int arr[],int idx,int n,int k){
    if(arr[idx]==k || n==0) return idx+1;
    lastOcc(arr,idx-1,n-1,k);
}
int main(){
    int arr[]={1,4,5,6,3,4,2,6,4,4,3,2};
    cout<<firstOcc(arr,0,12,4)<<" "<<lastOcc(arr,11,12,4);
    return 0;
}