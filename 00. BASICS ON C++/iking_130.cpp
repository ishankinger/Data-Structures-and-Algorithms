// PRINTING FACTORIAL OF FIRST N NUMBERS

#include<iostream>
using namespace std;

int main(){
   int N;
   cin>>N;
   for(int i=1;i<=N;i++){
        int factorial=1;
        for(int j=1;j<=i;j++){
            factorial *= j;
        }
        cout<<factorial<<endl;
   }



    // ANY N NUMBER RAISE TO POWER M

    int n=4;
    int m=3;
    int k=1;
    for(int i=1;i<=m;i++){
        k=k*n;
    }
    cout<<k;
}