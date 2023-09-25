// ARRAYS OF OBJECTS OF A PARTICULAR CLASS

#include<iostream>
using namespace std;

class Employee{                                           // CUSTOM DATAYPES ARE DEFINED BY THE CLASS SAME AS INT,FLOAT,BOOLEAN....
    int id;
    string name;
    int salary;
    static int count;
    public:
    void setId(void){                                    // SIMILAR TYPE OF CLASS IS MADE AS DONE IN PREVIOUS QUESTION
        salary=10000;                             
        cout<<"Enter id of employee : ";
        cin>>id;
        cout<<"Enter the name of the id : ";
        cin>>name;
    }
    void getId(void){
        count++;
        cout<<"id of the "<<count<<" employee is : "<<id<<endl;
        cout<<"Name of this employee is : "<<name<<endl;
    }
};
int Employee :: count;
int main(){
    // Employee harry, ishan ,rohan ,shruti;            // IF WE HAVE MANY OBJECTS TO BE USED IN A PARTICULAR CLASS WE NEED NOT DEFINE LIKE THIS
    // harry.setId();
    // harry.getId();

    // ANOTHER WAY TO WRITE THIS

    Employee company[4];                                // HERE COMES THE USE OF ARRAY OF OBJECTS
    for(int i=0;i<4;i++){                               // nameOfClass_nameOfObject[no.OfObjects];
        company[i].setId();                             // nameOfObject[i].functionInClass SYNTAX TO USE THIS
    }
    for(int i=0;i<4;i++){
        company[i].getId();
    }
}