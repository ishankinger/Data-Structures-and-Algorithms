// FUNCTIONS PROTOTYPE

#include<iostream>                             // THOUGH WE HAVE TO USE FUNCTION OTHER THAN MAIN ABOVE THE MAIN FUNCTION
using namespace std;                           // BUT THERE CAN BE SUBSITUTE WAY OF THAT TO USE FUNCTIONS PROTOTYPE

int add(int num1,int num2);                    // THIS IS FUCNTION PROTOTYPE
                                               // SO BY USING THIS THIS WILL WORK
int main(){                                    // MAIN FUNCTION
    cout<<add(2,3);
}
int add(int num1,int num2){                   // FUNCTION OF ADD USE AFTER MAIN FUNCTION
    int sum=num1+num2;
    return sum;
}