// DELETION IN A MAX HEAP
// HERE SWAPPING WILL OCCUR ON THE CONDITION THAT HIGHEST OF BOTH CHILD SHOULD BE SWAPPED
// AS IN MAX HEAP WE WANT PARENT TO BE GREATER THAN IT'S CHILD

#include <iostream>
#include <vector>
using namespace std;
const int N = 1e3;

void deleteMaxHeap(int maxHeap[], int &size){
    swap(maxHeap[1],maxHeap[size]);                                          // FIRST LAST AND ROOT NODE ARE SWAPPED
        size--;                                                                  // THEN SIZE DECREASE
        int curr = 1;                                                            // POINTER TO TRAVERSE IN THE ARRAY
        while(curr <= (size/2) && maxHeap[curr]<max(maxHeap[2*curr],maxHeap[2*curr + 1])){

            if(2*curr == size){                                                   // THIS MEANS THAT RIGHT CHILD FOR THIS NODE IS NOT PRESENT
                swap(maxHeap[curr],maxHeap[2*curr]);                              // THIS IS CONSIDER AS A CORNER CASE AS IF WE DONOT PUT THIS 
                curr = 2*curr;                                                    // THEN THE LAST VALUE WHICH WAS INITIALLY FIRST NODE WILL ALSO
                continue;                                                         // BE IN THE ARRAY SWAPPING
            }
            if(maxHeap[2*curr]< maxHeap[2*curr + 1]){                            // LEFT CHILD < RIGHT CHILD
                swap(maxHeap[curr],maxHeap[2*curr + 1]);                             // THEN SWAP WITH LEFT CHILD
                curr = 2*curr + 1;                                                   // UPDATE THE CURRENT POINTER
            }
            else{
                swap(maxHeap[curr],maxHeap[2*curr]);                          // ELSE SWAP WITH RIGHT CHILD
                curr = 2*curr;                                                // AGAIN UPDATE THE POINTER
            }
        }
}

int main(){
    int maxHeap[] = {-1,90,80,70,20,10,50,60};
    int size = 7;
    for(int i=1;i<=size;i++){
        cout<<maxHeap[i]<<" ";
    }
    cout<<"\n";
    deleteMaxHeap(maxHeap,size);
    for(int i=1;i<=size;i++){
        cout<<maxHeap[i]<<" ";
    }
    cout<<"\n";
    deleteMaxHeap(maxHeap,size);
    for(int i=1;i<=size;i++){
        cout<<maxHeap[i]<<" ";
    }
    cout<<"\n";
    deleteMaxHeap(maxHeap,size);
    for(int i=1;i<=size;i++){
        cout<<maxHeap[i]<<" ";
    }
    cout<<"\n";
    deleteMaxHeap(maxHeap,size);
    for(int i=1;i<=size;i++){
        cout<<maxHeap[i]<<" ";
    }
    cout<<"\n";
    deleteMaxHeap(maxHeap,size);
    for(int i=1;i<=size;i++){
        cout<<maxHeap[i]<<" ";
    }
    cout<<"\n";
    deleteMaxHeap(maxHeap,size);
    for(int i=1;i<=size;i++){
        cout<<maxHeap[i]<<" ";
    }
    cout<<"\n";
    return 0;
}