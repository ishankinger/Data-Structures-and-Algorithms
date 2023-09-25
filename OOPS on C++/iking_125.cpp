// MULTIPLE INHERITANC0E  ( A,B,C,D.... ---> (ONE DERIVED CLASS) ) 
// SYNTAX FOR INHERITING IN MULTIPLE INHERITANCE
// CLASS {{DERIVED_CLASS}} : {{VISIBILITY_MODE BASE1}},{{VISIBILITY_MODE BASE2}},.....

#include<iostream>
using namespace std;

class Base1{                                                                 // FIRST BASE CLASS
    protected:                                                               // DEFINING SOME VARIABLES AND FUNCTIONS IN IT
        int base1int;
    public:
        void set_base1int(int a){                                            // PROTECTED SO HAVE TO USE THIS FUNCTION
            base1int=a;
        }
};

class Base2{                                                                  // SECOND BASE CLASS
    protected:                                                                // EVERYTHING SAME ONLY THE VARIABLE IS CHANGED
        int base2int;
    public:
        void set_base2int(int a){
            base2int=a;
        }
};
class Derived : public Base1, public Base2{                                    // DERIVED CLASS DERIVING VARIABLES AND FUCNTIONS FROM THE BASE CLASS
    public:                                                                    // USING PUBLIC AS VISIBILITY MODE
        void show(){
            cout<<"The value of Base1 is "<< base1int<<endl;
            cout<<"The value of Base2 is "<< base2int<<endl;
            cout<<"The sum of these values is "<< base1int + base2int<<endl;
        }
};

int main(){
    Derived harry;                                                              // OBJECT OF DERIVED CLAS
    harry.set_base1int(25);                                                     // PUBLIC FUCNTION OF FIRST BASE CLASS
    harry.set_base2int(5);                                                      // PUBLIC FUNCTION OF SECOND BASE CLASS
    harry.show();                                                               // FUCNTION OF DERIVED CLASS
    return 0;
}
