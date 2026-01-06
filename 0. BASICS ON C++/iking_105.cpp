// IF ELSE STATEMENT

#include<iostream>
using namespace std;

int main(){
    int a;
    cin>>a;
     
    if(a%2==0){                                       // ONE CONDITION IS GIVEN IN IF()
        cout<<"even number\n";                          // CONDITION TRUE THEN THIS WILL WORK
    }else{
        cout<<"odd number\n";                           // CONDITION FALSE THEN THIS WILL WORK
    }
    int x,y;
    x=30;
    y=90;
    if(x*y==540 && y-x==60){                          // HERE WHOLE CONDITION BECOMES FALSE AS ONE IS FALSE AND && IS USED SO FALSE
        cout<<"hurrah\n";
    }else{
        cout<<"alas\n";                                 // THIS WILL PRINT
    }
    if(x*y==540 || y-x==60){                          // HERE WHOLE CONDITION BECOMES TRUE DUE TO OR OPERATOR
        cout<<"hurrah\n ";                               // SO THIS WILL WORK
    }else{
        cout<<"alas\n";
    }
    return 0;
}