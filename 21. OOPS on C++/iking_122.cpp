// CONSTRUCTORS AND DESTRUCTORS IN INHERITANCE
// FIRST CONSTRUCTOR OF PARENT WILL INVOKE THEN CONSTRUCTOR OF CHILD
// FOR DESTRUCTORS IT WILL BE REVERSED MEANS FIRST CHILD DESTRUCTOR CALLED THEN PARENT DESTRUCTOR

#include<iostream>
using namespace std;

// BASE CLASS
// AS LONG AS NO BASE CLASS CONSTRUCTOR TAKES ANY ARGUMENTS, THE DERIVED CLASS NEED NOT HAVE A CONSTRUCTOR FUNCTION
// IF ANY BASE CLASS CONTAINS A CONSTRUCTOR WITH ONE OR MORE ARGUMENT, THEN IT IS MANDATORY FOR THE DERIVED CLASS TO 
// HAVE A CONSTRUCTOR AND PASS THE ARGUMENT TO THE BASE CLASS

// AN EMPTY DEFAULT CONSTRUCTOR TO BE INCLUDED IN BASE CLASS BECAUSE IN DERIVED CLASS CONSTRUCTOR IF WE ARE NOT EXPLICITLY 
// DEFINING THE BASE CLASS CONSTRUCTOR TO BE USED THEN IT WILL USE EMPTY ARGS CONSTRUCTOR
class Employee{
public:

    int id;
    float salary;

    // IF I WILL COMMENT OUT THIS CONSTRUCTOR THEN THERE WILL BE AN ERROR BECAUSE DERIVED CLASS FIRST CONSTRUCTOR IS NOT EXPLICITLY
    // MENTIONING WHICH BASE CLASS CONSTRUCTOR TO CALLED SO UNPARAMETERISED CONSTRUCTOR SHOULD BE CALL
    // IF WE DONOT DEFINE ANY CONSTRUCTOR OF BASE CLASS THEN IT'S FINE BECAUSE THEN COMPILER WILL PROVIDE EMPTY ARGS CONSTRUCTOR
    Employee(){                                           // WE HAVE TO USE A DEFAULT CONSTRUCTOR TO RUN DERIVED CLASS
        cout << "Constructor1 Parent\n";
    }

    ~Employee(){
        cout << "Destructor Parent\n";
    }
    
    Employee(int inpId, int salary){
        cout << "Constructor2 Parent\n";
        id = inpId;
        this->salary = salary;
    }
    
    Employee(int inpId){                                   // A CONSTRUCTOR IS MADE WHICH WILL PRINT SOME LINE
        cout << "Constructor3 Parent\n";
        cout<<"The salary of employee is ";                // AND SET SALARY AND ID OF THE EMPLOYEE
        id=inpId;
        salary=15000;
    }

};


// DERIVED CLASS SYNTAX
// OBJECTS OF THIS CLASS CAN USE THE DATA MEMBERS OF THE BASE CLASS
class Programmer : public Employee{   
    public:                                                        // ID AND FLOAT ARE INHERITED FROM THE BASE CLASs

    int langCode=9;

    Programmer(int inpId){                                         // CONSTRUCTOR OF THIS CLASS IN WHICH WE ARE USING 
        cout << "Constructor1 child\n";                            // NO CONSTRUCTOR OF PARENT CLASS DEFINED SO NON PARAMETERISED CONSTRUCTOR CALLED
        id=inpId;                                                  // THE PUBLIC VARIABLE OF BASE CLASS 
    }

    // CALL PARENT CLASS CONSTRUCTOR EXPLICITLY
    Programmer(int inpId, float salary) : Employee(inpId,salary){ 
        cout << "Constructor2 child\n";
    }

    ~Programmer(){
        cout << "Destructor child\n";
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
    cout << skillF.id << "\n";
    cout << skillF.salary << "\n";
    skillF.getData();                         

    Programmer skillT(1,15000);               // FOR THIS CONSTRUCTOR 2 WILL BE CALLED
    cout << skillT.salary << "\n";

    return 0;
}