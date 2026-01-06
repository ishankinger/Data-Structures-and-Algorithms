// GIVEN A STRING REPLACE ALL THE "PI" WITH 3.14

#include<bits/stdc++.h>
using namespace std;

void replacePI(string str,int n,int idx,string &newStr){
    if(n==1) return;
    if(str[idx]=='p' && str[idx+1]=='i') newStr+="3.14",idx++;
    else newStr+=str[idx];
    replacePI(str,n-1,idx+1,newStr);
}

void replacePi(string s){                           // FUNCTION TO REPLACE PI WITH 3.14
    if(s.length()==0){                              // BASE CONDITION 
        return;                                     // IF STRING BECOME EMPTY THEN RETURN
    }
    if(s[0]=='p' && s[1]=='i'){                     // IF CONSECUTIVE STRING CHARCTERS ARE P AND I
        cout<<"3.14";                               // THEN PRINT 3.14
        replacePi(s.substr(2));                     // AND THEN CALL FUNCTION FOR STRING EXCEPT THAT TWO NUMBERS
    }else{
        cout<<s[0];                                 // IF NOT THEN PRINT THAT CHARACTER
        replacePi(s.substr(1));                     // AND CALL FUNCTION FOR STRING EXCEPT ONE NUMBER
    }
}

// ****substr()*****
// INSTEAD OF USING INDEX INCREMENT OPERATOR WE WILL USE THIS SUBSTR FUNCTION TO TRAVERSE IN A STRING
// IT MAKES THE FUNCTION PARAMETERS BETTER AND SYSTEMATIC AND EASY TO CALL

string replacePi2(string s){
    if(s.length()==0) return "";
    if(s[0]=='p' && s[1]=='i') return "3.14"+replacePi2(s.substr(2));
    else return s[0]+replacePi2(s.substr(1));
}

int main(){
    string str; cin>>str;
    cout<<str<<"\n";
    cout<<replacePi2(str);
    return 0;
}