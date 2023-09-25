// SIGNED AND UNSIGNED INTEGERS

#include<bits/stdc++.h>
using namespace std;

int main(){
    cout<<INT_MAX<<"\n";       // (1<<32) WILL NOT STORE IN INT SO MAKE IT LONG LONG
    int a=(1LL<<32)-1;         // 1<<n ==2 pow n 
    cout<<a<<"\n";             // THIS IS SIGNED MEANS 1 BIT RESERVE FOR SIGN THAT IS NUM + OR -
                               // SO OUTPUT IS -1 MEANS OVERFLOW
    int b=(1LL<<31)-1;         // HERE IF WE SEE IT WILL GIVE US OUR REQUIRED VALUE
    cout<<b<<"\n";

    unsigned int c=(1LL<<32)-1; // NOW HERE THAT EXTRA BIT IS NOT PRESENT
    cout<<c<<"\n";
    unsigned int d=(1LL<<31)-1;
    cout<<d<<"\n";
    
    return 0;
}