// UNORDERED MAP -> NOT STORE ELEMENT IN ORDER
// MULTIMAP-> STORE DUPLICATE KEYS ALSO
// UNORDERED MULTIMAP -> STORE DUPLICATE BUT NOT IN ORDERED WAYS

#include<bits/stdc++.h>
using namespace std;

int main(){

    unordered_map<int,string>um;
    um[4]="eht";
    um[2]="dgn";
    um[9]="dgn";
    um[5]="dhe";
    um[4]="egd";
    for(auto pr:um) cout<<pr.first<<" "<<pr.second<<"\n";
    
    cout<<"\n";
    
    multimap<int,string>mm;
    // mm[4]="eht";   ==> can't use in multimap
    mm.insert(make_pair(4,"eht"));
    mm.insert(make_pair(2,"dgn"));
    mm.insert(make_pair(9,"dgn"));
    mm.insert(make_pair(5,"dhe"));
    mm.insert(make_pair(4,"egd"));
    for(auto pr:mm) cout<<pr.first<<" "<<pr.second<<"\n";
    cout<<mm.count(4)<<"\n";
    cout<<mm.count(9)<<"\n";

    cout<<"\n";

    unordered_multimap<int,string>umm;
    umm.insert(make_pair(4,"eht"));
    umm.insert(make_pair(2,"dgn"));
    umm.insert(make_pair(9,"dgn"));
    umm.insert(make_pair(5,"dhe"));
    umm.insert(make_pair(4,"egd"));
    for(auto pr:umm) cout<<pr.first<<" "<<pr.second<<"\n";

    

    return 0;
}