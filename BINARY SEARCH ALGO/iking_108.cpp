// OTHER WAY OF DOING LAST QUESTION

#include<iostream>
using namespace std;

int main(){
    int n; cin>>n;
    int arr[n];
    for(int i=0;i<n;i++) cin>>arr[i];
    int k; cin>>k;
    int low=0;
    int high=n-1;
    while(low<=high){
        int mid=low+(high-low)/2;
        if(arr[mid]==k){
            cout<<mid<<"\n";
            break;
        }
        if(arr[mid]>arr[low]){
            if(k>arr[low] && k<arr[mid]) high=mid-1;
            else low=mid+1;
        }else if(arr[mid]<arr[low]){
            if(k>arr[mid] && k<arr[high]) low=mid+1;
            else high=mid-1;
        }
    }
    return 0;
}