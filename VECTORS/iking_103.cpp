// SECOND DATASTRUCTURES--> VECTORS( DYNAMIC ARRAY )

#include<iostream>
#include<vector>                                               // CALLING THE VECTOR OPERATIONS WHICH TO BE USED FURTHER
using namespace std;

int main(){
    vector<int>v;                                              // INT DATATYPE WILL BE MADE     VECTOR<DATATYPE>NAME;
    
    cout<<v.size()<<"  "<<v.capacity()<<endl;                  // V.SIZE() GIVE THE LENGTH OF VECTOR THAT IS TOTAL NUMBER OF ELEMENTS 

    v.push_back(1);                                            // SO ELEMENTS WILL BE ADDED FROM THE BACK
     cout<<v.size()<<"  "<<v.capacity()<<endl;                 // CAPACITY WILL INCREASE BY FACTOR OF 2 IF ONE BY ONE ELEMENT ADDED

    v.push_back(2);                                            // AFTER 1 ELEMENT 2 WILL BE ADDED
     cout<<v.size()<<"  "<<v.capacity()<<endl;

    v.push_back(3);
     cout<<v.size()<<"  "<<v.capacity()<<endl;

    v.resize(5);                                               // RESIZE OPERATOR CHANGE ITS SIZE TO 5
      cout<<v.size()<<"  "<<v.capacity()<<endl;

    v.resize(10);                                              // CHANGE SIZE TO 10
      cout<<v.size()<<"  "<<v.capacity()<<endl;                // NOW CAPACITY CAN BE ANYTHING DEPENDING ON THE COMPILER

    v.pop_back();                                              // DELETE FROM THE BACK ELEMENTS
    v.pop_back();
      cout<<v.size()<<"  "<<v.capacity()<<endl;
}
// THIS vector<int>v() TYPES OF THINGS ARE DONE WITH THE HELP OF STL
// STL IS A BUILT IN C++ LIBRARY WHICH CONTAINS READY TO USE IMPLEMENTATIONS OF SOME COMMONLY
// USED DATA STRUCTURES. IT HELPS US WRITE EFFICIENT ALGORITHMS WITH LESS CODE.
// IT IS USED IN IMPLEMENTING MORE COMPLEX DATA STRUCTURES.

