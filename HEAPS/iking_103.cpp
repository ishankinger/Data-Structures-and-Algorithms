// INSERTION IN A MAX HEAP
// SIMILAR METHODOLOGY AS DONE IN MIN HEAP

#include<bits/stdc++.h>
using namespace std;
const int N = 1e3;

void insertMaxHeap(int maxHeap[],int &size,int value){
    size++;
    maxHeap[size] = value;
    int curr = size;
    while(curr/2 > 0 && maxHeap[curr/2]<maxHeap[curr]){                // HERE ONLY THIS CONDITION CHANGES THAT PARENT SHOULD BE GREATER THAN CHILD
        swap(maxHeap[curr],maxHeap[curr/2]);                           // OTHERWISE THE WHOLE CODE REMAINS SAME
        curr = curr/2; 
    }
}

int main(){
    int maxHeap[N] = {-1,60,50,40,30,20,30,10};
    int size = 7;
    int value = 100;
    for(int i=1;i<=size;i++){
        cout<<maxHeap[i]<<" ";
    }
    cout<<"\n";
    insertMaxHeap(maxHeap,size,value);
    for(int i=1;i<=size;i++){
        cout<<maxHeap[i]<<" ";
    }
    cout<<"\n";


    return 0;
}