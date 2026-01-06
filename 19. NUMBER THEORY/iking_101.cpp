// BASIC NUMBER SYSTEM 

// BASIC CONVERSIONS OF DIFFERENT NUMBER SYSTEM

#include<bits/stdc++.h>
using namespace std;

int main(){
 
    // BINARY TO DECIMAL

    int n1; cin>>n1;
    int ans1=0;
    int i=1;
    while(n1>0){
        int c=n1%10;
        ans1+=c*i;
        i*=2;
        n1/=10;
    }
    cout<<ans1<<"\n";

    // DECIMAL TO BINARY

    int n2; cin>>n2;
    int ans2=0;
    int i=1;
    while(n2>0){
        int c=n2%2;
        ans2=ans2+c*i;
        i*=10;
        n2=n2/2;
    }
    cout<<ans2<<"\n";

    // OCTAL TO DECIMAL

    int n3; cin>>n3;
    int ans3=0;
    int i=1;
    while(n3>0){
        int c=n3%10;
        ans3+=c*i;
        i*=8;
        n3/=10;
    }
    cout<<ans3<<"\n";

    // DECIMAL TO OCTAL

    int n4; cin>>n4;
    int ans4=0;
    int i=1;
    while(n4>0){
        int c=n4%8;
        ans4=ans4+c*i;
        i*=10;
        n4=n4/8;
    }
    cout<<ans4<<"\n";

    // HEXADECIMAL TO DECIMAL
    
    string n5; cin>>n5;
    int i=1;
    int ans5=0;
    for(int j=n5.size()-1;j>=0;j--){
        if(n5[j]>='0' && n5[j]<='9') ans5+=i*(n5[j]-'0');
        else if(n5[j]>='A' && n5[j]<='F') ans5+=i*(n5[j]-'A'+10);
        i*=16;
    }
    cout<<ans5<<"\n";

    // DECIMAL TO HEXADECIMAL

    int n6; cin>>n6;
    string ans6="";
    while(n6>0){
        int c=n6%16;
        char d;
        if(c<=9 && c>=0) d='0'+c;
        else d='A'+c-10;
        ans6=d+ans6;
        n6/=16;
    }
    cout<<ans6<<"\n";
}
