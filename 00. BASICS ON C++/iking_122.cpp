// NUMERICAL RECTANGULAR PATTERN

#include<iostream>
using namespace std;

int main(){
    for(int i=1;i<=7;i++){
        for(int j=i;j<=6;j++){
            cout<<j<<" ";
        }
        cout<<"7 ";

        for(int j=1;j<=i-1;j++){             // HERE FOR I=1 THERE WILL BE NO VALID CONDITION SO NOTHING WILL PRINT AND THATS WE WANT
            cout<<j<<" ";
        }
        cout<<endl;
    }
    
    // FLOYD'S TRIANGLE

    int count=0;
    for(int i=1;i<=5;i++){
        for(int j=1;j<=i;j++){
            cout<<count<<" ";
            count++;
        }
        cout<<endl;
    }
}