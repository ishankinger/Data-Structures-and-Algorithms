// ****************** REVERSING THE SENTENCE ********************

#include<iostream>
#include<stack>
using namespace std;

int main(){
    string s="Hey, how are you doing?";
    stack<string>st;
    string newString="";
    for(int i=0;i<=s.size();i++){
        if(s[i]==' ' || i==s.size()){
            st.push(newString);
            newString="";
        }else{
            newString += s[i];
        }
    }
    while(!st.empty()){
        cout<<st.top()<<" ";
        st.pop();
    }
}
