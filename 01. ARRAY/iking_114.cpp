// ************** REVERSE OPERATION ***************
// ( WITHOUT USING EXTRA MEMORY WE CAN ROTATE VECTOR )
// reverse(i,j) => REVERSE FROM I TO J-1 INDICES IN THE VECTOR

#include<iostream>
#include<vector>
#include<algorithm>                             // THIS TO BE USED TO WORK REVERSE FUNCTION

using namespace std;

int main(){
    vector<int>v;
    v.push_back(1);
    v.push_back(2);
    v.push_back(3);
    v.push_back(4);
    v.push_back(5);
    v.push_back(6);

    int k=2;
    k=k%v.size();
                                                   // REVERSE FUNCTION ALREADY IN BUILT IN C++
    reverse(v.begin(),v.end());                    // FIRST OF ALL REVERSE ALL THE ELEMENTS     
    reverse(v.begin(),v.begin()+k);                // THEN REVERSE TILL Kth ELEMENT
    reverse(v.begin()+k,v.end());                  // THEN REVERSE AFTER Kth ELEMENT TO GET REQUIRED ARRAY

    for(int i=0;i<6;i++){
        cout<<v[i]<<" ";
    }
}
