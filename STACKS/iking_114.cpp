// ******************* EVALUATION OF INFIX EXPRESSION ************************

// SO FOR INFIX EXPRESSION WE WILL BE SIMPLY USING BODMAS AND PRECEDENCE PROPERTIES
// FOR THIS WE WILL BE USING TWO STACKS ==> FIRST STACK WILL ONLY STORE DIGIT AND OTHER STACK WILL ONLY STORE THE OPERATORS
// SO IF WHILE ADDING OPERATORS WE WILL BE ADDING ACCORDING TO PRECEDENCE
// MEANS IF WE GET + - AND * OR / IS PRESENT THEN FIRST THEY WILL OPERATE ON GIVEN DIGITS (TOP AND TOP-1) AND THEN AT END WE WILL ADD THEM
// ALSO FOR BRACKET IF WE GET CLOSING BRACKET THEN WE WILL TRAVESE BACK IN STACK AND SOLVE AS SAME WITH PRECEDNCE

#include<bits/stdc++.h>
using namespace std;

 // FUNCTION TO CALCULATE BASIC OPERATIONS
int calculate(int v1,int v2,char op){                        
    if(op=='^') return pow(v1,v2); 
    else if(op=='/') return v1/v2;
    else if(op=='*') return v1*v2;
    else if(op=='+') return v1+v2;
    else return v1-v2;
}

// FUNCTION TO GIVE PRECEDENCE ORDER
int precedence(char ch){                                      
    // PRECEDENCE ORDER -->  (^)  >  (*,/)  >  (+,-)  
    // AND WHEN WE HAVE SAME PRECEDENCE THEN WE WILL APPLY OPERATIONS FROM LEFT TO RIGHT IN THESE OPERATORS
    if(ch=='^') return 3;
    else if(ch=='*' || ch=='/') return 2;
    else if(ch=='+' || ch=='-') return 1;
    else return -1;
}

int eval(string &str){

    // TWO EMPTY STACKS ARE CREATED FOR STORING OPERANDS AND OPERATORS
    stack<int>nums;
    stack<int>ops;

    // GOING IN LOOP FROM LEFT TO RIGHT FOR ASSOSCIATIVITY
    for(int i=0;i<str.size();i++){

        // DIGITS PUSHED INTO NUM STACK
        if(isdigit(str[i])) nums.push(str[i]-'0'); 

        // OPENING BRACKET PUSHED INTO OPS STACK AND FOR IT'S PRECEDENCE IS DEFINED TO BE -1 
        // SO NO OPERATOR WILL WORK WHEN THIS IS AT TOP
        else if(str[i]=='(') ops.push(str[i]);    

        // IF WE GET CLOSING BRACKET THEN WE WILL APPLY OPERATIONS ON TOP TWO ELEMENTS OF NUM WITH TOP OPERAND
        else if(str[i]==')'){ 

            // THIS LOOP WILL END WHEN WE WILL GET CLOSING BRACKET AND SIMILAR TO POSTFIX
            // WE WILL CALCULATE OP ON TOP TWO ELEMENTS AND THEN PUSH                           
            while(not ops.empty() && ops.top()!= '('){         
                char op=ops.top();                           
                ops.pop();
                int v2=nums.top();
                nums.pop();
                int v1=nums.top();
                nums.pop();
                nums.push(calculate(v1,v2,op));
            }

            // REMOVING THE OPENING BRACKET FROM THE OPS STACK
            if(not ops.empty()) ops.pop();  

        // FOR SIMPLE OPERATIONS WE WILL APPLY ACCORDING TO PRECEDENCE
        }else{               

            // THIS WHILE SHOULD ONLY WORK WHEN WE ARE GETTING LESS PRECEDENCE ELEMENT THAN ON TOP OF STACK ,OR STACK IS EMPTY
            // SO HERE ALSO WE WILL CALCUATE OP ON TOP TWO ELEMENTS AND PUSH INTO THE OPERAND STACK
            while(not ops.empty() and precedence(ops.top())>=precedence(str[i])){   
                char op=ops.top();
                ops.pop();
                int v2=nums.top();
                nums.pop();
                int v1=nums.top();
                nums.pop();
                nums.push(calculate(v1,v2,op));
            }

            // THE CURRENT STRING WILL THEN BE PUSHED
            ops.push(str[i]);
        }
    }

    // AFTER THE ONE TRAVERSAL THERE IS A POSSIBILITY THAT STACK IS NOT COMPLETELY CALCULATED IF OPERATIONS STACK IS NOT EMPTY
    // SO WE WILL AGAIN TRAVERSE TILL OPERATION STACK BECOMES EMPTY
    // SIMILAR TO ABOVE TOP TWO ELEMENTS ARE CALCULATED BY THE OPERATOR AND THEN PUSH INTO THE OPERAND STACK
    while(not ops.empty()){
        char op=ops.top();
        ops.pop();
        int v2=nums.top();
        nums.pop();
        int v1=nums.top();
        nums.pop();
        nums.push(calculate(v1,v2,op));
    }

    // THE TOP ELEMENT IN THE OPERAND STACK WILL BE OUR FINAL ANSWER
    return nums.top();
}

int main(){
    string str="((2+4)*6)/(2*3)";
    cout<<eval(str)<<"\n";
    string str2 = "(2+4*6)/(2*3)";
    cout<<eval(str2)<<"\n";
    string str3 = "2+4*6/(2*3)";
    cout<<eval(str3)<<"\n";
    string str4 = "2+4*6/2*3";
    cout<<eval(str4);

    return 0;
}

// ********* ALGORITHM **********
// >> CREATE AN EMPTY OPERATOR STACK
// >> CREATE AN EMPTY OPERAND STACK
// >> FOR EACH TOKEN IN THE INPUT STRING
//       > GET THE NEXT TOKEN IN THE INFIX STRING
//       > IF NEXT TOKEN IS AN OPERAND, PLACE IT ON THE OPERAND STACK
//       > IF NEXT TOKEN IS AN OPERATOR, EVALUATE THE OPERATOR(NEXT OP)
// >> WHILE OPERATOR STACK IS NOT EMPTY, POP OPERATOR AND OPERANDS (LEFT AND RIGHT) 
//    EVALUATE LEFT AND RIGHT AND PUSH RESULT ONTO OPERAND STACK
// >> POP RESULT FROM THE OPERATOR STACK
