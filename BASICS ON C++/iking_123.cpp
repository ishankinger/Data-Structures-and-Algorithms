// 1-2 RECTANGLE

#include<iostream>
using namespace std;

int main(){
    for(int i=1;i<=5;i++){
        for(int j=1;j<=5;j++){
            if((i+j)%2==0){
                cout<<"1 ";
            }else{
                cout<<"2 ";
            }
        }
        cout<<endl;
    }
    // 0-1 TRIANGLE

    for(int i=1;i<=5;i++){
        for(int j=1;j<=i;j++){
            if((i+j)%2==0){
                cout<<"0 ";
            }else{
                cout<<"1 ";
            }
        }
        cout<<endl;
    }
}