// PRINTING THE MAXIMUM VALUE OF THE ARRAY

#include<bits/stdc++.h>
using namespace std;

int maxValue(int arr[],int idx,int n){
    if(n==0) return -1;
    return max(maxValue(arr,idx+1,n-1), arr[idx]);
}

int main(){
    int arr[]={3,6,2,6,7,2};
    cout<<maxValue(arr,0,6);
    return 0;
}