// SMALLEST SUB-SEQUENCE WITH SUM K

#include<bits/stdc++.h>
using namespace std;

int main(){
    int n,k; cin>>n>>k;            
    vector<int>v(n);
    for(int i=0;i<n;i++) cin>>v[i];
    priority_queue<int,vector<int>>pq;
    for(int i=0;i<n;i++) pq.push(v[i]);               // PRIORITY QUEUE WILL GIVE THE ELEMENTS IN DECREASING ORDER
    int sum=0;
    int count=0;
    while(!pq.empty()){                              // TILL WE DONOT GET
        sum+=pq.top();
        pq.pop();

        count++;
        
        if(sum>=k){
            break;
        }
    }
    if(sum<k) cout<<"-1"<<"\n";
    else cout<<count<<"\n";

    return 0;
}