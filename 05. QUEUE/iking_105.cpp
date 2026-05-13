// ********************** METHOD 2 -> POP OPERATION WILL BE COSTLY ****************************8

// IN THIS METHOD ALSO WE WILL MAKE TWO QUEUES Q1 AND Q2
// Q1 WILL REPRESENT OUR ELEMENTS OF STACK BUT IN REVERSE ORDER AS IN THIS METHOD WE WILL SIMPLY PUSH ELE IN Q1
// NOW FOR POPPING WE NEED TO DELETE THE LAST ELEMENT OF OUR STACK WHICH IS ADDED AT LAST WHICH REPRESENT THE TOP OF OUR STACK
// TO DO SO FIRST N-1 ELEMENTS OF Q1 WILL BE PUSHED IN Q2 AND LAST ELEMENT WILL BE POPPED OUT AND NOT PUSHED IN Q2 AND THEN WE WILL SWAP Q1,Q2
// SO WE REMOVE LAST (TOP) ELEMENT FROM OUR STACK
// SIMILAR THING IS FOR PEEK ALSO

#include<bits/stdc++.h>
using namespace std;

class stacks{
    public:
        queue<int>q1;
        queue<int>q2;
        void pushStack(int x){
            q1.push(x);
        }
        void popStack(){
            if(q1.empty()){
                cout<<"Stack is empty\n";
                return;
            }
            if(q1.size()==1){
                q1.pop();
                return;
            }
            while(q1.size()>1){
                q2.push(q1.front());
                q1.pop();
            }
            q1.pop();
            swap(q1,q2);
        }
        int peekStack(){
            if(q1.empty()){
                cout<<"Stack is empty\n";
                return -1;
            }
            if(q1.size()==1){
                return q1.front();
            }
            while(q1.size()>1){
                q2.push(q1.front());
                q1.pop();
            }
            int a=q1.front();
            q2.push(q1.front());
            q1.pop();
            swap(q1,q2);
            return a;
        }
        bool emptyStack(){
            if(q1.empty()) return true;
            else return false;
        }
};

int main(){
    stacks st;
    st.pushStack(1);
    st.pushStack(2);
    st.pushStack(3);
    cout<<st.emptyStack()<<endl;
    cout<<st.peekStack()<<endl;
    st.popStack();
    cout<<st.peekStack()<<endl;
    st.popStack();
    cout<<st.peekStack()<<endl;
    st.popStack();
    cout<<st.peekStack()<<endl;
    st.popStack();
    cout<<st.emptyStack()<<endl;

    return 0;
}
