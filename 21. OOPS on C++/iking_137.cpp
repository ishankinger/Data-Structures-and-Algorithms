// OVERLOADING UNARY OPERATOR

// op x  or x op  --> FOR MEMEBER FUNCTION   x.operator op()
//                --> FOR FRIEND FUNCTION    operator op(x)

// OPERATOR FUNCTIONS WHEN MEMBER FUNCTIONS BEHAVE EXACTLY AS WHAT MEMBER FUNCTION DOES
// SO IF DEFINE PRIVATE THEN CAN'T BE CALLED IN MAIN FUNCTION

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
    space operator-();
    // friend void operator-(space &s);
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
// HERE WE ARE NOT UPDATING THE OBJECT INSTEAD SENDING A NEW OBJECT WITH UPDATED VALUES
space space :: operator-(){
    return space(-x, -y, -z);
}

// FRIEND FUNCTION USED AS OPERATOR FUNCTION
// HERE ARGUMENT TO BE PASSED BY REFERENCE AND WILL NOT WORK IF PASSED BY VALUE
// IF WE PASS BY VALUE THEN COPY OF OBJECT WILL BE PASSED AND CHANGE WILL NOT BE REFLECTED IN THE CALLED OBJECT
// void operator-(space &s){
//     s.x = -s.x;
//     s.y = -s.y;
//     s.z = -s.z;
// }

int main(){
    space s;
    s.getdata(10,-20,30);
    s.display();

    -s;
    s.display();
    
    // STATEMENTS LIKE THIS WILL ONLY WORK WHEN OUR OPERATOR IS RETURNING SOME VALUE
    // WHEN USING RETURNING OPERATOR FUNCTION THE ABOVE -S WILL NOT AFFECT THE DATA OF THE REAL OBJECT
    space p = -s;
    s.display();
    p.display();
}