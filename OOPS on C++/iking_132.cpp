// THIS POINTER IN C++
// this ==>  A KEYWORD WHICH IS POINTER WHICH POINTS TO THE OBJECT WHCIH INVOKES THE MEMBER FUNCTION

#include<iostream>
using namespace std;

class A{
    int a,b;
    public:
        void setData(int a1){
            a=a1;
        }
        void setDataByThis(int b){
            this->b=b;
        }
        void getData(void){
            cout<<"The value of a is "<<a<<endl;
            cout<<"The value of b is "<<b<<endl;
        }
        A & setdata(int a,int b){
            this->a=a;
            this->b=b;
            return *this;
        }
};

int main(){
    A a;
    a.setData(4);
    a.setDataByThis(5);
    a.getData();
    
    a.setdata(1,2).getData();
    return 0;
}