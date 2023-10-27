// **************** REDUNDANT PARANTHESIS ***********************
// FOR A MATHEMETICAL EXPRESSION CONTAINING + - * / WE HAVE TO TELL WHETHER EXTRA BRACKETS ARE USED OR NOT

// ex.1 => ((a+b)) ans=1
// ex.2 => (a+(a+b)) ans=0

// WE WILL APPROACH THIS QUESTION WITH THE HELP OF STACK
// WHENEVER WE WILL GET OPENING BRACKET AND OPERATOR WE WILL PUSH THAT INTO OUR STACK
// WHEN CLOSING BRACKET COMES THEN THERE MUST BE ONE OPERATOR AND OPENING BRACKET PRESENT
// IF NOT THEN IT IS REDUNDANT

#include<bits/stdc++.h>
using namespace std;

int main(){
    string s; cin>>s;
    stack<char>st;
    bool ans=false;
    for(int i=0;i<s.size();i++){
        if(s[i]=='+'||s[i]=='-'||s[i]=='*'||s[i]=='/'||s[i]=='('){
            st.push(s[i]);
        }else if(s[i]==')'){
            if(st.top()=='(') ans=true;
            while(st.top()=='+' or st.top()=='-' or st.top()=='*' or st.top()=='/' ) st.pop();
            st.pop();
        }
    }
    cout<<ans<<"\n";

    return 0;
}
