// TYPES OF POINTERS :-

// >> NULL POINTER
// >> WILD POINTER
// >> DANGLING POINTER
// >> VOID POINTER

// WILD POINTER
// POINTER WHICH IS DECALARED BUT NOT DEFINED DUE TO WHICH IT ENDS UP POINTING INTO RANDOM MEMORY LOCATION
// DUE TO WHICH WE MIGHT GET SOME UNDEFINED BEHAVIOUR
// IN SOME CASES WE GET SEGMENTED FAULT( MEMORY FAULT )

// NULL POINTER
// IF WE WANT TO  HAVE A POINTER VARIABLE WHICH IS JUST DECALARED BUT WILL GET ADDRESS LATER TO STORE

// DANGLING POINTER
// IT IS A TYPE OF POINTER THAT POINTS TO A MEMORY LOCATION THAT IS NOT VALID
// IT CAN BE VALID INITIALLY

// VOID POINTER
// THESE ARE SPECIAL POINTER THAT CAN POINT TO ANY DATATYPE VALUE

#include<iostream>
using namespace std;

int main(){
    int x;                     // INITIALLY THERE IS SOME GARBAGE VALUE
    x=10;                      // THEN REPLACED BY 10

    int *ptr;                  // DECALARED NOT DEFINED YET SO SIMILARLY THIS POINTER WILL ALSO HAVE SOME RANDOM VALUE
    cout<<ptr<<endl;
    cout<<*ptr<<endl;                           // THIS TYPE OF POINTER IS CALLED WILD POINTER 
   
    int *ptr1=NULL;
    int *ptr2=NULL;
    int *ptr3=0;                 // 0 CAN BE USED AS NULL IT IS RESERVED IN THE PROGRAMME
    int *ptr4='\0';              // SIMILARY '\0' IS ALSO SIMILAR TO NULL
    cout<<ptr1<<endl;            // ALL OF THEM WILL HAVE SAME ADDRESS 
    cout<<ptr2<<endl;            // ALL NULL POINTER WILL HAVE SAME ADDRESS
    cout<<ptr3<<endl;
    cout<<ptr4<<endl;
    cout<<*ptr1<<endl;        // NO TO DEREFERENCE NULL POINTER
    cout<<*ptr2<<endl;

    int *pt=NULL;
    {
        int x=10;
        pt =&x;
    }
    cout<<pt<<endl;
    cout<<*pt<<endl;
    float f=10.2;
    int x=10;
    void *ptr=&f;
    ptr=&x;
    cout<<*ptr<<endl;               // VOID POITERS CANNOT BE DEREFRENCED
    
    int *intPoint=(int *)ptr;
    cout<<*intPoint<<endl;
    return 0;
    }