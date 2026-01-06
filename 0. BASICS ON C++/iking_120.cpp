// INVERTED TRIANGULAR PATTERN

#include<iostream>
using namespace std;

int main(){
    for(int i=1;i<=7;i++){
        for(int j=1;j<=8-i;j++){
            cout<<"*";
        }
        cout<<endl;
    }
// INVERTED NUMBER TRIANGLE
    
     for(int i=1;i<=7;i++){
        for(int j=1;j<=8-i;j++){
            cout<<j;
        }
        cout<<endl;
    }
    return 0;
}