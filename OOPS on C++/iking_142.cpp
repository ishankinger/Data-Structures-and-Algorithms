// CLASS TO BASIC
 
// CONSTRUCTOR FUNCTIONS DO NOT SUPPORT THIS OPERATION
// C++ ALLOWS US TO DEFINE AN OVERLOADED CASTING OPERATOR THAT COULD BE USED TO CONVERT A CLASS TYPE DATA TO A BASIC TYPE
// THIS OVERLOADED CASTING OPERATOR FUNCTION USUALLY REFERRED TO AS CONVERSION FUNCTION AND IT SHOULD SATISFY FOLLOWING CONDITIONS -
// >> IT MUST BE A CLASS MEMBER
// >> IT MUST NOT SPECIFY A RETURN TYPE
// >> IT MUST NOT HAVE ANY ARGUMENTS ( IT'S A MEMBER FUNCTION SO INVOKED BY OBJECT, THUS THE VALUES INSIDE FUNCTION BELONG TO THE OBJECT )

#include<iostream>
using namespace std;


class time{
    int hrs;
    int mins;
    public :
        time(){};
        time(int t);                // CONSTRUCTOR
        void display();
        operator int(){             // FIRST CONVERSION FUNCTION
            return hrs*60 + mins;
        }
        operator double();          // SECOND CONVERSION FUNCTION DECLARATION
};

void time::display(){
	cout << hrs << ": Hour(s)  ";
	cout << mins << ": Minutes" << endl ;
}

time :: time(int t){
    hrs = t/60;
    mins = t % 60;
}

// SECOND CONVERSION FUNCTION DEFINED HERE
time ::operator double(){
    double t = hrs*60 + mins;
    double time = t / 60;
    return time;
}

int main(){
    int duration = 85;
    time t1 = duration;
    
    int minutes = int(t1);              // CAN USE CASTING LIKE THIS
    cout << minutes << "\n";
    
    double hours = t1;                  // OR SIMPLY PUT THE OBJECT
    cout << hours << "\n";

    int roundHours = double(t1);
    cout << roundHours << "\n";

    double roundMinutes = int(t1);
    cout << roundMinutes << "\n";
    
    return 0;
}