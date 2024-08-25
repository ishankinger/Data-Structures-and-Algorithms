// MULTILEVEL INHERITANCE( A-->B-->C-->D-->.....)
// CLASS B, C IS KNOWN AS INTERMEDIATE CLASS AND A,B,C,D IS KNOWN AS INHERITANCE PATH


#include<iostream>
using namespace std;

class Student{                                                        // FIRST BASE CLASS

    protected:                                                        // PROTECTED ACCESS MODIFIERS
        int roll_number;

    public:                                                           // PUBLIC ACCESS MODIFIERS
        Student(){
            cout << "Constructor parent\n";
        }
        ~Student(){
            cout << "Destructor parent\n";
        }
        void set_roll_number(int);                                    // FUNCTION TO SET VALUE OF ROLL_NUM AS IT CANNOT BE ACCESSED  
        void get_roll_number(void);                                   // AS SIMILAR TO THE PRIVATE ACCESS MODIFIERS AND THEN PRINT THAT VALUE
};

void Student :: set_roll_number(int r){                               // MAKING FUNCTION OUT OF THE CLASS USING ::
    roll_number=r;
}

void Student :: get_roll_number(){
    cout<<"The roll number is "<<roll_number<<endl;
}



class Exam : public Student{                                           // FIRST DERIVED CLASS DERIVED FROM FIRST BASE CLASS

    protected:                                                         // PUBLIC VISIBILITY MODE IS USED SO PUBLIC FUNCTIONS AND VARIABLES WILL
        float maths;                                                   // BE PUBLIC AND PROTECTED WILL BE PROTECTED
        float physics;

    public:
        Exam() : Student(){                                            // CAN ALSO EXPLICITLY DEFINED FOR PARAMETERIZED CONSTRUCTOR
            cout << "Constructor derive1\n";
        }
        ~Exam(){
            cout << "Destructor dervie1\n";
        }
        void set_marks(float,float);                                   // MARKS OF MATH AND PHYSICS ARE PROTECTED ONES SO WE HAVE TO USE 
}; 
                                                                    
void Exam :: set_marks(float m1, float m2){                            // FUCNTION TO SET THEIR VALUES
    maths=m1;
    physics=m2;
}



class Result : public Exam{                                            // SECOND DERIVED CLASS DERIVED FROM THE FIRST DERIVED CLASS

    float percentage;                                               // PUBLIC TO PUBLIC AND PROTECTED TO PROTECTED

    public:
        Result(){
            cout << "Constructor derive2\n";
        }
        ~Result(){
            cout << "Destructor derive2\n";
        }
        void display(void){
            cout<<"Your mean marks are "<<(maths+physics)/2<<endl;
        }
};


int main(){
    Result harry;                                                       // OBJECT OF SECOND DERIVED CLASS
    harry.set_roll_number(420);                                         // FUNCTION OF FIRST BASE CLASS
    harry.get_roll_number();                                            // FUCNTION OF FIRST BASE CLASS
    harry.set_marks(94.2,98.5);                                         // FUNCTION OF FIRST DERIVED CLASS
    harry.display();                                                    // FUNCTION OF SECOND DERIVED CLASS
    return 0;
}

// CONSTRUCTOR CALLING -> class A : B{}
//                        class B : C{}
//                        class C : D{}  => CONSTRUCTOR OF A CALLED THEN B CALLED THEN C CALLED AND THEN D CALLED
//                                       => DESTRUCTOR GOES IN REVERSE ORDER