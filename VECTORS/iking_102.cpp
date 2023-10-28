// ******************* INPUTS FROM THE ARRAY ********************
#include<iostream>
using namespace std;

int main(){
    char vowels[5];                            // DEFINING ARRAY OF SIZE 5
    for(int i=0;i<5;i++){
        cin>>vowels[i];                        // TAKING INPUT AS ARRAY
    }

    // ******** USING 'FOR EACH' LOOP ALSO **********
    
    for(char &letter:vowels){                  // AMPERSANT OPERATOR IS MUST FOR 'FOR EACH LOOP'
        cin>>letter;                           // OTHERWISE IT WILL SHOW EROR
    }
    cout<<"Your given character array is :- ";
    for(char letter:vowels){
        cout<<letter<<" ";
    }
}
