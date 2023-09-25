// MULTILEVEL INHERITANCE( A-->B-->C-->D-->.....)

#include<iostream>
using namespace std;

class Student{                                                        // FIRST BASE CLASS
    protected:                                                        // PROTECTED ACCESS MODIFIERS
        int roll_number;
    public:                                                           // PUBLIC ACCESS MODIFIERS
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
        void set_marks(float,float);                                   // MARKS OF MATH AND PHYSICS ARE PROTECTED ONES SO WE HAVE TO USE 
};                                                                     // FUCNTION TO SET THEIR VALUES
void Exam :: set_marks(float m1, float m2){
    maths=m1;
    physics=m2;
}

class Result : public Exam{                                            // SECOND DERIVED CLASS DERIVED FROM THE FIRST DERIVED CLASS
       float percentage;                                               // PUBLIC TO PUBLIC AND PROTECTED TO PROTECTED
       public:
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