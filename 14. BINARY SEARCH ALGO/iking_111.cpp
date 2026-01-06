// *************** BINARY SEARCH IN A 2-D ARRAY ***************
// 2-D ARRAY IS SORTED ROW-WISE AND LAST ELE OF ROW (N-1)th IS LESS THAN FIRST ELE OF ROW Nth

// SO SIMPLY IT IS SORTED ARRAY OF SIZE 0 - N.M-1
// X=MID / M AND Y=MID % M

#include<bits/stdc++.h>
using namespace std;

bool searchMatrix(vector<vector<int>>&a, int target){
    int n=a.size();
    int m=a[0].size();

    int low=0,high=(n*m)-1;
    while(low<=high){
        // MID INDEX AS THE BINARY SEARCH FOR THE 2-D ARRAY WHEN CONVERTED INTO 1-D ARRAY
        int mid=(low+high)/2;
        // GETTING THE COORDINATES OF X,Y ACCORDING TO THE MID VALUE
        int x=mid/m;
        int y=mid%m;
        // NOW SIMPLY APPLY BINARY SEARCH TO THE COORDINATES
        if(a[x][y]==target){
            return true;
        }
        else if(a[x][y]<target){
            low=mid+1;
        }
        else{
            high=mid-1;
        }
    }
    return false;
}

int main(){
    int n,m; cin>>n>>m;
    vector<vector<int>>v(n,vector<int>(m));
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>v[i][j];
        }
    }
    int k; cin>>k;

    if(searchMatrix(v,k)) cout<<"Present\n";
    else cout<<"Absent\n";

    return 0;
}
