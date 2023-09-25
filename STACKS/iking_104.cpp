// SWAP FUNCTION IN STACKS

#include<iostream>
#include<stack>
using namespace std;

int main(){

    stack<int>st;                  // FIRST STACK

    st.push(1);
    st.push(2);
    st.push(3);
    st.push(4);
    st.push(5);

     stack<int>st2;                // SECOND STACK

    st2.push(9);
    st2.push(8);
    st2.push(7);
    st2.push(6);

    st.swap(st2);                 // ELEMENTS OF STACKS 1 AND 2 WILL GET INTERCHANGE WITH EACH OTHER

     while(!st.empty()){          // NOW FROM PRINTING WE CAN VERIFIED THAT
        cout<<st.top()<<" ";
        st.pop();
    }
    cout<<endl;
     while(!st2.empty()){
        cout<<st2.top()<<" ";
        st2.pop();
    }
    return 0;
}

