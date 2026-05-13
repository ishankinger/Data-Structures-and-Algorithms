// *********** STRINGS ****************
// OUTPUTS AND INPUTS
// NO NEED TO KNOW SIZE BEFOREHEAD
// PERFORMING OPERATIONS LIKE CONCATESATION AND APPEND IS EASIER
// TERMINATED WITH A SPECIAL /0

#include<iostream>
#include<string>                                // HEADER FILE OF A STRING IS TO BE INCLUDED TO USE STRING
using namespace std;

int main(){
      
    string str("ishan");
    cout<<str<<"\n";
    
    string str1(5,'n');                         // ONE WAY TO DEFINE A STRING WHICH MEANS REPEAT CHAR N 5 TIMES
    cout<<str1<<endl;
    
    string str2="ishan kinger";                 // OTHER WAY TO DEFINE STRING
    cout<<str2;

    string str3;                                //  WAY TO TAKE INPUT FROM THE USER
    cin>>str3;
    cout<<str3;

    string str4;                                // FIRST STRING IS DEFINE 
    getline(cin,str4);                          // TO WRITE FULL LINE WE HAVE TO USE GET LINE FUNCTION
    cout<<str4.size()<<endl;

    return 0;
}
