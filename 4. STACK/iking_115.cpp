// ************************ CONVERSIONS OF PREFIX EXPRESSIONS AND POSTFIX EXPRESSIONS **************************
// PREFIX EXPRESSION ==> * + 3 2 - 1 5
// POSTFIX EXPRESSION ==> 3 2 + 1 5 - *

#include <iostream>
#include <stack>
#include <math.h>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

// *************** PREFIX TO POSTFIX *********************

string prefix_To_Postfix(string & pre){
    int n = pre.size();
    // AN EMPTY STACK OF STRING DATATYPE IS CREATED
    stack<string>st;
    // REVERSE THE STRING
    reverse(pre.begin(),pre.end());
    // GOING IN A LOOP FROM LEFT TO RIGHT
    for(int i=0;i<n;i++){
        // IF CURRENT CHAR IS DIGIT THEN PUSH INTO THE STACK
        if(isdigit(pre[i])) st.push(to_string(pre[i]-'0'));
        // ELSE IF IT IS OPERATOR THEN CONVERT TOP TWO ELEMENTS AND OPERATOR INTO POSTFIX EXPRESSION AND INSERT INTO THE STACK AS A STRING
        else{
            string v1=st.top();
            st.pop();
            string v2=st.top();
            st.pop();
            string newexp=v1+v2+pre[i];
            st.push(newexp);
        }
    }
    // AT END ONLY ONE STRING WILL LEFT WHICH WILL BE OUR FINAL ANSWER EXPRESSION
    return st.top();
}

// ****************** POSTFIX TO PREFIX *************************

string postfix_To_Prefix(string &post){
    int n = post.size();
    // AN EMPTY STACK OF STRING DATATYPE IS CREATED
    stack<string>st;
    // GOING IN A LOOP FROM LEFT TO RIGHT
    for(int i=0;i<n;i++){
        // IF CURRENT CHAR IS DIGIT THEN PUSH INTO THE STACK
        if(isdigit(post[i])) st.push(to_string(post[i]-'0'));
        // ELSE IF IT IS OPERATOR THEN CONVERT TOP TWO ELEMENTS AND OPERATOR INTO PREFIX EXPRESSION AND INSERT INTO THE STACK AS A STRING
        else{
            string v1 = st.top();
            st.pop();
            string v2 = st.top();
            st.pop();
            string newExp = post[i]+v1+v2;
            st.push(newExp);
        }
    }
    // AT END ONLY ONE STRING WILL LEFT WHICH WILL BE OUR FINAL ANSWER EXPRESSION
    return st.top();
}

int main(){
    string s="*+32-15";
    cout<<prefix_To_Postfix(s)<<"\n";
    cout<<postfix_To_Prefix(s)<<"\n";

    return 0;
}


class Solution {
  public:
    string preToPost(string pre_exp) {
        int n = pre_exp.size();
        stack<string> st;
        for(int i = n-1; i >= 0; i--){
            if(pre_exp[i] == '^' || pre_exp[i] == '*' || pre_exp[i] == '/' || pre_exp[i] == '+' || pre_exp[i] == '-'){
                string exp1 = st.top(); st.pop();
                string exp2 = st.top(); st.pop();
                string op = ""; op.push_back(pre_exp[i]);
                string newExp = exp1 + exp2 + op;
                st.push(newExp);
            }
            else{
                string op = ""; op.push_back(pre_exp[i]);
                st.push(op);
            }
        }
        string post_exp = st.top(); st.pop();
        return post_exp;
    }
};

class Solution2 {
  public:
    string postToPre(string post_exp) {
        int n = post_exp.size();
        stack<string> st;
        for(int i = 0; i < n; i++){
            if(post_exp[i] == '^' || post_exp[i] == '*' || post_exp[i] == '/' || post_exp[i] == '+' || post_exp[i] == '-'){
                string exp1 = st.top(); st.pop();
                string exp2 = st.top(); st.pop();
                string op = ""; op.push_back(post_exp[i]);
                string newExp = op + exp2 + exp1;
                st.push(newExp);
            }
            else{
                string op = ""; op.push_back(post_exp[i]);
                st.push(op);
            }
        }
        string pre_exp = st.top(); st.pop();
        return pre_exp;
    }
};