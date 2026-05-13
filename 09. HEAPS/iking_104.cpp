// DELETION IN A MIN HEAP
// ONLY ROOT NODE IS DELETED IN ONE TRAVERSAL OF THE ARRAY
// AND ALSO THE RESULTED ARRAY SHOULD ALSO BE A HEAP

// TIME COMPLEXITY FOR THAT WILL BE O(LOG(N))

// ROOT NODE AND LAST NODE TO BE SWAPPED
// THEN DELETE THE LAST NODE
// THEN TRAVERSE IN THE ARRAY AND CHECK THE CONDITION FOR MIN HEAP
// CONDITION IS LIKE THAT FIRST CHECK IT'S MIN VALUE OF LEFT CHILD AND RIGHT CHIILD 
// AND SWAP MINIMUM WITH THAT ROOT NODE, NOW AGAIN DO SAME TILL IT IS LESS THAN BOTH OF IT'S CHILD

#include <iostream>
#include <vector>
using namespace std;
const int N = 1e3;

void deleteMinHeap(int minHeap[],int &size){
        swap(minHeap[1],minHeap[size]);                                          // FIRST LAST AND ROOT NODE ARE SWAPPED
        size--;                                                                  // THEN SIZE DECREASE
        int curr = 1;                                                            // POINTER TO TRAVERSE IN THE ARRAY

        while(curr <= (size/2) && minHeap[curr]>max(minHeap[2*curr],minHeap[2*curr + 1])){

            if(2*curr == size){                                                   // THIS MEANS THAT RIGHT CHILD FOR THIS NODE IS NOT PRESENT
                swap(minHeap[curr],minHeap[2*curr]);                              // THIS IS CONSIDER AS A CORNER CASE AS IF WE DONOT PUT THIS 
                curr = 2*curr;                                                    // THEN THE LAST VALUE WHICH WAS INITIALLY FIRST NODE WILL ALSO
                continue;                                                         // BE IN THE ARRAY SWAPPING
            }
            
            if(minHeap[2*curr]< minHeap[2*curr + 1]){                            // LEFT CHILD < RIGHT CHILD
                swap(minHeap[curr],minHeap[2*curr]);                             // THEN SWAP WITH LEFT CHILD
                curr = 2*curr;                                                   // UPDATE THE CURRENT POINTER
            }
            else{
                swap(minHeap[curr],minHeap[2*curr + 1]);                          // ELSE SWAP WITH RIGHT CHILD
                curr = 2*curr + 1;                                                // AGAIN UPDATE THE POINTER
            }
        }
}

int main(){
    int minHeap[N] = {-1,5,20,10,40,50,30,60};
    int size = 7;
    for(int i=1;i<=size;i++){
        cout<<minHeap[i]<<" ";
    }
    cout<<"\n";
    deleteMinHeap(minHeap,size);
    for(int i=1;i<=size;i++){
        cout<<minHeap[i]<<" ";
    }
    cout<<"\n";

    return 0;
}
