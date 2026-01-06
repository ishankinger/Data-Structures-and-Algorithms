// ****************** SMALLEST POSITIVE MISSING NUMBER ******************
// OUR TASK IS TO FIND THE SMALLEST INTEGER WHICH IS MISSING FROM THE ARRAY

#include<bits/stdc++.h>
using namespace std;

int main(){
    int n; cin>>n;
    vector<int>v(n);
    for(int &ele:v) cin>>ele;
    sort(v.begin(),v.end());
    int ans;
    for(int i=0;i<n;i++){
        if(v[i]>0 && v[i+1]!=v[i]+1){
            ans=v[i]+1;
            break;
        }
    }
    cout<<ans<<"\n";
    return 0;
}
// OTHER WAY TO DO THIS QUESTION IS BY MAKING A BOOLEAN ARRAY AND THEN IF WE GET OUR ELEMENT THEN GIVE IT TRUE
// AND THEN TRAVERSE IN BOOL ARR AND GET FIRST FALSE INDEX AS OUR ANSWER
