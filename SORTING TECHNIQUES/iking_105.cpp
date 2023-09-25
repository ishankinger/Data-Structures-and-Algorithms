// QUICK SORT

// DIVIDE AND CONQUERER THEOREM

#include<iostream>
using namespace std;

int partition(int arr[], int l, int r){     // FUNCTION TO PLACE PIVOT ELEMENT AT IT'S ORIGINAL POSITION
    int pivot=arr[r];                       // TAKE PIVOT ELEMENT AS THE LAST ELEMENT OF THE ARRAY
    int i=l-1;                              // A POINTER I WHICH WILL HELP FURTHER IN SWAPPING SMALLER ELEMENTS FURTHER

    for(int j=l;j<r;j++){                   // WE WILL TRAVERSE IN WHOLE LOOP TO MAKE ELEMENTS LESS THAN PI AT FIRST AND THEN LARGER ONE
        if(arr[j]<pivot){                   // IF LESSER ELEMENT THEN
            i++;                            // MAKE I++
            swap(arr[i],arr[j]);            // THEN SWAP
        }                                   // AFTER EACH SWAP SMALLER ELEMENT WILL COME AT INITIAL SUB-ARRAY
    }                                       // AT END ITH ELEMENT WILL BE LAST SMALLER ELEMENT THAN PIVOT THEN LARGER ELEMENT WILL START
    swap(arr[i+1],arr[r]);                  // SO AT LAST SWAP TO GET PI ELEMENT AT IT'S ORIGINAL POSITION
    return i+1;                             // RETURN ORIGIANL POSIITION THAT IS I+1
}

void quickSort(int arr[], int l, int r){
    if(l<r){
        int pi=partition(arr,l,r);

        quickSort(arr,l,pi-1);
        quickSort(arr,pi+1,r);
    }
    return ;
}

int main(){
    int arr[]={6,3,9,5,2,8,7};
    quickSort(arr,0,6);
    for(int i=0;i<7;i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}

// >>> TIME COMPLEXITY = O(N.LOG(N))
// >>> SPACE COMPLEXITY = O(1)
// >>> UNSTABLE SORTING ALGORITHM