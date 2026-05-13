// **************** IMPLEMENTATION OF STACKS USING STL *********************
// PUSH , TOP AND POP MAIN PILLAR FUNCTIONS FOR STACK DATASTRUCTURE

#include<iostream>
#include<stack>                                      // USING SPECIAL HEADER FILE FOR STACK DATASTRUCTURES
using namespace std;

int main(){
    stack<int>st;                                    // DECLARATION OF A STACK VARIABLE NAMED AS ST ( SIMILAR TO VECTORS DECLARATION )
    
    st.push(1);                                      // PUSH FUNCTION IT WILL PUSH AT THE TOP
    st.push(2);
    st.push(3);
    st.emplace(4);                                   // OTHER FUNCTION SAME AS PUSH BUT NAMED AS EMPLACE
    st.push(5);

    cout<<st.size()<<endl;                           // SIZE() FUNCTION GIVE SIZE OF THE STACKS MEANS NUMBER OF ELEMENTS

    while(!st.empty()){                              // GOING IN THE LOOP SINCE EMPTY() GIVES FALSE SO IT WILL BECOME TRUE DUE TO ! AND WILL TRAVERSE
        cout<<st.top()<<" ";                         // TOP ELEMENT WILL BE PRINTED IN THE TOP FUNCTION
        st.pop();                                    // ELEMENT FROM THE TOP WILL GET ELIMINATED SO NUMBER PRINTED WILL POP
    }
    cout<<endl;
    cout<<st.size()<<endl;                           // NOW IT WILL BE AN EMPTY STACK

    st.push(1);
    st.push(2);
    st.push(3);
    st.push(4);
    st.push(5);
 
    cout<<st.size()<<endl;

    st.pop();                                  // TWO TIMES POP SO TWO ELEMENTS WILL GET REMOVED
    st.pop();

    cout<<st.size()<<endl;                    // HENCE SIZE WILL DECREASE BY TWO

    while(!st.empty()){                       // IN STACKS THIS IS BASIC LOOP TO GET OUTPUT OF THE STACK
        cout<<st.top()<<" ";                  // HERE REVERSE ORDER OF SERIES WILL BE PRINTED
        st.pop();                             // IF WE ADD IN ORDER OF 1,2,3,4 THEN IT WILL BE PRINTED AS 4,3,2,1
    }
}
