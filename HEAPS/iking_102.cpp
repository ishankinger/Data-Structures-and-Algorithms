// INSERTION IN A MIN HEAP

// FIRST ADD GIVEN ELEMENT TO LAST 
// THEN CHECK IT'S VALUE WITH IT'S PARENT IF PARENT HAS GREATER VALUE THEN SWAP
// AND THEN AGAIN CHECK THIS WAY
// TILL WE REACH ROOT NODE OR PARENT < ELE

// TIME COMPLEXITY FOR THIS WILL BE O(LOG(N)) AS WE ARE GOING HEIGHT LEVELWISE

#include<bits/stdc++.h>
using namespace std;
int const N = 1e3;

void insertMinHeap(int arr[],int &size, int value){
    size++;                                              // SIZE INCREASED BY 1
    arr[size] = value;                                   // AT LAST THE VALUE OF NEW ELE IS ADDED
    int curr = size;                                     // CURR VARIABLE KEEPING THE TRACK OF INDICES OF ARRAY

    while(curr/2 > 0 && arr[curr/2]>arr[curr]){          // IF CURR REACH ROOT MEANS CURR =1 THEN CURR/2 == 0 OR CONDITION FOR MIN HEAP SATISFY
        swap(arr[curr/2],arr[curr]);
        curr = curr/2;                                   // EACH TIME OUR SAMPLE SPACE DECREASING BY FACTOR OF 2
    }
}

int main(){
    int minHeap[N] = {-1,10,20,30,40,50};            // -1 ADDED ONLY TO MAKE INDEXING STARTING FROM 1
    int size = 5;                                    // SIZE OF THE ARRAY
    int value = 5;                                   // VALUE TO BE ADDED
    for(int i=1;i<=size;i++){
        cout<<minHeap[i]<<" ";
    }
    cout<<"\n";
    insertMinHeap(minHeap,size,value);               // FUNCTION CALLED FOR INSERTION
    for(int i=1;i<=size;i++){
        cout<<minHeap[i]<<" ";
    }
}