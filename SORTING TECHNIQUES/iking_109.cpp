// DNF SORT
// Dutch National Flag Algorithm

// ALSO CALLED 0,1,2 SORT

// WE WILL USE THREE POINTERS-> LOW , MID AND HIGH

// LOW=> TELLS THE POSITION FROM WHERE 1 STARTED
// HIGH=> TELLS THE POSITION FROM WHERE 2 STARTED
// MID=> FOR UNKNOWN REGION

// IF 0 COMES , THEN SWAP ARR[LOW] AND ARR[MID] LOW++ , MID++
// IF 1 COMES , THEN MID++
// IF 2 COMES , SWAP ARR[MID] AND ARR[HIGH] HIGH--

#include<bits/stdc++.h>
using namespace std;

void dnfSort(int arr[], int n){
    int low=0;
    int mid=0;
    int high=n-1;

    while(mid<=high){
        if(arr[mid]==0){
            swap(arr[low],arr[mid]);
            low++,mid++;
        }
        else if(arr[mid]==1){
            mid++;
        }
        else{
            swap(arr[mid],arr[high]);
            high--;
        }
    }
}

int main(){
    int n; cin>>n;
    int arr[n];
    for(int i=0;i<n;i++) cin>>arr[i];
    dnfSort(arr,n);
    for(int i=0;i<n;i++) cout<<arr[i]<<" ";
    cout<<"\n";

    return 0;
}

// >>> TIME COMPLEXITY = O(N)