// ************* SORTING AN ARRAY CONSISTING OF ONLY 0's AND 1's ****************

// ************ USING NEW ARRAY METHOD ************

#include<iostream>
using namespace std;

int main(){
    int arr[]= {1,0,0,0,1,0,1,0,1,1,1};          // MAKING AN ARRAY OF ONLY 0's AND 1's
    int size=11;
    int newArr[size];                            // DEFINING A NEW ARRAY
    int j=0;                                     // INITIALISING VARIABLE FOR TRAVERSING IN THE LOOP
    for(int i=0;i<size;i++){                     // TRAVERSING IN THE ARRAY TO GET 0'S
        if(arr[i]==0){                           // IF ELEMENT EQUAL TO 0
            newArr[j++]=arr[i];                  // ADD THAT IN NEW ARRAY INITIAL ELEMENTS
        }
    }
    for(int i=0;i<size;i++){                     // SAME FOR ONES BUT THEY WILL BE ADDED AFTER ALL THE ZEROES ARE ADDED
        if(arr[i]==1){
            newArr[j++]=arr[i];
        }
    }
    
    for(int i=0;i<size;i++){                     // NOW PRINTING OUR NEW ARRAY
        cout<<newArr[i]<<" ";
    }
}
