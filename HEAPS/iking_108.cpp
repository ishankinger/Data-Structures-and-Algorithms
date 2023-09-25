// HEAP SORTING TECHNIQUE

// >>> CONVERT THE ARRAY INTO THE HEAP DATASTRUCTURE USING HEAPIFY
// >>> ONE BY ONE DELETE THE ROOT NODE OF THE HEAP AND REPLACE IT WITH THE LAST NODE IN THE HEAP AND 
//     THEN HEAPIFY THE ROOT OF THE HEAP. REPEAT THIS PROCESS TILL THE SIZE OF HEAP IS GREATER THAN 1

// SO FOR MAX-HEAP THE ROOT NODE WILL BE THE LARGEST VALUE WHICH WE PRINT AND THEN 
// AFTER HEAPIFY THE ROOT, ROOT NODE WILL CONTAIN THE SECOND LARGEST VALUE 
// WE WILL GET DECREASING ORDER OF THE ARRAY USING MAX HEAP  
// SIMILARLY WE WILL GET AN INCREASING ORDER OF THE ARRAY USING MIN HEAP
// SO FOR N ELEMENTS WE ARE USING HEAPIFY HENCE TIME COMPLEXITY => O(N.LOG(N)) 

#include<bits/stdc++.h>
using namespace std;

void heapify(int maxHeap[], int &size, int curr){                          // SIMPLE HEAPIFY FUNCTION TO CONVERT GIVEN COMPLETE TREE INTO MAX HEAP
    
    while(2*curr <= size){
        int leftchild = 2*curr;
        int rightchild = 2*curr + 1;
        int maxchild = leftchild;
        if(rightchild<=size && maxHeap[rightchild]>maxHeap[maxchild]){
            maxchild = rightchild;
        }
        if(maxHeap[maxchild] <= maxHeap[curr]){
            return;
        }
        swap(maxHeap[maxchild],maxHeap[curr]);
        curr = maxchild;
    }
}

void removeMaxEle(int arr[], int &size){           // SO THIS FUNCTION IS SIMILAR TO AS DONE IN DELETION IN MAX HEAP

    swap(arr[1],arr[size]);                        // ONLY DIFFERENCE HERE IS USE OF HEAPIFY FUNCTION WHEREAS IN THAT DELETION FILE
    size--;                                        // WE WRITE THE WHOLE CODE ON OUR OWN
    heapify(arr,size,1);                           // WILL CALL N TIMES AND EACH TIME COMPLEXITY IS O(LOG(N))
}

void heapSort(int arr[],int n){
    
    for(int i=n/2;i>0;i--){                          // FIRSTLY THE ARRAY WILL BE HEAPIFY
        heapify(arr,n,i);
    }

    while(n>0){                                      // THEN FOR N TIMES WE WILL CALL THIS REMOVE MAX ELE FUNCTION
        removeMaxEle(arr,n);                         // IN THIS FUNCTION FIRST MAX ELE IS THAT IS FIRST ELEMENT WILL BE DELETED AND THEN
    }                                                // CONVERTED IT INTO A BINARY HEAP 
}

int main(){
    int N = 7;
    int arr[N] = {-1,60,10,80,50,5,20,70};
    for(int i=1;i<=N;i++){
        cout<<arr[i]<<" ";
    }
    cout<<"\n";
    heapSort(arr,N);
    for(int i=1;i<=N;i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}