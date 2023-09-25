// CALL BY REFERENCE USING POINTERS
// POINTERS ARE POINTING TO THE ADDRESS OF THE ELEMENTS SO SIMILAR TO AMPERSANT THEY CAN ALSO BE USED IN CALL BY REFERENCE TYPE FUNCTIONS

#include<iostream>
using namespace std;

void swapm(int x, int y){                            // SIMPLE CODE TO SWAP TWO NUMBERS PASSED IN THS FUNCTION
    int c;                                           // BUT AFTER CALLING THIS FUNCTION THIS WILL NOT BE ABLE TO SWAP THE VALUES OF X AND Y
    c=x;                                             // THIS IS DUE TO 'PASS BY VALUE' PRINCIPLE  
    x=y;                                             // THIS MEANS THAT THE METHODS AND OPERAIONS ACTING ON X AND Y ARE DIFFERENT FROM THE X AND Y
    y=c;                                             // WE PASSED IN THE FUNCTION SO THEY ARE OTHER NEW VARIBLE NOTHING WILL HAPPEN TO OUR ORIGINAL
}                                                    
void swapMod(int &x,int &y){                         // THIS ALSO SWAP TWO NUMBERS BUT NOW AMPERSANT OPERATOR IS USED Here                                        
    int c=x;                                         // NOW ALL THE CODE IS SAME BUT THE THING IS THAT NOW X AND Y PASSED IN THE FUNCTION ARE
    x=y;                                             // SAME VARIABLE ON WHICH THIS FUNCTION IS WORKING SO NOW SWAPPING WILL OCCUR
    y=c;
}
void swapByPtr(int *x,int *y){                       // FUNCTION TO SWAP TWO NUMBERS USING A POINTER IN THIS INPUT IS TAKEN A POINTER
    int c=*x;                                        // *X WILL GIVE THE VALUE OF INT STORE IN THAT ADDRESS
    *x=*y;                                           // SO SAME CODE AND SWAPING WILL OCCUR
    *y=c;
}
int main(){
    int x=10;
    int y=20;

    swapm(x,y);

    cout<<"the value of x is "<<x<<endl;
    cout<<"the value of y is "<<y<<endl;

    swapMod(x,y);
    
    cout<<"the value of x is "<<x<<endl;
    cout<<"the value of y is "<<y<<endl;

    int *ptr1=&x;                                         // MAKING TWO POINTERS WHICH STORES THE ADDRESS OF X AND Y
    int *ptr2=&y;

    swapByPtr(ptr1,ptr2);                                 // SO WE ARE PASSING ADDRESS OF X AND Y IN THE FUNCTION 
    
    cout<<"the value of x is "<<x<<endl;
    cout<<"the value of y is "<<y<<endl;

    
    return 0;
}