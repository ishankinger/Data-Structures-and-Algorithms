// *******BALANCED PARATHESIS********
// ( A COMPILER CODE AS COMPILER ALSO DOES THE SAME FOR BRACKETS THAT WE USE IN OUR CODE )
// LAST OPENING BRACKET SHOULD GET FIRST CLOSING BRACKET IN BALANCED PARANTHESIS
//  {[({[]})]}---> THIS WILL BE REGARDED AS BALANCED PARATHESIS

// MAIN APPROACH FOR THIS QUESTION WILL BE THAT WE SHOULD GET OPENING FOR ANY CLOSING BRACKET
// SO IF WE ARE GETTING OPENING BRACKET THEN WE WILL PUSH THAT IN OUR STACK
// AND WE WANT THAT BRACKET TO FIRSTLY GET CLOSING BRACKET TO MAINTAIN BALANCED PARATHESIS
// SO WHENEVER WE GET CLOSING BRACKET WE WILL CHECK TOP OF STACK SO IF THEY ARE EQUAL SO POP IT AS WE GET PAIR
// BUT IF THEY ARE NOT EQUAL THEN IT IS NOT BALANCED HENCE BREAK

#include<bits/stdc++.h>
using namespace std;

int main(){
    int t; cin>>t;
    while(t--){
        string s; cin>>s;
        stack<int>st;
        int i=0;
        bool check=true;
        while(s.size()!=i){
            if(s[i]=='(' || s[i]=='{' || s[i]=='['){
                st.push(s[i]);
                i++;
            }else if(s[i]==')'){
                if(st.top()=='('){
                    st.pop();
                    i++;
                }else{
                    check=false;
                    break;
                }
            }else if(s[i]=='}'){
                if(st.top()=='{'){
                    st.pop();
                    i++;
                }else{
                    check=false;
                    break;
                }
            }else if(s[i]==']'){
                if(st.top()=='['){
                    st.pop();
                    i++;
                }else{
                    check=false;
                    break;
                }
            }
        }
        if(st.size()){
            cout<<"A unbalanced paranthesis\n";
            continue;
        }
        if(check) cout<<"A balanced paranthesis\n";
        else cout<<"A unbalanced parathesis\n";
    }
    return 0;
}