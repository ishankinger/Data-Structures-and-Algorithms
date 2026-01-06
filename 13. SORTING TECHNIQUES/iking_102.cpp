// ******************** BUBBLE SORT *********************

// Bubble sort is the simplest sorting algorithm. 
// It works by iterating the input array from the first element to the last, comparing each pair of elements and swapping them if needed.
// Bubble sort continues its iterations until no more swaps are needed.
// The algorithm gets its name from the way smaller elements "bubble" to top of the list

#include<iostream>
#include<bits/stdc++.h>
#include<algorithm>
using namespace std;

/* in each pass largest element is shifted to end of that pass range */
void BubbleSort_Cpp(vector<int> &a){
    int n = a.size();
    for(int pass = n-1; pass >= 0; pass--){
        for(int i = 0; i <= pass-1; i++){
            if(a[i] > a[i+1]){
                swap(a[i],a[i+1]);
            }
        }
    }
}

/* if the list is already sorted we can use flag to skip the remaining passes */
void BubbleSort_improved(vector<int> &a){
    int n = a.size();
    int swapped = 1;
    for(int pass = n-1; pass >= 0 && swapped; pass--){
        swapped = 0;
        for(int i = 0; i <= pass-1; i++){
            if(a[i] > a[i+1]){
                swap(a[i],a[i+1]);
                swapped = 1;
            }
        }
    }
}

int main(){
    
    int n;
    cin >> n;

    vector<int> a(n);
    for(int i = 0; i < n; i++) cin >> a[i];

    for(int i = 0; i < n; i++) cout << a[i] << " ";
    cout << "\n";

    BubbleSort_Cpp(a);

    for(int i = 0; i < n; i++) cout << a[i] << " ";
    cout << "\n";

}

// >>> TIME COMPLEXITY -
//    >> WORST CASE - O(N2)
//    >> BEST CASE (IMPROVED VERSION) - O(N)
//    >> AVERAGE CASE - O(N2)

// >>> SPACE COMPLEXITY = O(1)

// >>> STABLE SORTING ALGORITHM
//     ex. 3 4 3* 2 ==>  2 3 3* 4

// >>> MAX SWAPS (INVERSIONS) = O(N2 / 2), WORST FOR REVERSE SORTED ARRAY
// >>> MAX COMPARISONS = O(N2 / 2)
// >>> IF THE INPUT ARRAY IS ALREADY SORTED THEN IT WILL TAKE O(N) SWAPS
