// DESTRUCTORS IN C++
// >> NEVER TAKES AN ARGUMENT AND NOT RETURN ANY VALUE
// >> DEALLOCATE THE MEMORY
// >> COMPILER AUTOMATICALLY MAKE DETRUCTOR
// >> DEALLOCATE ONLY STATICALLY ALLOCATED MEMORY

// TO DEALLOCATE DYNAMICALLY ALLOCATED MEMORY WE HAVE TO USE DELETE KEYWORD
// DELETE KEYWORD DELETE THE MEMORY IN THE HEAP,IT IS IMPORTANT TO FREE THE HEAP MEMORY USING DELETE KEYWORD 
// BECAUSE WHEN POINTERS TO OBJECTS GO OUT OF THE SCOPE A DESTRUCTOR IS NOT CALLED IMPLICITY
#include<iostream>
using namespace std;

class num{
    static int count;
    public:

    num(){
        count++;
        cout<<"This is the time when constructor is called for object number "<<count<<endl;
    }

    ~num(){
        cout<<"This is the time when my destructor is called to check number "<<count<<endl;
        count--;
    }
};

int num :: count;

int main(){
    cout<<"We are inside our main function "<<endl;
    cout<<"Creating firstobject n1 "<<endl;
    num n1;
     {                                                        // BLOCK 
        cout<<"Entering this block"<<endl;                    // AS NUM N2 AND N3 ARE MADE SO CONSTRUCTOR WILL INVOKED
        cout<<"Creating two more objects"<<endl;              // WHILE EXITING THE BLOCK DESTRUCTOR WILL BE CALLED FOR N2 AND N3
        num n2;                                               // AS THERE IS NO NEED OF N2 AND N3 AFTER THE BLOCK IN MAIN CODE SO 
        num n3;                                               // DESTRUCTOR WILL WORK AND WILL BE INVOKED FOR N2 AND N3
        cout<<"Exiting this block"<<endl;                     // ONE MORE THING TO NOTICE IS THAT FIRST N3 DESTRUCTOR WILL BE CALLED AND THEN FOR N2
     }
    cout<<"Back to main"<<endl;

    return 0;
}

// IF WE NOT USE THE BLOCK THEN FIRST BACK TO MAIN WILL BE PRINTED THEN DESTRUCTORS OF ALL THREE WILL BE CALLED 
// WHILE USING BLOCK THEN FIRST DESTRUCTORS WILL ACT FOR N2 AND N3 THEN BACK TO MAIN AND THEN DESTRUCTOR FOR N1