// REVERSE A STRING USING RECURSION

#include<bits/stdc++.h>
using namespace std;

void reverseStr(string str,int n,int idx,string &newStr){
    if(n==0) return;
    reverseStr(str,n-1,idx+1,newStr);
    newStr+=str[idx];
}
string reverseStrBetter(string str,int n,int idx){
    if(n==0) return "";
    string curr="";
    curr+=str[idx];
    return reverseStrBetter(str,n-1,idx+1) +curr;
}
void reverseBest(string str){                         // FUNCTION TO REVERSE THE STRING
    if(str.length()==0){                              // BASE CONDITION 
        return;                                       // IF ALL ELEMENTS REMOVED THEN WE WILL RETURN
    }
    string restStr= str.substr(1);                    // .SUBSTR(I) --> STRING AFTER Ith INDEX WILL COME IN THIS STRING
    reverseBest(restStr);                             // CALLING THE FUNCTION AGAIN TO MAKE STACKS
    cout<<str[0];                                     // AND AFTER RETURN EACH ELEMENT WILL BE PRINTED IN REVERSE ORDER
}
int main(){
    string str; cin>>str;
    cout<<str<<"\n";
    string newStr="";
    reverseStr(str,str.size(),0,newStr);
    cout<<newStr<<"\n";
    cout<<reverseStrBetter(str,str.size(),0)<<"\n";
    reverseBest(str);
    return 0;
}