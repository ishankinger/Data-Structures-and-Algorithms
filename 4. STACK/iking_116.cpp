// ***************** CONVERSION OF INFIX TO POSTFIX ************************

// MOVE FROM LEFT TO RIGHT
// IF IT IS AN OPERAND THEN PRINT
// IF IT IS AN OPENING BRACKET INSERT IN STACK
// IF IT IS AN CLOSING BRACKET POP OUT TILL WE GET OPENING BRACKET
// IF OPERATOR THEN POP FROM STACK AND PRINT UNTIL AN OPERATOR WITH LESS PRECEDENCE IS FOUND

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

// HERE WE ARE TAKING ^ AS LEFT ASSOSCIATIVITY BUT IT HAS RIGHT ASSOSCIATIVITY FOR THAT-
// bool isRightAssociative(char op) {
//     return op == '^';
// }

// while (!st.empty() && ((precedence(c) < precedence(st.top())) || (precedence(c) == precedence(st.top()) && !isRightAssociative(c)))) {
//     res += st.top(); st.pop();
// }

string Infix_To_Postfix(string &str){

    // ONE EMPTY STACK IS CREATED FOR STORING OPERATORS
    stack<char> ops;
    // OUTPUT STRING IS CREATED
    string nums = "";

    // GOING IN LOOP FROM LEFT TO RIGHT FOR ASSOSCIATIVITY
    int n = str.size();
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
            while(!ops.empty() && precedence(ops.top()) >= precedence(str[i])){   
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
    return nums;
}


int main(){

    string str = "1*2-(3+4)+5";
    cout<<Infix_To_Postfix(str)<<"\n";

    string str2 = "(1+2)*3-4";
    cout<<Infix_To_Postfix(str2) << "\n";

    string str3 = "5*3/5";
    cout << Infix_To_Postfix(str3) << "\n";

    return 0;
}


// ************************** CONVERSION OF POSTFIX TO INFIX ****************************
class Solution {
  public:
    string postToInfix(string exp) {
        int n = exp.size();
        stack<string> st;
        for(int i = 0; i < n; i++){
            if(exp[i] == '^' || exp[i] == '*' || exp[i] == '/' || exp[i] == '+' || exp[i] == '-'){
                string exp1 = st.top(); st.pop();
                string exp2 = st.top(); st.pop();
                string mid = ""; mid.push_back(exp[i]);
                string newExp = "(" + exp2 + mid + exp1 + ")";
                st.push(newExp);
            }
            else{
                string toPush = "";
                toPush.push_back(exp[i]);
                st.push(toPush);
            }
        }
        string exp_infix = st.top(); st.pop();
        return exp_infix;
    }
};