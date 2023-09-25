// GET THE SUM OF ELEMENTS OF THE ARRAY

#include<bits/stdc++.h>
using namespace std;

int sumEle(int arr[],int idx,int n){
    if(n==0) return 0;
    return sumEle(arr,idx+1,n-1)+arr[idx];
}

int main(){
    int arr[]={1,5,8,4,2,5};
    cout<<sumEle(arr,0,6);
    return 0;
}