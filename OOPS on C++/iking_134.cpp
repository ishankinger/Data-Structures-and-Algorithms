// VIRTUAL FUNCTIONS
// RULES FOR VIRTUAL FUNCTIONS
// >> THEY CANNOT BE STATIC
// >> THEY ARE ACCESSED BY OBJECT POINTERS
// >> VIRTUAL FUNCTIONS CAN BE A FRIEND OF ANOTHER CLASS
// >> A VIRTUAL FUNCTION IN A BASE CLASS MIGHT NOT BE USED
// >> A VIRTUAL FUCNTION DEFINE IN A BASE CLASS THERE IS NO NECESSITY OF IT DEFINE IN THE BASE CLASS

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

int main(){
    baseClass obj_base;
    derivedClass obj_derived;

    baseClass *base_class_ptr;
    base_class_ptr = &obj_derived;
    base_class_ptr->display();         // HERE STILL THE POINTER IS OF BASE CLASS BUT THIS DISPLAY FUNCTION CAN BE USED FOR DERIVED CLASS

    return 0;
}