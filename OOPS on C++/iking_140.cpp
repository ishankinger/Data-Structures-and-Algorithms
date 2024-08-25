// RULES FOR OVERLOADING OPERATOR

// >> ONLY EXISTING OPERATORS CAN BE OVERLOADED, NO NEW OPERATORS CANNOT BE CREATED
// >> OVERLOADED OPERATOR MUST HAVE ATLEAST ONE OPERAND THAT IS USER DEFINED TYPE
// >> OVERLOADED OPERATOR FOLLOW THE SYNTAX RULE OF ORIGINAL OPERATORS AND CANNOT BE OVERRIDEN
// >> SOME OPERATORS CANNOT BE OVERLOADED -> . , .* , :: , ?: , sizeof()
// >> SOME OPERATORS CANNOT BE USED BY FRIEND FUNCTION -> = , () , [] , ->
// >> UNARY OPERATORS FOR MEMBER FUNCTION TAKE NOT ARGUMENT WHILE TAKE ONE ARGUMENT FOR FRIEND FUNCTION
// >> BINARY OPERATORS OVERLOADED THROUGH A MEMBER FUNCTION TAKE ONE EXPLICIT ARGUMENT WHILE TAKE TWO ARGUMENTS FOR FRIEND FUNCTION
// >> WHEN USING BINARY OPERATOR OVERLOADED THROUGH A MEMBER FUNCTION, THE LEFT HAND OPERAND MUST BE AN OBJECT OF RELAVANT CLASS
// >> BINARY ARITHMETIC OPERATORS +, -, * AND / MUST EXPLICITLY RETURN A VALUE AND MUST NOT ATTEMPT TO CHANGE THEIR OWN ARGUMENT

#include<iostream>
#include<conio.h>
using namespace std;

// USING THE SUBSCRIPT OPERATOR TO ACCESS THE PRIVATE ARRAY ELEMENTS 
class arr{
    int a[5];
    public:
        arr(int *a){
            for(int i = 0; i < 5; i++) a[i] = a[i];
        }
        int operator[](int k){
            return (a[k]);
        }
};

// OVERLOADING POINTER TO MEMBER(->) OPERATOR
class test{
    public:
        int num;
        test(int j){
            num = j;
        }
        test* operator ->(void){
            return this;
        }
};

int main(){
    int x[5] = {1,2,3,4,5};
    arr A(x);
    int i;
    for(int i = 0; i < 5; i++){
        cout << x[i] << " ";
    }  
    cout << "\n";

    test T = test(5);
    test *ptr = &T;

    cout << T.num << "\n";          // accessing num normally
    cout << ptr->num << "\n";       // accesssing num using normal object pointer
    cout << T->num << "\n";         // accessing num using overloaded -> operator
    
    return 0;
}