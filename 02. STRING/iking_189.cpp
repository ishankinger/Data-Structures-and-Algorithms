// // DECODING OF THE STRING OF ENCODED STRING
// // IN SQUARE BRACKETS STRING IS GIVEN AND OUT OF THAT A NUMBER IS GIVEN
// // IT DECODES THAT THE STRING OCCURS THAT NUMBER OF TIMES
// // EXAMPLE--  3[B2[CA]]==> BCACABCACABCACA

#include<bits/stdc++.h>
using namespace std;

string decodedString(string &s){
    string result="";
    for(int i=0;i<s.size();i++){                                                 // TRAVERSING IN THE STRING
        if(s[i]!=']'){                                                           // IF WE ARE NOT GETTING CLOSING BRACKET THEN MOVE                                                       
            result+=s[i];                                                        // AND ADD CHARACTERS IN RESULT
        }else{                                                                   // ELSE
            string str="";                                                       // STR STRING TO TAKE STRING INSIDE BRACKET WHICH TO BE REPEATED
            while(!result.empty() && result.back()!='['){                        // TILL IT NOT REACHES '[' THERE WILL BE SOME ELEMENTS OF ALPHABERS
                str.push_back(result.back());                                    // THESE WILL BE PUSHED BACK IN THE STRING STR
                result.pop_back();                                               // THE CHARACTER ADDED WILL SIMUTANEOUSLY BE REMOVED
            }
            reverse(str.begin(),str.end());                                      // WE GET REVERSE STRING SO MAKING IT IN ORDER
            result.pop_back();                                                   // '[' THIS BRACKET TO BE REMOVED
            string num="";                                                       // NOW MAKING A STRING TO STORE NUM FOR FREQUENCY OF STRING
            while(!result.empty() && result.back()>='0' && result.back()<='9'){  // CHECKING THAT NUMBER IS INTEGER CHARACTER OR NOT
                num.push_back(result.back());                                    // PUSH BACK THAT NUMBER IN THE STRING
                result.pop_back();                                               // SIMUTANEOUSLY POP OUT THE NUMBER ADDED
            }
            reverse(num.begin(),num.end());                                      // NOW MAKING IN ORDER THE INTEGER STRING
            int int_num=stoi(num);                                               // CONVERTING THE INT STRING INTO INT USING STOI FUNCTION
            while(int_num){                                                      // NOW GOING IN A LOOP TILL INT_NUM!=0
                result+=str;                                                     // ADD STORED STRING INT_NUM TIMES
                int_num--;                                                       // DECREMENTING INT_NUM AFTER EACH ADDITION OF STRING
            }
        }
    }
    return result;                                                               // RETURN THE DECODED STRING AT THE END
}
int main(){
    string str; cin>>str;

    cout<<decodedString(str)<<endl;
    return 0;
}

// ISHAN'S SPECIAL ----

#include<bits/stdc++.h>
using namespace std;

int main(){
    string s; cin>>s;
    for(int i=0;i<s.size();i++){
        if(s[i]==']'){
            string str;
            int j=i-1;
            for(;j>=0;j--){
                if(s[j]=='[') break;
                else str=s[j]+str;
            }
            j--;
            int num=s[j]-'0';
            s.erase(j,str.size()+3);
            while(num--){
                s.insert(j,str);
                j+=str.size();
            }
            i=j-1;
        }
    }
    cout<<s<<"\n";
    return 0;
}