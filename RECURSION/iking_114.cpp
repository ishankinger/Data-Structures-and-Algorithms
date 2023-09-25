// CHECK WHETHER NUMBER IS PALLINDROME OR NOT

#include<bits/stdc++.h>
using namespace std;

bool checkPall(int num,int *temp){
    if(num>=0 && num<=9){
        int lastDig=(*temp)%10;
        *temp/=10;
        return num==lastDig;
    }
    bool result=checkPall(num/10,temp) && (num%10==(*temp%10));
    (*temp)/=10;
    return result;
}
int main(){
    int n=9478749;
    int *ptr=&n;
    if(checkPall(n,ptr)) cout<<"It is a pallindromic number"<<"\n";
    else cout<<"It is not a pallindromic number"<<"\n";
    return 0;
}