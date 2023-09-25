// HOLLOW RECTANGULAR PATTERN

#include<iostream>
using namespace std;

int main(){
    for(int i=1;i<6;i++){
        for(int j=1;j<5;j++){
            if(i==1 || i==5 || j==1 || j==4){
                cout<<"*";
            }else{
                cout<<" ";
            }
        }
        cout<<endl;
    }

// HOLLOW RHOMBUS PATTERN
    
    for(int i=1;i<=5;i++){
        for(int j=1;j<=5-i;j++){
            cout<<" ";
        }
        for(int j=1;j<=5;j++){
            if(i==1 || i==5 || j==1 || j==5){
                cout<<"*";
            }else{
                cout<<" ";
            }
        }
        cout<<"\n";
    }
    return 0;
}