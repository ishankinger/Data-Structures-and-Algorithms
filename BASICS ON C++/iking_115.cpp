// PRINT THE FIRST MULTIPLE OF 5 WHICH ALSO MULTIPLE OF 7

#include<iostream>
using namespace std;

int main(){
    
    int i=5;                                                   // INITIALISATION WITH FIRST MULTIPLE OF 5
    while(true){                                               // SYNTAX AS DISCUSSED BEHIND
        if(i%7==0){                                            // CONDITION THAT IT IS MULTIPLE OF 7 OR NOT
            cout<<i<<endl;                                     // IF YES THEN PRINT IT 
            break;                                             // AND GET OUT OF THE LOOP
        }
        i += 5;                                                // OTHERWISE MOVE LOOP BY 5 SO THAT MULTIPLE OF 5 REMAIN IN THE GAME
    }

    for(int i=5; ; i+=5){                                      // SIMILAR THING CAN BE DONE WITH FOR LOOP
        if(i%7==0){                                            // WE OMITTED CONDITION PART IN FOR LOOP WHICH WE USE INSIDE
            cout<<i<<endl;
            break;
        }
    }
    return 0;
}