// HEAPIFY
// ARRANGING NODE IN CORRECT ORDER SO THAT THEY FOLLOW PROPERTIES OF MIN/MAX HEAP

// USING HEAPIFY TO GENERATE A MIN HEAP
/*          (60)                             (5)
           /    \                           /    \ 
          (10)   (80)         ===>        (10)   (20)
         /   \   /   \                   /   \   /   \ 
      (50)  (5) (20) (70)              (50) (60) (80) (70)
*/
// WE WILL START CHECKING FROM THE LAST PARENT NODE
// IF MIN CHILD VALUE IS LESS THAN CURR NODE THEN SWAP
// THEN MOVE TO PREV NODE FOR LAST PARENT NODE (MEANS IN SAME LEVEL)
// WHEN WE MOVE ON FURTHER PARENT LEVEL THEN WE HAVE TO ALSO CHECK THE NODES WHICH ARE SWAPPED
// AS NODE SWAPPED MAY NOT SATISFY CONDITION WITH MIN AND AMX HEAP

// LEAF NODE IN ARRAY OF HEAP STARTS FROM (N/2)+1
// BEFORE THAT ALL WILL BE NON-LEAF NODES
// LAST PARENT NODE WILL BE AT (N/2) 

// TIME COMPLEXIY OF HEAPIFY => O(LOG(N)) 

#include <iostream>
#include <vector>
using namespace std;
const int N = 1e3;

void heapify(int arr[], int &size, int curr){
    
    while(2*curr <= size){                                                // SIMILAR WHILE LOOP AS DONE IN DELETION ONLY DIFF IS HERE WE USE INDICES
        int leftChild = 2*curr;
        int rightChild = 2*curr + 1;
        int minChild = leftChild;

        if(rightChild<=size && arr[rightChild]<arr[minChild]){            // THIS CONDITION CHECK TWO THINGS ONE THAT RIGHT CHILD IS PRESENT OR NOT
            minChild = rightChild;                                        // OTHER THAT THE RIGHT CHILD IS SMALLER THAN LEFT OR NOT
        }                                                                 // IF BOTH CONDITION SATISFY THEN ONLY CHANGE MINCHILD TO RIGHT ELSE NOT

        if(arr[minChild] >= arr[curr]){                                   // IF OUR CONDITON IS TRUE THAT PARENT IS LESS THAN IT'S MIN CHILD
            return;                                                       // THEN SIMPLY RETURN
        } 
        swap(arr[minChild],arr[curr]);                                    // ELSE WE WILL SWAP THE ELEMENTS
        curr = minChild;                                                  // UPDATE THE CURR VALUE ALSO
    }
}

int main(){
    int arr[N] = {-2,60,10,50,5,80,70};
    int size = 6;
    for(int i=size/2;i>0;i--){           // i IS A PARENT NODE HERE
        heapify(arr,size,i);             // THIS WILL HEAPIFY EACH PARENT NODE STARTING FROM THE LAST PARENT NODE
    }
    for(int i=1;i<=size;i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}
