// ****************** STACK USING QUEUES **********************

// ***************** METHOD 1 -> MAKING PUSH COSTLY **********************

// WE WILL MAKE TWO QUEUES Q1 AND Q2
// NOW OUR STACK ELEMENTS WILL BE REPRESENTED IN Q1 IN SAME ORDER
// WHEN WE HAVE TO PUSH ANY ELEMENT FIRST WE WILL PUSH THAT INTO Q2
// THEN ALL ELEMENTS OF Q1 WILL BE PUSHED INTO Q2
// NOW WE WILL SWAP Q1 AND Q2 THUS OUR NEW ELEMENT WILL BE PUSHED AT FRONT POSITION WHICH IS TOP OF OUR STACK 

#include<bits/stdc++.h>
using namespace std;

class stacks{
    public:
        queue<int>q1;
        queue<int>q2;
        void pushStack(int x){
            if(q1.empty()){
                q1.push(x);
                return;
            }
            q2.push(x);
            while(!q1.empty()){
                q2.push(q1.front());
                q1.pop();
            }
            swap(q1,q2);
        }
        void popStack(){
            if(q1.empty()){
                cout<<"Stack is empty"<<"\n";
                return;
            }
            q1.pop();
        }
        int peekStack(){
            if(q1.empty()){
                cout<<"Stack is empty"<<"\n";
                return -1;
            }
            return q1.front();
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

