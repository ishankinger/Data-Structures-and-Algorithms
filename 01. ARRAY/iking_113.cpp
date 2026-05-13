// **************** NEW ARRAY MEMORY ********************
// ROTATE THE GIVEN ARRAY BY K STEPS( K CAN BE GREATER THAN SIZE OF ARRAY)

#include<iostream>
using namespace std;

int main(){
    int arr[]={1,2,3,4,5};                            // DEFINING THE ARRAY
    int n=5;                                          // SIZE OF THE ARRAY
    int k=2;                                          // TO ROTATE THE ARRAY ELEMENTS BY HOW MANY STEPS

    int newArr[5];                                    // MAKING A NEW ARRAY OF SIZE 5

    k=k%n;                                             // k CAN BE GREATER THAN n
                                                       // BUT WE WILL FOCUS ON REMIANDER USE SOME MATH TYPE THINGS
    int j=0;                                           // INITIALISATION VARIABLE SO THAT TO TRAVERSE IN THE NEW ARRAY
    for(int i=n-k;i<n;i++){                            // ADDING THE ELEMENTS IN THE ARRAY FROM THE N-K INDEX
        newArr[j++]=arr[i];                            // NEW WAY TO J++ IT WILL BE ADDING IN EACH LOOP
    }
    for(int i=0;i<=k;i++){                             // TO ADD OTHER ELEMENTS AFTER THE BEHIND ELEMENTS GET ADDED                           
        newArr[j++]=arr[i];
    }
    for(int i=0;i<n;i++){                             // NOW PRINT THE NEW ARRAY WHICH IS ROTATED ONE
        cout<<newArr[i]<<" ";
    }
}
// FOR THESE TYPES ONE OF THE APPROACH IS TO MAKE A NEW FROM THE GIVEN ARRAY ELEMENTS TO DO THE PROBLEM
