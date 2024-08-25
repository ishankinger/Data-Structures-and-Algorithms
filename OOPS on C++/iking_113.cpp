// CONSTRUCTORS IN C++
// int sum=6; --> MEANS WE TAKE SUM AS A VARIABLE OF INT DATATYPE AND HAVE TO FILL 6 IN ITS MEMORY STORAGE VALUE
// SIMILARLY IF WE TAKE CLASSES ACT AS CUSTOM DATATYPES
// CONSTRUCTOR IS A SPECIAL MEMBER FUNCTIONS WITH SAME NAME AS OF THE CLASS. IT IS USED TO INITIALISE THE OBJECTS OF ITS CLASS
// IT IS AUTOMATICALLY INVOKED ( CALLED ) WHENEVER AN OBJECT IS CREATED
// IT IS CALLED CONSTRUCTOR BECAUSE IT CONSTRUCTS THE VALUES OF DATA MEMBERS OF THE CLASS

#include<iostream>
using namespace std;

class Complex{
    int a,b,c,d;
    public:
    Complex(void);                                                 // CONSTRUCTOR DECLARATION NAME SHOULD BE NAME OF THE CLASS

    void printNumber(void){
            cout<<"Your number is "<<a<<" + "<<b<<"i"<<endl;
        }
    void printNum(void){
        cout<<"Your number is "<<c<<" + "<<d<<"i"<<endl;
    }
};

Complex :: Complex(void){                                          // CONSTRUCTOR USED OUTSIDE THE CLASS
    a=10;
    b=5;
    c=5;
    d=10;
    cout<<"rock with this number"<<endl;
}

int main(){
    Complex c1,c2;                                                 // IF THERE IS ANY COUT WRITTEN IN CONSTRUCTOR THEN IT WILL DIRECTLY GET 
    c1.printNumber();                                              // PRINTED ON THE SPOT WHEN THE OBJECT IS DEFINED FOR THAT CLASS
    c2.printNum();
    Complex c3;                                                    // NOW FROM THIS WE CAN UNDERSTAND MORE ABOUT THE INVOKING PRINCIPLE OF A
    c3.printNumber();                                              // CONSTRUCTOR AND HOW IT IS IMPLEMENTED
    Complex c4;
    c4.printNumber();
    return 0;
}

// PROPERTIES OF CONSTRUCTORS
// >> IT SHOULD BE DECLARED IN PUBLIC SECTION OF THE CLASS 
// >> THEY ARE AUTOMATICALLY INVOKED (USED WHENEVER THE OBJECT IS FORMED)
// >> THEY CANNOT RETURN VALUES AND DO NOT HAVE RETURN TYPES 
// >> IT CAN HAVE DEFAULT ARGUMENTS (INT A,INTB TYPE THINGS CAN BE TAKEN IN THE BRACKETS)
// >> WE CANNOT REFER TO THEIR ADDRESS
// >> THEY CANNOT BE INHERITED ( THOUGH DERIVED CLASS CAN CALL THE BASE CALL CONSTRUCTOR )
// >> CONSTRUCTORS CANNOT BE VIRTUAL
// >> AN OBJECT WITH A CONSTRUCTOR CAN NOT BE USED AS A MEMBER OF A UNION
// >> THEY MAKE IMPLICIT CALLS TO THE OPERATORS 'NEW' AND 'DELETE' WHEN MEMORY ALLOCATION IS REQUIRED