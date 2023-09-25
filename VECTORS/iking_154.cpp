// *****TARGET SUM PROBLEMS*****
// TOTAL NUMBER OF PAIRS IN THE ARRAY WHOSE SUM IS EQUAL TO THE GIVEN VALUE OF X
// BRUTE FORCE METHOD

#include<iostream>
using namespace std;

int main(){
    int arr[]={3,4,5,6,2};                               // MAKING THE ARRAY
    int x=7;                                             // SUM TO BE EQUAL TO THIS NUMBER
    
    int pairs=0;                                          // VARIABLE TO TELL NUMBER OF THE PAIRS
    for(int i=0;i<5;i++){                                 // OUTER LOOP FOR CHOOSING FIRST ELEMENT
        for(int j=i+1;j<5;j++){                           // IT WILL MOVE FURTHER OF THE ELEMENT CHOSEN IN THE FIRST LOOP
           if(arr[i]+arr[j]==x){                          // CONDITION THAT ANY PAIR HAS SUM EQUAL TO GIVEN NUMBER OR NOT
            pairs++;                                      // NOW WE WILL CONSECUTIVELY ADD THE PAIRS
           }
        }
    }
    cout<<pairs;                                          // AT LAST PRINT THE PAIRS
}
// THIS NESTED LOOP CONCEPT IN ARRAY HELP A LOT TO COMPARE ONE ELEMENT AT A TIME WITH ALL ELEMENTS NEXT TO IT
// SO WHENEVER WE NEED THIS TYPE OF SITUATION THIS BRUTAL FORCE METHOD SHOULD BE USED