// ********************* MAXIMUM CIRCULAR SUB ARRAY SUM ********************

// CASE 1= {-1,4,-6,7,5,-4} HERE NO RAPPING IS REQUIRED AS HERE MAXIMUM WILL BE 12 WITHOUT RAPPING
// CASE 2= {4,-4,6,-6,10,-11,12} HERE AFTER RAPPING (FROM 12 TO 10) WE WILL 22 OTHERWISE WITHOUT RAPPING WE WILL GET 12

// SO FOR THIS WE WILL SIMPLY DO = TOTAL SUM OF ARRAY- TOTAL SUM OF NON CONTRIBUTING ELEMENTS
// SO THE CONCEPT USED HERE IS THAT INSTEAD OF GETTING THE MAX SUM FROM ARRAY WE WILL FIND THE MIN SUM OF SUB-ARRAY
// AS WE GET MIN SUM WE CAN SUBTRACT THEM FROM TOTAL SUM AS LEFT ELEMENTS WILL GIVE US MAXSUM AND ALSO IF WE SEE THAT THIS THING IS POSSIBLE IN
// CASE OF CIRCULAR SUBARRAY AS WE CAN MOVE IN CIRCLE AND CAN TAKE ANY SUB-ARRAY CIRCULAR WISE ALSO

#include<iostream>
#include<climits>
using namespace std;

int kadane(int arr[], int size){                      // SIMPLE FUNCTION THAT WE HAVE DONE IN PREVIOUS QUESTION 
    int currSum=0;                                    // THIS WILL RETURN THE MAXIMUM SUM OF CONTINUOUS POSITIVE INTEGERS
    int maxSum=INT_MIN;
    for(int i=0;i<size;i++){
        currSum+=arr[i];
        if(currSum<0){
            currSum=0;
        }
        maxSum= max(maxSum, currSum);
    }
    return maxSum;
}

int main(){
    int arr[]={4,-4,6,-6,10,-11,12};                  // GIVEN ARRAY
    int size=7;                                       // SIZE OF THE ARRAY
    int wrapSum;                                      // SUM USING THE CIRCULAR ARRAY TO GET MAXIMUM SUM
    int nonWrapSum;                                   // SUM WITHOUT USING THE CIRCULAR ARRAY TO GET THE MAXIMUM SUM

    nonWrapSum= kadane(arr,size);                     // NON WRAP SIMPLY FROM KADANE FUNCTION
    cout<<nonWrapSum<<endl;
    
    int totalSum=0;                                   // FOR WRAP DEFINING A TOTAL SUM VARIABLE
    for(int i=0;i<size;i++){                          // TRAVERSING USING THE LOOP
        totalSum += arr[i];                           // GET TOTAL SUM
        arr[i]=-arr[i];                               // ALSO WE HAVE REVERSED THE SIGN OF THE ELEMENTS
    }  
    cout<<kadane(arr,size)<<endl;                     // THIS IS DONE SO THAT WHEN WE CALL KADANE FUNCTION IT WILL GIVE US SUM OF NON CONTRIBUTING
    wrapSum = totalSum + kadane(arr,size);            // ELEMENTS THAT IS THAT ARE NEGATIVE PREVIOUSLY
    
    cout<<max(wrapSum,nonWrapSum);                    // MAX OF BOTH THE SUM WILL BE OUR REQUIRED ANSWER

    return 0;
}
// SO TO FIND MAX CIRCULAR SUM FOURMULA IS ==> TOTAL SUM + (MAXSUM OF OPPOSITE SIGNS)
