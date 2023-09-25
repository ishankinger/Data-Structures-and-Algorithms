// EVALUATION OF INFIX EXPRESSION
// SO FOR INFIX EXPRESSION WE WILL BE SIMPLY USING BODMAS AND PRECEDENCE PROPERTIES
// FOR THIS WE WILL BE USING TWO STACKS ==> FIRST STACK WILL ONLY STORE DIGIT AND OTHER STACK WILL ONLY STORE THE OPERATORS
// SO IF WHILE ADDING OPERATORS WE WILL BE ADDING ACCORDING TO PREDENCE
// MEANS IF WE GET + - AND * OR / IS PRESENT THEN FIRST THEY WILL OPERATE ON GIVEN DIGITS (TOP AND TOP-1) AND THEN AT END WE WILL ADD THEM
// ALSO FOR BRACKET IF WE GET CLOSING BRACKET THEN WE WILL TRAVESE BACK IN STACK AND SOLVE AS SAME WITH PRECEDNCE

#include<bits/stdc++.h>
using namespace std;

int calculate(int v1,int v2,char op){                         // FUNCTION TO CALCULATE BASIC OPERATIONS
    if(op=='^') return pow(v1,v2); 
    else if(op=='/') return v1/v2;
    else if(op=='*') return v1*v2;
    else if(op=='+') return v1+v2;
    else return v1-v2;
}

int precedence(char ch){                                      // FUNCTION TO GIVE PRECEDENCE ORDER
    if(ch=='^') return 3;
    else if(ch=='*' || ch=='/') return 2;
    else if(ch=='+' || ch=='-') return 1;
    else return -1;
}

int eval(string &str){
    stack<int>nums;
    stack<int>ops;
    for(int i=0;i<str.size();i++){
        if(isdigit(str[i])) nums.push(str[i]-'0');             // DIGITS PUSHED INTO NUM STACK
        else if(str[i]=='(') ops.push(str[i]);                 // OPENING BRACKET PUSHED INTO OPS STACK
        else if(str[i]==')'){                                  // IF WE GET CLOSING BRACKET
            while(not ops.empty() && ops.top()!= '('){         // THEN WE WILL APPLY OPERATIONS ON TOP TWO ELEMENTS OF NUM WITH TOP OPERAND 
                char op=ops.top();                             // THIS LOOP WILL STOP WHEN WE WILL GET OPENING BRACKET
                ops.pop();
                int v2=nums.top();
                nums.pop();
                int v1=nums.top();
                nums.pop();
                nums.push(calculate(v1,v2,op));
            }
            if(not ops.empty()) ops.pop();                    // REMOVING THE OPENING BRACKET FROM THE OPS STACK
        }else{
            while(not ops.empty() and precedence(ops.top())>=precedence(str[i])){   // FOR SIMPLE OPERATIONS WE WILL APPLY ACCORDING TO PRECEDENCE
                char op=ops.top();
                ops.pop();
                int v2=nums.top();
                nums.pop();
                int v1=nums.top();
                nums.pop();
                nums.push(calculate(v1,v2,op));
            }
            ops.push(str[i]);
        }
    }
    while(not ops.empty()){
        char op=ops.top();
        ops.pop();
        int v2=nums.top();
        nums.pop();
        int v1=nums.top();
        nums.pop();
        nums.push(calculate(v1,v2,op));
    }
    return nums.top();
}

int main(){
    string str="1+(2*(3-1))+2";
    cout<<eval(str)<<"\n";
    return 0;
}