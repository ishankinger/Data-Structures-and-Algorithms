// LOCAL CLASSES 
// CLASSES WHICH CAN BE DEFINED AND USED INSIDE A FUNCTION OR A BLOCK





// MEMBERS OF CLASSES : NESTING OF CLASSES
// A CLASS CAN CONTAIN OBJECTS OF OTHER CLASSES AS IT'S MEMBER
// class C {
//     A a;
//     B b;
// };

// THIS KIND OF RELATIONSHIP IS CALLED CONTAINERSHIP OR NESTING
// CREATION OF OBJECT CONTAINING OTHER OBJECT IS DIFFERENT FROM SIMPLE OBJECT CREATION
// FIRST MEMBER OJECTS ARE CREATED USING THEIR RESPECTIVE CONSTRUCTORS AND THEN THE OTHER MEMBER ARE CREATED
// CONSTRUCTOR OF ALL MEMBER OBJECTS SHOULD BE CALLED BEFORE IT'S OWN CONSTRUCTOR BODY
// WHICH CAN ACHIEVED BY USING INITIALIZATION LIST

// C(arglist) : a(agrlist) , b(arglist2)
// {
//
// }

// arglist DOESNOT CONTAINS DATA TYPES THEY ARE FUNCTION CALLS

// CONSTRUCTORS OF THE MEMBER OBJECTS ARE CALLED IN ORDER THEY ARE DEFINED IN THE NESTED CLASS

#include <iostream>
using namespace std;

class Point {
    int x, y;
public:
    Point(int x_, int y_) : x(x_), y(y_) {}
};

class Rectangle {
    Point topLeft;
    Point bottomRight;

public:
    Rectangle(int x1, int y1, int x2, int y2)
        : topLeft(x1, y1), bottomRight(x2, y2)   // initialize both members
    {
        cout << "Rectangle constructed!\n";
    }
};

// MEMBER OJECTS SHOULD NOT BE CONSTRUCTED IN THE BODY USE ONLY INITIALIZATION LIST
class B {
    int &ref;   // reference to an int
public:
    B(int &r) : ref(r) { }    // must bind in initializer list
};

class A {
    const int x;   // constant member
public:
    A(int val) : x(val) { }   // must initialize in initializer list
};



// CONSTANT MEMBER FUNCTIONS AND OBJECTS

// CONSTANT MEMBER FUNCTIONS
// IF A MEMBER FUNCTION DOESNOT ALTER ANY DATA IN THE CLASS THEN WE MAY DECLARE IT AS A const MEMBER FUNCTION
// THE COMPILER WILL GENERATE AN ERROR MESSAGE IF SUCH FUNCTIONS TRY TO ALTER THE DATA VALUE
// VOID MUL(INT,INT) CONST;
// DOUBLE GET_BALANCE() CONST;

// CONSTANT OBJECTS
// WE MAY CREATE AN OBJECT CONSTANT BY USING THE const KEYWORD BEFORE OBJECT DECLARATION
// ANY ATTEMPT TO CHANGE THE DATA MEMBERS OF OBJECT WILL GENERATE A COMPILE TIME ERROR
// ALSO A CONSTANT OBJECT CAN ONLY CALL THE CONSTANT MEMBER FUNCTION

#include <iostream>
using namespace std;

class Point {
    int x, y;
public:
    Point(int a, int b) : x(a), y(b) {}

    int getX() const {           // const member function
        // x = 5;                // ❌ ERROR: cannot modify member in const function
        return x;
    }

    void move(int dx, int dy) {   // non-const member function
        x += dx;
        y += dy;
    }

    void print() const;
};

void Point::print() const {          // also const
    cout << "(" << x << ", " << y << ")\n";
}

int main() {
    const Point p1(3,4);   // p1 is a const object
    Point p2(1,2);         // non-const object

    cout << p1.getX() << "\n";   // ✅ OK, getX is const
    // p1.move(1,1);            // ❌ ERROR: cannot call non-const function on const object

    p2.move(2,3);                // ✅ OK
    p2.print();                  // ✅ OK, print is const
}
