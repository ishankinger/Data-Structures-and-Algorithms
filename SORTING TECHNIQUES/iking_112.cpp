// GIVEN AN ARRAY MAKE ALL 0'S TO END OF THE ARRAY WITHOUT CHANGING THE RELATIVE ORDER OF NON ZERO ELEMENTS
// ALSO WE HAVE TO DO THIS WITHOUT MAKING A NEW ARRAY

#include<bits/stdc++.h>
using namespace std;

int main(){
    vector<int>v;
    v={0,5,0,3,4,2};
    for(int i=0;i<v.size();i++){
        if(v[i]==0){
            v.erase(v.begin()+i);
            v.push_back(0);
        }
    }
    for(int i=0;i<v.size();i++) cout<<v[i]<<" ";

    return 0;
}
// OTHER ALGORITHIMIC SORTING WAY:
// X,Y  IF X IS ZERO AND Y IS NON-ZERO SO SWAP WILL TAKE PLACE
// CORRECT ORDER WILL BE NON-ZERO AND THEN ZERO