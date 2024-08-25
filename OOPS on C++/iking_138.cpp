// OVERLOADING BINARY OPERATOR

// AS A RULE IN OVERLOADING OF A BINARY OPERATOR (FOR MEMBER FUNCTIONS) , THE LEFT HAND OPERATOR IS USED TO INVOKE TEH OPERAND FUNCTION 
// AND THE RIGHT HAND OPERAND IS PASSED AS AN ARGUMENT
// x op y ---> FOR MEMBER FUNCTION   x.operator op(y)
//        ---> FOR FRIEND FUNCTION   opeator op(x,y)

#include<iostream>
using namespace std;

class complex{
    float x, y;
    public:
        complex(){};
        complex(float real, float img){
            x = real;
            y = img;
        }
        complex operator+(complex);
        // friend complex operator+(complex, complex);
        void display();
};

complex complex :: operator+(complex c){
    complex temp;
    temp.x = x + c.x;
    temp.y = y + c.y;
    return temp;
}

// complex operator+(complex a, complex b){
//     return complex((a.x + b.x),(a.y + b.y));
// }

void complex :: display(){
    cout << x << " + j" << y << "\n";
}

int main(){

    complex c1, c2, c3;
    c1 = complex(2.5,3.5);
    c2 = complex(1.6,2.7);
    
    c3 = c1 + c2;

    c1.display();
    c2.display();
    c3.display();
}