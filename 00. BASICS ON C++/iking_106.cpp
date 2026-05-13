// IF - ELSE IF STATEMENTS

#include<iostream>
using namespace std;

int main(){
    int marks;
    cin>>marks;

    if(100>=marks>80){
        cout<<"A";
    }else if(80>marks>60){
        cout<<"B";
    }else if(60>marks>40){
        cout<<"C";
    }else if(marks<=40){
        cout<<"D";
    }else{
        cout<<"F";
    }
    return 0;
}