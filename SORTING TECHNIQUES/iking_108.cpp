// BUCKET SORT 

// SCATTER AND GATHER APPROACH

// THIS IS USED FOR DECIMAL NUMBERS
// SO ALL DECIMALS WILL LIE IN (0,1] HENCE HERE WE WILL MAKE DIFFERENT BUCKETS
// ACCORDING TO SIZE*ARR[I]

#include<bits/stdc++.h>
using namespace std;

int main(){
    int n; cin>>n;
    vector<int>v(n);
    // A BUCKET FOR EVERY INDEX IS FORMED
    vector<vector<float>>bucket(n,vector<float>());
    for(int i=0;i<n;i++){
        float ele; cin>>ele;
        int index=ele*n; 
        bucket[index].push_back(ele);
    }
    // NOW ELEMENT OF EACH BUCKET IS SORTED
    for(int i=0;i<n;i++){
        sort(bucket[i].begin(),bucket[i].end());
    }
    // NOW WE WILL SIMPLY GATHER ALL THE ELEMENTS FROM THE BUCKET
    for(int i=0;i<n;i++){
        for(int j=0;j<bucket[i].size();j++){
            cout<<bucket[i][j]<<" ";
        }
    }
    return 0;
}
// TIME COMPLEXITY = O(N2)
// SPACE COMPLEXITY = O(N+K)