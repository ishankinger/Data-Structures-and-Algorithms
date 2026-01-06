// ********************* MAXIMUM CIRCULAR SUB ARRAY SUM ********************

// CASE 1= {-1,4,-6,7,5,-4} HERE NO RAPPING IS REQUIRED AS HERE MAXIMUM WILL BE 12 WITHOUT RAPPING
// CASE 2= {4,-4,6,-6,10,-11,12} HERE AFTER RAPPING (FROM 12 TO 10) WE WILL 22 OTHERWISE WITHOUT RAPPING WE WILL GET 12

// SO FOR THIS WE WILL SIMPLY DO = TOTAL SUM OF ARRAY- TOTAL SUM OF NON CONTRIBUTING ELEMENTS
// SO THE CONCEPT USED HERE IS THAT INSTEAD OF GETTING THE MAX SUM FROM ARRAY WE WILL FIND THE MIN SUM OF SUB-ARRAY
// AS WE GET MIN SUM WE CAN SUBTRACT THEM FROM TOTAL SUM AS LEFT ELEMENTS WILL GIVE US MAXSUM AND ALSO IF WE SEE THAT THIS THING IS POSSIBLE IN
// CASE OF CIRCULAR SUBARRAY AS WE CAN MOVE IN CIRCLE AND CAN TAKE ANY SUB-ARRAY CIRCULAR WISE ALSO

#include<bits/stdc++.h>
using namespace std;

int kadane(int arr[], int size){                      // SIMPLE FUNCTION THAT WE HAVE DONE IN PREVIOUS QUESTION 
    int currSum=0;                                    // THIS WILL RETURN THE MAXIMUM SUM OF CONTINUOUS POSITIVE INTEGERS
    int maxSum=INT_MIN;
    for(int i=0;i<size;i++){
        currSum+=arr[i];
        maxSum= max(maxSum, currSum);
        if(currSum<0) currSum=0;
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
    
    if(wrapSum == 0){
        cout << nonWrapSum << "\n";
        return 0;
    }
    cout<<max(wrapSum,nonWrapSum);                    // MAX OF BOTH THE SUM WILL BE OUR REQUIRED ANSWER

    return 0;
}
// SO TO FIND MAX CIRCULAR SUM FOURMULA IS ==> TOTAL SUM + (MAXSUM OF OPPOSITE SIGNS)

int kadane(vector<int> nums){
    int maxSum = INT_MIN, sum = 0;
    for(int i = 0; i < nums.size(); i++){
        sum += nums[i];
        maxSum = max(sum,maxSum);
        if(sum < 0) sum = 0;
    }
    return maxSum;
}
int maxSubarraySumCircular(vector<int>& nums) {
    int non_wrap = kadane(nums);
    int totalSum = 0;
    for(int i = 0; i < nums.size(); i++) totalSum += nums[i], nums[i] *= -1;
    int wrap = totalSum + kadane(nums);
    if(wrap == 0) return non_wrap;
    return max(wrap,non_wrap);
}

// We can also combine both sum loops to make one loop