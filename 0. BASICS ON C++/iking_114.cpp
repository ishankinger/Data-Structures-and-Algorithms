// WHILE LOOP IMP APPLICATION ( WHEN WE DONOT KNOW WHEN WILL THE WORK WILL TERMINATE )
// INPUT TILL -1 WILL COME

#include<iostream>
using namespace std;

int main(){

    while(true){                               // SYNTAX TO WRITE WHEN WE DONOT KNOW WHEN WILL THE WORK WILL TERMINATE
        int n;                                 // HERE FIRST WE TAKE INPUT FROM USER
        cin>>n;
        if(n==-1){                             // NOW IN THESE TYPES WE HAVE TO MAKE A CONDITION INSIDE THE WHILE LOOP
            
            break;                             // IF CONDITION TRUE THEN BREAK( A KEYWORD FOR WHICH WE WILL GET OUT OF THE LOOP)
                                               // 'BREAK' KEYWORD ONLY TAKE OUT OF THE NEAREST LOOP
        }else{                                 // OTHERWISE WE WILL PRINT THE NUMBER OTHER THAN -1
        cout<<n;                               
        }                                      // SO WE GO THIS WAY AS TILL -1 WILL NOT REACH IT WILL KEEP GOING IN WHILE LOOP AND USER
    }                                          // WILL HAVE TO PUT INPUT
    return 0;
}       
// SO WHENEVER WE ARE USING THIS TYPE OF WHERE while(true/1) THEN WE HAVE TO USE BREAK; KEYWORD TO EXIT THE WHILE LOOP OTHERWISE IT WILL BE 
// RUN FOR INFINITE CASES

// *** IF THERE ARE A LOT IF-ELSE THEN BREAK THEN ALSO IT WILL GO OUT OF LOOP NOT ONLY IN PARTICULAR IF-ELSE