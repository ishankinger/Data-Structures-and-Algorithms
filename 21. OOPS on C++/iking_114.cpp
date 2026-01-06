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

    Complex2(int x){
        a = x;
    }

    // ALL THESE CAN'T BE USED AT ONCE FIRST COMMENT OUT
    // LOGIC DONE IN FURTHER SLIDES IN CONSTRUCTOR OVERLOADING

    // CONSTRUCTORS DEFINED INSIDE THE FUNCTION ALSO ACT LIKE INLINE FUNCTION
    // USED FOR SMALL FREQUENTLY CALLED CONSTRUCTORS

    Complex2(int x,int y){                                           // PARAMETERISED CONSTRUCTORS WE ARE GIVING SOME ARGUMENTS IN THE CONSTRUCTOR
        a=x;                                                         // THEY ARE VARIABLES OF DATATYPES IN THE BRACKETS
        b=y;
    }

    // // INITIALISATION LIST IN THE CONSTRUCTOR FUNCTIONS
    // Complex2(int x, int y) : a(x), b(x+y){                           // ANOTHER WAY TO INITITALISE THE DATA MEMBERS OF THE CLASS
    //     cout << "Initialised Constructor\n";
    // }

    // Complex2(int x, int y) : a(x), b(a + y){
    //     cout << "initial parameter used in next parameter\n";
    // }

    // // INITIALISATION WILL HAPPEN IN THE ORDER VARIABLES ARE DEFINED IN THE CLASS
    // Complex2(int x, int y) : b(y), a(x + b){
    //     cout << "This will create problem will give a garbage value";
    //     cout << "Here a is initialised first in the class so a = x+b will be executed first thus give garbage value as b's value is not assigned\n";
    // }

    // Complex2(int a, int c){                                          // 'this' POINTER IS USED TO POINT TO THE PROPERTIES OF THE OBJECT
    //     this->a = a;                                                 // this - POINTER AUTOMATICALLY CREATED, WHICH STORE THE ADDRESS OF OBJECT
    //     this->b = c;
    // }
    
    void printNumber(){
        cout<<"Your Number is "<< a<<" + "<<b<<"i"<<endl;
    }
};

int main(){
    Complex a;
    a.printNumber();

    Complex2 b(4,6);                                                   // IMPLICIT CALL ( IMPLIED OR UNDERSTOOD INDIRECTLY WIHOUT BEING STATED OUTRIGHT )
    b.printNumber();                                                   // ONE WAY OF USING THE VALUE OF CONSTRUCTOR AS SHOWN

    Complex2 c = Complex2(6,4);                                        // EXPLICIT CALL ( CLEARLY AND DIRECTLY STATED WITHOUT LEAVING ROOM FOR CONFUSION )
    c.printNumber();                                                   // OTHER WAY OF USING THE VALUE CONSTRUCTOR
    
    // The {4,6} is list-initialization (a feature from C++11).
    //  compiler looks for a constructor of Complex2 that can be called with two ints.
    // Finds Complex2(int,int) → constructs the object.
    Complex2 d = {4,6};
    d.printNumber();

    // The compiler sees we’re creating a Complex2 object but giving it an int.    
    // It looks for a constructor that can take one int → finds Complex2(int x).
    Complex2 e = 5;
    e.printNumber();

    // If you don’t want Complex2 e = 5; to work implicitly,
    //  you can prevent the compiler from doing this conversion by declaring the constructor as explicit:

    //  explicit Complex2(int x, int y) {
    //     a = x;
    //     b = y;
    // }
    
    // Complex2 d = {4,6};  //  error if constructor is explicit
    // Complex2 e = 5;      //  error if constructor is explicit

    // explicit prevents implicit conversions, but does NOT prevent direct initialization.
    // Complex2 b(4,6); is still valid. 

    return 0;
}