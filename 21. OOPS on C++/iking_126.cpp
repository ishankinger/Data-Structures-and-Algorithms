// AMBIGUITY RESOLUTION IN INHERITANCE
// WHEN SAME NAME FUNCTION IS USED IN DIFFERENT BASE CLASSES WHICH TO BE USED IN DERIVED CLASS OF ALL
// SO WE WILL BE USING THESE THINGS IN MULLTIPLE INHERITANCE

// IMPORTANT - EVEN IF PARAMETERS ARE DIFFERENT THEN ALSO SAME FUNCTION NAME WILL GIVE AMBUIGUITY ERROR

#include<iostream>
using namespace std;

// FOR MULTIPLE INHERITANCE
// HAVE TO DEFINE IN THE DERIVED CLASS USING SCOPE RESOLUTION OPERATOR
class Base1{                                                // FIRST BASE CLASS
    public: 
        void greet(){                                       // SIMPLE PUBLIC FUNCTION OF GREET
            cout<<"how are you"<<endl;
        }
};
class Base2{                                                 // SECOND BASE CLASS
    public :
        void greet(){                                        // A FUCNTION OF SAME NAME GREET
            cout<<"kaise ho"<<endl;
        }
};
class derived: public Base1,public Base2{                   // DERIVED CLASS
    int a;
public:
    // IF SAME NAME FUNCTION PRESENT IN BOTH 
    // IF THIS FUNCTION NOT DEFINED THEN DERIVED CLASS OBJECT CALLING THIS FUNCTION WILL GIVE AMBUITY ERROR 
    // AS TO WHICH GREET IT SHOULD CALL
    void greet(){                                        // NOW IT IS USING GREET FUNCTION 
        Base1::greet();                                  // THIS LINE RESOLVES THE AMBIGUITY OF WHICH BASE CLASS PUBLIC FUNCTION TO BE USED      
    }                                                    // HERE AS BOTH OF THEM HAVE SAME NAME FUCNTIONS
};

// FOR SINGLE LEVEL AND MULTILEVEL INHERITANCE
// IF FUNCTION DEFINED IN CLASS THEN TAKE BY DEFAULT THAT FUNCTION, IF NOT DEFINED THEN 
// IT WILL TAKE FROM THE LAST DERIVED CLASS
class B{
    public:
        void say(){
            cout<<"hello my beautiful people"<<endl;
        }
};
class D : public B{
    int a;
    public:
        void say(){
            cout<<"hello world"<<endl;
        }
};
class E : public D{
    
};


int main(){
    Base1 base1obj;
    base1obj.greet();

    Base2 base2obj;
    base2obj.greet();

    derived base3obj;
    base3obj.greet();

    B b; 
    b.say();
    D d;
    d.say();                         
    E e;                       
    e.say();

    // CAN ALSO DEFINE PARTICULARY WHICH FUNCTION TO USE IN MULTILEVEL INHERITANCE USING SCOPE RESOLUTION OPERATOR
    e.E::say();   // E::say() WILL BE D::say() AS IT IS NOT DEFINED SO CALL IT'S LAST DERIVED CLASS FUNCTION
    e.D::say();
    e.B::say();

    return 0;
}