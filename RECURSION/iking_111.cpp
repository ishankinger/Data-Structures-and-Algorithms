// REMOVE ALL THE OCCURENCES OF A PARTICULAR CHARACHTER FROM THE STRING

#include<bits/stdc++.h>
using namespace std;

void removeChar(string &str,int n,int idx,char chr,string &newStr){         // IT'S LIKE SIMPLE ITERATION METHOD
    if(n==0) return;
    if(str[idx]==chr) newStr+="";
    else newStr+=str[idx];
    removeChar(str,n-1,idx+1,chr,newStr);                                  // CALLING THE FUNCTION WITH INDEXES INCREMENTED
}
string removeChar2(string &str,int idx,int n,char chr){                    // IT'S PURE RECURSIVE WAY SOLUTION FOR THIS PROBLEM
    if(n==0) return "";
    string curr="";                                                        // EACH TIME CURR STRING MAKE SURE TO CHECK THE CHARACTER
    curr+=str[idx];
    return ((str[idx]==chr)?"":curr)+removeChar2(str,idx+1,n-1,chr);
}
string removeChar3(string &str,char chr){                                  // SIMPLIFIED WAY TO USE A REAL FUNCTION
    if(str.length()==0) return "";
    string restStr=str.substr(1);
    string curr="";
    curr+=restStr[0];
    return ((restStr[0]==chr)?"":curr)+removeChar3(restStr,chr);           // NICE USE OF TERNARY OPERATOR INSTEAD OF USING IF-ELSE
}
int main(){
    string str; cin>>str;
    cout<<str<<"\n";
    char chr; cin>>chr;
    cout<<chr<<"\n";
    string newStr;
    removeChar(str,str.size(),0,chr,newStr);
    cout<<newStr<<"\n";
    cout<<removeChar2(str,0,str.size(),chr)<<"\n";
    cout<<removeChar3(str,chr);
    return 0;
}