// OPERATOR OVERLOADING

// THE MECHANISM OF GIVING SOME SPECIAL MEANINGS TO AN OPERATOR IS CALLED OPERATOR OVERLOADING
// WE CAN OVERLOAD ALL THE C++ OPERATORS EXCEPT- . , .* , :: , sizeof, ?:
// OPERATOR OVERLOADING CANNOT CHANGE THE SYNTAX AND GRAMMATICAL RULES THAT GOVERNS IT'S USE SUCH AS NUMBER OF OPERANDS, PRECEDENCE AND ASSOSCIAVITY
// ALSO WHEN AN OPERATOR IS OVERLOADED IT'S ORIGINAL MEANING IS NOT LOST

// OPERATOR FUNCTIONN

// TO DEFINE AN ADDITIONAL TASK TO AN OPERATOR, WE USE OPERATOR FUNCTION
// OPERATOR FUNCTION MUST BE EITHER MEMBER FUNCTION OR FRIEND FUNCTIONS
// BASIC DIFFERENCE IS THAT FRIEND FUNCTION WILL HAVE ONE ARGUMENT FOR UNARY OPERATOR AND TWO ARGUMENTS FOR BINARY OPERATORS
// WHILE MEMBER FUNCTION WILL HAVE NO ARGUMENT FOR UNARY OPERATOR AND SINGLE ARGUMENT FOR BINARY OPERATORS
// THIS IS SO BECAUSE THE OBJECT USED IN INVOKING THE MEMBER FUNCTION IS PASSED IMPLICITLY AND THEREFORE IS AVAILABLE FOR THE MEMBER FUNCTION
// WHILE THAT IS NOT THE CASE FOR FRIEND FUNCTION

// OVERLOADING UNARY OPERATOR

// op x  or x op  --> FOR MEMEBER FUNCTION   x.operator op()
//                --> FOR FRIEND FUNCTION    operator op(x)

#include<iostream>
using namespace std;

class space{
    int x, y, z;
    public:
        space(){}
        space(int a, int b, int c);
        void getdata(int a, int b, int c);
        void display();
        // void operator-();
        // space operator-();
        friend void operator-(space &s);
};

space :: space(int a, int b, int c){
    x = a;
    y = b;
    z = c;
}

void space :: getdata(int a, int b, int c){
    x = a;
    y = b;
    z = c;
}

void space :: display(){
    cout << x << " " << y << " " << z << "\n";
}

// OPERATOR FUNCTION JUST UPDATING THE OBJECT
// void space :: operator-(){
//     x = -x;
//     y = -y;
//     z = -z;
// }

// OPERATOR FUNCTION RETURNING THE NEW UPDATED OBJECT
// space space :: operator-(){
//     x = -x;
//     y = -y;
//     z = -z;
//     return space(x,y,z);
// }

// FRIEND FUNCTION USED AS OPERATOR FUNCTION
// HERE ARGUMENT TO BE PASSED BY REFERENCE AND WILL NOT WORK IF PASSED BY VALUE
// IF WE PASS BY VALUE THEN COPY OF OBJECT WILL BE PASSED AND CHANGE WILL NOT BE REFLECTED IN THE CALLED OBJECT
void operator-(space &s){
    s.x = -s.x;
    s.y = -s.y;
    s.z = -s.z;
}

int main(){
    space s;
    s.getdata(10,-20,30);
    s.display();

    -s;
    s.display();
    
    // space p = -s;
    // s.display();
}