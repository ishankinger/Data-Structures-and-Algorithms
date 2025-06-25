// PASSING OBJECTS IN FUNCTIONS
// LIKE ANY OTHER DATATYPE AN OBJECT MAY BE USED AS FUNCTION ARGUMENT
// THIS CAN BE DONE - PASS BY VALUE (MAKING A COPY OF THE OBJECT IN THE MEMORY) - NO CHANGE WILL OCCUR IN ORIGINAL OBJECT
//                  - PASS BY REFERENCE (PASSING THE ADDRESS OF THE OBJECT) - ALL CHANGES WILL AFFECT ORIGINAL OBJECT 

#include<iostream>
using namespace std;

class complex{                                                    // A CLASS RELATED TO COMPLEX FUNCTIONS
    int a;                                                        // TAKE 'a' AS REAL PART OF THE COMPLEX NUMBER
    int b;                                                        // TAKE 'b' AS COMPLEX PART OF THE COMPLEX NUMBER
    public:                                                       // NOW SOME PUBLIC THINGS
    int c;                                                     
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

// AN OBJECT CAN ALSO BE PASSED AS AN ARGUMENT TO A NON-MEMBER FUNCTION, HOWEVER FUNCTONS CAN HAVE ONLY ACCESS TO PUBLIC DATA MEMBERS
// AND PUBLIC MEMBER FUNCTIONS ONLY THROUGH THE OBJECTS PASSED AS AN ARGUMENT TO IT
void check(complex obj1){
    cout <<" HELLO\n";
    // printNumber();                     // CAN'T USE NESTING OF FUNCTION IN NON-MEMBER FUNCTION
    obj1.printNumber();
    // obj1.a                             // CAN'T ACCESSS PRIVATE MEMEBER IN A NON-MEMBER FUNCTION
    obj1.c;
}

// A FUNCTION CANNOT ONLY RECEIVE OBJECTS AS ARGUMENTS BUT ALSO CAN RETURN THEM

int main(){
    complex c1,c2,c3;                                              // THREE OBJECTS OF COMPLEX FUNCTIONS ARE MADE
    
    c1.setData(1,2);                                               // VALUE OF FIRST OBJECT IS ASSIGNED
    c1.printNumber();                                              // PRINTING OF FIRST NUMBER

    c2.setData(3,4);                                               // VALUE OF SECOND OBJECT IS ASSIGNED
    c2.printNumber();                                              // PRINTING OF SECOND NUMBER

    c3.setDataBySum(c1,c2);                                        // NOW USING ONE FUNCTION WHICH CONTAIN TWO COMPLEX CLASS OBJECTS
    c3.printNumber();                                              // AND IT WILL PRINT THE SUM OF BOTH THE COMPLEX NUMBERS

    check(c1);
}
// SO WE DEFINE THIRD LIKE THIS SO THAT AFTER WE PASS OBJECTS IN IT IT WILL GET VALID
