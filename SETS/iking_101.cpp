// SETS DATASTRUCTURE
// BASIC OPERATIONS --

#include<bits/stdc++.h>
using namespace std;

int main(){
    
    set<string>s;

    s.insert("abc");                      // INSERTION OCCURS IN O(LOG(N))
    s.insert("xhe");
    s.insert("win");
    s.insert("abc");                      // SIMILAR ELEMENTS WILL NOT BE STORED

    for(auto val:s) cout<<val<<" ";       // STORED ELEMENTS IN SORTED MANNER
    cout<<"\n";
    cout<<s.size()<<"\n";

    auto it=s.find("abc");                // .FIND(VALUE) SEARCH WITH THE HELP OF VALUE AND RETURN ITERATOR TO IT
    if(it!=s.end()) s.erase(it);          // IF NO ELEMENT THEN RETURN S.END AND THUS WE ARE CHECKING CONDITION BEFORE ERASING
    
    for(auto val:s) cout<<val<<" ";       // NOW VALUE OF "abc" WILL BE REMOVED FROM OUR SET    
    cout<<"\n";
    cout<<s.size()<<"\n";

    set<int,greater<int>>sInput;          // NOW PRINTING WILL OCCUR IN SORTED DECREASING ORDER
    for(int i=0;i<5;i++){
        int x; cin>>x;
        sInput.insert(x);
    }
    for(auto val:sInput) cout<<val<<"\n";

    set<int>sDelete;
    for(int i=0;i<7;i++){
        int x; cin>>x;
        sDelete.insert(x);
    }
    for(auto ele:sDelete) cout<<ele<<" ";
    cout<<"\n";

    auto itrStart=sDelete.find(3);
    auto itrEnd=sDelete.find(6);

    sDelete.erase(itrStart,itrEnd);            // DELETE FROM itrStart TO itrEnd-1

    for(auto ele:sDelete) cout<<ele<<" ";
    cout<<"\n";

    sDelete.erase(6);                          // DIRECTLY ALSO BY VALUE WE CAN DELETE THE ELEMENT IN THE SET

    for(auto ele:sDelete) cout<<ele<<" ";
    cout<<"\n";

    return 0;
}