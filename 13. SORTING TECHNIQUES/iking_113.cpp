// PROGRAM TO GET Kth SMALLEST ELEMENT IN ARRAY USING QUICK SORT

// QUICK SORT RETURN US THE ORIGINAL POSITION OF OUR GIVEN ELEMENT
// SO Kth ELEMENT WILL HAVE K-1 POSITION SO WE HAVE TO RETURN ELEMENT WHOSE PIVOT WILL BE K-1
// ALSO EVERY TIME WE WILL CHECK PIVOT ELEMENT LESS THAN OR GREATER TO OUR K-1
// IF LESS THEN WE WILL CALL RIGHT PART OF ARRAY AND IF GREATER THEN WE WILLL ONLY CALL LEFT PART OF THE ARRAY
// SO NO NEED TO CALL BOTH THE ARRAYS

// INTUTION BE LIKE  "GET PIVOT AND THEN SOME TASTE OF BINARY SEARCH ALGO"

#include<bits/stdc++.h>
using namespace std;

int partition(int arr[],int l, int r){
    int pivot=arr[r];                       // TAKE PIVOT ELEMENT AS THE LAST ELEMENT OF THE ARRAY
    int i=l-1;                              // A POINTER I WHICH WILL HELP FURTHER IN SWAPPING SMALLER ELEMENTS FURTHER
    
    for(int j=l;j<r;j++){                   // WE WILL TRAVERSE IN WHOLE LOOP TO MAKE ELEMENTS LESS THAN PI AT FIRST AND THEN LARGER ONE
        if(arr[j]<pivot){                   // IF LESSER ELEMENT THEN
            i++;                            // MAKE I++
            swap(arr[i],arr[j]);            // THEN SWAP
        }                                   // AFTER EACH SWAP SMALLER ELEMENT WILL COME AT INITIAL SUB-ARRAY
    }                                       // AT END ITH ELEMENT WILL BE LAST SMALLER ELEMENT THAN PIVOT THEN LARGER ELEMENT WILL START
    swap(arr[i+1],arr[r]);                  // SO AT LAST SWAP TO GET PI ELEMENT AT IT'S ORIGINAL POSITION
    return i;     
}

int kthSmallest(int arr[], int l, int r, int k){
    if(k>0 and k<=r-l+1){
        int pos=partition(arr,l,r);
        if(pos-l==k-1) return arr[pos];
        else if(pos-l>k-1) return kthSmallest(arr,l,pos-1,k);
        else return kthSmallest(arr,pos+1,r,k-pos+l-1);
    }
    
}

int main(){
    int n; cin>>n;
    int arr[n];
    for(int i=0;i<n;i++) cin>>arr[i];
    int k; cin>>k;
    cout<<kthSmallest(arr,0,n-1,k);
    return 0;
}