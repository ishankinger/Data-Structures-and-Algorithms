// A NEW RACING TRACK FOR KIDS IS BEING BUILT IN NEW YORK WITH STARTING SPOTS
// ALL SPOTS ARE IN THUS INCREASING ORDER 
// AT A TIME ONLY M CHILDREN CAN ENTER THE RACE
// THE RACE TRACK IS FOR KIDS, THEY MAY RUN INTO EACH OTHER SO TO PREVENT THIS
// MINIMUM DISTANCE BETWEEN ANY TWO OF THEM IS AS LARGE AS POSSIBLE
// WHAT IS THE LARGEST MINIMUM DISTANCE

#include<bits/stdc++.h>
using namespace std;

bool canPlaceStudent(vector<int>&pos,int s,int mid){
    int studentsRequired=1;
    int lastPlaced=pos[0];
    for(int i=1;i<pos.size();i++){
        if(pos[i]-lastPlaced>=mid){
            studentsRequired++;
            lastPlaced=pos[i];
            if(studentsRequired==s){
                return true;
            }
        }
    }
    return false;
}

int race(vector<int>&pos,int s){
    int n=pos.size();
    int low=1; 
    int high=pos[n-1]-pos[0];
    int ans=-1;
    while(low<=high){
        int mid=(low+high)/2;
        if(canPlaceStudent(pos,s,mid)){
            ans=mid;
            low=mid+1;
        }
        else{
            high=mid-1;
        }
    }
    return ans;
}

int main(){
    int n; cin>>n;
    vector<int>v(n);
    for(auto &ele:v) cin>>ele;
    int m; cin>>m;

    cout<<race(v,m);

    return 0;
}