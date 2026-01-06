// ****************** SELECTION SORT ******************

// Selection sort is an in-place sorting algorithm. Selection sort works well for small files. It is used
// for sorting the files with very large values and small keys. This is because selection is made
// based on keys and swaps are made only when required.

// >> find the minimum element in the list
// >> swap it with the value in the current position
// >> repeat this process for all the elements until the entire array is sorted

// The algorithm is called selection sort since it repeatedly selects the smallest element

#include<bits/stdc++.h>
using namespace std;

void SelectionSort(vector<int> &a){
    int n = a.size();
    int minEleInd;
    for(int i = 0; i < n-1; i++){
        minEleInd = i;
        for(int j = i+1; j < n; j++){
            if(a[j] < a[minEleInd]){
                minEleInd = j;
            }
        }
        swap(a[i],a[minEleInd]);
    }
}

int main(){

    int n;
    cin >> n;

    vector<int> a(n);
    for(int i = 0; i < n; i++) cin >> a[i];

    for(int i = 0; i < n; i++) cout << a[i] << " ";
    cout << "\n";

    SelectionSort(a);

    for(int i = 0; i < n; i++) cout << a[i] << " ";
    cout << "\n";
}

// >>> TIME COMPLEXITY= O(N2) for all cases

// >>> SPACE COMPLEXITY = O(1)

// >>> UNSTABLE SORTING ALGORITHM ( ORDER OF OCCURENCE OF SIMILAR ELEMENTS CHANGE )
//     ex. 3 4 3* 2 ==> 2 3* 3 4        

// >>> MAX SWAPS THAT WILL OCCUR IS O(N)
// >>> MAX COMPARISONS IS O(N2 / 2)
