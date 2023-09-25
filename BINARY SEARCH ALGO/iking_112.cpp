// YOU HAVE N BOXES OF CHOCLATES. EACH BOX CONTAINS Ai CHOCLATES.
// ARRAY IS GIVEN IN ASCENDING ORDER
// WE NEED TO DISRTIBUTE THESE CHOCLATES TO M STUDENTS SUCH THAT THE MAXIMUM NUMBER OF CHOCLATES 
// TO A CHILDREN SHOULD BE MINIMUM
// ONE BOX WILL BE ALLOCATED TO EXACTLY ONE STUDENT
// ALL THE BOXES SHOULD BE ALLOCATED
// EACH STUDENT HAS TO BE ALLOCATED ONE BOX
// ALLOTEMENT SHOULD BE CONTINGUOUS ORDER (A STUDENT CANNOT BE GIVEN BOX 1 AND BOX 3 SKIPPING BOX 2)
// RETURN THE MINIMUM POSSIBLE NUMBER FOR MAXIMUM CHOCLATES

#include<bits/stdc++.h>
using namespace std;

bool canDistChoclate(vector<int>arr,int mid,int &s){
    
    int n=arr.size();

    int students=1;                                      // STUDENTS THAT ARE REQUIERED 
    int currSum=0;

    for(int i=0;i<n;i++){

        if(arr[i]>mid){
            return false;
        }

        if(currSum+arr[i]>mid){
            students++;
            currSum=arr[i];
            if(students>s) return false;
        }
        else{
            currSum+=arr[i];
        }
    }
    return true;
}

int distributeChoclates(vector<int>&arr,int s){
    int n=arr.size();    
    if(n<s) return -1;

    int low=arr[0];                                  // LOW WIL BE FIRST ELEMENT
    int high=0;                                      // HIGH WILL BE LAST THAT IS TOTAL OF ALL THE ELEMENTS
    for(int i=0;i<n;i++) high+=arr[i];

    int ans=INT_MAX;
    while(low<=high){                                // NOW WE WILL USE BINARY SEARCH ALGORITHM
        int mid=(low+high)/2;
        if(canDistChoclate(arr,mid,s)){              // THIS FUNCTION WILL TELL WHETHER WE WILL GET THE ANSWER OR NOT
            ans=min(ans,mid);
            high=mid-1;
        }else{
            low=mid+1;
        }
    }
    return ans;
}

int main(){

    int n; cin>>n;
    vector<int>v(n);
    for(auto &ele:v) cin>>ele;
    int m; cin>>m;
    
    cout<<distributeChoclates(v,m);

    return 0;
}