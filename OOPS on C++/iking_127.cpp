// VIRTUAL BASE CLASS
//      A           ==> A WILL BE VIRTUAL BASE CLASS
//    /   \
//   B     C
//    \   /
//      D
// ANY VARIABLE OF A WILL BE IN B AND C BOTH SO D WILL HAVE TWO SAME VARIANLE SO THERE IS SOME AMBIGITYT
// SO THERE WILL BE AMBIGUITY

#include<iostream>
using namespace std;

class Student{                                                               // FIRST BASE CLASS
    protected:                                                               // SIMILAR FORMAT FOR GETTING ROLL NO OF A STUDENT
        int roll_no;
    public:
        void set_no(int a){
            roll_no=a;
        }
        void print_no(void){
            cout<<"The roll no. of the student is : "<<roll_no<<endl;
        }
};

class Test : virtual public Student{                                         // FIRST DERIVED CLASS WHICH IS DERIVED VIRTUALLY AND 
    protected:                                                               // USING PUBLIC VISIBILITY MODE FROM STUDENT CLASS
        float maths,physics;                                                 // SO HERE INT ROLL NO WILL BE TAKEN AS PROTECTED AND OTHER 
    public:                                                                  // FUNCTIONS TO BE TAKEN AS PUBLIC
        void set_marks(float m1,float m2){                                   // ABOVE PROCEDURE IS TO JUST SET AND GET MARKS DONE EARLIER
            maths=m1;
            physics=m2;
        }
        void print_marks(void){
            cout<<"Your result is here "<<endl
                <<"maths : "<<maths<<endl
                <<"physics : "<<physics<<endl;
        }
};

class Sports : virtual public Student{                                        // SECOND DERIVED CLASS
    protected:                                                                // ALL THINGS SIMILAR AS THAT OF FIRST DERIVED CLASS
        float score;
    public:
        void set_score(float sc){
            score=sc;
        } 
        void print_score(void){
            cout<<"Your score in sports is : "<<score<<endl;
        } 
};

class Result : public Test, public Sports{                                     // THIRD DERIVED CLASS DERIVED FROM FIRST AND SECOND DERIVED CLASS
    private:
        float total;
    public:
        void display(void){
            total=maths+physics+score;
            print_no();
            print_marks();
            print_score();
            cout<<"Your total score is : "<<total<<endl;
        }
}; 

int main(){                                                                 // IF WE DONONT USE THAT VIRTUAL KEYWORD THEN AMBIGUITY WILL OCCUR
    Result harry;                                                           // BUT NOW CODE WILL RUN WITHOUT EROR
    harry.set_no(12);
    harry.set_marks(78,90);
    harry.set_score(79);
    harry.display();
    return 0;
}