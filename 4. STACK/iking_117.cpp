// ********************** CONVERSION OF INFIX TO PREFIX ***********************

// FIRST REVERSE THE WHOLE STRING AND THEN TRAVERSE ONCE TO CONVERT OPENING BRACKET TO CLOSING AND VICE VERSA
// THEN ALL THE THING WHICH WE HAVE DONE FOR POSTFIX CAN BE APPLIED HERE
// THEN OUR RESULTING STRING WILL BE RETURNED BY REVERSING IT

#include <iostream>
#include <stack>
#include <math.h>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

// FUNCTION TO GIVE PRECEDENCE ORDER
int precedence(char ch){                                      
    // PRECEDENCE ORDER -->  (^)  >  (*,/)  >  (+,-)  
    // AND WHEN WE HAVE SAME PRECEDENCE THEN WE WILL APPLY OPERATIONS FROM LEFT TO RIGHT IN THESE OPERATORS
    if(ch=='^') return 3;
    else if(ch=='*' || ch=='/') return 2;
    else if(ch=='+' || ch=='-') return 1;
    else return -1;
}

string Infix_To_Prefix(string &str){
    int n = str.size();
    // ONLY CHANGE FOR INFIX TO PREFIX
    reverse(str.begin(),str.end());
    for(int i=0;i<n;i++){
        if(str[i] == ')') str[i] = '(';
        else if(str[i] == '(') str[i] = ')';
    }

    // ONE EMPTY STACK IS CREATED FOR STORING OPERATORS
    stack<char> ops;
    // OUTPUT STRING IS CREATED
    string nums = "";

    // GOING IN LOOP FROM LEFT TO RIGHT FOR ASSOSCIATIVITY
    for(int i=0;i<n;i++){

        // DIGITS PUSHED INTO NUM STACK
        if(isdigit(str[i])) nums.push_back(str[i]); 

        // OPENING BRACKET PUSHED INTO OPS STACK AND FOR IT'S PRECEDENCE IS DEFINED TO BE -1 
        // SO NO OPERATOR WILL WORK WHEN THIS IS AT TOP
        else if(str[i]=='(') ops.push(str[i]);    

        // IF WE GET CLOSING BRACKET THEN WE WILL APPLY OPERATIONS ON TOP TWO ELEMENTS OF NUM WITH TOP OPERAND
        else if(str[i]==')'){ 

            // THIS LOOP WILL END WHEN WE WILL GET CLOSING BRACKET                         
            while(!ops.empty() && ops.top()!= '('){         
                nums.push_back(ops.top());
                ops.pop();
            }

            // REMOVING THE OPENING BRACKET FROM THE OPS STACK
            if(!ops.empty()) ops.pop();  

        // FOR SIMPLE OPERATIONS WE WILL APPLY ACCORDING TO PRECEDENCE
        }else{               

            // THIS WHILE LOOP SHOULD ONLY WORK WHEN WE ARE GETTING LESS PRECEDENCE ELEMENT THAN ON TOP OF STACK ,OR STACK IS EMPTY
            while(!ops.empty() && precedence(ops.top())>=precedence(str[i])){   
                nums.push_back(ops.top());
                ops.pop();
            }

            // THE CURRENT STRING WILL THEN BE PUSHED
            ops.push(str[i]);
        }
    }

    // AFTER THE ONE TRAVERSAL THERE IS A POSSIBILITY THAT STACK IS NOT COMPLETELY CALCULATED IF OPERATIONS STACK IS NOT EMPTY
    // SO WE WILL AGAIN TRAVERSE TILL OPERATION STACK BECOMES EMPTY
    while(!ops.empty()){
        nums.push_back(ops.top());
        ops.pop();
    }

    // THE TOP ELEMENT IN THE OPERAND STACK WILL BE OUR FINAL ANSWER
    reverse(nums.begin(),nums.end());
    return nums;
}

int main(){
    string str = "(1+2)*3-4";
    cout<<Infix_To_Prefix(str);
    return 0;
}


// ************************ CONVERSION OF PREFIX TO INFIX *********************************
class Solution {
  public:
    string preToInfix(string pre_exp) {
        int n = pre_exp.size();
        stack<string> st;
        for(int i = n-1; i >= 0; i--){
            if(pre_exp[i] == '^' || pre_exp[i] == '*' || pre_exp[i] == '/' || pre_exp[i] == '+' || pre_exp[i] == '-'){
                string st1 = st.top(); st.pop();
                string st2 = st.top(); st.pop();
                string mid = ""; mid.push_back(pre_exp[i]);
                string newSt = "(" + st1 + mid + st2 + ")";
                st.push(newSt);
            }
            else{
                string mid = ""; mid.push_back(pre_exp[i]);
                st.push(mid);
            }
        }
        string in_exp = st.top(); st.pop();
        return in_exp;
    }
};