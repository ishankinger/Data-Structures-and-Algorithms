// *************** EVALUATION OF PREFIX EXPRESSIONS ********************

// TRAVERSE FROM BACK OF THE EXPRESSION AND APPLY SAME LOGIC OF POSTFIX
// - 9 + * 5 3 1
// - 9 + (5*3) 1 ==> - 9 + 15 1 ==> - 9 (15+1) ==> - 9 16 ==> 7

// SO IT'S SIMPLY THE REVERSE OF POSTFIX EXPRESSIONS

#include<bits/stdc++.h>
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
    for(int i=str.size()-1;i>=0;i--){
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
    if(not st.empty()){
        cout<<"Input Error"<<"\n";
        return INT_MAX;
    }
    return ans;
}

int main(){
    string str="-9+*531";
    cout<<eval(str)<<"\n";
    return 0;
}
