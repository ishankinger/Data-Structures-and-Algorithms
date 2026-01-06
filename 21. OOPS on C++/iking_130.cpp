// POINTERS TO OBJECTS AND ARROW OPERATORS
// SYNTAX TO DEFINE A POINTER
// {DATATYPE}_{NAME OF POINTER}= new {DATATYPE};
// HERE DATATYPE CAN BE INT, FLOAT..... OR OUR CLASS NAME AS WE ARE MAKING CLASS TO MAKE DATATYPES

#include<iostream>
using namespace std;

class complex{                                                            // SIMPLE CLASS TO GET A COMPLEX NUMBER
    int real,img;
    public:
        complex(){
            cout << "Constructor called\n";
        }
        ~complex(){
            cout << "Destructor Called\n";
        }
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
    complex *ptrc1 = &c1;                   // DEFINING A POINTER TO C1 OBJECT AS C1 OBJECT IS ALSO A VARIABLE SO IT WILL ALSO BE STORED IN SOME
                                            // MEMORY SPACE WHICH WE CAN GET FROM POINTER DATATYPE
    c1.setData(1,2);                        // SO HERE ALSO  (C1 === *PTR)
    (*ptrc1).getData();                     // SAFE TO USE () IN DEREFERENCING THERE DUE TO DOT

    // HERE SIMPLE POINTER IS DEFIINED STORED IN STACK MEMORY SO AFTER CLOSING BRACKET DESTRUCTOR WILL BE CALLED IMPLICITLY
    complex *savePtrc1;
    {
        complex c2;
        complex *ptrc2 = &c2;

        savePtrc1 = ptrc2;

        c2.setData(3,4);
        (*ptrc2).getData();
    }
    // THIS VALUE MAY OR MAY NOT GIVE CORRECT DATA OUTPUT AS IT IS FREE MEMORY NOW AFTER DESTRUCTOR CALLED
    savePtrc1->getData();

    // HERE EVEN AFTER END OF THE BLOCK THE MEMORY IS NOT DELETED AS DESTRUCTOR IS NOT CALLED FOR HEAP MEMORY
    // SO SAVED PONTER CAN FURTHER BE USED TO SET AND GET DATA
    complex *savePtr1, *savePtr2;
    {
        complex *ptr1= new complex;           // JUST USING *PTR AS WE USE WITH INT FLOAT HERE WE ARE USING COMPLEX DATATYPE WHICH IS MADE BY US
        complex *ptr2= new complex;           // THIS TYPE OF WAY WE HAVE ALREADY SEEN IN INT ARRAY 

        savePtr1 = ptr1;
        savePtr2 = ptr2;

        (*ptr1).setData(1,2);                 // (*PTR1) CAN BE TAKEN AS AN OBJECT OF A COMPLEX CLASS
        (*ptr1).getData();

        ptr2->setData(1,2);                   // ARROW OPERATOR, HERE WE DONOT HAVE TO USE STAR INSTEAD WE ARE USING ONLY NAME OF THE POINTER
        ptr2->getData();                      // SAME FUNCTION AS THAT OF USING DOT TO RUN A FUNCTION JUST WE ARE USING AN ARROW HERE NOTHING ELSE
    }
    
    // STILL CAN USE THE SAVE POINTER IN THE HEAP MEMORY TO GET AND SET DATA AND WILL GIVE THE CORRECT OUTPUT
    savePtr2->getData();                      

    delete(savePtr1);                         // FOR DYNAMICALLY ALLOCATED MEMOERY WE HAVE TO EXPLICITLY WRITE DELETE KEYWORD TO CALL THE DESTRUCTOR
    delete savePtr2;                         // TO DELETE THEM FROM HEAP MEMORY WHILE FOR STACK MEMORY THEY GET AUTOMATICALLY DELETED
    
    return 0;                             
}                                         

// FOR USING VARIABLES AND FUNCTIONS FOR A POINTER OBJECT 
// TWO SYNTAX >>>   (*PTR).VAR/FUNC();
//            >>>    PTR->VAR/FUNC();