// GIVEN TWO VECTORS THAT REPRESENT A SEQUENCE OF KEYS
// WE HAVE TO CHECK WHETHER THE BST FORMED VIA EACH ARRAY ARE IDENTICAL WITHOUT MAKING TREE

// [4 2 5 1 3]   [4 5 2 3 1]  => MAKING IDENTICAL BST
//       (4)                  
//       /  \                 ELEMENTS OF SAME LEVEL ARE SWAPPED THEN BST REMAINS SAME
//     (2)  (5)               IF ELEMENTS OF DIFFERENT LEVEL ARE SWAPPED THEN BST NOT SAME
//    /   \         
//   (1)  (3)

// FOR EVERY ELEMENT VALUES OF LC AND RC SHOULD BE INSERTED AFTER IT IN THE ARRAY
// IF THIS IS FOLLOWED BY BOTH THE ARRAYS THEN THEY WILL FORM IDENTICAL BST'S

#include<bits/stdc++.h>
using namespace std;

bool checkIdenticalBSTHelper(vector<int> &v1, vector<int> &v2,int a1, int a2, int minValue, int maxValue){
    int i;
    for(i=a1;i<v1.size();i++){
        if(v1[i] > minValue && v1[i] < maxValue) break;
    }
    int j;
    for(j=a2;j<v2.size();j++){
        if(v2[j] > minValue && v2[j] < maxValue) break;
    }

    // IF NO ELEMENT IS FOUND WITHIN RANGE THEN THEY ARE LEAF NODE
    if(i == v1.size() && j == v2.size()) return true;
    
    // IF IN ONE LEAF NODE BUT NOT IN OTHER THEN RETURN FALSE
    if((i == v1.size() && j != v2.size()) && (i != v1.size() && j == v2.size())) return false;         

    // CHECKING IF BOTH THE ELEMENTS ARE EQUAL OR NOT
    if(v1[i] != v2[j]) return false;

    // RECURSIVELY CHECK FOR LEFT AND RIGHT SUB-TREE
    return checkIdenticalBSTHelper(v1,v2,a1+1,a2+1,minValue,v1[i]) &&
           checkIdenticalBSTHelper(v1,v2,a1+1,a2+1,v1[i],maxValue);

}
bool checkIdenticalBSTs(vector<int> &v1, vector<int> &v2){
    return checkIdenticalBSTHelper(v1,v2,0,0,INT_MIN,INT_MAX);
}

int main(){
    int n; cin>>n;
    vector<int> v1(n), v2(n);
    for(auto &ele:v1) cin>>ele;
    for(auto &ele:v2) cin>>ele;
    
    if(checkIdenticalBSTs(v1,v2)){
        cout<<"Arrays have identical BSTs\n";
    }
    else{
        cout<<"Arrays doesnot have identical BSTs\n";
    }

    return 0;
}