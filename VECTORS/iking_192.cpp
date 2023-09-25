// ******MAXIMUM SUB-ARRAY SUM******* 
// FROM THE ARRAY OF INTEGERS ( BOTH POSITIVE AND NEGATIVE INCLUDED )

#include<iostream>
#include<climits>                                           // USE THIS CLIMITS TO GET INT_MIN AND INT_MAX VALUES
using namespace std;

// BRUTE FORCE METHOD
// DONE WITH THREE NESTED LOOPS O(N3)

int main(){
    int arr[]={-4,3,2,-5,3,5,-2,6};                         // GIVEN ARRAY
    int size=8;                                             // SIZE OF THE ARRAY
    int maxSum=INT_MIN;                                     // INT_MIN GIVES US THE LOWEST ELEMENT IN THE ARRAY

    for(int i=0;i<size;i++){                                // GOING IN THE LOOP FOR THE STARTING INDEX
        for(int j=i;j<size;j++){                            // AGAIN INSIDE THE FOR ENDING INDEX
               int sum=0;                                   // EACH TIME FOR NEW SUB ARRAY WE HAVE TO MAKE SUM =0 VERY CRITICAL POINT
            for(int k=i;k<=j;k++){                          // LAST LOOP FOR WHICH WE HAVE TO IMPLEMENT STARTING AND ENDING INDEX
                sum += arr[k];                              // ADD SUM IN ARRAY FOR DIFFERENT SUB ARRAYS 
            }
            maxSum= max(maxSum,sum);                        // MAX SUM OF ALL THE SUB ARRAYS WILL BE STORED IN THIS VARIABLE
        }
    }
    cout<<maxSum<<endl;                                     // AND THEN PRINT MAXIMUM SUM FROM ALL THE SUB ARRAY

// OPTIMISED METHOD FOR ABOVE QUESTION
// USING PREFIX SUM ARRAY THEN DONE WITH O(N2)
     
    int currSum[size+1];                                    // MAKING A NEW ARRAY WITH SIZE OF ELEMENTS INCREASED BY ONE
    currSum[0]=0;                                           // FIRST ELEMENT OF THAT ARRAY IS GIVEN AS 0

    for(int i=1;i<size+1;i++){                              // NOW TRAVERSING IN THIS NEW ARRAY TO ADD ELEMENTS
        currSum[i]= currSum[i-1]+arr[i-1];                  // SO ELEMENT IS LIKE ADDITION OF PREVIOUS ELEMENT WITH SIMILAR ELEMENT AT THAT 
    }                                                       // INDEX OF PREVIOUS ARRAY
    for(int i=0;i<size+1;i++){                              // TRAVERSING IN THE NEW ARRAY
        int newSum=0;                                       // MAKING VARIABLE TO GIVE SUM OF SUB ARRAYS
        for(int j=0;j<i;j++){
            newSum= currSum[i]-currSum[j];                  // THIS WILL GIVE SUM OF DIFFERENT SUM OF SUB ARRAYS
            maxSum=max(newSum,maxSum);                      // THEN AGAIN SIMILARLY USING THE MAX OPERATION WE WILL GET OUR MAXIMUM SUM
        }
    }
    cout<<maxSum<<endl;                                           // PRINTING OF THE MAXIMUM SUM
    
    // KADAEN'S ALGORITHM
    // DONE WITH O(N)

    int curSum=0;                                           // UNLIKE PREVIOUS OF MAKING AN ARRAY WE WILL MAKE A VARIABLE THIS TIME
    for(int i=0;i<size;i++){                                // TRAVERSING IN THE GIVEN ARRAY
        curSum+=arr[i];                                     // ELEMENTS ARE ADDED IN THE CURR SUM
        if(curSum<0){                                       // IF CURR SUM GET LESS THEN ZERO THEN 
            curSum=0;                                       // MAKE CURR SUM EQUALS TO ZERO
        }
        maxSum=max(maxSum,curSum);                          // AND THEN MAXIMUM OF ALL SUM WE WILL GET
        }
    cout<<maxSum<<endl;                                     // PRINT THE MAXIMUM ANSWER 
    return 0;
}