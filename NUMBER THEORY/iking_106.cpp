// XOR OPERATOR=> a^b
// a    b    a^b
// 0    0     0
// 1    1     0
// 1    0     1
// 0    1     1
// x^x==0 and x^0==x

#include<bits/stdc++.h>
using namespace std;

// WRITE A PROGRAM TO FIND A UNIQUE NUMBER IN AN ARRAY WHERE ALL NUMBERS EXCEPT ONE ARE PRESENT TWICE
// IF WE APPLY XOR TO ALL NUMBERS THEN EQUAL ELEMENTS WILL GIVE 0 AND XOR OF 0 AND NUM IS NUM
// SO FROM THAT UNIQUE ELEMENT WILL LEFT AT LAST IN XORSUM

int unique(int arr[],int n){
    int xorSum=0;
    for(int i=0;i<n;i++){
        xorSum = xorSum^arr[i];
    }
    return xorSum;
}

// WRITE A PROGRAM TO FIND TWO UNIQUE NUMBER IN AN ARRAY WHERE ALL NUMBERS EXCEPT TWO ARE PRESENT TWICE
// AT END OF LOOP WE WILL GET A^B
// NOW IN A^B AT LEAST ONE 1 BIT WILL BE PRESENT
// SO THAT BIT IS DUE TO DIFFERENT BITS AT THAT PARTICULAR POSITION ONLY
// SO A MAY HAVE 0 AT THAT THEN B MUST HAVE 1
// SO NOW WE WILL XOR ALL THE NUMBERS THAT HAVE 0 AT THAT POSITION
// THEN WE WILL GET A FROM THAT
// AND ALSO IF WE DO A^(A^B) THEN WE WILL GET B

int setBit(int n,int pos){
    return (n & (1<<pos))!=0;
}
void twoUnique(int arr[],int n){
    int xorSum=0;
    for(int i=0;i<n;i++){
        xorSum = xorSum^arr[i];
    }
    int saveXor=xorSum;
    int setbit=0;
    int pos=0;
    while(setbit!=1){
        setbit = xorSum & 1;
        pos++;
        xorSum = xorSum>>1;
    }
    int newXor=0;
    for(int i=0;i<n;i++){
        if(setBit(arr[i],pos-1)){
            newXor =newXor^arr[i];
        }
    }
    cout<<newXor<<"\n";
    cout<<(saveXor^newXor)<<"\n";
}

// WRITE A PROGRAM TO GET UNIQUE NUMBER WHERE EXCEPT THAT NUM ALL OCCUR THRICE
// SO WE WILL FORM A 64 BIT FREQUENCY ARRAY WHICH WILL STORE COUNT OF 1 ON INDEX FOR ALL ELEMENTS
// THEN WE WILL TRAVERSE IN THAT ARRAY AND WILL CHECK WHETHER THE COUNT IS DIVISIBLE BY 3
// SO COUNT%3 STORE INDEX WISE AND THEN RETURN NUM WHICH WILL BE OUR REQUIRED ANSWER

bool getBit(int n,int pos){
    return ((n & (1<<pos))!=0);
}
int setbit(int n,int pos){
    return (n | (1<<pos));
}
int threeUnique(int arr[],int n){
    int result=0;
    for(int i=0;i<64;i++){
        int sum=0;
        for(int j=0;j<n;j++){
            if(getBit(arr[j],i)){
                sum++;
            }
        }
        if(sum%3!=0){
            result = setbit(result,i);
        }
    }
    return result;
}


int main(){
    int arr[5]={1,2,3,3,1};
    cout<<unique(arr,5)<<"\n";
    int arr2[]={1,2,3,1,2,3,5,7};
    twoUnique(arr2,8);
    int arr3[]={1,2,3,4,1,2,3,1,2,3};
    cout<<threeUnique(arr3,10);

    return 0;
}