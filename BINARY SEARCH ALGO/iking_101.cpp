// ********************** BINARY SEARCH ALGORITHM ************4***************
// GETTING TARGET ELEMENT IN SORTED ARRAY IN O(LOG(N)) USING THIS ALGO

#include<iostream>
using namespace std;

int main(){
    int n; cin>>n;
    int arr[n];
    for(int i=0;i<n;i++) cin>>arr[i];
    int k; cin>>k;
    int low=0;                                          // TWO POINTERS TO DEFINE FOR BINARY SEARCH ALGORITHM
    int high=n-1;                                       // LOW POINTER INITIALIZE FROM FIRST ELEMENT AND HIGH POINTER FROM LAST ELEMENT
    bool check=false;
    while(low<=high){                                   // WE WILL MOVE IN THIS TILL LOW OVERTAKE HIGH
        int mid=(low+high)/2;                           // MID VARIABLE : THE KEY THING OF BINARY SEARCH ( THIS MAKES IT SO EFFICIENT )
        if(arr[mid]==k){                                // IF WE GET TARGET ELEMENT THEN BREAK;
            check=true;
            break;
        }
        else if(arr[mid]<k) low=mid+1;                  // ELSE IF NOT THEN LOW MID+1 MEANS WE WILL CHECK PART OF ARRAY ABOVE THE MID ELEMENT
        else if(arr[mid]>k) high=mid-1;                 // IF GREATER THEN WE WILL CHECK PART BELOW PART OF ARRAY
    }
    if(check) cout<<"Target element is present"<<"\n";
    else cout<<"Target element is not present"<<"\n";
    return 0;
} 
