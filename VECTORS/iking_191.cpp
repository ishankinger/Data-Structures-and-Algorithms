// *******RECORD BREAKING*******  ( FROM ARRAY WE HAVE TO CALCULATE NUMBER OF ELEMENTS SATISFYING BOTH THE GIVEN CONDITION
// >> ELEMENT SHOULD BE STRICTLY LARGER THAN ALL THE PREVIOUS ELEMENTS BEHIND IT AND IT CAN BE FIRST ELEMENT 
// >> ELEMENT SHOULD BE LARGER THAN ITS FOLLOWING ONE ELEMENT ONLY AND IT CAN BE LAST ELEMENT ALSO          )

#include<iostream>
using namespace std;

int main(){
    int givenArr[]={3,2,2,7,2,3,4};                                   // GIVEN ARRAY FROM WHICH WE HAVE TO CHOOSE ELEMENTS
    int ans=0;                                                        // ANS TO BE PRINTED
    int maxEle=-1;                                                    // MAXIMUM ELEMENT TO GET FROM THE ARRAY

    for(int i=0;i<7;i++){                                             // TRAVERSING IN THE ARRAY VIA FOR LOOP
        if(givenArr[i]>maxEle && givenArr[i]>givenArr[i+1]){          // CONDITIONS SATISFIED IN THE CODE
            ans++;                                                    // IF SATISFIED THEN ANSWER GET INCREASED
        } 
        maxEle=max(maxEle,givenArr[i]);                               // FUNCTION TO GET MAXIMUM ELEMENT FROM THE ARRAY
    }
    cout<<ans;                                                        // PRINT THE ANSWER
    return 0;

}