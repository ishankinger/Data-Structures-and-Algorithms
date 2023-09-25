// SUM OF DIGITS OF A GIVEN NUMBER N

#include<iostream>
using namespace std;

int main(){
    
    int n=848826491;
    int sum=0;                                             // VARIABLE OF INT SUM
   
    while(n>0){                                            // SIMILAR
        int lastDigit= n%10;                               // VARIABLE OF REMAINDER THAT IS LAST DIGIT OF N NUMBER
        sum=sum+ lastDigit;                                // GETTING ADD IN SUM 
        n=n/10;                                            // IT MAKE NEW NUMBER
    }
   
    cout<<sum;
    return 0;
}

