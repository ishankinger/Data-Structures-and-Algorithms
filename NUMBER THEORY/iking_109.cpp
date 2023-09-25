// SOME IMPORTANT TRICKS ON BIT MANIPULATION

#include<bits/stdc++.h>
using namespace std;

// >> PRINTING OF A BINARY NUMBER
void printBinary(int num){
    for(int i=10;i>=0;i--){
        cout<<((num>>i)&1);
    }
    cout<<"\n";
}

int main(){

// >> CHECK NUMBER IS EVEN OR ODD
    int n=5;
    if(n & 1){                         // IF NUMBER ODD THEN AT LAST 1 IS PRESENT 
        cout<<"odd\n";                 // SO & WITH 1 WILL NOT GIVE 0 SO ODD
    }
    else{                              // ELSE 000001 WILL MAKE ALL 0 SO EVEN
        cout<<"even\n";
    }                                  // THIS METHOD IS FASTER THAN N%2==0

// >> MULTIPLY OR DIVIDE BY 2
    int a=5;
    cout<<(a>>1)<<"\n";                // RIGHT SHIFT MEANS DIVIDE BY 2
    cout<<(a<<1)<<"\n";                // LEFT SHIFT MEANS MULTIPLY BY 2

// >> CONVERTING FROM UPPERCASE TO LOWERCASE AND VICE VERSA
    char ch1='a';
    char ch2='A';
    printBinary(ch1);
    printBinary(ch2);
    // difference between these two binaries is at 6th pos from end as they have diff of 32
    // so to make conversion from ch1 to ch2 we want clear bit at 6 pos and for vice versa we want set bit
    
    ch2= 'A' | (1<<5);
    cout<<char(ch2)<<"\n";

    ch1 = 'a' & (~(1<<5));
    cout<<char(ch1)<<"\n";

    // (1<<5)-> ' '  &&  ~(1>>5)->'_'
    cout<<char('C' | ' ')<<"\n";
    cout<<char('c' & '_')<<"\n";

// >> CLEAR ALL THE BITS TILL GIVEN NUMBER OF BITS
    int b=59;
    int i=4;
    cout<< (b & (~((1<<(i+1))-1))) <<"\n";
    cout<< (b & (1<<i+1))<<"\n";

    return 0;
}