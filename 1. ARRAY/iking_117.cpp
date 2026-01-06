// PREVIOUS QUESTION WITHOUT USING EXTRA MEMORY AND DONE WITH VECTORS
//  ************** COUNTING ZEROS AND ONES ***************

#include<iostream>
#include<vector>
using namespace std;

void sort0And1(vector<int> &v){                 // AMPERSANT VARIABLE IMPORTANT TO USE
    int noOfZeroes=0;                           // VARIABLE TO COUNT NUMBER OF ZEROES
    for(int i=0;i<v.size();i++){                // TRAVERSING IN THE LOOP TO COUNT THE NUMBER OF ZEROES
        if(v[i]==0){                            // IF VECTOR'S ELEMENT EQUAL TO 0 THEN
            noOfZeroes++;                       // VARIABLE WILL GET ADDED BY 1
        }
    }
    for(int i=0;i<v.size();i++){                // NOW AGAIN TRAVERSING IN THE LOOP AND THIS TIME WE WILL MAKE CHANGES AS WE CAN CHANGE IN VECTORS
        if(i<noOfZeroes){
            v[i]=0;
        }else{
            v[i]=1;
        }
    }
}

int main(){
    vector<int>v;                                       // MAKING A VECTOR
    v.push_back(1);
    v.push_back(0);
    v.push_back(0);
    v.push_back(1);
    v.push_back(1);
    v.push_back(1);
    v.push_back(0);
    v.push_back(0);

    sort0And1(v);                                       // CALLING THE FUNCTION TO MAKE CHANGES IN THE VECTOR

    for(int i=0;i<v.size();i++){
        cout<<v[i]<<" ";
    }
}
