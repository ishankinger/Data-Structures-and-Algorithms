// WHAT IF A PRIVATE DATA NEEDS TO BE INHERITED BY A DERIVED CLASS
// THIS COULD BE ACCOMPLISHED BY MAKING THE PRIVATE MEMBER TO PUBLIC BUT THAT WILL MAKE IT ACCESSIBLE TO ALL 
// SO C++ PROVIDE A THIRD MODIFIER - PROTECTED ACCESS MODIFIER WHICH IS VISIBLE TO MEMBER FUNCTONS OF IT'S OWN AND IT'S IMMEDIATELY DERIVED CLASS ONLY
// SO PRIVATE DATA OF BASE CLASS WILL REMAIN PRIVATE AND ALSO GET USED BY THE DERIVED CLASS WHICH SOLVES THE ABOVE PROBLEM

#include<iostream>
using namespace std;

class Base{
    protected:                    // VISIBLE TO MEMBER FUNCTION OF IT'S OWN AND DERIVED CLASS
        int a;
    private:                      // VISIBEL TO MEMBER FUNCTION WITHIN IT'S CLASS
        int b;
    public:                       // VISIBLE TO ALL FUNCTION IN THE PROGRAM
        int c;
};

//   VISI MODE  |   PUBLIC DERIVATION      | PRIVATE DERIVATION  |   PROTECTED DERIVATION 
//   VARIABLES  |                          |                     | 
//   PRIVATE    |     NOT INHERITED        |    NOT INHERITED    |    NOT INHERITED          
//   PROTECTED  |      PROTECTED           |       PRIVATE       |     PROTECTED
//   PUBLIC     |      PUBLIC              |       PRIVATE       |     PROTECTED

class Derived : protected Base{

};

int main(){
    Base b;
    Derived d;

    // PRIVATE MEMBER CANNOT BE ACCESSED
    // cout<<b.a<<endl;
    // cout<<d.a<<endl;

    // PUBLIC MEMEBR OF B CAN ACCESS BUT IN D IT BECOMES PROTECTED SO CAN'T BE ACCESSED
    cout << b.c << endl;
    // cout << d.c << endl;

}
// PROTECTED IS SIMILAR TO PRIVATE THE ONLY DIFFERENCE IS THAT IT CAN BE INHERITED BUT THE PRIVATE CANNOT BE INHERITED IN THE DERIVED CLASS

// THE KEYWORDS PRIVATE, PUBLIC AND PROTECTED MAY APPEAR IN ANY ORDER AND ANY NUMBER OF TIMES BUT THE NORMAL PRACTICE IS TO USED AS PRIVATE, PROTECTED AND PUBLIC

