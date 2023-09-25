// WAVE SORT

// 1>=2<=3>=4<=5>=6....

#include<bits/stdc++.h>
using namespace std;

int main(){
    int n; cin>>n;
    int arr[n];
    for(int i=0;i<n;i++) cin>>arr[i];

    for(int i=1;i<=n-1;i+=2){
        if(arr[i]>arr[i-1]){
            swap(arr[i],arr[i-1]);
        }
        if(arr[i]>arr[i+1] && i<=n-2){
            swap(arr[i],arr[i+1]);
        }
    }
    for(int i=0;i<n;i++) cout<<arr[i]<<" ";

    return 0;
}
// >>> TIME COMPLEXITY = O(N)