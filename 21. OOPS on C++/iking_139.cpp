// OVERLOADING BINARY OPERATORS USING FRIENDS

// IN MOST OF THE CASES WE WILL GET THE SAME RESULT BY THE USE OF EITHER FRIEND FUNCTION OR A MEMBER FUNCTION
// BUT THERE CAN BE CERTAIN SITUATIONS WHERE WE WOULD LIKE TO USE FRIEND FUNCTION RATHER THAN THE MEMBER FUNCTION
// CONSIDER --> A = B + 2 , THIS WILL WORK FOR A MEMBER FUNCTION BUT A = 2 + B, WILL NOT WORK FOR A MEMBER FUNCTION
// THIS IS BECAUSE THE LEFT HAND OPERAND WHICH IS RESPONSIBLE FOR INVOKING THE MEMBER FUNCTION SHOULD BE AN OBJECT OF THE SAME CLASS
// HOWEVER FRIEND FUNCTION ALLOWS BOTH APPROACHEDS AS IN FRIEND FUNCTION WE NEED NOT TO INVOKE THE OBJECT WHILE WE PASS IT AS ARGUMENT
// SO WE WILL MAKE TWO DIFFERENT FRIEND FUNCTION WITH DIFFERENT ORDER OF ARGUMENTS PASSING IN IT

#include<iostream>
#include <stdlib.h>
#include <stdio.h>
using namespace std;
class vector{
public:
    int *v;
    int size;
    int capacity;

    void doubleSize();

    vector();
    vector(int size);
    void push_back(int val);
    void pop_back();
    void display();
    friend vector operator*(int a, vector b);
    friend vector operator*(vector b, int a);
};

vector :: vector(){
    size = 1;
    capacity = 1;
    v = (int*)(calloc(size, sizeof(int)));
}

vector :: vector(int size){
    for(int i = 0; i < size; i++)
        push_back(0);
}

void vector :: doubleSize(){
    capacity *= 2;
    v = (int*)realloc(v, capacity * sizeof(int));
}

void vector :: push_back(int val){
    if(size == capacity)
        doubleSize();
    v[size++] = val;
}

void vector :: pop_back(){
    if(size == 1) 
        return;
    size--;
}

void vector :: display(){
    for(int i = 1; i < size; i++){
        cout << v[i] << " ";
    }
    cout << "\n";
}

vector operator *(int a, vector b){
    vector c;
    c.size = b.size;
    c.capacity = b.capacity;
    c.v = (int*)(malloc(sizeof(int)*c.size));
    for(int i = 0; i < b.size; i++){
        c.v[i] = a * b.v[i];
    }
    return c;
}

vector operator *(vector b, int a){
    vector c;
    c.size = b.size;
    c.capacity = b.capacity;
    c.v = (int*)(malloc(sizeof(int)*c.size));
    for(int i = 0; i < b.size; i++){
        c.v[i] = b.v[i] * a;
    }
    return c;
}

int main(){

    vector v;
    v.push_back(1);
    v.push_back(2);
    v.push_back(3);
    v.push_back(4);
    v.push_back(5);
    v.push_back(6);

    v.display();

    v.pop_back();
    v.pop_back();
    v.pop_back();

    v.display();

    vector p, q;
    p = 2 * v;                               // invokes friend 1
    q = v * 2;                               // invokes friend 2

    p.display();
    q.display();
}