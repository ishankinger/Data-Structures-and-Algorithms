// WRITE A PROGRAM TO WRITE NUMBER OF ONES IN A BINARY NUMBER

// FOR A GIVEN NUMBER N DO (N & N-1) THEN IF 1 THEN COUNT++
// AND N=N-1 AGAIN PROCEDE WITH SAME PROCESS AND WHEN WE GET 0 WE WILL STOP

#include<bits/stdc++.h>
using namespace std;

int numberOfOnes(int n){
    int count=0;
    while(n!=0){
        n = (n & (n-1));
        count++;
    }
    return count;
}

int main(){
    cout<<numberOfOnes(19);
    return 0;
}