// CONVERSION OF A PREFIX EXPRESSION TO A POSTFIX EXPRESSION AND VICE VERSA
// PREFIX EXPRESSION ==> * + 3 2 - 1 5
// POSTFIX EXPRESSION ==> 3 2 + 1 5 - *

#include<bits/stdc++.h>
using namespace std;

// PREFIX TO POSTFIX

string preToPost(string & pre){
    stack<string>st;
    reverse(pre.begin(),pre.end());
    for(int i=0;i<pre.size();i++){
        if(isdigit(pre[i])) st.push(to_string(pre[i]-'0'));
        else{
            string v1=st.top();
            st.pop();
            string v2=st.top();
            st.pop();
            string newexp=v1+v2+pre[i];
            st.push(newexp);
        }
    }
    return st.top();
}

// POSTFIX TO PREFIX

string postToPre(string &post){
    stack<string> st;
    for(int i=0;i<post.size();i++){
        if(isdigit(post[i])) st.push(to_string(post[i]-'0'));
        else{
            string v1 = st.top();
            st.pop();
            string v2 = st.top();
            st.pop();
            string newExp = post[i]+v1+v2;
            st.push(newExp);
        }
    }
    return st.top();
}

int main(){
    string s="*+32-15";
    cout<<preToPost(s)<<"\n";
    cout<<postToPre(s);

    return 0;
}