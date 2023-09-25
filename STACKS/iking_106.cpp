//  *******RECURSION IN STACKS*********
// IN RECURSIVE CALLS A CALL STACK IS FORMED INBUILT SO THAT REDUCES THE EFFORT OF MAKING A TEMPORARY AS TO BE DONE IN ITERATIVE METHODS

#include<iostream>
#include<stack>
using namespace std;

// INSERT AN ELEMENT AT BOTTOM OF THE STACK

void insertAtBottom(stack<int>&st,int ele){   // FUNCTION TO INSERT 
    if(st.empty()){                           // IF STACK BECOMES EMPTY PUSH GIVEN ELEMENT
        st.push(ele);                         // ELE TO BE PUSHED
        return;                               // THEN RETURN MEANS ALL ELEMENTS IN CALL STACK WILL BE PRINTED
    }
    int topele=st.top();                      // FIRST TOP ELEMENT WILL MOVE IN CALL STACK THEN OTHER
    st.pop();                                 // POP OUT
    insertAtBottom(st,ele);                   // CALL FUNTION AGAIN TO STORE OTHER ELEMENTS IN CALL STACK (STORED IN REVERSE ORDER)
    st.push(topele);                          // NOW WHILE RETURNING SAME ORDER ELEMENTS WILL BE PRINTED
}

// INSERT AN ELEMENT AT INDEX Ith OF THE STACK

void insert(stack<int>&st,int ind,int ele){
    if(st.size()==ind){                        // ALL SAME ONLY BASE CONDITION IS CUSTOMIZED
        st.push(ele);                              
        return;
    }
    int topEle=st.top();
    st.pop();
    insert(st,ind,ele);
    st.push(topEle);
}

// REMOVING AN ELEMENT AT INDEX Ith OF THE STACK

void erase(stack<int>&st,int ind){             // ALL SAME ONLY POPING OCCUR INSTEAD AT PUSHING
    if(st.size()==ind){
        st.pop();
        return;
    }
    int topEle=st.top();
    st.pop();
    erase(st,ind);
    st.push(topEle);
}

// REVERSING ELEMENTS OF THE STACK

void reverse(stack<int>&st){                  // THIS REVERSING WILL OCCUR WITH TIME COMPLEXITY OF O(N2)
    if(st.empty()) return;                    // FIRST N FOR POPING OUT ELEMENTS AND THEN WHILE PUSHING WE ARE USING PUSH AT BOTTOM FUNCITON

    int ele=st.top();
    st.pop();
    reverse(st);
    insertAtBottom(st,ele);                  // AT END WE WILL USE INSERT AT BOTTOM FUCNTION TO GET REVERSING THE STACK
}

int main(){
    stack<int>st;
    for(int i=5;i>=1;i--) st.push(i);

    insertAtBottom(st,7);
    insertAtBottom(st,11);
    insertAtBottom(st,8);

    insert(st,4,6);

    erase(st,2);
    
    reverse(st);

    while(!st.empty()){
        cout<<st.top()<<" ";
        st.pop();
    }
}