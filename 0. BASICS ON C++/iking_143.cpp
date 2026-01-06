// POINTERS AS A SPECIAL DATATYPES

#include<iostream>
using namespace std;

int main(){

    int *ptr;                     // ONLY DECLARATION IS DONE
    cout<<ptr<<endl;              // ANY MEMORY IS LOCATED BY IT INITIALLY

    int marks=90;                 // A VARIABLE IS MADE
    ptr= &marks;                  // WHEN WE ARE USING IT AGAIN AFTER DECLARATION THEN WE DON'T NEED TO PUT STAR AGAIN ABOVE 
    
    cout<<ptr<<endl;              // SO SIMILAR TO OTHER VARIABLES AS WE RE ASSIGN THEIR VALUES HERE ALSO WE CAN RE ASSIGN THEIR VALUES LIKE THIS
    return 0;                     // SO FIRST DECALARE AND THEN IMPLEMENTED
}