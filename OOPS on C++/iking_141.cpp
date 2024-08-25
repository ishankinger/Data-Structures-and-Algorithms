// TYPE CONVERSIONS
// C++ APPLIES AUTOMATIC TYPE CONVERSION TO THE OPERANDS AS PER CERTAIN RULES 
// SINCE THE USER DEFINED DATA TYPES ARE DEFINED BY US, THE COMPILER DOESNOT SUPPORT AUTOMATIC TYPE CONVERSION FOR SUCH DATA TYPES
// SO WE MUST DEFINE THE CONVERSION ROUTINE BY OURSELVES THAT ARE-
// >> BASIC TYPES TO CLASS TYPES 
// >> CLASS TYPES TO BASIC TYPES
// >> CLASS TYPES TO CLASS TYPES

// BASIC TO CLASS 
// THIS CAN BE PERFORMED USING TWO WAYS
// >> USING CONSTRUCTOR
// >> USING OPERATOR OVERLOADING

#include<iostream>
using namespace std;

// CONSTRUCTOR CAN PERFORM A DEFACTO TYPE CONVERSION FROM THE ARGUMENT'S TYPE TO THE CONSTRUCTOR'S CLASS TYPE
// EXAMPLES - VECTOR(INT ARRAY), STRING(CHAR ARRAY) DONE IN PREVIOUS EXAMPLES
// THE CONSTRUCTOR USED FOR TYPE CONVERSION TAKES A SINGLE ARGUMENT WHOSE TYPE IS TO BE CONVERTED
class time{
    int hrs;
    int mins;
    public :
        time(){};
        time(int t);                // CONSTRUCTOR
        void display();
};

void time::display(){
	cout << hrs << ": Hour(s)  ";
	cout << mins << ": Minutes" << endl ;
}

time :: time(int t){
    hrs = t/60;
    mins = t % 60;
}

// WE CAN ALSO ACCOMPLISH THIS CONVERSION USING AN OVERLOADED = OPERATOR 
class Time{
	int hrs,mins;
	public:
		void display();
		void operator=(int);            // OPERATOR FUNCTION
};

void Time::display(){
	cout << hrs << ": Hour(s)  ";
	cout << mins << ": Minutes" << endl ;
}

void Time::operator=(int t){
	hrs = t/60;
    mins = t % 60;
}

int main(){
    int duration = 85;

    // THREE WAYS TO CALL THE CONSTRUCTOR 
    time T1(duration);
    T1.display();

    time T2 = time(duration);
    T2.display();

    time T3 = duration;
    T3.display();

    // Time T4 = duration;             // this is not assignment operator here constructor is used
    Time T4;                           // so have to use this way for operator overloading
    T4 = duration;
    T4.display();
}