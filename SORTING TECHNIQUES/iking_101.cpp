// ****************** SELECTION SORT ******************

// Selection sort is an in-place sorting algorithm. Selection sort works well for small files. It is used
// for sorting the files with very large values and small keys. This is because selection is made
// based on keys and swaps are made only when required.

// TRAVERSE ON EACH ELEMENT VIA FIRST LOOP AND THEN TRAVERSE ON NEXT ELEMENTS TO IT VIA SECOND LOOP
// IN SECOND LOOP WE WILL SWAP THE MINIMUM ELEMENT
// SO MAIN FUNDA FOR THIS SORTING IS THAT WE WILL CHOOSE MINIMUM ELEMENT FROM THE LEFT ARRAY AND SWAP IT WITH FIRST ELEMENT OF ARRAY LEFT

#include<bits/stdc++.h>
using namespace std;

int main(){
    int n; cin>>n;
    vector<int>v(n);
    for(auto &ele:v) cin>>ele;

    for(int i=0;i<n;i++){                       // GO IN LOOP FOR EVERY ELEMENT
        int minEle=INT_MAX;                     // GET THE MINIMUM ELEMENT AND IT'S INDEX(SO TO USE IN SWAP)
        int minInd=0;                           // IN THE SUB ARRAY OF I+1 TO N
        for(int j=i;j<n;j++){                   // LOOP TO GET MINIMUM ELEMENT
            if(v[j]<minEle){
                minEle=v[j];
                minInd=j;
            }
        }
        swap(v[i],v[minInd]);                  // AT END SWAP IT WITH FIRST ELEMENT
    }
    
    for(int i=0;i<n;i++) cout<<v[i]<<" ";
}

// >>> TIME COMPLEXITY= O(N2)
// >>> SPACE COMPLEXITY = O(1)
// >>> UNSTABLE SORTING ALGORITHM ( ORDER OF OCCURENCE OF SIMILAR ELEMENTS CHANGE )
//     ex. 3 4 3* 2 ==> 2 3* 3 4        
// >>> MAX SWAPS THAT WILL OCCUR IS O(N)
