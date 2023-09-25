// POINTERS TO OBJECTS AND ARROW OPERATORS
// SYNTAX TO DEFINE A POINTER
// {DATATYPE}_{NAME OF POINTER}= new {DATATYPE};
// HERE DATATYPE CAN BE INT, FLOAT..... OR OUR CLASS NAME AS WE ARE MAKING CLASS TO MAKE DATATYPES

#include<iostream>
using namespace std;

class complex{                                                            // SIMPLE CLASS TO GET A COMPLEX NUMBER
    int real,img;
    public:
        void setData(int a,int b){
            real=a;
            img=b;
        }
        void getData(void){
            cout<<"The complex number is "<<real<<" + i"<<img<<endl;
        }
};

int main(){
    complex c1;
    complex *ptr = &c1;                   // DEFINING A POINTER TO C1 OBJECT AS C1 OBJECT IS ALSO A VARIABLE SO IT WILL ALSO BE STORED IN SOME
                                          // MEMORY SPACE WHICH WE CAN GET FROM POINTER DATATYPE
    complex *ptr1= new complex;           // JUST USING *PTR AS WE USE WITH INT FLOAT HERE WE ARE USING COMPLEX DATATYPE WHICH IS MADE BY US
    complex *ptr2= new complex;           // THIS TYPE OF WAY WE HAVE ALREADY SEEN IN INT ARRAY 
    
    c1.setData(1,2);
    c1.getData();

    (*ptr).setData(1,2);                  // SO HERE ALSO  (C1 === *PTR)
    (*ptr).getData();                     // SAFE TO USE () IN DEREFERENCING THERE DUE TO DOT
    
    (*ptr1).setData(1,2);                 // (*PTR1) CAN BE TAKEN AS AN OBJECT OF A COMPLEX CLASS
    (*ptr1).getData();

    ptr2->setData(1,2);                   // ARROW OPERATOR
    ptr->getData();                       // SAME FUNCTION AS THAT OF USING DOT TO RUN A FUNCTION JUST WE ARE USING AN ARROW HERE NOTHING ELSE
    return 0;                             // HERE WE DONOT HAVE TO USE STAR INSTEAD WE ARE USING ONLY NAME OF THE POINTER
}                                         // THIS MAKES ARROW OPERATOR DIFFERENT FROM DOT
// FOR USING VARIABLES AND FUNCTIONS FOR A POINTER OBJECT 
// TWO SYNTAX >>> (*PTR).VAR/FUNC();
//            >>> PTR->VAR/FUNC();