// BASIC OPERATION ON HEAPS STL

// INSERTION USING PUSH(__) IN O(LOG(N))
// DELETION USING POP(__) IN O(LOG(N))
// FRONT ELEMENT VALUE TO BE RETURNED IN O(1) USING TOP()
// SIZE AND EMPTY FUNCTIONS ARE ALSO PRESENT

#include<bits/stdc++.h>
using namespace std;

int main(){
    
    priority_queue<int,vector<string>>pq;      
    pq.push("ishan");
    pq.push("rehan");
    pq.push("manish");
    pq.push("papa");
    pq.push("mom");
    
    cout<<pq.top()<<" ";
    pq.pop();
    cout<<pq.top()<<" \n";

    cout<<pq.size()<<"\n";
    cout<<pq.empty()<<"\n";

    return 0;
}