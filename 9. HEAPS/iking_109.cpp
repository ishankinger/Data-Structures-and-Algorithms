// GIVEN TWO BINAY MAX HEAPS THE TASK IS TO MERGE THE GIVEN HEAPS

#include<bits/stdc++.h>
using namespace std;

void heapify(vector<int> &v, int size, int curr){
    
    while(2*curr+1 < size){
        int leftchild = 2*curr + 1;                                    // NOW WE ARE USING VECTORS HERE SO INDEX STARTS FROM 0 
        int rightchild = 2*curr + 2;                                   // HENCE POSITIONS VALUES SHOULD BE MODIFIED
        int maxchild = leftchild;
        if(rightchild<=size-1 && v[rightchild]>v[maxchild]){
            maxchild = rightchild;
        }
        if(v[maxchild] <= v[curr]){
            return ;
        }
        swap(v[maxchild],v[curr]);
        curr = maxchild;
    }
}

// SIMPLY WE WILL FIRST MERGE BOTH THE VECTORS AND THEN USE THE HEAPIFY FUNCTION TO CONVERT IT INTO A MAX HEAP

vector<int> mergeHeap(vector<int> &a, vector<int> &b, int n, int m){
    vector<int> mergedHeap;
    for(auto &ele:a){
        mergedHeap.push_back(ele);
    }
    for(auto &ele:b){
        mergedHeap.push_back(ele);
    }

    int lastParentNode = (n+m)/2 - 1;
    for(int i=lastParentNode;i>=0;i--){
        heapify(mergedHeap,n+m,i);
    }
    return mergedHeap;
}

int main(){
    int n; cin>>n;
    vector<int> a(n);
    for(int i=0;i<n;i++) cin>>a[i];
    int m; cin>>m;
    vector<int> b(m);
    for(int i=0;i<m;i++) cin>>b[i];

    for(int i=0;i<a.size();i++) cout<<a[i]<<" ";
    cout<<"\n";
    for(int i=0;i<b.size();i++) cout<<b[i]<<" ";
    cout<<"\n";
    
    vector<int> ans = mergeHeap(a,b,n,m);

    for(int i=0;i<ans.size();i++){
        cout<<ans[i]<<" ";
    }

    return 0;
}