// POINTERS TO THE MEMBERS

#include<iostream>
using namespace std;

class M{
    int x;
    int y;
    public:
    void set_xy(int a, int b){
        x = a;
        y = b;
    }
    friend int sum(M m);
};

int sum(M m){

    int M :: *px = &M :: x;
    int M :: *py = &M :: y;

    M *pm = &m;

    int S = m.*px + pm ->*py;
    return S;
}

int main(){
    M n;
    void (M :: *pf)(int,int) = &M :: set_xy;
    (n.*pf)(10,20);
}

// CONSTANT MEMBER FUNCTIONS
// IF A MEMBER FUNCTION DOESNOT ALTER ANY DATA IN THE CLASS THEN WE MAY DECLARE IT AS A const MEMBER FUNCTION
// THE COMPILER WILL GENERATE AN ERROR MESSAGE IF SUCH FUNCTIONS TRY TO ALTER THE DATA VALUE

// CONSTANT OBJECTS
// WE MAY CREATE AN OBJECT CONSTANT BY USING THE const KEYWORD BEFORE OBJECT DECLARATION
// ANY ATTEMPT TO CHANGE THE DATA MEMBERS OF OBJECT WILL GENERATE A COMPILE TIME ERROR
// ALSO A CONSTANT OBJECT CAN ONLY CALL THE CONSTANT MEMBER FUNCTION

// LOCAL CLASSES
