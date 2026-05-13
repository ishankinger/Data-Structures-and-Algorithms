// GIVEN AN INTEGER ARRAY AND INTEGER K 
// WE HAVE TO FIND THE KTH LARGEST ELEMENT ( NOT THE KTH DISTINCT ELEMENT)

// TIME COMPLEXITY => O(N.LOG(K))  AS SIZE OF HEAP IS K SO INSERTION OCCURS AS LOG(K)

#include<bits/stdc++.h>
using namespace std;

int kthLargestElement(vector<int> a, int n, int k){
    
    priority_queue<int,vector<int>,greater<int>> pq;         // CREATING A MIN HEAP
    for(int i=0;i<n;i++){
        pq.push(a[i]);                                       // WE WILL PUSH ELEMENTS K TIMES AND MAKING A CONSTANT SIZE HEAP OF SIZE K
        if(pq.size() > k){                                   // NOW EVERY TIME WE WILL POP THE SMALLEST ELEMENT
            pq.pop();
        }                                                     // AT END WE WILL POP (N-K) SMALLEST ELEMENTS
    }                                                         // AND THE TOP ELEMENT WILL NOW BE THE KTH LARGEST ELEMENT
    return pq.top();        
}

int main(){
    int n,k; 
    cin>>n>>k;
    vector<int> a(n);
    for(int i=0;i<n;i++) cin>>a[i];
    cout<<kthLargestElement(a,n,k)<<"\n";
    return 0;
}