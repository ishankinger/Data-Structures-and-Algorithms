// UNIONS
// ONLY ONE VARIABEL TO BE USED FROM ALL THE VARIABLES IN UNIONS SO IT SAVES THE HIGHEST OF THE DATATYPES MEMORY

#include<iostream>
using namespace std;

union money{                                           // AN UNION DATATYPE IS FORMED                         
    int rice;                                          // DIFFERENT  TYPE OF VARIABLES ARE DEFINED IN IT
    char car;
    float ruppees;
};                                                     // USE SEMICOLON AFTER CURLY BRACKETS 
                                                                                        
int main(){
    union money m1;                                    // AN OBJECT IS FORMED 
    m1.rice=34;
    cout<<m1.rice<<endl;
    return 0;
}
// IN ABOVE EXAMPLE MEMORY STORED IS 4 BYTES WHICH IS HIGHEST OF ALL DATATYPES
// STRINGS CANNOT BE USED IN THIS AS THEY DONOT HAVE CONSTANT MEMORY SO IT WILL SHOW EROR TO OUR OBJECT