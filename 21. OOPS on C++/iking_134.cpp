// VIRTUAL FUNCTIONS
// THE FUNCTION IN BASE CLASS IS DECLARED VIRTUAL
// WHEN THE FUNCTION IS MADE VIRTUAL C++ DETERMINES WHICH FUNCTION TO USE AT RUN TIME BASED ON THE TYPE OF THE OBJECT POINTED
// TO BY THE BASE POINTER, RATHER THAN THE TYPE OF POINTER

// WE MUST ACCESS THE VIRTUAL FUNCTIONS THROUGH THE USE OF A POINTER DECLARED AS POINTER TO THE BASE CLASS

// RULES FOR VIRTUAL FUNCTIONS
// >> DEFINED IN A BASE CLASS AND ARE ALWAYS DECLARED WITH A BASE CLASS AND OVERRIDDEN IN A CHILD CLASS
// >> CALLED DURING RUN TIME
// >> THEY CANNOT BE STATIC, THEY ARE DYNAMIC IN NATURE
// >> THEY ARE ACCESSED BY OBJECT POINTERS
// >> VIRTUAL FUNCTIONS CAN BE A FRIEND OF ANOTHER CLASS
// >> A VIRTUAL FUNCTION IN A BASE CLASS MIGHT NOT BE USED BUT MUST BE DEFINED
// >> WE CANNOT HAVE VIRTUAL CONSTRUCTORS BUT VIRTUAL DESTRUCTORS
// >> A VIRTUAL FUCNTION DEFINE IN A BASE CLASS, THEN  THERE IS NO NECESSITY OF IT TO REDEFINE IN THE DERIVED CLASS
//    IN SUCH CASES CALL WILL INVOKE THE BASE FUNCTION
// >> WE CANNOT USE THE POINTER TO DERIVED CLASS TO AN OBJECT OF BASE TYPE

#include<iostream>
using namespace std;

class baseClass{
    public:
        int var_base;
        virtual void display(){                                                   // THIS FUNCTION IS MADE VIRTUAL
            cout<<"1.Displaying base class variable var_base "<<var_base<<endl;
        }
};

class derivedClass : public baseClass{
    public:
        int var_derived;
        void display(){
            cout<<"2.Displaying base class variable var_base "<<var_base<<endl;
            cout<<"2.Displaying derived class variable var_derived "<<var_derived<<endl;

        }
};

class derivedClass2 : public baseClass{
    public:
        int var_derived;
        void display(){
            cout<<"3.Displaying base class variable var_base "<<var_base<<endl;
            cout<<"3.Displaying derived class2 variable var_derived "<<var_derived<<endl;

        }
};

class derivedClass3 : public baseClass{
    public:
        int var_derived;
};

int main(){
    baseClass obj_base;
    derivedClass obj_derived;
    derivedClass2 obj_derived2;
    derivedClass3 obj_derived3;
    baseClass *base_class_ptr;

    base_class_ptr = &obj_base;
    base_class_ptr->display();  

    // HERE STILL THE POINTER IS OF BASE CLASS BUT THIS DISPLAY FUNCTION CAN BE USED FOR DERIVED CLASS
    base_class_ptr = &obj_derived;
    base_class_ptr->display();     
    
    base_class_ptr = &obj_derived2;
    base_class_ptr->display();  

    base_class_ptr = &obj_derived3;
    base_class_ptr->display(); 

    return 0;
}