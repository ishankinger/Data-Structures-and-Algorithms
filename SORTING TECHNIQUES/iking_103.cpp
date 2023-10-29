// ****************** INSERTION SORT *********************

// In this algorithm, each iteration removes an element from the input data and 
// inserts it into the correct position in the list being sorted. 

// >> Adaptive: If the input list is presorted [may not be completely] then insertions sort
//              takes O(n + d), where d is the number of inversions
// >> Stable: Maintains relative order of input data if the keys are same

// Insertion sort is one of the elementary sorting algorithms with O(n2) worst-case time. Insertion
// sort is used when the data is nearly sorted (due to its adaptiveness) or when the input size is small
// (due to its low overhead).

// FIRST TRAVERSE ON EACH ELEEMENT AND  INNER WHILE LOOP WILL TRAVERSE BACK TO THAT ELEMENT
// WHILE TRAVERSING BACK IF WE GET ELEMENT LESSER THAN IT THEN INSERT OUR ELEMENT NEXT TO IT 
// AS IT WILL BE OUR REQUIRED ELEMENT'S POSITION

#include<iostream>
using namespace std;

int main(){
    
    int arr[]={12,45,51,23,8,19}; 
    // FOR 23 FIRST WE WILL TRAVERSE BACK AND FIRST 51 OCCURS NOW 51 IS GREATER SO ON 23 POSITION
    // 51 WILL TAKE PLACE AND FURTHER MOVING 45 IS ALSO GREATER SO OLD 51 POSITION TAKEN BY 45 
    // NOW 12 IS LESSER SO LOOP WILL BREAK AND
    // 23 WILL BE INSERTED NEXT TO 12 
    
    for(int i=1;i<6;i++){
        int currEle=arr[i];                // TAKE REFERENCE OF ITH ELEMENT
        int j=i-1;                         // START TRAVERSING FROM PREVIOUS OF ITH ELEMENT
        while(j >= 0 && arr[j]>currEle){   // IF WE GET ELEMENT GREATER THAN IT THEN GREATER ELEMENT WILL BE PUSHED IN JTH
            arr[j+1]=arr[j];                     
            j--;                           // FURTHER MOVE BACK
        }
        arr[j+1]=currEle;                  // WHEN WE GET OUT OF LOOP MEANS WE REACH OUR REQUIRED CONDITION
    }
    for(int i=0;i<6;i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}

// >>> TIME COMPLEXITY = O(N2)
// >>> SPACE COMPLEXITY = O(1)
