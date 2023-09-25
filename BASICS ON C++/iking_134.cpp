// SCOPE OF VARIABLE IN C++

#include<iostream>
using namespace std;

void print(){
    cout<<apples;                    // THIS APPLES IS ONLY DEFINED IN THE MAIN FUNCTION
}
int main(){
    int apples=5;
    print();                         // SO HERE IT WILL SHOW EROR AND THIS IS CONCEPT TO LEARN

    int p=5;                        // THIS WILL ALSO SHOW ERROR AS WE CANNOT DEFINE A VARIABLE IN TWO DATATYPES
    float p= 5.348759;
    cout<<p;
}

