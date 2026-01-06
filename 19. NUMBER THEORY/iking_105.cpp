// WRITE A PROGRAM TO GENERATE ALL POSSIBLE SUB-SETS OF A GIVEN SET

// {a,b,c} ~ BINARY REPRESENTATION
// BIT MASKING-

// {}       => 000
// {c}      => 001
// {b}      => 010
// {b,c}    => 011
// {a}      => 100
// {a,c}    => 101
// {a,b}    => 110
// {a,b,c}  => 111

#include<bits/stdc++.h>
using namespace std;

void subsets(int arr[],int n){
    for(int i=0;i<(1<<n);i++){      // TRAVERSING IN ALL THE NUMBERS FROM 0 TO 2^N-1
        for(int j=0;j<n;j++){       // NOW WE WILL TRAVERSE IN THE RESPECTIVE NUMBERS BINARY
            if( i & (1<<j)){        // AND CHECK AT WHICH POSITION SET BIT IS PRESENT
                cout<<arr[j];       // IF SET BIT IS PRESENT THAT MEANS ELEMENT IS PRESENT AT THAT POSITION
            }
        }
        cout<<"\n";                 // AFTER J LOOP WE WILL GET ONE SUB-SET SO COUT
    }
}

int main(){
    int arr[4]={1,2,3,4};
    subsets(arr,4);
    return 0;
}