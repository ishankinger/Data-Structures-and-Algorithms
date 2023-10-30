// *************** OTHER WAY OF DOING LAST QUESTION ********************
// WITH ONLY ONE TRAVERSAL WE CAN ALSO DO THIS QUESTION AS----

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
        
        // DEFINING MID ELEMENT INDEX
        int mid=low+(high-low)/2;                           

         // IF WE GET OUR ELEMENT THEN PRINT IT AND BREAK
        if(arr[mid]==k){                                   
            cout<<mid<<"\n";
            break;
        }
        
        // FROM OUTER IF-ELSE, WE WILL GET TO KNOW WHETHER OUR MID IS IN FIRST INCREASING SERIES OR SECOND INCREASING SERIES
        // IF(_) IS TRUE THEN IT MEANS IT IS IN FIRST INCREASING SERIES
        if(arr[mid]>arr[low]){   
            // SO FOR FIRST INCREASING SERIES CHECK LOW AND MID
            // IF K LIES IN BETWEEN LOW AND MID THEN HIGH COMES BACK ELSE LOW MOVES FORWARD
            if(k>arr[low] && k<arr[mid]) high=mid-1;
            else low=mid+1;
            
        // ELSE IF(_) IS TRUE THEN IT MEANS IT IS IN THE SECOND INCREASING SERIES 
        }else if(arr[mid]<arr[low]){
            // SO FOR SECOND INCREASING SERIES CHECK HIGH AND MID
            // IF K LIES IN BETWEEN HIGH AND MID THEN LOW COMES FORWARD ELSE HIGH MOVES BACK
            if(k>arr[mid] && k<arr[high]) low=mid+1;
            else high=mid-1;
        }
    }
    return 0;
}
