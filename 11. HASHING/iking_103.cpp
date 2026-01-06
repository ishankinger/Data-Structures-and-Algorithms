// SOME OTHER OPERATIONS ON MAP

#include<bits/stdc++.h>
using namespace std;

int main(){
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
    m1.emplace(6,"dne");
    for(auto pr:m1) cout<<pr.first<<" "<<pr.second<<"\n";

    m1.swap(m2);
    for(auto pr:m1) cout<<pr.first<<" "<<pr.second<<"\n";


    return 0;
}