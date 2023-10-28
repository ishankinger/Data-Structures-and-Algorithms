// ************* FREQUENCY ARRAY METHOD ***************
// GIVEN Q QUERIES AND IN THAT CHECK WHETHER NUMBER IS PRESENT IN ARRAY OR NOT( VALUE OF ALL ELEMENTS ARE LESS THAN 10^5 )
// Q QUERIES CAN BE A VERY BIG NUMBER SO WE HAVE TO CHECK BY TRAVERSING IT BUT IT WILL NOT BE A GOOD METHOD ( BRUTE FORCE METHOD )
// OTHER WAY IS TO MAKE AN ARRAY OF 10^5 SIZE AND FILL IT WITH 0 AND THE ELEMENT'S NUMBER INDEX WILL BE ADDED BY 1 EACH TIME WHEN IT IS PRESENT

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main(){
    vector<int>v;                               // A VECTOR IS CREATED WITH INITIAL 0 SIZE
    v.push_back(8);                             // NOW WE ADD SOME ELEMENTS IN THE VECTOR
    v.push_back(4);                            
    v.push_back(7);
    v.push_back(1);
    v.push_back(3);
    v.push_back(4);

    vector<int>queries;                         // A VECTOR TO TAKE QUERIES IS CREATED
    queries.push_back(4);
    queries.push_back(1);
    queries.push_back(2);

    int freq[10];                                // AN ARRAY TO CHECK FREQUENCY 
    for(int i=0;i<10;i++){                       // INITIALLY ALL ELEMENTS ARE AT ZERO
        freq[i]=0;
    }
    for(int i=0;i<6;i++){                        // LOOPING IN THE GIVEN VECTOR AND VALUE OF ELEMENT IS ACTING AS AN INDEX FOR THE FREQUENCY ARRAY
        freq[v[i]]++;                            // AS MANY TIMES IT COMES IT WILL BE ADDED BY ONE SO WE GET FREQUENCY OF EACH ELEMENT WITH THIS
    }
    for(int i=0;i<queries.size();i++){
        cout<<"number of times the element "<<queries[i]<<" comes in the given vector : ";
        cout<<freq[queries[i]]<<endl;
    }
    
    return 0;
}
