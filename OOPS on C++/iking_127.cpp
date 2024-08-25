// VIRTUAL BASE CLASS
// HERE MULTIPLE , MULTILEVEL AND HIERARICHAL INHERITANCE ARE INVOLVED
//      A           ==> A WILL BE VIRTUAL BASE CLASS
//    /   \
//   B     C
//    \   /
//      D
// ANY VARIABLE OF A WILL BE IN B AND C BOTH SO D WILL HAVE TWO SAME VARIABLE SO THERE IS SOME AMBIGITYT
// SO THERE WILL BE AMBIGUITY

#include<iostream>
using namespace std;

class Student{                                                               // FIRST BASE CLASS
    protected:                                                               // SIMILAR FORMAT FOR GETTING ROLL NO OF A STUDENT
        int roll_no;
    public:
        Student(){
            cout << "Student Virtual\n";
        }
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
        Test(){
            cout << "Test\n";
        }
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

class Sports : virtual public Student{                                        // SECOND DERIVED CLASS, VIRTAUL AND PUBLIC CAN BE USED IN ANY ORDER
    protected:                                                                // ALL THINGS SIMILAR AS THAT OF FIRST DERIVED CLASS
        float score;
    public:
        Sports(){
            cout << "Sports\n";
        }
        void set_score(float sc){
            score=sc;
        } 
        void print_score(void){
            cout<<"Your score in sports is : "<<score<<endl;
        } 
};

class Music{
    protected:
        float points;
    public:
        Music(){
            cout << "Music Non Virtual\n";
        }
        void set_points(float p){
            points = p;
        }
        void print_points(void){
            cout << "Your points in Music is :" << points << "\n";
        }
};

class Result : public Sports, public Music, public Test{    // THIRD DERIVED CLASS DERIVED FROM FIRST AND SECOND DERIVED CLASS AND ONE ANOTHER CLASS MUSIC                                
    private:                                                
        float total;
    public:
        Result(){
            cout << "Result\n";
        }
        void display(void){
            total=maths+physics+score+points;
            print_no();
            print_marks();
            print_score();
            print_points();
            cout<<"Your total score is : "<<total<<endl;
        }
}; 

int main(){                                                                 // IF WE DONONT USE THAT VIRTUAL KEYWORD THEN AMBIGUITY WILL OCCUR
    Result harry;                                                           // BUT NOW CODE WILL RUN WITHOUT EROR
    harry.set_no(12);
    harry.set_marks(78,90);
    harry.set_score(79);
    harry.set_points(45);
    harry.display();
    return 0;
}

// THE CONSTRUCTOR OF VIRTUAL BASE CLASSES ARE INVOKED BEFORE AN NON VIRTUAL BASE CLASS EVEN IF ANY NON VIRTUAL CLASS IS DEFINED FIRST
// IF THERE ARE MULTIPLE VIRTUAL BASE CLASSES, THEY ARE INVOKED IN THE ORDER DECLARED