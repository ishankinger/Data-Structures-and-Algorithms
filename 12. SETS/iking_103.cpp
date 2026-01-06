// MULTISET DATASTRUCTURE
// IT CAN STORE DUPLICATE VALUES ALSO
// ALL OTHER THINGS WILL BE SAME AS ORDERED MAP

#include<bits/stdc++.h>
using namespace std;

int main(){
 
    multiset<int>ms;

    ms.insert(1);                     // O(LOG(N))
    ms.insert(3);
    ms.insert(5);
    ms.insert(3);
    ms.insert(1);

    for(auto ele:ms) cout<<ele<<" ";
    cout<<"\n";

    ms.erase(3);                       // ALL OCCURENCES OF 3 WILL BE ERASED

    cout<<ms.count(3)<<"\n";           // RETURN THE COUNT OF OCCURENCES OF A PARTICULAR ELEMENT
    cout<<ms.count(5)<<"\n";
    cout<<ms.count(7)<<"\n";

    for(auto ele:ms) cout<<ele<<" ";
    cout<<"\n";

    auto it=ms.find(1);                // TO DELETE PARTICULAR VALUE WE WILL PASS ITERATOR IN IT
    ms.erase(it);                      // NOW ONLY ONE OCCURENCE OF 1 WILL BE ERASED

    for(auto ele:ms) cout<<ele<<" ";   // FIND FUNCTION WILL GIVE FIRST OCCURENCE OF ANY ELEMENT
    cout<<"\n";

    return 0;
}