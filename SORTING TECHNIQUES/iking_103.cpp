// ****************** INSERTION SORT *********************

// In this algorithm, each iteration removes an element from the input data and 
// inserts it into the correct position in the list being sorted. 

// >> Insertion sort is linear for partially sorted array -
// >> Adaptive: If the input list is presorted [may not be completely] then insertions sort
//              takes O(n + d), where d is the number of inversions
// >> Stable: Maintains relative order of input data if the keys are same

// Insertion sort is one of the elementary sorting algorithms with O(n2) worst-case time. Insertion
// sort is used when the data is nearly sorted (due to its adaptiveness) or when the input size is small
// (due to its low overhead).

#include<bits/stdc++.h>
using namespace std;

void InsertionSort(vector<int> &a){
    int n = a.size();
    for(int i = 1; i < n; i++){
        int currEle = a[i];
        int j = i;
        while(a[j-1] > currEle and j >= 1){
            a[j] = a[j-1];
            j--;
        }
        a[j] = currEle;
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

// >>> TIME COMPLEXITY = O(N2)
//     >> WORST COMPLEXITY - O(N2), INNER LOOP HAS TO MOVE CURR ELE TO ALL ELEMETNS OF 1...I RANGE
//     >> AVERAGE CASE - O(N2), INNER LOOP INSERT CURR ELE IN THE MIDDLE OF 1...I RANGE
//     >> BEST CASE - O(N) , ALREADY SORTED ARRAY

// >>> SPACE COMPLEXITY = O(1)

// N2 / 4 COMPARISONS AND N2 / 8 COMPARISONS IN AVERAGE CASE
// IN WORST CASE IT DOUBLES
