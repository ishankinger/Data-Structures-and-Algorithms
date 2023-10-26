// ***************** STACK IMPLEMENTATION USING LINKED LIST ***********************
// ASSUME THE LINKED LIST IS PLACED IN A WELL WITH NODE AT UPPER END FROM WHERE WE WILL EXTRACT OTHER ELEMENTS BY DELETING IT 
// AND ALSO ADD AT THE HEAD SO PUSH AND POP WILL OCCUR AT THE HEAD ONLY

#include<bits/stdc++.h>
using namespace std;

class Node{                                      // CLASS OF NODE
    public:
        int data;                                // DATA TO BE PUT IN THE NODE                               
        Node *next;                              // POINTER STORING ADDRESS OF NEXT NODE
        Node(int value){                         // WHENEVER A NODE IS MADE THIS WILL BE CALLED ITSELF TO 
            data=value;                          // ASSIGN VALUE AS INPUT
            next=NULL;                           // AND NEXT TO IT ASSIGN
        }
};

class Stack{
    Node*head;
    int capacity;
    int currsize;
public:
    Stack(int c){                                // STACK CONSTRUCTOR
        capacity=c;
        currsize=0;
        head=NULL;
    }
    void push(int data){
        if(isFull()){
            cout<<"OVERFLOW"<<"\n";
            return;
        }
        Node*newNode=new Node(data);             // ADDING NEW NODE AT THE HEAD
        newNode->next=head;
        head=newNode;
        currsize++;
    }
    void pop(){
        if(isEmpty()){
            cout<<"UNDERFLOW"<<"\n";
            return;
        }
        Node* toDelete=head;                        // SIMPLY DELETING NODE AT HEAD
        head=head->next;
        currsize--;
        delete toDelete;
    }
    int top(){
        if(isEmpty()){
            cout<<"UNDERFLOW"<<"\n";
            return INT_MIN;
        }
        return head->data;                        // RETURNING HEAD DATA
    }
    int size(){
        return currsize;                          // CURRSIZE IS INCREMENTED WHENEVER WE CALLED A NEW NODE
    }
    bool isEmpty(){
        return head==NULL;                        // IF HEAD == NULL MEANS EMPTY ELSE NOT EMPTY
    }
    bool isFull(){                                // IF CURR SIZE IS EQUAL TO CAPACITY THEN IT IS FULL
        return currsize==capacity;
    }
};
int main(){
    Stack st(100);
    for(int i=1;i<6;i++) st.push(i);
    if(!st.isEmpty()) cout<<"Stack isn't empty"<<"\n";
    for(int i=1;i<=5;i++){
        cout<<st.top()<<" ";
        st.pop();
    }
    cout<<"\n";
    if(st.isEmpty()) cout<<"Stack is empty"<<"\n";
    return 0;
}
