// ********************** IN A STRING GET THE CHARACTER WHICH HAS HIGHEST FREQUENCY ****************************

#include<iostream>
#include<string>
using namespace std;

int main(){
    string str="abcacbade";                        // A STRING IS GIVEN
    int freq[26];                                  // AN ARRAY OF INTEGER DATATYPE HAVING 26 ELEMENTS IS TAKEN
    for(int i=0;i<26;i++){                         // INITIALLY EACH OF THE ARRAY ELEMENT HAVE VALUE 0
        freq[i]=0;
    }
    for(int i=0;i<str.length();i++){               // NOW IMAGINE THAT EACH NUMBER OF ENGLISH CHARACTER HAVE ONE ELEMENT
        freq[str[i]-'a']++;                        // STR[I]=E THEN E-A MEANS 4th INDEX IS FOR E AND IT WILL BE TAKEN NOW AS 1 AS ++
    }
    char ans='a';
    int maxF=0;

    for(int i=0;i<26;i++){                        // TRAVERSING IN THE FREQUENCY ARRAY
        if(freq[i]>maxF){                         // MAXIMUM OF THE APPEARED WILL BE TRIGGERED
            maxF=freq[i];                         // NUMBER OF FREQUECY WILL TELL HOW MANY TIMES CHAR APPEAR
            ans=i+'a';                            // AND THAT INDEX WHEN ADDED 'A' GIVE THE CAHRACTER APPEARED IN THE ARRAY MAXIMUM TIMES                    
        }
    }
    cout<<ans<<endl;
    cout<<maxF<<endl;

    // SOME THINGS TO UNDERSTAND

    char a=5+'a';
    int b=5+'a';
    cout<<a<<endl;
    cout<<b<<endl;
    return 0;
    // ASCII VALUE OF 'a' IS 97 AND 'z' HAS 122
}
