// UNORDERED MULTISET DATASTRUCTURE
// DUPLICATE VALUES ARE ALLOWED AND NOT STORED IN SORTED ORDER

#include<bits/stdc++.h>
using namespace std;

int main(){
    unordered_multiset<int>ums;
    ums.insert(4);
    ums.insert(8);
    ums.insert(3);
    ums.insert(1);
    ums.insert(4);
    ums.insert(5);

    for(auto ele:ums) cout<<ele<<" ";
    cout<<"\n";
    
    cout<<ums.count(4)<<"\n";
    
    return 0;
}