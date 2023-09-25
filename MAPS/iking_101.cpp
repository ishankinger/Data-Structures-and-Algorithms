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
    m[2]="dur";                                            // LAST DEFINED VALUE WILL BE TAKEN

    map<int,string>::iterator it;                          // TO TRAVERSE IN THE MAP WE WILL BE USING ITERATORS AS THEY ARE NOT STORED IN
    for(it=m.begin();it!=m.end();it++){                    // CONTIGOUS ORDER SO WE HAVE TO JUMP TO NEXT ADDRESS USING IT++
        cout<<(*it).first<<" "<<(*it).second<<"\n";        // SYNTAX TO GET KEY AND VALUE PAIR
    }                                                      // m.begin() and m.end() STORE THE ADDRESS OF THE FIRST AND ONE AFTER THE LAST ELEMENT ADDRESS

    map<int,string,greater<int>>mRev;                       // TO STORE ELEMENTS IN DESCENDING ORDER
    mRev[1]="abc";                                        
    mRev[2]="dje";                                           
    mRev[5]="dur";
    mRev[3]="urn";
    mRev[7]="etr";
    mRev[4];                                             
    mRev[2]="dkt"; 

    for(auto pr: mRev){                                       // SHORTER WAY TO USE ITERATOR USING THIS AUTO KEYWORD
        cout<<(pr).first<<" "<<(pr).second<<"\n";           
    } 

    

    return 0;
}