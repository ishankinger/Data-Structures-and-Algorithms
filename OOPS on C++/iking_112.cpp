// FRIEND CLASS

#include<iostream>
using namespace std;

// FORWARD DECLARATION ( TO GIVE COMPILER INFO ABOUT CLASS WHICH IS USED IN OTHER CLASS )
class complex;                                                        // DECALRATION OF CLASS AS WE ARE USING OBJECTS OF IT'S IN OTHER CLASS

class calculator{                                                     // SHOULD BE WRITTEN UP
    public:
    int add(int a,int b){
        return a+b;
    }                                       
    int sumRealComplex(complex , complex );                      // ONLY DECALARATION TO BE GIVEN
    int sumCompComplex(complex,complex);
};

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

int calculator:: sumRealComplex(complex o1, complex o2){
        return o1.a+o2.a;
    }
int calculator:: sumCompComplex(complex o1, complex o2){
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
}
// BUT WE HAVE OTHER WAY TO DO ABOVE QUESTION USING FRIEND CLASS
// WHAT WE HAVE TO DO IS JUST WRITE
// 'friend class calculator' THIS WILL BE WRITTEN IN COMPLEX CLASS
// SO FROM USING THIS WE CAN GET RID OF SO MUCH HEAVY CODE AND IF WE HAVE MANY FUNCTION THEN TO DEFINE EACH FUNCTION IS VERY HECTIC TASK
// SO THIS FAR BETTER METHOD THAN DOING THIS 
