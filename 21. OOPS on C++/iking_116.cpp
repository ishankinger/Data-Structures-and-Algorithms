// CONSTRUCTOR OVERLOADING ( MULTIPLE CONSTRUCTORS CAN BE USED IN A CLASS )

// Complex(){  } -> "do nothing" IMPLICIT CONSTRUCTOR
// WHEN DEFINING A CONSTRUCTOR IT'S BETTER TO DEFINE A DO NOTHING CONSTRUCTOR BECAUSE 
// AFTER DEFINING OUR OWN CONSTRUCTOR COMPILER WILL NOT USE
//  IT'S OWN DEFAULT CONSTRUCTOR THUS   A a;  WILL GIVE ERROR

#include<iostream>
using namespace std;

class Complex{
    int a,b;
    public:
    
    Complex(int x,int y){                                       // 1ST CONSTRUCTOR
        cout<<"My complex number is ";                          // TAKING TWO ARGUMENTS X AND Y OF INT DATATYPES
        a=x;
        b=y;
    }

    Complex(int x){                                             // 2ND CONSTRUCTOR
        cout<<"My purely real number is ";                      //  TAKING ONE ARGUMENT X OF INT DATATYPES
        a=x;
        b=0;
    }

    // Complex(int y){                                          // THIS CONSTURCTOR CANNOT BE USED AS IT'S ARGUMENTS TO 2ND CONSTURCTOR
    //     cout<<"My purely imaginary number is ";              // AND IF WE USE THIS THEN THERE WILL BE EROR THAT CONSTRUCTOR OVERLOADING 
    //     a=0;                                                 // CANNOT OCCUR
    //     b=y;
    // }

    Complex(){                                                  // 3RD CONSTRUCTOR 
        cout<<"your number is ";                                // NO ARGUMENTS ARE TAKEN IN THIS
        a=0;
        b=0;
    }
    
    void printNumber(){
         cout<< a<<" + "<<b<<"i"<<endl;
    }
};

int main(){
    
    Complex a(4,6);                                             // MAIN IMPLICATIONS OF CONSTRUCTOR OVERLOADING DEPENDS UPON THE TYPE AND NUMBER
    a.printNumber();                                            // USED IN THE CONSTRUCTOR
    
    Complex b(5);                                               // ACCORDING TO ARGUMENTS THE DIFFERENT OBJECTS WILL BE CATEGORISED INTO DIFFERENT
    b.printNumber();                                            // CONSTRUCTOR
    
    Complex c;                                                  // HERE WE DONOT GIVE ANY SPECIALISATION TO THE OBJECT SO IT WILL WORK UNDER
    c.printNumber();                                            // DEFAULT CONSTRUCTOR

    return 0;
}