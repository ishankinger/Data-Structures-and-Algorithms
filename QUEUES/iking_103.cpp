// IMPLEMENTATION OF QUEUE USING STACK
// APPROACH 2 : USING FUNCTION CALL STACK

#include<iostream>
#include<stack>
using namespace std;

class queues{                                             // CLASS FORMED FOR QUEUE DATASTRUCTURE
    public: 
        stack<int>st;                                     // ONLY ONE STACK IS DEFINED
        void enque(int val){                              // ENQUE WILL BE PUSHING OF ELEMENT INTO OUR STACK
            st.push(val);
        }
        void dequeue(){                                   // REMOVING FIRST ELEMENT FROM STACK
            if(st.empty()){                               // WE WILL BE USING RECURSIVE APPROACH FOR REMOVAL
                cout<<"queue is empty"<<endl;
                return;
            }
            if(st.size()==1){                             // IF SIZE IS 1 MEANS WE REACHED LAST ELEMENT IN STACK
                st.pop();                                 // THEN WE WILL POP IT OUT AND RETURN AND WILL NOT STORE IT'S VALUE
                return;                                   // RETURN
            }                      
            int x=st.top();                               // FIRST WE WILL SAVE ALL THE ELEMENTS 
            st.pop();                                     // WE WILL POP IN EACH CALL
            dequeue();                                    // THEN WE WILL USE OUR RECURSIVE CALL
            st.push(x);                                   // THEN WHILE RETURNING WE WILL PUSH ELEMENTS IN OUR STACK
        }
        int peek(){
            
        }
        bool empty(){
            if(st.empty()) return true;
            else return false;
        }
};

int main(){
     queues q;
    q.enque(1);
    cout<<q.peek()<<" ";
    q.enque(2);
    cout<<q.peek()<<" ";
    q.enque(3);
    cout<<q.peek()<<" ";
    q.enque(4);
    cout<<q.peek()<<" ";
    q.enque(5);
    cout<<q.peek()<<" "<<endl;

    q.dequeue();
    q.dequeue();

    cout<<q.peek()<<endl;

    q.enque(6);

    while(!(q.empty())){
        cout<<q.peek()<<" ";
        q.dequeue();
    }
    return 0;
}