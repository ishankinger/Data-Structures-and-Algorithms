// A ENGLISH CHARACTER IS CONSONANT OR VOWEL

#include<iostream>
using namespace std;

int main(){
    char character;
    cin>>character;
    
    switch(character){                               // ANY VARIABLE NAME CAN BE WRITTEN IN SWITCH
        case 'a':                                    // ACCORDING TO VARIABLE DATATYPE CASE _ DASH SHOULD BE FILLED
        cout<<"its a vowel";
        break;                                       
        case 'e':
        cout<<"its a vowel";
        break;
        case 'i':
        cout<<"its a vowel";
        break;
        case 'o':
        cout<<"its a vowel";
        break;
        case 'u':
        cout<<"its a vowel";
        break;
        default :
        cout<<"its a consonant";
    }
    return 0;
}