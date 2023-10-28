// ********************* EXTRACTING SUM FROM A 2-D MATRIX ****************************
// GIVEN A 2D VECTOR WE HAVE TO FIND THE SUM OF RECTANGLE HAVING COODINATES AS (L1,R1) AND (L2,R2)

#include<bits/stdc++.h>
using namespace std;

int main(){

    // ************** BRUTE FORCE METHOD ******************

    int n,m; cin>>n>>m;
    vector<vector<int>>v(n,vector<int>(m));
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>v[i][j];
        }
    }
    int l1,r1,l2,r2; cin>>l1>>r1>>l2>>r2;
    int sum=0;
    for(int i=l1;i<=l2;i++){
        for(int j=r1;j<=r2;j++){
            sum+=v[i][j];
        }
    }
    cout<<sum<<"\n";

    // **************** PREFIX SUM APPROACH( ROW WISE ) ******************

    for(int i=0;i<n;i++){
        for(int j=1;j<m;j++){
            v[i][j]+=v[i][j-1];
        }
    }
    int ans=0;
    for(int i=l1;i<=l2;i++){
        ans+=v[i][r2]-v[i][r1-1];
    }
    cout<<ans<<"\n";

    // *************** PREFIX SUM APPROACH ( BOTH ROW WISE AND COLUMN WISE ) **********************
    
    for(int j=0;j<m;j++){
        for(int i=1;i<n;i++){
            v[i][j]+=v[i-1][j];
        }
    }
    cout<<v[l2][r2]-v[l1-1][r2]-v[l2][r1-1]+v[l1-1][r1-1]<<"\n";

    return 0;
}
