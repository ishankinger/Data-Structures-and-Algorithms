// *********** FIND THE SECOND LARGEST ELEMENT IN THE GIVEN ARRAY **************
// ( ELEMENT CAN HAVE DUPLICATES)

#include<iostream>
using namespace std;

int main(){
    int arr[]={2,3,6,9,5,9,4};                           // MAKING A GIVEN ARRAY
     int max= arr[0];                                    // SAME METHODOLOGY TAKE MAX VARIABLE AS FIRST ELEMENT
        int maxIndex=-1;                                 // INDEX OF THAT ELEMENT AS INITIALISATION VALUE OF -1
        for(int i=0;i<7;i++){                            // TRAVERSING IN THE ARRAY USING FOR LOOP
            if(arr[i]>max){                              // IF WE GET NUMBER GREATER
                max=arr[i];                              // THEN REPLACE THE VALUE
                maxIndex=i;                              // ALSO CHANGE THE INDEX OF THE MAXIMUM ELEMENT 
            }
        }

    int c=arr[maxIndex];                                 // FIRST STORE VALUE OF MAX IN OTHER VARIBLE
    arr[maxIndex]=-1;                                    // THEN MANIPULATE IT'S VALUE
   
    for(int i=0;i<7;i++){                                // THIS LOOP IS TO MANIPULATE DUPLICATES OF THE MAX ELEMENT                            
        if(arr[i]==c){             
            arr[i]=-1;
        }
    }
    int secMax=arr[0];                                   // NOW SAME LOOP TO GET SEC MAX ELEMENT
    int secMaxInd=-1;
    for(int i=0;i<7;i++){
        if(arr[i]>secMax){
            secMax=arr[i];
            secMaxInd=i;
        }
    }

    cout<<"second largest element in the array : "<< arr[secMaxInd];   //  NOW PRINT THAT ELEMENT
}
