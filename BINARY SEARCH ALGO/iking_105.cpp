// FIRST AND LAST OCCURENCE OF THE GIVEN TARGET ELEMENT IN SORTED ARRAY

#include<iostream>
using namespace std;

int main(){
    int n; cin>>n;
    int arr[n];
    for(int i=0;i<n;i++) cin>>arr[i];
    int ans1,ans2,k;
    cin>>k;
    int low=0;
    int high=n-1;
    while(low<=high){
        int mid=(low+high)/2;
        if(arr[mid]==k){
            high=mid-1;                                // FOR FIRST OCCURENCE HIGH IS MOVED BACK
            ans1=mid;
        }else if(arr[mid]<k) low=mid+1;
        else high=mid-1;
    }
    low=0,high=n-1;
    while(low<=high){
        int mid=(low+high)/2;
         if(arr[mid]==k){
            low=mid+1;                                 // FOR LAST OCCURENCE LOW IS MOVED ABOVE
            ans2=mid;
        }else if(arr[mid]<k) low=mid+1;
        else high=mid-1;
    }
    cout<<ans1<<" , "<<ans2<<"\n";
}

