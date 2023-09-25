// COUNTING THE TOTAL NUMBER OF PATHS TO GO FROM ONE END OF GRID TO OTHER CORNER END

#include<bits/stdc++.h>
using namespace std;

int f(int i,int j,int m,int n){
    if(i==m-1 && j==n-1) return 1;
    else if(i>=m || j>=n) return 0;
    return f(i+1,j,m,n)+f(i,j+1,m,n);
}

int main(){
    cout<<f(0,0,2,3)<<"\n";  
    return 0;
}