// ************* SUB ARRAY SUM DIVISIBLE BY 3 HAVING SIZE K *****************
// GIVEN AN ARRAY WE HAVE TO CHECK WHETHER THERE EXIST ANY SUB-ARRAY HAVING SIZE K WHICH FORM A NUMBER DIVISIBLE BY 3
// WHEN WE ARE DEALING WITH FIX SIZE OF SUB-ARRAY THEN WE CAN USE THIS CONCEPT OF SLIDING WINDOW 

#include<bits/stdc++.h>
using namespace std;

int sumDig(int n){
    int sum=0;
    while(n>0){
        sum+=(n%10);
        n/=10;
    }
    return sum;
}

int main(){
    int n; cin>>n;
    vector<int>v(n);
    for(auto &ele:v) cin>>ele;
    int k; cin>>k;
    int sum=0;
    bool check=false;
    for(int i=0;i<k;i++) sum+=sumDig(v[i]);
    if(sum%3==0) check=true;
    for(int i=k;i<n;i++){
        sum=sum+sumDig(v[i])-sumDig(v[i-k]);
        if(sum%3==0){
            check=true;
            break;
        }
    }
    if(check) cout<<"YES"<<"\n";
    else cout<<"NO"<<"\n";
    
    return 0;
}
