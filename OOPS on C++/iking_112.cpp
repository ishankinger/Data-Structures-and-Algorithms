// FRIEND CLASS

#include<iostream>
using namespace std;

// FORWARD DECLARATION ( TO GIVE COMPILER INFO ABOUT CLASS WHICH IS USED IN OTHER CLASS )
// DECALRATION OF CLASS AS WE ARE USING OBJECTS OF IT'S IN OTHER CLASS
class complex;                                                       
class complex2;

class calculator{                                                     // SHOULD BE WRITTEN UP
    public:
    int add(int a,int b){
        return a+b;
    }                                       
    int sumRealComplex(complex O1,complex O2);                      // ONLY DECALARATION TO BE GIVEN
    int sumCompComplex(complex,complex);                            // IN DECLARATION NO NEED OF WRITING THE VARIABLE ONLY DATATYPE WILL
    int sumRealComplex2(complex2,complex2);                         // WORK IN THE ARGUMENT
    int sumCompComplex2(complex2,complex2);  
};

// MEMBER OF ONE CLASS CAN BE FRIEND FUNCTIONS OF ANTHER CLASS. IN SUCH CASES THEY AE DEFINED USING THE SCOPE RESOLUTION OPERATOR 
class complex{
    int a;
    int b;
    friend int calculator :: sumRealComplex(complex o1, complex o2);
    friend int calculator :: sumCompComplex(complex o1, complex o2);       // to access private data
    public:
        void setNumber(int n1, int n2){
            a=n1;
            b=n2;
        }
        void printNumber(){
            cout<<"Your number is"<<a<<" + "<<b<<"i";
        }
};

// FUNCTION OF THE CALCULATOR CLASS WHICH ARE MADE FRIEND FUNCTIONS OF THE COMPLEX CLASS
// TO ACCESS THE PRIVATE DATA OF THE COMPLEX CLASS
int calculator:: sumRealComplex(complex o1, complex o2){
    return o1.a+o2.a;
}

int calculator:: sumCompComplex(complex o1, complex o2){
    return o1.b+o2.b;
}

// BUT WE HAVE OTHER WAY TO DO ABOVE QUESTION USING FRIEND CLASS
// WHAT WE HAVE TO DO IS JUST WRITE
// 'friend class calculator' THIS WILL BE WRITTEN IN COMPLEX CLASS
// SO FROM USING THIS WE CAN GET RID OF SO MUCH HEAVY CODE AND IF WE HAVE MANY FUNCTION THEN TO DEFINE EACH FUNCTION IS VERY HECTIC TASK
// SO THIS FAR BETTER METHOD THAN DOING THIS 
// SO WE CAN DECLARE ALL THE MEMBER FUNCTIONS OF ONE CLASS AS THE FRIEND FUNCTIONS OF ANOTHER CLASS
class complex2{
    int a;
    int b;
    friend class calculator;
    public:
        void setNumber(int n1, int n2){
            a=n1;
            b=n2;
        }
        void printNumber(){
            cout<<"Your number is"<<a<<" + "<<b<<"i";
        }
};

int calculator:: sumRealComplex2(complex2 o1, complex2 o2){
    return o1.a+o2.a;
}

int calculator:: sumCompComplex2(complex2 o1, complex2 o2){
    return o1.b+o2.b;
}

int main(){
    complex o1,o2;
    o1.setNumber(1,4);
    o2.setNumber(1,7);
    calculator calc1,calc2;
    int res1= calc1.sumRealComplex(o1,o2);
    cout<<"The sum of real part of complex numbers is "<< res1<<endl;;
    int res2= calc2.sumCompComplex(o1,o2);
    cout<<"The sum of complex part of complex numbers is "<< res2<<endl;

    complex2 c1,c2;
    c1.setNumber(1,4);
    c2.setNumber(1,7);
    res1= calc1.sumRealComplex2(c1,c2);
    cout<<"The sum of real part of complex numbers is "<< res1<<endl;;
    res2= calc2.sumCompComplex2(c1,c2);
    cout<<"The sum of complex part of complex numbers is "<< res2<<endl;
}

