// ***************** GETTING THE MINIMUM ELEMENT IN A ROTATED ARRAY ***********************

#include<iostream>
using namespace std;

int findMin(int arr[],int n){
    int low=0,high=n-1;
    if(n==1) return low;                                          // IF ONLY ELEMENT THEN THAT WILL BE THE ANSWER
    if(arr[low]<arr[high]) return low;                            // MEANS ARRAY IS NOT ROTATED ONLY SORTED SO FIRST ELEMENT AS OUR ANSWER
    while(low<=high){    
                                                 
        int mid=(low+high)/2;                         
        
        // TERMINATING CONDITIONS
        if(arr[mid]>arr[mid+1]) return mid+1;                    // THIS IS POSSIBLE FOR BIGGEST ELEMENT
        else if(arr[mid]<arr[mid-1]) return mid;                 // THIS CONDITION IS POSSIBLE ONLY FOR SMALLEST ELEMENT
        
        // MOVING CONDITION
        if(arr[mid]>arr[low]) low=mid+1;                         // IF MID>LOW THEN LOWER ELEMENT IN RIGHT OF MID                 
        else high=mid-1;                                         // ELSE IN LEFT OF MID 
    }
}
int main(){
    int n; cin>>n;
    int arr[n];
    for(int i=0;i<n;i++) cin>>arr[i];
    cout<<findMin(arr,n);
    return 0;
}
