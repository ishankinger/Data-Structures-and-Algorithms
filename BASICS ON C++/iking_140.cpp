// DEFAULT PARAMETER VALUE

#include<iostream>
using namespace std;

int add(int num1, int num2=0, int num3=4){
    int sum= num1+num2+num3;
    return sum;
}
int main(){
   int sum= add(5);                                   // SO HERE BY DEFAULT NUM2 WILL BE GIVEN AS OTHER TWO ARE FILLED ALREADY
   cout<<sum<<endl;
   cout<<add(5,8);
}