// BUBBLE SORT

// SIMPLY REAPEATEDLY SWAP TWO ELEMENTS IF THEY ARE IN DIFFERENT ORDER
// AFTER ONE TRAVERSAL LARGEST ELEMENT WILL GET AT LAST POSITION
// SO EACH TIME OUR SECOND LOOP LENGTH WILL DECREASE BY ONE

#include<iostream>
#include<bits/stdc++.h>
#include<algorithm>
using namespace std;

int main(){
    int n; cin>>n;
    vector<int>v(n);
    for(auto &ele:v) cin>>ele;

    for(int i=0;i<n;i++){                           // LOOP WILL RUN N TIMES
        for(int j=0;j<=n-i-1;j++){                  // SECOND LOOP EACH TIME WILL GET SHORTEN BY ONE
            if(v[j]>v[j+1]) swap(v[j],v[j+1]);      // SWAP EACH TIME TO GET LARGEST ELEMENT AT THE BACK
        }
    }

    for(int i=0;i<n;i++) cout<<v[i]<<" ";
}

// >>> TIME COMPLEXITY = O(N2)
// >>> SPACE COMPLEXITY = O(1)
// >>> STABLE SORTING ALGORITHM
//     ex. 3 4 3* 2 ==>  2 3 3* 4
// >>> MAX SWAPS = O(N2)
