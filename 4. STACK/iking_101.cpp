// *************** STACKS ********************
// LINEAR DATASTRUCTURE AND BASED ON LIFO MECHANISM
// LAST IN FIRST OUT IN O(1) TIME

// IMPLEMENTATION USING AN ARRAY
// ( BASIC FUNCTIONS BUILDING MEANS HOW IT IS MADE ORIGINALLY )

#include<iostream>
using namespace std;

#define n 100                           // SYNTAX TO DEFINE ANY VARIABLE VALUE WHICH WILL REMAIN FIX FOR WHOLE OF THE CODE

class stack{                            // A CLASS IS DEFINED FOR STACK DATASTRUCTURE
    int *arr;                           // DEFINING AN ARRAY POINTER
    int top;                            // VARIABLE NAMED AS TOP ( WILL GIVE US TOP ELEMENT )

    public:
        stack(){                        // CONSTRUCTOR OF STACK CLASS ( WHENEVER STACK WILL BE FORMED THIS WILL BE SELF IVOKED )
            arr=new int[n];             // DEFINING THE ARRAY POINTER PROPERLY
            top=-1;                     // GIVING VALUE TO TOP INITIALLY
        }
        void push(int x){               // FUNCTION TO ADD ELEMENT AT TOP OF THE STACK
            if(top==n-1){               // CORNER CASE TO TELL THAT STACK IS FULL
                cout<<"Stack Overflow"<<endl;
                return;
            }
            top++;                       // MAKING A NEW POSITION IN ARRAY
            arr[top]=x;                  // ASSIGNING IT'S VALUE AS X
        }
        void pop(){                      // REMOVING AN ELEMENT FROM THE TOP OF THE STACK
            if(top==-1){                 // CORNER CASE FOR EMPTY STACK
                cout<<"Stack is empty"<<endl;
            }
            top--;                        // SO FROM THIS LAST POSITION WILL GET DELETED ITSELF
        }
        int Top(){                        // FUNCTION WHICH RETURN TOP ELEMENT OF THE STACK
            if(top==-1){                  // IF NO ELEMENT THEN TOP==-1
                cout<<"No element in the stack"<<endl;
                return -1;
            }
            return arr[top];              // SIMPLY RETURN ARR[TOP] UPPERMOST ELEMENT OF THE STACK
        }
        bool empty(){                     // TELL WHETHER STACK IS EMPTY OR NOT
            return (top<=-1);             // IF TRUE THEN 1 ELSE 0;
        }
        bool full(){                      // TELL WHETHER STACK IS FULL OR NOT
            return (top==n-1);            // WHEN TOP IS AT LAST INDEX THEN IT IS FULL ONLY
        }
};

int main(){
    stack st;
    st.push(1);
    st.push(2);
    st.push(3);
    cout<<st.empty()<<endl;
    cout<<st.Top()<<endl;
    st.pop();
    cout<<st.Top()<<endl;
    st.pop();
    cout<<st.Top()<<endl;
    st.pop();
    cout<<st.Top()<<endl;
    st.pop();
    cout<<st.empty()<<endl;
    return 0;
}
