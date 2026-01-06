// GIVEN P AND Q GET THE VALUE OF P^Q

#include<bits/stdc++.h>
using namespace std;

int raiseToPow1(int p,int q){
    if(q==1) return p;
    return p*raiseToPow1(p,q-1);
}
int raiseToPow2(int p,int q){
    if(q==0) return 1;
    if(q%2==0){
        int res=raiseToPow2(p,q/2);
        return res*res;
    }else{
        int res=raiseToPow2(p,q/2);
        return res*res*p;
    }
}
int main(){
    cout<<raiseToPow2(5,3);
    return 0;
}