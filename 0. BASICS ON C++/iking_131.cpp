// FUNCTIONS( OTHER THAN MAIN FUNCTIONS )
// ALSO CONCEPT OF FUNCTION OVERLOADING

#include<iostream>
using namespace std;

int add(int num1, int num2){                            // THESE FUNCTIONS MUST TO DEFINE ABOVE THE MAIN FUNCTION
    int sum= num1+num2;                                 // FUNCTION NAME ADD AND TWO INT PARAMETERS
    return sum;
}
int add(int num1, int num2, int num3){                  // FUNCTION NAME ADD BUT THREE INT PARAMETERS SO 
    int sum= num1+num2+num3;                            // DIFFERENT FROM FIRST ONE
    return sum;
}
float add(float num1, float num2){                      // NAME ADD BUT DATATYPE OF VARIABLE IS DIFFERENT
    float sum= num1+ num2;                              // SO DIFFERENT FROM OTHER TWO
    return sum*10;
}
int main(){

    cout<<add(2,4)<<endl;
    cout<<add(2,3,4)<<endl;
    cout<<add(2.1f,4.5f);
    return 0;
}