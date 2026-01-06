// USING HEAPIFY TO GENERATE MAX HEAP

#include <iostream>
#include <vector>
using namespace std;
const int N = 1e3;


void heapify(int maxHeap[], int &size, int curr){
    
    while(2*curr <= size){
        int leftchild = 2*curr;
        int rightchild = 2*curr + 1;
        int maxchild = leftchild; 
        if(rightchild<=size && maxHeap[rightchild]>maxHeap[maxchild]){      // EVERYTHING SAME AS PREVIOUS ONLY THE CONDITIONS IN IF(_____)
            maxchild = rightchild;                                          // IS CHANGED FOR MAX HEAP (PARENT > CHILD)
        }
        if(maxHeap[maxchild] <= maxHeap[curr]){
            return;
        }
        swap(maxHeap[maxchild],maxHeap[curr]);
        curr = maxchild;
    }
}

int main(){
    int maxHeap[N] = {-1,60,10,80,50,5,20,70};
    int size = 7;
    for(int i=size/2;i>0;i--){
        heapify(maxHeap,size,i);
    }
    for(int i=1;i<=size;i++){
        cout<<maxHeap[i]<<" ";
    }
    return 0;
}

// TAKE AWAY => IN MAX HEAP THE ROOT NODE WILL ALWAYS CONTAIN THE LARGEST VALUE OF TREE
// ALSO AFTER DELETING WE WILL GET SECOND LARGEST VALUE AS A ROOT
// SIMILARLY FOR MIN HEAP THE ROOT WILL ALWAYS BE SMALLEST VALUE
