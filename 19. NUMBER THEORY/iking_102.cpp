// BIT MANIPULATION

// 10111011
// INDEXING FROM RIGHT TO LEFT WITH 0 NUMBERED INDEXING
// RIGHT MOST BIT IS LEAST SIGNIFICANT BIT
// LEFT MOST BIT IS MOST SIGNIFICANT BIT
// BIT IS SET == MEANS BIT IS 1 AND FOR UNSET IT IS 0

#include<bits/stdc++.h>
using namespace std;

// >> GET BIT
// n=0101 (5)
// WE NEED TO KNOW AT ITH POSITION WHICH BIT IS PRESENT
// TO GET WE WILL FIRST MAKE 1<<I MEANS SHIFT I BITS OF 1 TOWARDS LEFT POSITION
// THEN TAKE AND WITH GIVEN NUMBER
// AS ALL OTHER ARE ZERO IN 1 EXCEPT ONE BIT THAT IS 1 IF AT THAT POSITION 1 IS PRESENT THEN 
// ANSWER WILL BE ONE ELSE ANSWER WILL BE ZERO

int getbit(int n,int pos){
    return (n & (1<<pos))!=0;
}

// >> SET BIT
// WE NEED TO SET BIT AS 1 AT GIVEN POSITION
// 1<<I AND THEN TAKE OR
// IF 1/0 ANYTHIING WITH 1 GIVE 1

int setbit(int n,int pos){
    return (n | (1<<pos));
}

// >> CLEAR BIT
// WE NEED TO MAKE ITH POSITION BIT AS 0
// 1<<I THEN TAKE COMPLEMENT TO FLIP ALL BITS
// THEN TAKE AND WITH ORIGINAL NUMBER SO AND WITH 0 ALWAYS GIVE 0

int clearbit(int n,int pos){
    int mask= ~(1<<pos);
    return (n & mask);
}

// >> UPDATE BIT
// WE NEED TO UPDATE A BIT AT GIVEN POSITION WITH GIVEN BIT
// FIRST CLEAR THE BIT AT GIVEN POSITION
// THEN WE WILL DO SET BIT

int updatebit(int n,int pos,int val){
    int mask = ~(1<<pos);
    n = n & mask;
    return (n | (val<<pos));
}

int main(){
    cout<<getbit(5,2)<<"\n";
    cout<<setbit(5,1)<<"\n";
    cout<<clearbit(5,2)<<"\n";
    cout<<updatebit(5,1,1)<<"\n";
    return 0;
}