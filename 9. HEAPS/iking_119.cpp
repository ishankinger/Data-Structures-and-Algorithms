// GIVEN K SORTED ARRAYS AND WE HAVE TO MERGE IT INTO SINGLE SORTED ARRAY

// SO MAIN IDEA OF THIS QUESTION IS THAT FIRST WE WILL MAKE INDX ARRAY WHICH WILL TELL ME WHETHER ANY OF MY ARRAY BECOMES FULLY TRAVERSED OR NOT
// THEN SECOND IS PRIORITY QUEUE WHCIH IS DEFINED SUCH A WAY THAT IT IS STORED AS A PAIR BECAUSE WHEN WE WILL ADD ANY ELEMENT IN ANS ARRAY 
// WE ARE ALSO DELETING THAT ELEMENT FROM OUR PQ SO TO ADD A NEW ELEMENT WE WILL BE ADDING NEW ELEMENT FROM THAT ARRAY WHICH THE POPPED OUT PAIR 
// BELONGS TO SO TO DO SO WE NEED THE ARRAY NUMBER OF THAT PARTICULAR ELEM'S ARRAY AND THEN WE WILL ADD IT AND AGAIN CHECK THE SAME PROCEDURE
// AND ALSO INCREASING IDX ARRAY SO TO KEEP TRACK OF FULL TRAVERSAL IN THE ARRAY

#include<bits/stdc++.h>
using namespace std;

int main(){
    int k; cin>>k;                                            // FIRST TAKING INPUT OF K SORTED ARRAYS AS A 2-D VECTOR
    vector<vector<int>>a(k);
    for(int i=0;i<k;i++){                                     // LOOP FOR ARRAY NUMBER(1,2,3,4...K)
        int size; cin>>size;                                  // THEN TAKING INPUT OF SIZE OF PARICULAR ARRAY
        a[i]=vector<int>(size);                               // DEFINING THAT AS A VECTOR OF SIZE 
        for(int j=0;j<size;j++){                              // THEN TAKING INPUT OF ELEMENTS IN THE RESPECTIVE ARRAY
            cin>>a[i][j];                           
        }
    }
    
    vector<int>idx(k,0);                                      // THIS IS VECTOR TO STORE INDEX OF THE ARRAY NUMBER INTITAILISING IT WITH ZERO                               

    priority_queue< pair<int,int> , vector<pair<int,int>> >pq;// PAIR IS DEFINED FOR VALUE AND ARRAY NUMBER

    for(int i=0;i<k;i++){                                     // FIRST WE WILL INSERT ALL THE FIRST ELEMENTS OF ALL THE ARRAYS IN THE PQ
        pq.push({a[i][0],i});                                 // INSERTED AS A PAIR WITH ELEMENT AND ARRAY NUMBER
    }

    vector<int>ans;                                           // AN ANSWER VECTOR IS ALSO FORMED

while(!pq.empty()){                                           // TILL PRIORITY QUEUE IS NOT EMPTY
    pair<int,int> x=pq.top();                                 // THIS WILL GIVE ME THE SMALLEST ELEMENT IN PQ WHICH WE WILL STORE
    pq.pop();                                                 // NOW POP THAT ELEMENT
    ans.push_back(x.first);                                   // NOW WE WILL PUSH THAT MIN PQ TOP'S FIRST ELEMENT IN OUR ANS ARRAY

    if(idx[x.second]+1 < a[x.second].size()){                 // THIS WILL CHECK WHETHER THE SIZE OF THE ARRAY FROM WHICH X BELONG IS FULL OR NOT 
        pq.push({a[x.second][idx[x.second]+1],x.second});     // IF NOT THEN WE WILL PUSH NEXT ELEMENT IN IT 
    }
    idx[x.second]++;                                          // ALSO WE WILL UPDATE THE IDX ARRAY
}
for(int i=0;i<ans.size();i++){                                // AT END WE WILL GET OUR ANS ARRAY AS OUR SORTED MERGED ARRAY
    cout<<ans[i]<<" ";
}
    return 0;
}