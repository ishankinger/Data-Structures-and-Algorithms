// ****************** TARGET SUM SUB-ARRAY PROBLEM ************************
// AN UNSORTED ARRAY IS GIVEN OF SIZE N OF NON NEGATIVE INTEGERS, FIND A CONTINUOUS SUB ARRAY WHICH ADDS TO GIVEN NUMBER S

// ************ BRUTE FORCE METHOD ****************

#include<iostream>
using namespace std;

int main(){
    int arr[]={1,2,3,7,5};                             // GIVEN ARRAY
    int size=5;                                        // SIZE OF THE ARRAY
    int sumToFind=12;                                  // SUB ARRAY SUM TO GET
    int prefixSum=0;                                   // VARIABLE TO STORE SUM OF DIFFERENT SUB ARRAYS
    int startInd=0;                                    // STARTING INDEX OF THE SUB ARRAY
    int endInd=0;                                      // ENDING INDEX OF THE SUB ARRAY
    for(int i=0;i<size;i++){                           // TRAVERSING IN THE ARRAY USING THE FOR LOOP
        for(int j=i;j<size;j++){                       // TO MAKE SUB ARRAY
            prefixSum += arr[j];                       // IN PREFIX SUM VARIABLE ARR ELEMENTS ACC TO J IS ADDED
            if(prefixSum==sumToFind){                  // IF PREFIX SUM IS EQUAL TO SUM TO FIND
                startInd=i;                            // GET STARTING AND
                endInd=j;                              // ENDING INDEX OF THE ARRAY
                break;                                 // THEN BREAK
            }
        }
        prefixSum =0;                                  // VERY CRITICAL TO MAKE NEW SUB ARRAY SUM WE HAVE TO USE THIS
    }
    cout<<"starting index of sub array is: "<<startInd<<endl;
    cout<<"ending index of sub array is: "<<endInd<<endl;
}
