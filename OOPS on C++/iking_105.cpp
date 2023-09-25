// CLASSES( STRUCTURES + MORE )
// CLASSES CAN HAVE VARIABLES, METHODS AND DIFFERENT OTHER DATATYPES
// CLASSES CAN MAKE MEMBERS AS PUBLIC AND PRIVATE ACCESS MODIFIERS
// DECLARATION OF OBJECTS CAN BE DONE WITH CLASS DECLARATION

#include<iostream>
using namespace std;

class Employee{                                           // A CLASS IS DEFINED USING 'CLASS' KEYWORD AND THEN NAME OF THE CLASS
    private:                                              // IN THIS ANY VARIABLE STORED WILL BE ACCESSED ONLY BY THE FUNCTIONS OF THIS CLASS
        int a,b,c;
    public:                                               // IN THIS ANY VARIABLE CAN BE USED DIRECTLY AND HAVE NO RESTRICTIONS ON IT
        int d,e;

        void setData(int a,int b,int c);                  // DECLARATION OF ONE FUNCTION OF THE CLASS

        void getData(){                                   // ANOTHER FUNCTION WHICH HAS SOME CODE WRITTEN INSIDE AND NOT ONLY DECLARED
            cout<<"The value of a is "<<a<<endl;
            cout<<"The value of b is "<<b<<endl;
            cout<<"The value of c is "<<c<<endl;
            cout<<"The value of d is "<<d<<endl;
            cout<<"The value of e is "<<e<<endl;
        }
};                                                        // NOW AT END THE CLASS ENDS WITH ' }; '

void Employee :: setData(int a1, int b1, int c1){         // AS WE HAVE DECLARED ONE FUNCTION IN THE CLASS WE CAN CALL IT AS SHOWN
    a=a1;                                                 // DECLARATION OF THE VARIABLES TO BE EQUAL TO VARIBLES DECLARED IN CLASS FUNCTION
    b=b1;                                                 // IF WE DONOT USE THIS FUNCTION THEN VALUE OF A,B,C WILL BE SOME GARBAGE VALUE PRINTED
    c=c1;                                                 // BECAUSE A,B,C ARE PRIVATE VARIABLES SO CANNOT BE ACCESED DIRECTLY
}                                                         // FOR PRIVATE VARIABLES IF WE WANT TO ASSIGN VALUES TO THEM WE HAVE TO MAKE THIS FUNCTION
                                                          // IN THIS FUNCTION WE WILL BE TAKING SOME VALUES WHICH WILL GET STORED IN THE PRIVATE VARIBALES
int main(){
    Employee harry;                                        // NOW CLASS NAME AND THEN OBJECT NAME IS USED TO WORK ALL FUNCTIONS OF CLASS ON THE OBJECT
    harry.setData(1,2,4);                                  // USING FUNCTION ON THE OBJECT
    harry.d=3;                                             // AS THESE D AND E ARE PUBLIC SO THERE VALUES CAN BE SIMPLY DECLARED LIKE THIS
    harry.e=5;                                             // FOR OBJECT PUBLIC VARIABLES VALUES CAN BE ASSIGNED USING {{OBJECT}.{VARIABLE}={VALUE}}
    harry.getData();                                       // THIS FUNCTION WILL PRINT THE DATA

    // harry.a=8;                                          // THIS SYNTAX CANNOT BE USED FOR THE INT A AS IT IS IN PRIVATE SO ONLY CAN BE USED 
    return 0;                                              // WITH FUNCTIONS AND NOTHING ELSE
}