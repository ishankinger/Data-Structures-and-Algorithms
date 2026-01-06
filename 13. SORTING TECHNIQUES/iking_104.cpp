// ****************** MERGE SORT *********************

// In Merge sort the input list is divided into two parts and these are solved recursively. After
// solving the sub problems, they are merged by scanning the resultant sub problems.

// DIVIDE AND THEN CONQUER ALGORITHM

#include<iostream>
using namespace std;

void merge(int arr[], int l, int mid, int r){
    
    // SIZE OF BOTH THE ARRAYS
    int n1=mid-l+1;
    int n2=r-mid;
    
    // TEMPORARY ARRAYS ARE CREATED
    int a[n1];
    int b[n2];
    
    // VALUES ARE INSERTED IN TEMPORARY ARRAYS
    for(int i=0;i<n1;i++){
        a[i]=arr[l+i];
    }
    for(int i=0;i<n2;i++){
        b[i]=arr[mid+i+1];
    }
    
    // NOW MERGE THE TWO SORTED ARRAY TO GET A NET SORTED ARRAY
    int i=0;
    int j=0;
    int k=l;
    while(i<n1 && j<n2){                  // IF ANY ONE FULLY TRAVERSED THEN BREAK
        if(a[i]<b[j]){                    // SMALLER ELEMENT WILL BE FILLED
            arr[k]=a[i];                  // RESPECTIVE ARRAY'S INDEX WILL BE INCREMENTED
            k++;
            i++;
        }else{
            arr[k]=b[j];
            k++;
            j++;
        }
    }
    
    // CHECKING LEFT ELEMENTS CONDITION
    while(i<n1){                          // CHECKING WHETHER WHOLE ARRAY IS EMPTY OR NOT
        arr[k]=a[i];                      // IF NOT THEN SIMPLY FILL LEFT VALUES AS THESE MUST BE GREATER THAN OUR OTHER ARRAY
        i++;
        k++;
    }
    while(j<n2){                          // SIMILAR THING TO CHECK WITH SECOND LOOP
        arr[k]=b[j];
        j++;
        k++;
    }
}

void mergeSort(int arr[],int l, int r){   // IT WILL GIVE OUR SORTED ARRAY
    
    // BASE CASE
    if(l>=r) return;
    
    // MAKING SUBSEQUENCES
    int mid=(l+r)/2;                      // FIRST WE WILL MAKE PARTITIONS OF ARRAYS TO BE SORTED
    mergeSort(arr,l,mid);                 // CALLING FIRST HALF OF THE ARRAY
    mergeSort(arr,mid+1,r);               // CALLING SECOND HALF OF THE ARRAY
    
    // USING MERGE FUNCTION TO SORT BOTH
    merge(arr,l,mid,r);                   // AND THEN MERGE BOTH THE RESPECTIVE ARRAYS
}

int main(){
    int arr[]={6,3,9,5,2,8,7,1};
    mergeSort(arr,0,7);
    for(int i=0;i<8;i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}

// >>> TIME COMPLEXITY = O(N.LOG(N))
// >>> SPACE COMPLEXITY = O(N)
// >>> STABLE SORTING ALGORITHM
