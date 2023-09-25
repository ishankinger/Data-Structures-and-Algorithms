// PRINTING OF ELEMENTS OF AN ARRAY RECURSIVELY

#include<bits/stdc++.h>
using namespace std;

void printEle(int arr[],int idx,int n){
    if(n==0) return;
    cout<<arr[idx]<<" ";
    printEle(arr,idx+1,n-1);
}
void printEleRev(int arr[],int idx,int n){
    if(n==0) return;
    printEleRev(arr,idx+1,n-1);
    cout<<arr[idx]<<" ";
}
int main(){
    int arr[]={1,2,3,4,5};
    printEle(arr,0,5);
    cout<<"\n";
    printEleRev(arr,0,5);
    return 0;
}