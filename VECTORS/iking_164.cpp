// ****TWO POINTERS CONCEPT**** (PREVIOUS QUESTION ONLY IN ONE TRAVERSAL)

#include<iostream>
#include<vector>
using namespace std;

void sort0And1(vector<int>&v){                                  // FUNCTION TO GET NEW V USE AMPERSANT VARIABLE
    
    int left_prt=0;                                             // FIRST POINTER STARTING THE VECTOR FROM LEFT MEANS FROM STARTING
    int right_prt=v.size()-1;                                   // SECOND POINTER STARTING THE VECTOR FROM RIGHT MEANS FROM ENDING

    while(left_prt<right_prt){                                  // WE HAVE TO TRAVERSE TILL THEY COINCIDE SO CONDITION LIKE THAT AS AFTER COINCIDING THE LEFT PART WILL BECOME GREATER THAN RIGHT PART AND WE WILL GET OUT OF LOOP 
        if(v[left_prt]==1 && v[right_prt]==0){                  // IF BOTH CONDITIONS GET TRUE THEN CONDITION WILL BECOME TRUE 
            v[left_prt++]=0;                                    // REPLACE LEFT ELEMENT AS 0 AND INCREASE LEFT POINTER VARIABLE
            v[right_prt--]=1;                                   // REPLACE RIGHT ELEMENT AS 1 AND DECREASE RIGHT POINTER VARIABLE
        }
        if(v[left_prt]==0){                                     // IF GETTING 0 IN LEFT PART THEN ITS OKAY MOVE
            left_prt++;                                         // THE TRAVERSAL IN THE LOOP
        }
        if(v[right_prt]==1){                                    // IF RIGHT PART EQUAL TO 1 THEN ITS OKAY AND MOVE
            right_prt--;                                        // THE TRAVEERSAL IN THE LOOP
        }
    }
}

int main(){
     vector<int>v;                                              // MAKING A VECTOR
    v.push_back(1);
    v.push_back(0);
    v.push_back(0);
    v.push_back(1);
    v.push_back(1);
    v.push_back(1);
    v.push_back(0);
    v.push_back(0);
    
    sort0And1(v);                                                // SORTING OF V BY CALLING THE FUNCTION

    for(int i=0;i<v.size();i++){                                 // THEN PRINT OUT NEW SORTED VECTOR
        cout<<v[i]<<" ";
    }
}
