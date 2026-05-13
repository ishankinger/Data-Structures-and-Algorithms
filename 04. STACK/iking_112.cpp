// ********************* EVALUATION OF A POSTFIX EXPRESSION ***********************

// 2 3 1 * + 9 -
// 2 (3*1) + 9 - ==> 2 3 + 9 - ==> (2+3) 9 - ==> 5 9 - ==> (5-9)==-4
// SO WHENEVER ANY OPERATOR IS COMING WE ARE APPLYING THAT ON IT'S PREVIOUS TWO OPERANDS

// SO THIS THING CAN BE DONE EASILY WITH THE HELP OF STACK DATASTRUCTURE
// THAT IS SO BECAUSE WHENEVER WE ARE ENCOUNTERING DIGIT WE WILL PUSH IT INTO THE STACK
// IF OPERAND COMES THEN APPLY IN ONLY TOP AND TOP-1 ELEMENT AND RESULT WILL PUSH INTO THE STACK
// THE SECOND POPPED ELEMENT WILL BE THE FIRST OPERAND AND OTHER WILL BE SECOND OPERAND
// THIS THING WILL CONTINUE TILL WE REACH END AND ONLY ONE ELEMENT WILL REMAIN IN THE STACK AS OUR POSTFIX ANSWER

#include <iostream>
#include <stack>
#include <math.h>
#include <vector>
#include <string>
#include <algorithm>
#include <limits.h>
using namespace std;

int calculate(int v1,int v2,char op){
    if(op=='^') return pow(v1,v2);
    else if(op=='/') return v1/v2;
    else if(op=='*') return v1*v2;
    else if(op=='+') return v1+v2;
    else return v1-v2;
}

int eval(string &str){
    stack<int>st;
    int n = str.size();
    for(int i=0;i<n;i++){
        char chr=str[i];
        if(isdigit(chr)) st.push(chr-'0');
        else{
            if(st.empty()){                           
                cout<<"Input Error"<<"\n";
                return INT_MAX;
            }
            int v2=st.top();
            st.pop();
            if(st.empty()){
                cout<<"Input Error"<<"\n";
                return INT_MAX;
            }
            int v1=st.top();
            st.pop();
            st.push(calculate(v1,v2,chr));
        }
    }
    int ans = st.top();
    st.pop();
    if(! st.empty()){
        cout<<"Input Error"<<"\n";
        return INT_MAX;
    }
    return ans;
}

int main(){

    string str="231*+9-4+54-+7913-+**";
    cout<<eval(str)<<"\n";
    
    return 0;
}
