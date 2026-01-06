// FRIEND FUNCTIONS
// TILL NOW WE KNOW THAT THE NON-MEMBER FUNCTIONS DOESNOT HAVE ANY ACCESS TO PRIVATE DATA OF THE CLASS
// C++ ALLOWS THE NON-MEMBER FUNCTIONS TO BE MADE FRIENDLY WITH THE CLASSES, THEREBY ALLOWING THE FUNCTION TO HAVE ACCESS TO THE PRIVATE DATA 

#include<iostream>
using namespace std;

class complex{
    int a;
    int b;
    public:
        void setNumber(int n1, int n2){
            a=n1;
            b=n2;
        }

        friend complex sumComplex(complex o1, complex o2);          // BY USING THIS FRIEND KEYWORD WE CAN ACCESS PRIVATE THINGS OF CLASS IN FUNCTION
                                                                    // SUM COMPLEX CAN ACCESS THE PRIVATE MEMBERS OF THIS CLASS
        void printNumber(void){
            cout<<"Your number is "<<a<<" + "<<b<<"i"<<endl;
        }
};

// HERE SUM COMPLEX IS NOT A MEMBER FUNCTION OF CLASS BUT A FRIEND FUNCTION WHICH CAN ACCESS THE PRIVATE DATA OF THE CLASS
// NO NEED TO USE FRIEND KEYWORD OR SCOPE OPERATOR :: HERE
complex sumComplex(complex o1, complex o2){
    complex o3;
    o3.setNumber((o1.a + o2.a), (o1.b + o2.b));       // IF FRIEND KEYWORD IS NOT SHOWN THEN IT WILL SHOW ERROR ON A AND B HERE
    // printNumber();                                 // CAN'T USE NESTING HERE
    return o3;
}
// SO FRIEND FUNCTION IS NOT PROPERLY A MEMBER FUNCTION OF THE CLASS
// WE CAN SAY THAT IT'S LIKE MAIN FUNCTION FOR WHICH ALL THE MEMBERS ARE PUBLIC

int main(){                                           // PROPERTIES OF FRIEND FUNCTIONS
    complex c1,c2,sum;                                // 1. NOTE IN THE SCOPE OF THE CLASS( NOT A FUNCTION OF CLASS)
                                                      // 2. SINCE IT IS NOT IN SCOPE OF CLASS IT CANNOT BE CALLED FROM THE OBJECT OF CLASS (C1.SUM)-Wrong
    c1.setNumber(1,4);                                // 3. CAN BE INVOKE WITHOUT ANY HELP OF THE OBJECTS
    c1.printNumber();                                 // 4. USUALLY CONTAINS THE OBJECTS AS ARGUMENTS
                                                      // 5. CAN BE DECLARED INSIDE PUBLIC AND PRIVATE SECTION OF THE CLASS WITHOUT AFFECTING IT'S MEANING
    c2.setNumber(5,8);                                // 6. IT CANNOT ACCESS THE MEMBERS DIRECTLY BY THEIR NAMES AND NEED OBJECT_NAME, MEMBER_NAME
    c2.printNumber();                                 //    TO ACCESS ANY MEMBER

    sum=sumComplex(c1,c2);
    sum.printNumber();

    // c1.sumComplex(c1,c2) --> GIVE ERROR FROM  PROPERTY
}