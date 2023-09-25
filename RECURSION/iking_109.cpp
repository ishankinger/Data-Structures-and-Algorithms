// CHECK WHETHER ARRAY IS SORTED OR NOT

#include<bits/stdc++.h>
using namespace std;

bool checkSort(int arr[],int idx,int n){
    if(n==0) return true;
    return checkSort(arr,idx+1,n-1) && arr[idx+1]>=arr[idx];
}

int main(){
    int arr[]={9,5,6,8,7,9};
    if(checkSort(arr,0,6)) cout<<"array is sorted"<<"\n";
    else cout<<"array is not sorted"<<"\n";
    return 0;
}