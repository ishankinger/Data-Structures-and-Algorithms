// AMPRESENT OPERATOR ( SIMPLY GIVES THE ADDRESS OF ANY VARIABLE STORED IN THE MEMORY )

#include<iostream>
using namespace std;

int main(){
    int p=5;
    int r=p;
    int &q=p;                                  // THIS IMPLIES THAT BOTH ARE GIVEN THE SAME LOCATION                           
    q=q+1;                                       // Q IS ADDED BY 1 BUT P WILL ALSO BECOME 6
    
    cout<<p<<endl;                             // SO HERE 6 WILL BE PRINTED
    cout<<q<<endl;
    cout<<r<<endl;
    
    cout<<&p<<endl;                            // CAN ALSO BE USED TO CHECK ADDRESS OF THE MEMORY
    cout<<&q<<endl;                            // BOTH WILL SHOW SAME PROCESS
    cout<<&r<<endl;
}