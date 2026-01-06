// BASIC OPERATIONS ON MAP

#include<bits/stdc++.h>
using namespace std;

int main(){
    map<int,string>m;
    m[4]="eht";
    m[2]="dgn";
    m[9]="dgn";
    m[5]="dhe";
    for(auto pr:m) cout<<pr.first<<" "<<pr.second<<"\n";

    cout<<m.size()<<"\n";

    auto it1=m.find(9);                                        // m.find(__key__) ==> IT WILL RETURN THE ADDRESS OF PAIR AT THAT KEY 
    cout<<(*it1).second<<"\n";                                 // .find() WORKS IN O(log(n))
    auto it2=m.find(3);                                        // IF THE KEY IS NOT PRESENT IN MAP THEN .find() WILL RETURN m.end() address value
    if(it2==m.end()) cout<<"NO VALUE"<<"\n";
    else cout<<(*it2).second<<"\n";
    
    m.erase(4);                                                // REMOVE PAIR OF THAT PARTICULAR KEY
    auto it3=m.find(4);                                        // .erase() O(LOG(N))
    if(it2==m.end()) cout<<"NO VALUE"<<"\n";
    else cout<<(*it2).second<<"\n";
    
    auto it4=m.find(5);
    m.erase(it4);                                              // IT ALSO ACCEPTS THE VALUE OF ITERATOR
    for(auto pr:m) cout<<pr.first<<" "<<pr.second<<"\n";

    m.clear();
    for(auto pr:m) cout<<pr.first<<" "<<pr.second<<"\n";
    if(m.empty()) cout<<"MAP IS EMPTY"<<"\n";
    else cout<<"MAP IS NOT EMPTY"<<"\n";
    

    return 0;
}