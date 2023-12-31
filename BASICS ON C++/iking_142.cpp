// SYNTAX OF THE POINTERS
// ACTUALLY THE ADDRESS IS NOT AN INT OR ANY OTHER BASIC DATATYPES SO WE NEED ANOTHER DATATYPES WHICH CAN ACCESS THESE TYPES OF NUMBERS
// AND THIS DONE WITH THE HELP OF POINTERS BY JUST USING SAME DATATYPES OF THE VARIABLE WHOSE ADDRESS TO BE STORED AND THEN USING * BEFORE NAME

#include<iostream>
using namespace std;

int main(){

    int x=10;
    float y=5.56;

    int *ptr1 = &x;              // STORES ADDRESS OF INT X
    float *ptr2 = &y;            // STORES ADDRESS OF FLOAT Y
    
    cout<<&x<<endl;              // THIS WILL GIVE ADDRESS OF THE INT X
    cout<<&y<<endl;              // SIMILAR FOR Y

    cout<<ptr1<<endl;            // STORES ADDRESS OF X SO IT WILL BE PRINTED
    cout<<ptr2<<endl;            // SIMILAR FOR Y

    cout<<&ptr1<<endl;           // POINTERS ARE ALSO STORED IN THE MEMORY SO THEY ALSO HAVE MEMORY VALUE
    cout<<&ptr2<<endl;           // SIMILARLY FOR THE SECOND POINTER

}
// TO DEFINE A POINTER WE HAVE TO USE * IN ABOVE OF IT'S NAME AFTER THAT IF WE WANT TO GET IT'S VALUE WE WILL BE USING IT'S NAME DIRECTLY