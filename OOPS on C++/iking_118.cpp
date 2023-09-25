// DYNAMIC INITIALIZATION OF OBJECT USING CONSTRUCTORS

#include<iostream>
using namespace std;

class bankDeposit{
    int principal;                                // DEFINING SOME PRIVATE VARIABLES
    int years;
    float interestRate;
    float returnValue;

    public:
    bankDeposit(){                                  // EMPTY CONSTRUCTOR
    }                                               // WE HAVE TO MAKE THIS DEFAULT CONSTRUCTOR SO THAT WE CAN USE DIFFERET CONSTRUCTORS
    bankDeposit(int p,int y,float r);               // CONSTRUCTOR HAVING ARGUMENTS(INT INT FLOAT)
    bankDeposit(int p,int y,int r);                 // CONSTRUCTOR HAVING ARGUMENTS(INT INT INT)
    void show();;
};

bankDeposit :: bankDeposit(int p,int y,float r){    // USING CONSTRUCTOR OUTSIDE THE CLASS
    principal=p;
    years=y;
    interestRate=r;
    returnValue=principal;
    for(int i=0;i<y;i++){
        returnValue = returnValue + returnValue*interestRate;
    }
}

bankDeposit :: bankDeposit(int p,int y, int r){     // SECOND CONSTRUCTOR OF DIFFERENT PARAMETERS
    principal=p; 
    years=y;
    interestRate=float(r)/100.0;                     // INT TO FLOAT
    returnValue= principal;
    for(int i=0;i<y;i++){
        returnValue = returnValue + returnValue*interestRate;
    }
}

void bankDeposit :: show(){
    cout<<endl<<"Principal Amount was "<<principal<<endl<<"Return value after "<<years
    <<"years is "<< returnValue<<endl;
}

int main(){
    int p,y;
    float r;                                               // R*100 means FRACTION
    int R;                                                 // PERCENTAGE
    cout<<"Enter the value of p y and r"<<endl;
    cin>>p>>y>>r;
    bankDeposit bd1(p,y,r);
    bd1.show();
    cout<<endl;
    cout<<"Enter the value of p y and R"<<endl;
    cin>>p>>y>>R;
    bankDeposit bd2(p,y,R);
    bd2.show();
    cout<<endl;
    // bankDeposit bd3;
    // bd3.show();

    return 0;
}

