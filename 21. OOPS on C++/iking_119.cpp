// COPY CONSTRUCTOR

#include<iostream>
using namespace std;

class Number{
    int a;

    public:

    Number(){                

    }

    Number(int num){
        a=num;
    }

    // COPY CONSTRUCTOR
    Number(Number &obj){
        cout<<"copy constructor called"<<endl;;
        a=obj.a;
    }

    // Number(Number obj){                 --> THIS WILL GIVE ERROR (CAN'T PASS CLASS OBJECT WITHOUT REFERENCE IN THE CONSTRUCTOR)
    //     cout << "give error\n";
    // }

    void display(){
        cout<<"the number for this object is "<<a<<endl;
    }

};

class Student{
public:

    string name;
    double *cgpaPtr;

    Student(){}

    Student(string name, double cgpa){
        this->name = name;
        cgpaPtr = new double;
        *cgpaPtr = cgpa;
    }
    
    // COPY CONTRUCTOR USING DEEP COPY
    Student(Student &obj){
        this->name = obj.name;
        cgpaPtr = new double;        // NEW MEMORY ADDRESS
        *cgpaPtr = *obj.cgpaPtr;     // BUT SAME VALUE ALLOCATED
    }

    void getInfo(){
        cout << "Name : " << name << "\n";
        cout << "cgpa : " << *cgpaPtr << "\n";
    }
};


int main(){

    // INITIALIZING THROUGH A COPY CONSTRUCTOR IS KNOWN AS COPY INITIALIZATION
    // IN EVERY COMPILER THERE IS INBUILT COPY CONSTRUCTOR SO FIRST COMPILER WILL CHECK WHETHER THERE IS COPY CONSTRUCTOR OR NOT 
    // IF THERE IS NO COPY CONSTRUCTOR THEN IT WILL BY DEFAULT USES IT'S OWN COPY CONSTRUCTOR
    // OTHERWISE IF THERE IS A COPY CONSTRUCTOR THEN IT WILL USE THAT
    // SO WITHOUT OUR COPY CONSTRUCTOR THE VALUE WILL BE PRINTED CORRECTLY
    // BUT "STRING PASSED IN COPY CONSTRUCTOR" WILL NOT BE CALLED
    // AS DEFAULT COPY CONSTRUCTOR OF COMPILER WILL ONLY MAKE NEW MEMORY WITH SAME VALUES OF OBJECT PASSED

    Number x,y(4),z;          // SIMPLE ARGUMENTS PASSED  
    y.display();              // ANY COPY CONSTRUCTOR IS NOT CALLED YET

    Number y1(y);             // USING COPY CONSTRUCTOR
    y1.display();             // USING FUNCTION OF DISPLAY THEN
    
    Number y2;                // FIRST DEFINE AND THEN ASSIGN VALUE
    y2=y;                     // COPY CONSTRUCTOR WILL NOT BE CALLED
    y2.display();
    
    Number y3=y;              // DEFINE AND ASSIGN SIMUTANEOUSLY
    y3.display();             // COPY CONSTRUCTOR WILL BE CALLED
                              

    // THERE ARE TWO TYPES OF COPY --> SHALLOW COPY AND DEEP COPY

    // SHALLOW COPY OF AN OBJECT COPIES ALL THE MEMBER VALUES FROM ONE OBJECT TO ANOTHER
    // AS WE ARE MAKING SHALLOW COPY OF OBJECT USING COPY CONSTRUCTOR
    // BUT THERE IS PROBLEM WITH SHALLOW COPY THAT IT DOESNOT WORK FOR DYNAMIC MEMORY ALLOCATION
    // NORMAL MEMORY ALLOCATES IN STACK MEMORY ( ALL VARIABLES OF FUNCTION WILL BE CREATED IN STACK MEMORY)
    // BUT IF WE ALLOCATE MEMORY USING 'new" KEYWORD, THIS MEMORY IS DYNAMIC MEMORY AND STORED IN A HEAP

    // DRAWBACK OF SHALLOW COPY
    Student s1("rahul",8.9);
    s1.getInfo();

    Student s2(s1);
    *(s2.cgpaPtr) = 9.2;
    s1.getInfo(); 

    Student s3 = s1;
    *(s3.cgpaPtr) = 9.4;
    s1.getInfo(); 

    Student s4;
    s4 = s1;
    *(s4.cgpaPtr) = 9.8;
    s1.getInfo();             

    // CGPA VALUE OF S1 GET'S CHANGED BECAUSE OF DYNAMIC ALLOCATION
    // SO HERE AS WE ARE DOING SHALLOW COPY
    // ACTUALLY SHALLOW COPY COPIES ALL THE PROPERTIES OF OBJECT SO POINTER'S ADDRESS WILL BE STORED
    // SO BOTH CGPA POINTER WILL BE STORING SAME ADDRESS SO ANY CHANGE IN S2 WILL ALSO AFFECT S1

    // SO HERE COMES THE ROLE OF DEEP COPY WHICH WE HAVE TO WRITE ON OUR OWN AS COMPILER ONLY DO SHALLOW COPY
    // DEEP COPY OF AN OBJECT NOT ONLY COPIES THE MEMBER VALUES BUT ALSO MAKE COPIES OF ANY DYNAMICALLY ALLOCATED MEMORY THAT THE MEMBERS POINT TO

    return 0;
}                                                       