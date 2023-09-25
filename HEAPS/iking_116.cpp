// GIVEN AN ARRAY OF N INTEGERS AND WE ARE SUPPOSED TO PERFORM K OPERATIONS ON IT
// IN EACH OPERATION TWO SMALLEST ELEMENTS OF THE ARRAY ARE REMOVED FROM THE ARRAY 
// AND THEIR PRODUCT IS ADDED BACK TO THE ARRAY
// RETURN THE LARGEST ELEMENT IN THE ARRAY AFTER K OPERATIONS

// >>> CREATE A MIN HEAP
// >>> POP 2 ELEMENTS AND PUSH THEIR PRODUCT
// >> AT LAST POP UNTIL ONE ELEMENT LEFT WHICH WILL OUR LARGEST ELEMENT

#include<bits/stdc++.h>
using namespace std;

int largestPoint(vector<int> a, int n, int k){
    priority_queue<int,vector<int>,greater<int>> pq;
    for(auto i: a){
        pq.push(i);
    }
    while(k--){
        int firstEle = pq.top();
        pq.pop();
        int secondEle = pq.top();
        pq.pop();
        int product = firstEle*secondEle;
        pq.push(product);
    }
    while(pq.size()>1){
        pq.pop();
    }
    return pq.top();
}

int main(){
    int n,k;
    cin>>n>>k;
    vector<int> v(n);
    for(auto &ele:v) cin>>ele;

    cout<<largestPoint(v,n,k)<<"\n";

    return 0;
}