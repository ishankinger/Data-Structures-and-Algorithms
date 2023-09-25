// STATIC VARIABLES ( CLASS VARIBLES ) ONE VARIABLE SHARED IN MANY OBJECTS OF A PARTICULAR CLASS
// STATIC DATA MEMBER OF A CLASS

#include<iostream>
using namespace std;

class Employee{                                      // A CLASS NAMED EMPLOYEE IS DEFINED
    int id;                                          // A SIMPLE VARIABLE IS DEFINED
    static int count;                                // BY DEFAULT INITIALISE WITH 0
    // INT COUNT =0;                                 // VARIABLE WITH ATTACH WITH CLASS SO THAT IT IS NOT PROPERTY OF A PARTICULAR OBJECT IT IS 
    public:                                          // PROPERTY OF THE CLASS WILL BE USED SAME AS FOR ALL OBJECTS OF THE PARTICULAR CLASS
    void setData(void){                              // FUNCTION TO GET ID OF DIFFERENT OBJECTS OF THE CLASS
        cout<<"Enter the Id "<<endl;                 // SOME WORDING TO TAKE INPUT
        count ++ ;                                   // FOR EACH OBJECT SAME VARIBLE COUNT IS ++ 
        cin>>id;                                     // TAKE INPUT OF ID
    }
    void getData(void){                              // FUNCTION TO PRINT THE DATA
        cout<<"The Id of the employee no."<<count<<" is "<<id<<endl;   
    }
    static void getCount(void){                       // STATIC MEMBER FUNCTIONS
        cout<<"The value of count is "<<count<<endl;  // ONLY STATIC VARIABLE CAN BE USED IN STATIC FUNCTIONS
        //cout<<id;                                   // THIS WILL THROW AN EROR IT IS NON STATIC VARIABLE
    }
};

int Employee :: count;                                 // HAVE TO DEFINE LIKE THIS OUTSIDE THE CLASS FOR A STATIC VARIABLE
         
int main(){
    Employee Ishan;                                    // THREE DIFFERENT OBJECTS FROM THE EMPLOYEE CLASS ARE MADE
    Employee Rohan;
    Employee Lovish;

    Ishan.setData();                                   // FOR EVERY OBJECT SAME COUNT WILL ++ AS IT IS STATIC VARIABLE 
    Ishan.getData();                                   // BUT ALL WILL HAVE DIFFERENT ID'S AS IT IS NOT A STATIC VARIABLE
    Employee::getCount();                              // STATIC FUNCTIONS ARE USED DIRECTLY WITHOUT ANY REFERENCE OF ANY PARTICULAR OBJECT

    Rohan.setData();
    Rohan.getData();
    Employee::getCount();

    Lovish.setData();
    Lovish.getData();
    Employee::getCount();

    return 0;
}
// IF WE DONOT USE THE VARIABLE COUNT THEN IT'S VALUE WILL INTIALISE AS 0 EACH TIME AND FOR EACH OBJECT IT WILL BE PRINTED AS 1