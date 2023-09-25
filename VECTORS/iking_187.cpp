// ##### INTERVIEW QUESTIONS ON ARRAY ######

// FIND AN ELEMENT IN THE ARRAY THAT IS FIRST IN OCCURENCE AND ALSO IT OCCURS MORE THAN ONCE

#include<iostream>
#include<climits>
using namespace std;

int main(){
    int arr[]={1,5,3,4,3,5,6};                                    // GIVEN ARRAY
    int size=7;                                                   // SIZE OF THE ARRAY
    int minInd=INT_MAX;                                           // VARIBALE TO GET MIN INDEX
    for(int i=0;i<size;i++){                                      // TRAVERSING IN THE ARRAY USING THE FOR LOOP
        for(int j=i+1;j<size;j++){                                // TRAVERSING WITH ANOTHER POINTER TO THE ELEMENTS AFTER THAT
            if(arr[i]==arr[j]){                                   // IF ELEMENTS HAVE DUPLICATES
                if(i<minInd){                                     // THEN CHECK THERE FIRST OCCURENCE THAT IS I NOT TO CHECK ANYTHING ABOUT J
                    minInd=i;                                     // GET MIN INDEX AS I
                }
            }
        }
        
    }
    cout<<"element in array repeating with least occ is: "<<arr[minInd]<<endl;
}