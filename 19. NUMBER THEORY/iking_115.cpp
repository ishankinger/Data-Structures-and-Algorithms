// PRIME NUMBERS THEORY

#include<bits/stdc++.h>
using namespace std;

bool isPrime(int a){                                // A FUNCTION TO CHECK A NUMBER IS PRIME OR NOT  
    if(a==0 || a==1) return false;
    for(int i=2;i*i<=a;i++){                        // WE WILL GO TILL ROOT OF THE ELEMENT AND IF %I==0 FALSE ELSE TRUE
        if(a%i==0) return false;
    }
    return true;
}

vector<int> primeFactors(int a){                    // FUNCTION THAT WILL RETURN PRIME FACTORS OF A NUMBER
    vector<int>v;                                   // VECTOR DEFINED TO STORE THE NUMBERS
    for(int i=2;i<=sqrt(a);i++){                    // WILL TRAVERSE TILL SQRT OF NUM
        while(a%i==0){                              // IF GIVEN NUMBER DIVISIBLE THEN PUSH BACK 
            v.push_back(i);
            a/=i;                                   // AND ALSO MAKE NEW A BY UPDATING IT ACCORDING TO CONDITION
        }
    }
    if(a>1) v.push_back(a);                        // IF STILL A>1 MEANS LEFT A IS PRIME NUMBER SO DIRECTLY PUSHED BACK
    return v;
}

int main(){
    int a; cin>>a;
    
    if(isPrime(a)) cout<<"It is a prime number\n";
    else cout<<"It is not a prime number\n";

    vector<int>primefact=primeFactors(a);
    for(int i=0;i<primefact.size();i++) cout<<primefact[i]<<" ";

    return 0;
}