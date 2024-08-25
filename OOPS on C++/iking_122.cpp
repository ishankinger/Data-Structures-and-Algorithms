// FORMS OF INHERITENCE

// >> SINGLE INHERITANCE == A DERIVED CLASS WITH ONLY ONE BASE CLASS         A---->B
// >> MULTILEVEL INHERITANCE == DERIVING A CLASS FROM ALREADY DERIVED CLASS      A--->B--->C...
// >> HIERARICHAL INHERITANCE == SEVERAL DERIVED CLASS FROM A SINGLE BASE CLASS      C ----> (A--->E--->F) AND (B----> C AND D)
// >> MULTIPLE INHERITANCE == A DERIVED CLASS WITH MORE THAN ONE BASE CLASS       A AND B... ----> C
// >> HYBRID INHERITANCE INHERITANCE == MIXTURE OF MULTIPLE INHERITANCE AND MULTILEVEL INHERITANCE     A--> B ---> D <--- C

// CLASS {{DERIVED CLASS NAME}} : {{VISIBILITY MODE}} {{BASE CLASS NAME}}

// DEFAULT VISIBILITY MODE IS PRIVATE VISIBILITY MODE
// PRIVATE VISIBILITY MODE--> PUBLIC MEMBER OF BASE CLASS BECOMES PRIVATE MEMBERS OF DERIVED CLASS
// PUBLIC VISIBILITY MODE--> PUBLIC MEMBER OF BASE CLASS BECOMES PUBLIC MEMBER OF DERIVED CLASS 
// PRIVATE MEMBERS OF BASE CLASS ARE NEVER INHERITED, THUS DONOT EXIST FOR THE DERIVED CLASS

#include<iostream>
using namespace std;

// BASE CLASS
class Base{
    int data1;                                           // PRIVATE DATATYPE
    public:
    int data2;                                           // PUBLIC DATATYPE
    Base(){

    }
    void setData();                                      // FUNCTION TO GIVE VALUE OF DATA1 AND DATA2
    int getData1();                                      // THIS IS USED TO GET DATA1 AS IT IS PRIVATE SO WE CANNOT USE IT DIRECTLY
};
void Base :: setData(void){
    data1=10;
    data2=20;
}
int Base :: getData1(void){
    return data1;
}

// PUBLIC DERIVED CLASS
class Derived : public Base{                               // ALL PUBLIC MEMBERS WILL GET INHERITED AS PUBLIC MEMBERS
    int data3;                                             // SO DATA2 WILL GET INHERITED AND DATA1 NOT
    public:
    void process();
    void display();
};
void Derived :: process(){
    data3= data2*getData1();                               // DATA2 WILL NOW BE A PART OF THIS CLASS CAN BE USED IN IT'S FUNCTION
}
void Derived :: display(){
    cout<<"The value of data 1 is "<< getData1()<<endl;    // DATA1 IS A PRIVATE VARIABLE SO WE ARE USING A FUNCTION TO GET IT'S VALUE
    cout<<"The value of data 2 is "<< data2<<endl;         // DATA2 AND DATA3 WILL BE DIRECTLY USED
    cout<<"The value of data 3 is "<< data3<<endl;
} 

// PRIVATE DERIVED CLASS
class Derived2 : Base{                                     // DEFAULT IS PRIVATE VISIBILITY MODIFIER
    int data3;
    public:
    void process();
    void display();
};

void Derived2 :: process(){
    setData();
    data3 = data2*getData1();
}
void Derived2 :: display(){
    cout << "The value of data 1 is "<< getData1()<<endl;
    cout << "The value of data 2 is "<< data2 << endl;
    cout<<"The value of data 3 is "<< data3<<endl;
}

// HERE DATA1 IS PRIVATE MEMBER OF BASE CLASS SO CAN NEVER BE USED DIRECTLY IN DERIVED CLASS
// WHILE DATA2 IS PUBLIC MEMBER SO IN PUBLIC DERIVED CLASS IT CAN BE ACCESSED AS PUBLIC MEMBER FOR DERIVED CLASS OBJECT ALSO
// BUT FOR PRIVATE DERIVED CLASS IT ACTS AS PRIVATE MEMBER SO CAN ONLY BE USED IN MEMBER FUNCTIONS


int main(){

    Derived der;
    der.setData();                                          // THIS ALSO BECOME PUBLIC FUNCTION FOR THE DERIVED CLASS AND THUS WE CAN USE THIS
    der.process();                                          // DIRECTLY BUT IF WE CHOOSE VISIBILITY MODE AS PRIVATE THEN WE HAVE TO DECLARE THIS
    der.display();                                          // IN PROCESS FUNCTION TO GET OUR REQUIRED RESULT AS IT IS NOW PRIVATE FUNCTION
    cout << der.data2 << "\n";                              // DATA2 IS PUBLIC MEMBER SO ACCESSIBLE

    Derived2 der2;
    der2.process();
    der2.display();
    // cout << der2.data2 << "\n"; --> GIVE ERROR INACCESSIBLE

    return 0;
}
// IF HERE IN DERIVED CLASS WE USE PRIVATE VISIBILITY IN PLACE OF PUBLIC THEN WE HAVE TO DO SOME CHANGES TO GET SAME RESULTS
// FIRST IS WE HAVE TO MAKE 'GET DATA2' FUNCTION FOR DATA2 AS IT WILL BECOME PRIVATE
// ALSO SET DATA , GET DATA FUNCTIONS CANNOT BE USED SIMPLY DIRECTLY IN MAIN FUCNTION AS THEY ALSO BECOME PRIVATE
// BUT WE CAN USE THEM IN OTHER FUNCTIONS DIRECTLY SO WHAT WE WILL DO IS USE SET DATA IN STARTING OF PROCESS FUNCTION TO GET SAME RESULT

// SUPPOSE A BASE CLASS AND DERIVED CLASS DEFINE A FUNCTION OF THE SAME NAME. IN SUCH CASES DERIVED CLASS FUNCTION
// SUPERSEDES THE BASE CLASS FUNCTION