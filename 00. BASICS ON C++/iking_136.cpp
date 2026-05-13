// SCOPE RESOLUTION VARIABLE( GLOBAL VARIABLE OVER LOCAL VARIABLE)

#include<iostream>
using namespace std;

int p=7;
int main(){
    int p=5;
    cout<<::p;                             // BECAUSE OF '::' GLOBAL VARIABLE IS PREFFERED OVER LOCAL VARIABLE
}