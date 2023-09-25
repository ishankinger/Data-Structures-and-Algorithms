// COPY CONSTRUCTOR

#include<iostream>
using namespace std;

class Number{
    int a;
    public:
    Number(){                 // DEFAULT CONSTRUCTOR OTHERWISE IT WILL SHOW EROR TO THE X,Y,Z LET

    }
    Number(int num){
        a=num;
    }
    Number(Number &obj){
        cout<<"copy constructor called"<<endl;;
        a=obj.a;
    }
    void display(){
        cout<<"the number for this object is "<<a<<endl;
    }

};

int main(){
    Number x,y(4),z;          // SIMPLE ARGUMENTS PASSED  
    y.display();              // ANY COPY CONSTRUCTOR IS NOT CALLED YET

    Number y1(y);             // USING COPY CONSTRUCTOR
    y1.display();             // USING FUNCTION OF DISPLAY THEN
    
    Number y2;                // FIRST DEFINE AND THEN ASSIGN VALUE
    y2=y;                     // COPY CONSTRUCTOR WILL NOT BE CALLED
    
    Number y3=y;              // DEFINE AND ASSIGN SIMUTANEOUSLY
    return 0;                 // COPY CONSTRUCTOR WILL BE CALLED
}
// IN EVERY COMPILER THERE IS INBUILT COPY CONSTRUCTOR SO FIRST COMPILER WILL CHECK WHETHER THERE IS COPY CONSTRUCTOR OR NOT 
// IF THERE IS NO COPY CONSTRUCTOR THEN IT WILL BY DEFAULT USES IT'S OWN COPY CONSTRUCTOR
// OTHERWISE IF THERE IS A COPY CONSTRUCTOR THEN IT WILL USE THAT
// SO WITHOUT OUT COPY CONSTRUCTOR THE VALUE WILL BE PRINTED CORRECTLY
// BUT "STRING PASSED IN COPY CONSTRUCTOR" WILL NOT BE CALLED
   