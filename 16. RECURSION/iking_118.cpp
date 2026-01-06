// CHECKING WHETHER A NUMBER IS ARMSTRONG OR NOT

#include<bits/stdc++.h>
using namespace std;

int countDig(int n){
    if(n==0) return 0;
    return 1+countDig(n/10);
}
int checkArmstrong(int n,int k){
    if(n==0) return 0;
    return pow(n%10,k)+checkArmstrong(n/10,k);
}

int main(){
    int n; cin>>n;
    int k=countDig(n);
    cout<<k<<"\n";
    cout<<checkArmstrong(n,k)<<"\n";
    if(checkArmstrong(n,k)==n) cout<<"IT'S AN ARMSTRONG NUMBER"<<"\n";
    else cout<<"IT'S NOT AN ARMSTRONG NUMBER"<<"\n";
    return 0;
}