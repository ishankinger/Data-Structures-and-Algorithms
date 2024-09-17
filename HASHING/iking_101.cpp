// BASIC SYNTAX TO DEFINE A MAP

#include<bits/stdc++.h>
using namespace std;

int main(){
    map<int,string>m;                                     // DEFININT A MAP STL
    m[1]="abc";                                           // KEY IS INTEGER AND VALUE STORED IS STRING DATATYPE
    m[2]="dje";                                           // ASSIGNING VALUE OCCUR IN O(LOG(N))
    m[5]="dur";
    m[3]="urn";
    m[7]="etr";
    m[4];                                                  // IF NO VALUE IS ASSIGNED THEN IT WILL STORE NULL VALUE (EMPTY STRING)
    m[2]="dkt";          
    
    map<int,string>::iterator it;                          // TO TRAVERSE IN THE MAP WE WILL BE USING ITERATORS AS THEY ARE NOT STORED IN
    for(it=m.begin();it!=m.end();it++){                    // CONTIGOUS ORDER SO WE HAVE TO JUMP TO NEXT ADDRESS USING IT++
        cout<<(*it).first<<" "<<(*it).second<<"\n";        // SYNTAX TO GET KEY AND VALUE PAIR
    }                                                      // m.begin() and m.end() STORE THE ADDRESS OF THE FIRST AND ONE AFTER THE LAST ELEMENT ADDRESS

    for(auto pr: m){                                       // SHORTER WAY TO USE ITERATOR USING THIS AUTO KEYWORD
        cout<<(pr).first<<" "<<(pr).second<<"\n";           
   }

    map<int,vector<int>>mVec;

    for(int i=0;i<5;i++){
        int ele; cin>>ele;
        mVec[ele].push_back(i);
    }
    for(auto x:mVec){
        cout<<x.second[0]<<" ";
    }

    return 0;
}