// FRIEND FUNCTIONS

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

complex sumComplex(complex o1, complex o2){
    complex o3;
    o3.setNumber((o1.a + o2.a), (o1.b + o2.b));       // IF FRIEND KEYWORD IS NOT SHOWN THEN IT WILL SHOW ERROR ON A AND B HERE
}
int main(){                                           // PROPERTIES OF FRIEND FUNCTIONS
    complex c1,c2,sum;                                // 1. NOTE IN THE SCOPE OF THE CLASS( NOT A FUNCTION OF CLASS)
                                                      // 2. SINCE IT IS NOT IN SCOPE OF CLASS IT CANNOT BE CALLED FROM THE OBJECT OF CLASS (C1.SUM)
    c1.setNumber(1,4);                                // 3. CAN BE INVOKE WITHOUT ANY HELP OF THE OBJECTS
    c1.printNumber();                                 // 4. USUALLY CONTAINS THE OBJECTS AS ARGUMENTS
                                                      // 5. CAN BE DECLARED INSIDE PUBLIC AND PRIVATE SECTION OF THE CLASS
    c2.setNumber(5,8);                                // 6. IT CANNOT ACCESS THE MEMBERS DIRECTLY BY THEIR NAMES AND NEED OBJECT_NAME, MEMBER_NAME
    c2.printNumber();                                 //    TO ACCESS ANY MEMBER

    sum=sumComplex(c1,c2);
    sum.printNumber();
}