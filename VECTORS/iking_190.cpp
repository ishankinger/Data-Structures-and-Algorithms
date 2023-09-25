// *****ARITHEMETIC ARRAY****** ( ARRAY CONTAINING ATLEAST TWO INTEGERS AND DIFFERENCE BETWEEN CONSECUTIVE INTEGERS ARE EQUAL )
// THE SUB ARRAY SHOULD BE CONTINUOUS
// FIND THE NUMBER OF ELEMENTS OF THE LARGEST ARITHEMETIC ARRAY FROM GIVEN ARRAY

#include<iostream>
#include<algorithm>
using namespace std;

int main(){
    int givenArr[]={10,7,4,6,8,10,11};                       // ARRAY FROM WHICH ELEMENT TO BE CHOSEN
    int pd=givenArr[1]-givenArr[0];                          // DIFFERENCE TO BE CHECKED FIRST STARTED WITH FIRST TWO ELEMENTS
    int j=2;                                                 // INITIALISER =2 SO THAT START FORM 2ND AND 3RD ELEMENTS
    int number=2;                                            // COUNT OF ELEMENTS TO BE PRINTED
    int ans=0;                                               // MAIN ANSWER AT THE END TO BE PRINTED
    while(j<7){                                              // TRAVERSING IN THE ARRAY VIA WHILE LOOP
        if(pd==givenArr[j]-givenArr[j-1]){                   // IT SAYS IF DIFFERENCE OF FIRST TWO ELEMENTS MATCHES 2ND AND 3RD THEN 
            number++;                                        // ONE MORE ELEMENT WILL BE ADDED IN THE ARITHEMETIC ARRAY
        }else{                                               // OTHERWISE
            pd=givenArr[j]-givenArr[j-1];                    // 2ND AND 3RD ELEMENT WILL BE CHECKED FURTHER THIS SHOWS THAT WE WILL BE CHOSING ONLY
            number=2;                                        // CONTINUOS ARRAY AND AGAIN NUMBER WILL BECOME 2
        }
        ans=max(ans,number);                                 // THIS IS THE MOST IMPORTANT ONE AS THOUGT THERE CAN BE ARRAYS OF DIFFERENT DIFFERENCES
        j++;                                                 // TO CHOOSE MAX FROM THEM WE USE THIS AS IT WILL PRESERVE ONLY MAX VALUE AND THEN J++
    }
    cout<<ans<<endl;                                         // AT END THE ANSWER WILL BE PRINTED
    return 0;                                                // ONLY PRINTING SO RETURN 0
}