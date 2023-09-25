// PROTECTED ACCESS MODIFIERS
// ANOTHER MODIFIER OF THE TYPE OF PUBLIC AND PRIVATE

#include<iostream>
using namespace std;

class Base{
    protected:                    // THIS CAN BE INHERITED
        int a;
    private:
        int b;
};

// VISI MODE ==>  PUBLIC DERIVATION       PRIVATE DERIVATION    PROTECTED DERIVATION 
// VARIABLES||
// PRIVATE         NOT INHERITED           NOT INHERITED        NOT INHERITED          
// PROTECTED       PROTECTED                  PRIVATE            PROTECTED
// PUBLIC          PUBLIC                     PRIVATE            PROTECTED

class Derived : protected Base{

};

int main(){
    Base b;
    Derived d;
    // cout<<b.a<<endl;
    // cout<<d.a<<endl;

}
// PROTECTED IS SIMILAR TO PRIVATE THE ONLY DIFFERENCE IS THAT IT CAN BE INHERITED BUT THE PRIVATE CANNOT BE INHERITED IN THE DERIVED CLASS