// POLYMORPHISM
// >> POLY == MANY  MORPHISM == FORMS
// >> ONE NAME WITH MULTIPLE FORMS

// >> COMPILE TIME POLYMORPHISM ( KNOWS WHICH FUNCTION TO RUN AND THEN RUN)
//    > FUNCTION OVERLOADING
//    > OPERATOR OVERLOADING

// >> RUN TIME POLYMORPHISM ( DECISION OF RUNNING FUNCTION TAKEN IN TIME OF RUNNING CODE)
//    > VIRTUAL FUCNTIONS


// POINTERS TO DERIVED CLASS AND CONCEPT OF LATE-BINDING

#include<iostream>
using namespace std;

class baseClass{                                                                  // BASE CLASS
    public:                                                                       // PUBLIC FUNCTIONS AND PUBLIC VARIABLES ARE DEFINED
        int var_base;
        void display(){
            cout<<"Displaying base class variable var_base "<<var_base<<endl;
        }
};

class derivedClass : public baseClass{                                             // DERIVED CLASS
    public:                                                                        // PUBLIC VISIBILITY SO PUBLIC FUNCTIONS AND PUBLIC VARIABLES
        int var_derived;                                                           // WILL BE INHERITED
        void display(){
            cout<<"Displaying base class variable var_base "<<var_base<<endl;
            cout<<"Displaying derived class variable var_derived "<<var_derived<<endl;

        }
};

int main(){
    baseClass obj_base;                 // OBJECT FROM BASE CLASS
    derivedClass obj_derived;           // OBJECT FROM DERIVED CLASS
    
    baseClass *base_class_ptr;
    base_class_ptr = &obj_derived;      // POINTER OF BASE CLASS CAN POINT TO OBJECT OF DERIVED CLASS AND THERE WILL BE NO EROR ON THAT

    base_class_ptr->var_base=34;        // LATE BINDING
    //base_class_ptr-> var_derived=45;  // HERE WE CANNOT USE VAR_DERIVED VARIABLE AND FUCNTION OF THE DERIVED CLASS

    base_class_ptr-> display();         // AS POINTER IS FROM BASE CLASS IT WILL BE ALWAYS BINDED TO THE BASE CLASS
    
    derivedClass  *derived_class_ptr;   // AND FOR DERIVED CLASS POINTER WE WILL BE USING DERIVED CLASS THINGS 
    derived_class_ptr= &obj_derived;    // THAT IS IT WILL ACCESS DISPLAY FUNCTION OF IT'S OWN DERIVED CLASS AND ALSO TAKE VARIABLES DEFINED
    derived_class_ptr-> var_derived=98;
    derived_class_ptr->display();                                 
    return 0;
}
