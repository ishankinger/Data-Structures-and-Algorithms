// PALLINDROMIC PATTERN

#include<iostream>
#include<vector>
using namespace std;

int main(){
    for(int i=1;i<=7;i++){
        for(int j=1;j<=7-i;j++){
            cout<<"  ";
        }
        for(int j=1;j<=i;j++){
            cout<< j<<" ";
        }
        for(int j=i-1;j>=1;j--){
            cout<< j<<" ";
        }
        cout<<endl;
    }

    // PASCAL'S TRIANGLE ( USING 2-D VECTORS )

    int n; cin>>n;
    vector<vector<int>>v(n,vector<int>(2*n+1,0));
    v[0][(2*n-1)/2]=1;
    for(int i=1;i<n;i++){
        for(int j = (2*n-1)/2-i ;  j <= (2*n-1)/2+i  ;  j++){
            if( i==n-1 && j==(2*n-1)/2-i){
                v[i][j]=1;
                continue;
            }
            v[i][j] =v[i-1][j-1]+ v[i-1][j+1];
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<(2*n)-1;j++){
            if(v[i][j]==0) cout<<"  ";
            else cout<<v[i][j]<<" ";
        }
        cout<<"\n";
    }
}