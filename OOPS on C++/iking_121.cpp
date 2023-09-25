// INHERITANCE ( REUSABILITY OF CLASS )

// REUSABILITY IS VERY IMPORTANT FEATURE OF OOP'S
// IN C++ WE CAN USE A CLASS AND ADD ADDITIONAL FEATURES TO IT
// REUSING CLASSES SAVES TIME AND MONEY
// RESUSING ALREADY TESTED AND DEBUGGED CLASS WILL SAVE A LOT OF EFFORT OF DEVELOPING AND DEBUGGING THE SAME THING AGAIN

// CONCEPT OF REUSABILITY IN C++ IS SUPPORTED USING INHERITANCE
// WE CAN REUSE THE PROPERTIES OF AN EXISTING CLASS BY INHERITING FROM IT
// THE EXISTING CLASS IS CALLED BASE CLASS
// THE NEW DERIVED CLASS INHERITED FROM BASE CLASS IS CALLED DERIVED CLASS

#include<iostream>
using namespace std;

// BASE CLASS
// AN EMPTY DEFAULT CONSTRUCTOR TO BE INCLUDED
class Employee{
    public:
    int id;
    float salary;
    Employee(int inpId){                                   // A CONSTRUCTOR IS MADE WHICH WILL PRINT SOME LINE
        cout<<"The salary of employee is ";                // AND SET SALARY AND ID OF THE EMPLOYEE
        id=inpId;
        salary=15000;
    }
     Employee(){                                           // WE HAVE TO USE A DEFAULT CONSTRUCTOR TO RUN DERIVED CLASS

     }
};
// DERIVED CLASS SYNTAX
// CLASS {{DERIVED CLASS NAME}} : {{VISIBILITY MODE}} {{BASE CLASS NAME}}
// DEFAULT VISIBILITY MODE IS PRIVATE VISIBILITY MODE
// PRIVATE VISIBILITY MODE--> PUBLIC MEMBER OF BASE CLASS BECOMES PRIVATE MEMBERS OF DERIVED CLASS
// PUBLIC VISIBILITY MODE--> PUBLIC MEMBER OF BASE CLASS BECOMES PUBLIC MEMBER OF  DERIVED CLASS 
// PRIVATE MEMBERS ARE NEVER INHERITED
class Programmer : public Employee{   
    public:                                                        // ID AND FLOAT ARE INHERITED FROM THE BASE CLASS
    int langCode=9;
    Programmer(int inpId){                                         // CONSTRUCTOR OF THIS CLASS IN WHICH WE ARE USING 
        id=inpId;                                                  // THE PUBLIC VARIABLE OF BASE CLASS 
    }
    void getData(){
        cout<<"id of programmer employee is "<< id<<endl;
    }
};

int main(){
    Employee harry(1);                        // THESE ARE SIMPLE OBJECTS OF THE BASE CLASS
    cout<<harry.salary<<endl;                 // CONSTRUCTOR WILL BE INVOKED AND THEN PRINTING OF THEIR SALARY
    Employee rohan(2);
    cout<<rohan.salary<<endl;

    Programmer skillF(1);                     // THIS IS THE OBJECT OF THE DERIVED CLASS
    cout<<skillF.langCode<<endl;              
    skillF.getData();
    return 0;
}