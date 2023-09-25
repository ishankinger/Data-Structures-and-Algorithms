// IMPLEMENTATION OF QUEUES USING LINKED LIST

#include<bits/stdc++.h>
using namespace std;

class node{                                          // FIRST NODE CLASS IS FORMED TO IMPLEMENT LINKED LIST
    public:
    int data;
    node *next;

    node(int val){
        data=val;
        next=NULL;
    }
};

class Queue{                                      // CLASS QUEUE IS DEFINED

    node *front;                                  // IN THIS WE WILL DEFINE TWO POINTER ONE AT HEAD AND OTHER ONE AT TAIL
    node *back;                                   // HEAD=FRONT AND TAIL=BACK
    
    public:
    Queue(){                                      // CONSTRUCTOR FORMED AND BOTH POINTING TO NULL
        front=NULL;
        back=NULL;
    }
    void enque(int x){                            // ENQUEUE FUNCTION IS SIMPLY INSERTING A NODE AT TAIL OF OUR LINKED LIST
        node*n=new node(x);
        if(front==NULL){                          // FRONT IS NULL MEANS QUEUE IS EMPTY SO BOTH WILL POINT TO NEW NODE
            back=n;
            front=n;
            return;
        }
        back->next=n;
        back=n;
    }
    void dequeue(){                               // DEQUEUE HERE IS SAME AS REMOVING A NODE AT HEAD OF OUR LINKED LIST
        if(front==NULL){
            cout<<"Stack is Empty"<<"\n";
            return;
        }
        node*toDelete=front;
        front=front->next;
        delete toDelete;
    }
    int peek(){                                  // RETURNING THE DATA OF HEAD
        if(front==NULL){
            cout<<"Stack is Empty"<<"\n";
            return -1;
        }
        return front->data;
    }
    bool empty(){                               // IF ELSE AS DONE ABOVE
        if(front==NULL){
            return true;
        }else{
            return false;
        }
    }
};

int main(){
    Queue q1;

    cout<<q1.empty()<<endl;

    q1.dequeue();

    q1.enque(1);
    cout<<q1.peek()<<" ";
    q1.enque(2);
    q1.enque(3);
    q1.enque(4);

    q1.dequeue();
    q1.dequeue();
    cout<<q1.peek()<<" "<<endl;
    cout<<q1.empty()<<endl;
    return 0;
}
