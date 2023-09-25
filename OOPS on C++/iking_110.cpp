// PASSING OBJECTS IN FUNCTIONS?????????????????????????

#include<iostream>
using namespace std;

class complex{                                                    // A CLASS RELATED TO COMPLEX FUNCTIONS
    int a;                                                        // TAKE 'a' AS REAL PART OF THE COMPLEX NUMBER
    int b;                                                        // TAKE 'b' AS COMPLEX PART OF THE COMPLEX NUMBER
    public:                                                       // NOW SOME PUBLIC THINGS
    void setData(int v1, int v2){                                 // FIRST OF ALL THIS FUNCTION WILL MAKE A AND B FROM PRIVATE TO PUBLIC
        a=v1;                                                     // SO THAT THEY CAN BE USED FURTHER
        b=v2;
    }
    // OBJECTS OF COMPLEX CLASS ARE PASSED IN THE FUNTION OF THE COMPLEX CLASS
    void setDataBySum(complex obj1, complex obj2){                // FUNCTION TO ADD A COMPLEX NUMBER
        a=obj1.a + obj2.a;                                        // VALUE OF A OF OBJECTS ARE ADDED
        b=obj1.b + obj2.b;                                        // SIMILARLY VALUES OF B ARE ADDED
    }
    void printNumber(void){                                       // FUNCTION TO PRINT THE COMPLEX NUMBER
        cout<<"Your complex number is "<<a<<"+i"<<b<<endl;
    }
};

int main(){
    complex c1,c2,c3;                                              // THREE OBJECTS OF COMPLEX FUNCTIONS ARE MADE
    
    c1.setData(1,2);                                               // VALUE OF FIRST OBJECT IS ASSIGNED
    c1.printNumber();                                              // PRINTING OF FIRST NUMBER

    c2.setData(3,4);                                               // VALUE OF SECOND OBJECT IS ASSIGNED
    c2.printNumber();                                              // PRINTING OF SECOND NUMBER

    c3.setDataBySum(c1,c2);                                        // NOW USING ONE FUNCTION WHICH CONTAIN TWO COMPLEX CLASS OBJECTS
    c3.printNumber();                                              // AND IT WILL PRINT THE SUM OF BOTH THE COMPLEX NUMBERS
}
// SO WE DEFINE THIRD LIKE THIS SO THAT AFTER WE PASS OBJECTS IN IT IT WILL GET VALID