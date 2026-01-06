// GIVEN AN ARRAY AND AN INTEGER K WHERE K IS SMALLER THAN THE SIZE OF THE ARRAY
// THE TASK IS TO FIND THE KTH SMALLEST ELEMENT IN THE GIVEN ARRAY. GIVEN THAT ELEMENT ARE DISTINCT

// SO FIRST WE WILL CREATE A MIN HEAP AND THEN REMOVE (K-1) ELEMENTS
// THUS OUR ANS WILL BE FIRST ELEMENT OF THE ARRAY

#include<bits/stdc++.h>
using namespace std;

void heapify(vector<int> &v,int size, int curr){                  // HEAPIFY FUNCTION TO CREATE A MIN HEAP
    while(2*curr + 1 < size){
        int leftchild = 2*curr + 1;
        int rightchild = 2*curr + 2;
        int minchild = leftchild;

        if(rightchild<size && v[rightchild]<v[minchild]){
            minchild = rightchild;
        }
        if(v[minchild] >= v[curr]){
            return;
        }
        swap(v[minchild],v[curr]);
        curr = minchild;
    }
}

void remove(vector<int> &v, int &size){
    v[0] = v[size-1];
    size--;
    heapify(v,size,0);
}

int kthSmallestElement(vector<int> &v, int size, int k){

    for(int i=(size/2)-1;i>=0;i--){                            // FIRST HEAPIFY THE GIVEN ARRAY INTO MIN HEAP
        heapify(v,size,i);
    }

    k -= 1;                                                   // K-1 TIMES ELEMENT WILL BE REMOVED
    while(k--){                                               // AS WE ARE CONVERTING IT INTO A MIN HEAP SO ELEMENTS WILL OCCUR IN INCRESING ORDER
        remove(v,size);                                       // HENCE KTH ELEMENT WILL BE KTH SMALLEST ELEMENT
    }
    return v[0];
}

int main(){
    int n; cin>>n;
    vector<int> v(n);
    for(int i=0;i<n;i++) cin>>v[i];
    int k; cin>>k;

    cout<<kthSmallestElement(v,n,k);

    return 0;
}