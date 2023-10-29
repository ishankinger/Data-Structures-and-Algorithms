// ******************** BUBBLE SORT *********************

// Bubble sort is the simplest sorting algorithm. It works by iterating the input array from the first
// element to the last, comparing each pair of elements and swapping them if needed. Bubble sort
// continues its iterations until no more swaps are needed.

// SIMPLY REAPEATEDLY SWAP TWO ELEMENTS IF THEY ARE IN DIFFERENT ORDER
// AFTER ONE TRAVERSAL LARGEST ELEMENT WILL GET AT LAST POSITION
// SO EACH TIME OUR SECOND LOOP LENGTH WILL DECREASE BY ONE

#include<iostream>
#include<bits/stdc++.h>
#include<algorithm>
using namespace std;

int main(){
    int n; cin>>n;
    vector<int>v(n);
    for(auto &ele:v) cin>>ele;
    bool check = true;                              // EACH TIME INITIALISE CHECK WITH TRUE
    for(int i=0;i<n;i++){                           // LOOP WILL RUN N TIMES
        check = true;                               // IF IN BETWEEN TRAVERSAL THE ARRAY BECOMES SORTED THEN WE CAN BREAK FROM THE LOOP
        for(int j=0;j<=n-i-1;j++){                  // SECOND LOOP EACH TIME WILL GET SHORTEN BY ONE
            if(v[j]>v[j+1]){                        // IF IRREGULARITY OCCURS
                swap(v[j],v[j+1]);                  // SWAP EACH TIME TO GET LARGEST ELEMENT AT THE BACK
                check = false;                      // AND MAKE CHECK AS FALSE TO FURTHER CHECK ONCE THAT THE ARRAY IS SORTED OR NOT
            }
        }
        if(check) break;                            // IF (TRUE == CHECK) MEANS SORTED SO WE CAN BREAK WITHOUT TRAVERSING FURTHER IN THE LOOP
    }

    for(int i=0;i<n;i++) cout<<v[i]<<" ";
}

// >>> TIME COMPLEXITY = O(N2)
// >>> SPACE COMPLEXITY = O(1)
// >>> STABLE SORTING ALGORITHM
//     ex. 3 4 3* 2 ==>  2 3 3* 4
// >>> MAX SWAPS = O(N2)
// >>> IF THE INPUT ARRAY IS ALREADY SORTED THEN IT WILL TAKE O(N) COMPLEXITY
