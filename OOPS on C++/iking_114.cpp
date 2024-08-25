// PARAMETERISED AND DEFAULT CONSTRUCTORS IN C++

// A CONSTRUCTOR THAT ACCEPTS NO PARAMETERS IS CALLED DEFAULT CONSTRUCTOR
// IF NO SUCH CONSTRUCTOR IS DEFINED THEN THE COMPILER SUPPORTS A DEFAULT CONSTRUCTOR TO INVOKE WHEN THE OBJECT IS CREATED

// ON THE OTHER HAND CONSTRUCTORS THAT CAN TAKE ARGUMENTS ARE CALLED PARAMETERISED CONSTRUCTOR
// THE PARAMETERS OF THE CONSTRUCTOR CAN BE OF ANY TYPE EXCEPT THAT OF THE CLASS TO WHICH IT BELONGS
// HOWEVER A CONSTRUCTOR CAN ACCEPT A REFERENCE TO IT'S OWN CLASS AS A PARAMETER ( USED IN COPY CONSTRUCTOR )

#include<iostream>
using namespace std;

class Complex{
    int a,b;
    public:
    Complex(void){                                                  // RUN BY DEFAULT WITHOUT ANY SPECIAL COMMAND 
        a=10;                                                       // THUS THESE TYPES OF CONSTRUCTORS ARE CALLED DEFAULT CONSTRUCTORS
        b=5;                                                        // IT DOESNOT ACCEPT ANY ARGUMENTS IN IT
    }
    void printNumber(){
        cout<<"Your Number is "<< a<<" + "<<b<<"i"<<endl;
    }
};

class Complex2{
    int a;
    int b;
    public:

    // ALL THESE CAN'T BE USED AT ONCE FIRST COMMENT OUT
    // LOGIC DONE IN FURTHER SLIDES IN CONSTRUCTOR OVERLOADING

    Complex2(int x,int y){                                           // PARAMETERISED CONSTRUCTORS WE ARE GIVING SOME ARGUMENTS IN THE CONSTRUCTOR
        a=x;                                                         // THEY ARE VARIABLES OF DATATYPES IN THE BRACKETS
        b=y;
    }

    // INITIALISATION LIST IN THE CONSTRUCTOR FUNCTIONS
    
    Complex2(int x, int y) : a(x), b(x+y){                           // ANOTHER WAY TO INITITALISE THE DATA MEMBERS OF THE CLASS
        cout << "Initialised Constructor\n";
    }

    Complex2(int x, int y) : a(x), b(a + y){
        cout << "initial parameter used in next parameter\n";
    }

    Complex2(int x, int y) : b(y), a(x + b){
        cout << "This will create problem will give a garbage value";
        cout << "Here a is initialised first in the class so a = x+b will be executed first thus give garbage value as b's value is not assigned\n";
    }

    Complex2(int a, int c){                                          // 'this' POINTER IS USED TO POINT TO THE PROPERTIES OF THE OBJECT
        this->a = a;                                                 // this - POINTER AUTOMATICALLY CREATED, WHICH STORE THE ADDRESS OF OBJECT
        this->b = c;
    }
    
    void printNumber(){
        cout<<"Your Number is "<< a<<" + "<<b<<"i"<<endl;
    }
};

int main(){
    Complex a;
    a.printNumber();

    Complex2 b(4,6);                                                   // IMPLICIT CALL
    b.printNumber();                                                   // ONE WAY OF USING THE VALUE OF CONSTRUCTOR AS SHOWN

    Complex2 c= Complex2(6,4);                                         // EXPLICIT CALL
    c.printNumber();                                                   // OTHER WAY OF USING THE VALUE CONSTRUCTOR
    
    return 0;

}