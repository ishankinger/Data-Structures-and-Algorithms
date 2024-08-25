// OVERLOADING BINARY OPERATORS USING FRIENDS

// IN MOST OF THE CASES WE WILL GET THE SAME RESULT BY THE USE OF EITHER FRIEND FUNCTION OR A MEMBER FUNCTION
// BUT THERE CAN BE CERTAIN SITUATIONS WHERE WE WOULD LIKE TO USE FRIEND FUNCTION RATHER THAN THE MEMBER FUNCTION
// CONSIDER --> A = B + 2 , THIS WILL WORK FOR A MEMBER FUNCTION BUT A = 2 + B, WILL NOT WORK FOR A MEMBER FUNCTION
// THIS IS BECAUSE THE LEFT HAND OPERAND WHICH IS RESPONSIBLE FOR INVOKING THE MEMBER FUNCTION SHOULD BE AN OBJECT OF THE SAME CLASS
// HOWEVER FRIEND FUNCTION ALLOWS BOTH APPROACHEDS AS IN FRIEND FUNCTION WE NEED NOT TO INVOKE THE OBJECT WHILE WE PASS IT AS ARGUMENT
// SO WE WILL MAKE TWO DIFFERENT FRIEND FUNCTION WITH DIFFERENT ORDER OF ARGUMENTS PASSING IN IT

#include<iostream>
using namespace std;

const int size = 3;

class vector{
    int v[size];
    public:
        vector();
        vector(int *x);
        friend vector operator*(int a, vector b);
        friend vector operator*(vector b, int a);
        friend istream &operator >> (istream &, vector &);
        friend ostream &operator << (ostream &, vector &);
};

// CONSTRUCTOR 1
vector :: vector(){
    for(int i = 0; i < size; i++){
        v[i] = 0;
    }
}

// CONSTRUCTOR 2
vector :: vector(int *x){
    for(int i = 0; i < size; i++){
        v[i] = x[i];
    }
}

// OPERATOR FUNCTION TO MULTIPLY THE CONSTANT ELEMENT WISE
vector operator *(int a, vector b){
    vector c;
    for(int i = 0; i < size; i++){
        c.v[i] = a * b.v[i];
    }
    return c;
}

// OPERATOR FUNCTION WITH DIFFERENT ORDER ARGUMENT
vector operator *(vector b, int a){
    vector c;
    for(int i = 0; i < size; i++){
        c.v[i] = b.v[i] * a;
    }
    return c;
}

// OPERATOR FUNCTION FOR TAKING INPUT OF VECTOR
istream &operator >>(istream &din, vector &b){
    for(int i = 0; i < size; i++){
        din >> b.v[i];
    }
    return din;
}

// OPERATOR FUNCTION FOR PRINTING THE OUTPUT OF VECTOR
ostream &operator <<(ostream &dout, vector &b){
    dout << "(" << b.v[0];
    for(int i = 1; i < size; i++){
        dout << ", " << b.v[i];
    }
    dout << ")";
    return dout;
}

int x[size] = {2,4,6};

int main(){
    vector m;                                // invokes constructor 1
    vector n(x);                             // invokes constructor 2

    // vector n = x  -> implicit call can define like this also

    cout << "Enter the elements of vector m " << "\n";
    cin >> m;                                // invokes operator function >>
    cout << "\n";
    cout << "m = " << m << "\n";             // invokes operator function <<

    vector p, q;
    p = 2 * m;                               // invokes friend 1
    q = n * 2;                               // invokes friend 2

    cout << "\n";
    cout << "p = " << p << "\n";             // invokes operator function <<
    cout << "q = " << q << "\n";             // invokes operator function <<
}