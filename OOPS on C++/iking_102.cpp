// STRUCTURES ( USER DEFINED DATATYPE )
// COLLECTION OF OBJECTS OF DIFFERENT DATATYPES
// IT WILL WORK SAME AS OUT PRE DEFINED DATATYPE DO 
// IT WILL TAKE INPUT AS USER DEFINED DATATYPES

#include<iostream>
using namespace std;

struct employee{                          // DEFINING A STRUCTURE NAMED AS EMPLOYEE
    int empID;                            // INTEGER DATATYPE VARIABLE
    char favChar;                         // CHARACTER DATATYPE VARIABLE
    float salary;                         // FLOAT DATATYPE VARIABLE 
    char name[30];                        // A CHARACTER ARRAY FOR NAME
};                                        // SEMICOLON MUST BE USED AFTER THE };

struct emply{
    int id;
    char name[30];
    int sal;
}e1,e2;                                   // GLOBAL VARIABLES OBJECTS ARE DEFINED HERE SO NO NEED TO DEFINE IN MAIN FUNCTION

typedef struct emplyee{                   // ANOTHER TYPE TO DEFINE A STRUCTURE DATATYPE SO THAT TO MAKE IT EASY TO CALL AN OBJECT FOR THIS 
    string favColor;                      // USE KEYWORD 'typedef'
    int favNumber;
} emp;                                    // eMp; TO BE USED LIKE THIS HERE ANY OTHER SHORTFORM CAN ALSO BE USED

int main(){
    struct employee harry;                // OBJECT OF STRUCTURE DEFINED LIKE THIS >>  struct_nameOfStructure_nameOfObject        
    struct employee shubham;              // ANOTHER OBJECT OF DIFFERENT NAME

    shubham.salary=90000;                 // VARIABLES IN THE STRUCTURE DATATYPE CAN BE USED LIKE >>  objectName.variable=_____
    harry.empID=1;                        // SIMILARLY OTHER VARIABLES VALUES CAN ALSO BE PUT 
    harry.favChar='c';
    harry.salary= 12000000;

    cout<<harry.favChar<<endl;            // NOW WE CAN GET OUTPUT FROM THIS
    cout<<harry.salary<<endl;
    cout<<shubham.salary<<endl;

    e1.id=100;
    e2.sal=1000000;

    cout<<e2.sal<<endl;
    cout<<e1.id<<endl;

    emp ishan;                            // NOW USE THAT SHORTCUT VIA HELP OF TYPEDEF KEYWORD

    ishan.favColor="blue";
    ishan.favNumber=7;

    cout<<ishan.favNumber<<endl;

    struct emply E1;
    struct emply *ptr;
    ptr=&E1;
    E1.id=1;
    E1.sal=150000;

    cout<<E1.id<<endl;
    cout<<E1.sal<<endl;

    cout<<(ptr)<<"\n";
    cout<<(*ptr).id<<"\n";

    return 0;
}

// LIMITATIONS OF STRUCTURES
// >> MEMBERS ARE PUBLIC
// >> NO METHODS
// >> DONOT ALLOW STRUCT DATA TYPE TO BE TREATED AS BUILT IN TYPES

// STRUCTURES USED IN C++
// >> STRUCTURES CAN HAVE BOTH VARIABLE AND FUNCTIONS
// >> IT CAN ALSO DECLARE SOME OF IT'S MEMBERS AS PRIVATE
// >> KEYWORD STRUCT CAN BE OMMITTED WHILE DEFINING THE OBJECT
// >> STRUCTUES AND CLASSES CAN BE USED INTERCHANGEABLY ( ONLY DIFFERENCE IS MEMBERS OF CLASS BY DEFAULT ARE PRIVATE WHERE AS STRUCT ARE PUBLIC)

// C++ PROGRAMMERS TENDS TO USE THE STRUCTURES FOR HOLDING ONLY DATA AND CLASSES TO HOLD BOTH DATA AND FUNCTIONS