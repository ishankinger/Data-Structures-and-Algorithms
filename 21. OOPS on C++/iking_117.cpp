// CONSTRUCTORS WITH DEFAULT ARGUMENTS IN C++

#include<iostream>
using namespace std;

class simple{
    int data1,data2;
    public:
    simple(int a,int b = 9){                                     // HERE IN DEFAULT ARGUMENT WE ARE DEFINING THE DEFAULT VALUE FOR VARIABLE B
        data1 = a;                                               // THAT MEANS THAT WHEN NO VALUE OF B IS PASSED IN OBJECT BY DEFAULT THIS VALUE 
        data2 = b;                                               // WILL BE USED IN THE OBJECT 
    }
    void printData();
};
void simple:: printData(){
    cout<<"The value of data is "<<data1<<" , "<<data2<<"\n";
}

int main(){
    
    simple s(1);                                              // HERE NO VALUE OF B IS PASSED SO WE WILL USE THE DEFAULT VALUE OF B
    s.printData();
    
    simple d(1,4);                                            // HERE VALUE OF B IS PASSED SO DEFAULT VALUE WILL NOT BE USED
    d.printData();
    
     return 0;
}

// IMPORTANT TO DISTINGUISH BETWEEN DEFUALT CONSTRUCTOR AND DEFAULT ARGUMENT CONSTRUCTOR
// A::A() OR A::A(int = 0) -> CAUSES AMBIGUITY FOR A STATEMENT A a;
// SO THIS AMBIGUITY WILL GIVE AN ERROR