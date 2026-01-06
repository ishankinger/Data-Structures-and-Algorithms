// RADIX SORT

// THIS IS UPGRADED VERSION FOR COUNT SORT
// THIS IS MAINLY MEANT FOR LARGE NUMBERS

// IN THIS WE WILL APPLY COUNT SORT DIGIT WISE

#include<bits/stdc++.h>
using namespace std;

void countSort(vector<int> &v, int pos){
    int n= v.size();
    vector<int>freq(10,0);
    for(int i=0;i<n;i++) freq[(v[i]/pos)%10]++;
    for(int i=1;i<10;i++) freq[i]+=freq[i-1];
    vector<int>ans(n);
    for(int i=n-1;i>=0;i--) ans[--freq[(v[i]/pos)%10]]=v[i];
    for(int i=0;i<n;i++) v[i]=ans[i];
}
void radixSort(vector<int>&v){
    int maxEle=INT_MIN;
    for(auto x:v){
        maxEle=max(x,maxEle);
    }
    for(int pos=1;maxEle/pos>0;pos*=10){
        countSort(v,pos);
    }
}

int main(){

    int n; cin>>n;
    vector<int>v(n);
    for(auto &ele:v) cin>>ele;
    radixSort(v);
    for(auto ele:v) cout<<ele<<" ";
}

// TIME COMPLEXITY = O((N+10)*(DIGITS OF MAXELE))
// SPACE COMPLEXITY = O(N+10)