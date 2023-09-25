// SUM OF THE SERIES(1-2+3-4+5-6+7-8+9-..........)

#include<iostream>
using namespace std;

int main(){
    int sum=0;
    for(int i=1;i<=10;i++){                         // GOING IN THE SERIES VIA LOOP
        if(i%2==0){                                 // FROM SERIES EVEN NUMBERS ARE SUBTRACTED
            sum -= i;
        }else{                                      // AND ODD NUMBERS ARE ADDED
            sum += i;
        }
    }
    cout<<sum;
    return 0;
}