// NESTED IF ELSE STATEMENT

#include<iostream>
using namespace std;

int main(){
    int marks;
    cin>>marks;

    if(marks>33){
        if(marks>80){
            cout<<"gracefully passed";
        }else{
            cout<<"passed";
        }
    }else{
        cout<<"failed";
    }
    return 0;
}
    