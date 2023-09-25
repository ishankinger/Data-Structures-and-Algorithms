// BASIC OPERATIONS ON MAP

#include<bits/stdc++.h>
using namespace std;

int main(){
    // map<int,string>m;
    // m[4]="eht";
    // m[2]="dgn";
    // m[9]="dgn";
    // m[5]="dhe";
    // for(auto pr:m) cout<<pr.first<<" "<<pr.second<<"\n";

    // cout<<m.size()<<"\n";

    // auto it1=m.find(9);                                        // m.find(__key__) ==> IT WILL RETURN THE ADDRESS OF PAIR AT THAT KEY 
    // cout<<(*it1).second<<"\n";                                 // .find() WORKS IN O(log(n))
    // auto it2=m.find(3);                                        // IF THE KEY IS NOT PRESENT IN MAP THEN .find() WILL RETURN m.end() address value
    // if(it2==m.end()) cout<<"NO VALUE"<<"\n";
    // else cout<<(*it2).second<<"\n";
    
    // m.erase(4);                                                // REMOVE PAIR OF THAT PARTICULAR KEY
    // auto it3=m.find(4);                                        // .erase() O(LOG(N))
    // if(it2==m.end()) cout<<"NO VALUE"<<"\n";
    // else cout<<(*it2).second<<"\n";
    
    // auto it4=m.find(5);
    // m.erase(it4);                                              // IT ALSO ACCEPTS THE VALUE OF ITERATOR
    // for(auto pr:m) cout<<pr.first<<" "<<pr.second<<"\n";

    // m.clear();
    // for(auto pr:m) cout<<pr.first<<" "<<pr.second<<"\n";
    // if(m.empty()) cout<<"MAP IS EMPTY"<<"\n";
    // else cout<<"MAP IS NOT EMPTY"<<"\n";
    
    map<int,string>m1;
    m1[8]="dnt";
    m1[5]="dng";
    m1[2]="etn";
    m1[5]="ishan";

    map<int,string>m2;
    m2[3]="eon";
    m2[5]="kes";
    m2[9]="kde";

    cout<<m1.at(5)<<"\n";
    cout<<m1[5]<<"\n";

    cout<<m1.count(5)<<"\n";

    auto it1=m1.lower_bound(2);
    auto it2=m1.upper_bound(2);
    cout<<(*it1).second<<" "<<(*it2).second<<"\n";
    
    m1.emplace(6,"dne");
    for(auto pr:m1) cout<<pr.first<<" "<<pr.second<<"\n";

    m1.swap(m2);
    for(auto pr:m1) cout<<pr.first<<" "<<pr.second<<"\n";

    return 0;
}