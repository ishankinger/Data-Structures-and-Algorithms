// HEAP STL
// MAX HEAP-> PRIORITY QUEUE
// MIN HEAP-> PRIORITY QUEUE WITH GREATER<INT> CONTAINER
// PRIORITY QUEUE WILL RETURN THE QUEUE IN DECREASING ORDER
// OTHER ONE WILL RETURN IN INCREASING SORTED ORDER

#include<bits/stdc++.h>
using namespace std;

int main(){
    
    priority_queue<int,vector<int>>pq;     // MAX HEAP BY DEFAULT
    for(int i=0;i<6;i++) pq.push(i);       // COMPLEXITY WILL BE N*LOG(N)
    for(int i=0;i<6;i++){
        cout<<pq.top()<<" ";               // COPLEXITY WILL BE O(1)
        pq.pop();                          // COMPLEXITY WILL BE O(LOG(N))
    }                                      // NET COMPLEXITY WILL BE O(N*LOG(N))
    cout<<"\n";

    priority_queue<int,vector<int>,greater<int>>pqr; // MIN HEAP ( WRITE GREATER<INT> TO DISINGUISH)
    pqr.push(4);                                      
    pqr.push(3);
    pqr.push(7);
    pqr.push(1);
    pqr.push(2);
    for(int i=0;i<5;i++){
        cout<<pqr.top()<<" ";                       // TOP ELEMENT WILL BE THE MINIMUM ELEMENT
        pqr.pop();                                  // TOP ELEMENT WILL BE POP OUT
    }
    cout<<"\n";

    return 0;
}