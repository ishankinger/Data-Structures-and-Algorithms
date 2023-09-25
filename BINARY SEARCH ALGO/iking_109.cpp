// FIND OUT THE PEAK ELEMENT OF A MOUNTAIN ARRAY
// FIRST ARRAY ELEMENTS ARE INCREASING THEN ELEMENTS ARE DECREASING

// SO IF MID IS IN INCREASING ONE THEN SEARCH SPACE WILL ONLY BE RIGHT OF IT AND WE CAN DISCARD THE LEFT OF THE SPACE
// ON OTHER HAND IF MID IS IN DECREASING THEN SEARCH SPACE WILL BE ONLY LEFT TO IT
// SO WE CAN APPLY BINARY SEARCH USING THIS CONCEPT

#include<bits/stdc++.h>
using namespace std;

int main(){
    int n; cin>>n;
    int arr[n];
    for(int i=0;i<n;i++) cin>>arr[i];

    int low=0;
    int high=n-1;
    int mid=(low+high)/2;
    while(low<=high){
        mid=(low+high)/2;
        if(arr[mid]>arr[mid-1] && arr[mid]>arr[mid+1]){
            cout<<arr[mid]<<"\n";
            break;
        }
        if(arr[mid]>arr[mid-1]){
            low=mid+1;
        }
        else if(arr[mid]<arr[mid-1]){
            high=mid-1;
        }
    }

    return 0;
}