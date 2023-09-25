// GIVEN AN ARRAY AND WE HAVE TO CHECK WHETHER THERE EXIST ANY SUB-ARRAY OF SIZE K FROM WHICH WE CAN CONCATENATE ELEMENTS TO FORM PALLINDROME

#include<bits/stdc++.h>
using namespace std;

bool checkPall(vector<int>&vp){
    for(int i=0;i<vp.size();i++){
        if(vp[i]!=vp[vp.size()-i-1]) return false;
    }
    return true;
}

int main(){
    int n; cin>>n;
    vector<int>v(n);
    for(auto &ele:v) cin>>ele;
    int k; cin>>k;
    bool check=false;
    vector<int>vp;
    for(int i=0;i<k;i++) vp.push_back(v[i]);
    if(checkPall(vp)) check=true;
    for(int i=k;i<n;i++){
        vp.push_back(v[i]);
        vp.erase(vp.begin());
        if(checkPall(vp)){
            check=true;
            break;
        }
    }
    if(check) cout<<"YES"<<"\n";
    else cout<<"NO"<<"\n";

    return 0;
}