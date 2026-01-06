// *************** DIFFERENT OPERATIONS ON STRINGS *********************

#include<iostream>
#include<string>
#include<bits/stdc++.h>
using namespace std;

int main(){
    string str="aaaa";

    string s1="fam";                               // DEFINING FIRST STRING
    string s2="ily";                               // DEFINING SECOND STRING

    cout<<s1+s2<<endl;                             // ADDITION WILL GIVE A NEW STRING
    
    cout<<s1<<endl;
    s1.append(s2);                                 // APPEND OPERATOR--> S2 IS ADDED IN S1
    cout<<s1<<endl;                                // HERE S1 IS CHANGED

    cout<<s1[1]<<endl;                             // ANY CHARACTER OF THE STRING CAN BE OBTAINED USING STRING_NAME[INDEX]
    cout<<s2[4]<<endl;                             // DON'T USE DOT AND USE SQUARE BRACKETS
    
    cout<<s1.empty()<<endl;                        // EMPTY OPERATOR--> CHECK WHETHER STRING HAS CHARACTERS OR NOT
    s1.clear();                                    // CLEAR OPERATOR--> CLEAR ALL THE ELEMENTS IN THE SRING
    cout<<s1<<endl;                                // SO NOTHING WILL BE PRINTED
    cout<<s1.empty()<<endl;                        // NOW HERE IT IS TRUE SO 1 WILL BE PRINTED

    s1.append("fam");                              // APPEND CAN BE OF ANY STRING GIVEN BY ITSELF ALSO LIKE THAT SHOWN
    cout<<s1<<endl;
                                                   // .COMPARE FUNCTION IF FIRST > SECOND(IN BRACKET) ===> PRINT -1 OTHERWISE +1
    cout<<str.compare(s1)<<endl;                   // COMPARE USING ALPHABETICAL ORDER

    string s3="fam";
    cout<<s1.compare(s3)<<endl;                    // IF BOTH OF THEM ARE EQUAL IN .COMPARE OPERATOR THEN 0 WILL BE PRINTED  

    if(s1.compare(s3)){                            // 0 MEANS FALSE SO ELSE STATEMENT SHOULD BE PRINTED
        cout<<"ishan is good person"<<endl;
    }else{
        cout<<"ishan has a good heart"<<endl;
    }   
    if(!s1.compare(s3)){                           // HERE DUE TO NOT FALSE BECOME TRUE HENCE FIRST STATEMENT WILL BE PRINTED
        cout<<"ishan is good person"<<endl;
    }else{
        cout<<"ishan has a good heart"<<endl;
    } 

    string s4="ishan is a good boy"; 
    string s5="ishan is not a good boy";         
    s4.insert(10," very");                         // INSERT OPERATOR--> INDEX AFTER WHICH STRING TO BE INSERTED AND "GIVE STRING"
    cout<<s4<<endl;                                // INDEXING IN STRINGS IS ALSO ZERO INDEXED

    s4.erase(6,4);                                 // ERASE OPERATOR--> FIRST INDEX FROM WHERE WE SHOULD START ERASING ELEMENTS 
    cout<<s4<<endl;                                // AND THEN WE HAVE TO WRITE NO. OF CHARACTERS
    s5.erase(6);                                   // IF NUMBER OF CHARACTERS ARE NOT MENTIONED THEN ALL CHARACTERS AFTER THAT WILL BE ERASED
    cout<<s5<<endl;                                // NOW ONLY ISHAN WILL BE PRINTED

    cout<<s4.find(" good ")<<endl;                 // IF WORD FOUND IN THE STRING THEN RETURN THE INDEX OF FIRST CHARACTER OF THE WORD IN STRING                      

    cout<<s4.size()<<endl;                         // TO GET TOTAL NUMBER OF CHARACTER WE CAN USE .SIZE() OR .LENGTH() OPERATOR
    cout<<s4.length()<<endl;                       // ALSO THE SPACES IN THE STRING WILL ALSO BE REGARDED AS CHARACTER

    for(int i=0;i<s1.length();i++){                // WE CAN ALSO USE ITERATIVE METHODS IN THE STRINGS
        cout<<s1[i];                               // .LENGTH() OPERATOR IS ALSO USED HERE
    }
    cout<<endl;

    string s= s4.substr(3,5);                      // SUBSTRING--> FIRST PUT STARTING INDEX AND THEN NUMBER OF CHARACTERS TO BE INCLUDED
    cout<<s<<endl;                                 // SO A NEW STRING OF SMALLER SIZE IS CREATED THAT'S WHY CALLED SUBSTRING

    string s6= "786";                              // A STRING CONTAINING INTEGER CHARACTERS
    int x= stoi(s6);                               // STOI--> CONVERT STRING TO INTEGER DATATYPE
    cout<<x+2<<endl;                               // NOW INT X=786 AND ADDED 2 SO 788 WILL BE PRINTED

    int p= 456;                                    // INTEGER DATATYPE CAN ALSO BE CHANGED TO STRING DATATYPE
    cout<< to_string(p)+"2"<<endl;                 // TO_STRING(VARIABLE)
                                                   // NOW IF "2" IS ADDED THEN IT WILL BE 4562
    string s7;
    s7="ishan";
    reverse(s7.begin(),s7.end());                  // REVERSE FUNCTION AND KEEP IN MIND TO PASS ITERATOR OF THE STRING NOT THE INTEGER VALUES
    cout<<s7<<"\n";
    return 0; 
}
