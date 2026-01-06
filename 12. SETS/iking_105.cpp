// GIVEN TWO VECTORS V1 AND V2 WE HAVE TO RETURN THE SUM OF ALL THE COMMON ELEMENTS BETWEEN THEM

#include<bits/stdc++.h>
using namespace std;

int main(){
    int n1; cin>>n1;
    vector<int>v1(n1);
    for(auto &ele:v1) cin>>ele;

    int n2; cin>>n2;
    vector<int>v2(n2);
    for(auto &ele:v2) cin>>ele;

    set<int>s1;
    for(int i=0;i<v1.size();i++){
        s1.insert(v1[i]);
    }
    
    set<int>s2;
    for(int i=0;i<v2.size();i++){
        s2.insert(v2[i]);
    }

    int sum=0;
    for(auto ele:s2){
        if(s1.find(ele)!=s1.end()){
            sum+=ele;
        }
    }
    cout<<sum<<"\n";

    return 0;
}