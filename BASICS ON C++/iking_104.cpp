// OPERATORS

#include<iostream>
using namespace std;

int main(){
    int a,b;
    a=5;
    b=3;

    b--;                                             // ARITHEMETIC OPERATORS
    cout<<b<<endl;
    cout<<a--<<endl;
    cout<<--a<<endl;

    cout<<a%b<<endl;                                 // MODULO OPERATOR

    cout<<(a>=b)<<endl;                              // RELATIONAL OPERATORS
    cout<<(a!=b)<<endl;
    cout<<(a>b)<<endl;

    bool exp1= true;                                 // LOGICAL OPERATORS
    bool exp2= false;                                // OTHER THAN THESE BOOLEANS THERE CAN BE CONDITIONS WHICH ARE TRUE OR FALSE
    cout<<(exp1 && exp2)<<endl;                      // AND OPERATOR
    cout<<(exp1 || exp2)<<endl;                      // OR OPERATOR 
    cout<<!(exp1)<<endl;                             // LOGICALLY NOT OPERATOR
    
    a +=1;                                           // ASSIGNMENT OPERATORS
    a /=2;                                           // MEANS VALUE OF A IS CHANGED AFTER DIVIDING IT BY TWO

    sizeof(a);                                       // SIZE OPERATOR
    sizeof(b);                                       // TELL ABOUT THE SIZE OF THE DATATYPES

    4==5? a=4:b=4;                                   // TERNARY OPERATORS -->  CONDITION? EXP1:EXP2; 
    b==4? a=4:b=5;                                   // IF CONDITION TRUE THEN EXP1 WORK OTHERWISE EXP2
    cout<<a<<endl;
    cout<<b<<endl;

    float c=7.54;                                    // CASTING OPERATOR
    cout<<int(c)<<endl;

    char chr='c';
    cout<<int(chr)<<endl;                            // FOR CHARACTERS IT WILL RETURN THEIR ASCII VALUES
    
    chr+=5;
    cout<<chr<<"\n";
    cout<<int(chr)<<"\n";

    int num=5;
    num+='c';
    cout<<num<<"\n";
    cout<<char(num)<<"\n";
    return 0;
}
// POINTER AND AMPERSANT OPERATOR ARE DISCUSSED IN FURTHER FILES
// DOT AND ARROW OPERATORS WILL BE DISCUSSED IN TIME OF OOP'S CONCEPTS