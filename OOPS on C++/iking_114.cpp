// PARAMETERISED AND DEFAULT CONSTRUCTORS IN C++

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
    int a,b;
    public:
    Complex2(int x,int y){                                           // PARAMETERISED CONSTRUCTORS WE ARE GIVING SOME ARGUMENTS IN THE CONSTRUCTOR
        a=x;                                                         // THEY ARE VARIABLES OF DATATYPES IN THE BRACKETS
        b=y;
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
    c.printNumber();                                                    // OTHER WAY OF USING THE VALUE CONSTRUCTOR
    
    return 0;

}