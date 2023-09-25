// PEAK ELEMENT IS ELEMENT GREATER THAN BOTH OF IT'S NEIGHBOUR
// SO WE HAVE TO FIND INDEX OF PEAK ELEMENT IF THERE ARE MULTIPLE PEAK THEN PRINT ANY

#include<bits/stdc++.h>
using namespace std;

int main(){
    int n; cin>>n;
    int arr[n];
    for(int i=0;i<n;i++) cin>>arr[i];

    int low=0;
    int high=n-1;
    int mid=(low+high)/2;
    int ans;
    while(low<=high){
        mid=(low+high)/2;
        if(mid==0){
            if(arr[mid]>arr[mid+1]){
                cout<<"0\n";
                return 0;
            }else{
                cout<<"1\n";
                return 0;
            }
        }
        else if(mid==n-1){
            if(arr[mid]>arr[mid-1]){
                cout<<n-1<<"\n";
                return 0;
            }else{
                cout<<n-2<<"\n";
                return 0;
            }
        }
        if(arr[mid]>arr[mid-1] && arr[mid]>arr[mid+1]){
            ans=mid;
            break;
        }
        if(arr[mid]>arr[mid-1]){
            low=mid+1;
            ans=mid;
        }
        else if(arr[mid]<arr[mid-1]){
            high=mid-1;
        }
    }
    cout<<ans<<"\n";

    return 0;
}