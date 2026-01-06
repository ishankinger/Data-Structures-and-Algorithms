// ++ AND -- DEFFERENT MEANING FOR POINTERS

#include<iostream>
using namespace std;

 int main(){
    int a=5;                       // RECALLING EXAMPLE OF POST AND PRE INCREMENTS AND DECREMENTS IN INT ARITHEMETIC
    cout<<a++<<endl;
    cout<<a<<endl;
    int b=19;
    cout<<++b<<endl;
    cout<<b<<endl;

    int arr[2]={1,2};
    int *ptr= &arr[0];
    int *ptr1=&arr[1];

    cout<<ptr<<endl;                // THERE IS A DIFFERENCE BETWEEN PTR++ AND PTR=PTR+1
    cout<<ptr++<<endl;              // PTR++ MEANS THAT WE WILL FIRST PRINT PTR VALUE AND THEN INCREMENT IT AND NOW ADDRESS OF PTR IS CHANGED
    cout<<ptr<<endl;                // SO HERE WE WILL GET NEXT MEMORY STACK
    cout<<*ptr<<endl;               // AS ARRAY IS CONTIGUOUS MEMORY SET NEXT OF PTR WILL BE SECOND ELEMENT WHICH WILL GET PRINTED

    ptr--;                          // NOW USING DECREMENT OPERATOR GETTING BACK THE PTR TO ORIGINAL FIRST POSITION

    cout<<ptr+1<<endl;              // NOW THIS THING JUST MEANS A SIMPLE ADDITION NO SHIFTING OF POINTER WILL OCCUR 
    cout<<ptr<<endl;                // POINTER WILL BE PRESENT AT IT'S OWN ORIGINAL ADDRESS
    cout<<*ptr<<endl;               // SO HERE FIRST ELEMENT WILL BE PRINTED

    cout<<*ptr++<<endl;             // THIS MEANS THAT FIRST WE WILL RETURN THE INITIALLY VALUE OF THE POINTER AND THEN INCREMENT IT                    
    cout<<arr[0]<<endl;             // BUT THIS POINTER GAME WILL HAVE NO EFFECT ON THE ELEMENTS OF THE ARRAY
    cout<<arr[1]<<endl;             // ELEMENTS OF THE ARRAY WILL BE SAME
    cout<<ptr<<endl;                // IF NOW WE PRINT THE PTR THEN IT WILL BE POINTING TOWARDS SECOND ELEMENT OF THE ARRAY
    cout<<*ptr<<endl;               // SO SECOND ELEMENT ADDRESS AND VALUE WILL BE PRINTED NOW

    *ptr--;                         // DECREMENT PTR TO GET IT TO IT'S ORIGINAL POSITION
    cout<<ptr<<endl;                // ANY THING CAN BE WRITTEN DURING DECREMENT OF PTR IT CAN BE PTR-- OR *PTR--

    cout<<*++ptr<<endl;             // SO HERE WE CAN APPLY SIMILAR CONCEPT OF POST AND PRE FIX INCREMENT IN ARITHEMETIC OPERATOR
    cout<<arr[0]<<endl;             // SO HERE PTR WILL INCREMENT AND DEREFERENCE TO PRINT THE VALUE
    cout<<arr[1]<<endl;
    cout<<ptr<<endl;
    cout<<*ptr<<endl;

    *ptr--;
    cout<<ptr<<endl;

    cout<<(*ptr)++<<endl;           // IN THIS FIRST PRINTING OF ELEMENT AT PTR POSITION WILL OCCUR AND THEN INCREMENT WILL OCCUR OF THE ELEMENT
    cout<<arr[0]<<endl;             // SO NOW THIS ELEMENT WHICH IS AT PTR IS INCREMENTED SO PRINTED BY +1
    cout<<arr[1]<<endl;             // AND THIS IS UNCHANGED
    cout<<ptr<<endl;                // HERE ONLY CHANGE THAT WILL OCCUR IS WITH INSIDE ELEMENTS OF THE ARRAY
    cout<<*ptr<<endl;               // NOTHING CHANGE WILL OCCUR IN PTR ADDRESS

    (*ptr)--;                       // IN THIS TO MAKE ORIGINAL CONDITION OF THE ARRAY AGAIN WE HAVE TO MAKE DECREMENT OF THE VALUE OF ELEMENT
    cout<<*ptr<<endl;               // PTR POSITION DECREASE BY 1 AND NOTHING TO BE DONE WITH PTR AS IT IS UNAFFECTED

    cout<<++(*ptr)<<endl;           // THE OUTPUT OF THIS ONE CAN BE EASILY ANALYSED NOW
    cout<<arr[0]<<endl;
    cout<<arr[1]<<endl;
    cout<<ptr<<endl;
    cout<<*ptr<<endl;

    (*ptr)--;
    cout<<*ptr<<endl;

    cout<<++*ptr<<endl;                // FIRST WE DO DEREFERENCING THEN INCREMENT OF THE DEREFERENCED VALUE
    cout<<arr[0]<<endl;
    cout<<arr[1]<<endl;
    cout<<ptr<<endl;
    cout<<*ptr<<endl;
    
    return 0;
}