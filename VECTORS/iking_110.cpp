// **************** ARRAY MANIPULATION ***************** 
// FIND THE UNIQUE NUMBER IN THE ARRAY WHERE EXCEPT ONE ELEMENT ALL HAVE DUPLICATES
// MANIPULATION MEANS CHANGING THE ELEMENTS OF THE ARRAY WITH ANY OTHER VALUE

#include<bits/stdc++.h>
using namespace std;

int main(){
    int arr[]={3,2,1,4,2,1,3};                           // MAKE AN ARRAY OF REQUIRED CONDITION

    for(int i=0;i<7;i++){                               // OUTER LOOP WILL BE CHOOSING FIRST ELEMENT
        for(int j=i+1;j<7;j++){                         // INNER LOOP WILL MOVE AFTER THE ELEMENT OF THE OUTER LOOP
            if(arr[i]==arr[j]){                         // IF WE GET SAME VALUE MEANS DUPLICATE
                arr[i]=arr[j]=-1;                       // THEN MAKE BOTH OF THEM -1 FOR THE SAKE THAT WILL FULFILL FURTHER CONDITION
            }
        }
    }
    for(int i=0;i<7;i++){                               // NOW TRAVERSING IN THE LOOP
        if(arr[i]>0){                                   // ALL DUPLICATES WILL BE CONVERTED INTO -1 SO WE WILL LEFT WITH ONLY 
            cout<<arr[i]<<endl;                         // THAT POSITIVE WHICH DONOT HAVE DUPLICATE
        }
    }
    
    // ************ SORT FUNCTION ************** ( DO SORTING IN O(N.LOG(N)) )
    // ANOTHER METHOD IS TO SORT THE ARRAY AND THEN CHECK THAT WHETHER THE NEXT AND PREVIOUSOF ITH ELEMENT ARE EQUAL TO IT OR NOT
    // IF ONE OF THEM EQUALS THEN IT HAS DUPLICATES ELSE IT IS THE ONLY UNIQUE ELEMENT IN THE GIVEN ARRAY
    // IT IS MORE EFFICIENT AS DONE IN O(N.LOG(N))

    vector<int>v={3,2,1,4,2,1,3};
    sort(v.begin(),v.end());
    for(auto ele:v) cout<<ele<<" ";
    cout<<"\n";
    for(int i=0;i<v.size();i++){
        if(not(v[i]==v[i-1] || v[i]==v[i+1])){
            cout<<v[i]<<"\n";
            break;
        }
    }
}
