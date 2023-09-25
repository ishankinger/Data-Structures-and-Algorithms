// IMPLEMENTATION USING STACKS
// APPROACH 1 : USING TWO STACKS

// THIS IS PUSH EFFICIENT AS PUSH IS IN O(1)

#include<iostream>
#include<stack>
using namespace std;

class queues{                                   // CLASS OF QUEUE IS FORMED
    public:
    stack<int>st1;                              // MAKE TWO STACKS
    stack<int>st2;
    void enque(int val){                        // FOR ENQUEUE WE WILL PUSH IT IN STACK1
        st1.push(val);
    }
    void dequeue(){                             // WE HAVE TO REMOVE LAST ELEMENT OF STACK1 WHICH IS THE FIRST ADDED ELEMENT IN THE STACK
        if(st1.empty()){                        // FIRST CHECK ELEMENT IS INITIALLY PRESENT OR NOT
            cout<<"STACK IS EMPTY"<<endl;
        }
        while(!(st1.empty())){                  // WE WILL PUSH ALL ELEMENTS OF STACK1 TO STACK2
            st2.push(st1.top());                // SO ELEMENTS WILL BE PUSHED IN REVERSE ORDER
            st1.pop();
        }
        st2.pop();                              // SO FIRST ELEMENT OF STACK2 IN REVERSE ORDER WILL GIVE LAST ELEMENT OF STACK1
        int n=st2.size();                       // NOW AGAIN PUSH ALL ELEMENTS OF STACK2 TO STACK1 AND WHAT WE WILL GET IS THAT ALL ELEMENTS WILL BE IN SAME POSITION
        for(int i=0;i<n;i++){                   // WITH LAST ELEMENT OF STACK 2 DELETED
            st1.push(st2.top());
            st2.pop();
        }
    }
    int peek(){                                  // EVERYTHING SAME AS DEQUEUE BUT ONLY DIFFERENT IS HERE WE WILL NOT POP IT OUT WE WILL RETURN IT'S VALUE
        if(st1.empty()){
            cout<<"STACK IS EMPTY"<<endl;
        }
        while(!(st1.empty())){
            st2.push(st1.top());
            st1.pop();
        }
        int a=st2.top();
        int n=st2.size();
        for(int i=0;i<n;i++){
            st1.push(st2.top());
            st2.pop();
        }
        return a;
    }
    bool empty(){                                   // IF STACK1 IS EMPTY MEANS QUEUE IS EMPTY
        if(st1.empty()){
            return true;
        }else{
            return false;
        }
    }
};

// THIS IS POP EFFICIENT

class queuess{
    public:
    stack<int>st1;
    stack<int>st2;
    void dequeue(){
        st1.pop();
    }
    int peek(){
        return st1.top();
    }
    void enque(int ele){                      // IN ENQUE FUNTION THE ELEMENT IN STACK WILL BE ADDED IN REVERSE ORDER
        if(st1.empty()){                      // IN EVERY PUSH WE WILL ADD ELEMENT AT THE BOTTOM OF THE STACK
            st1.push(ele);
            return;
        }
        while(!st1.empty()){
            st2.push(st1.top());
            st1.pop();
        }
        st1.push(ele);
        while(!st2.empty()){
            st1.push(st2.top());
            st2.pop();
        }
    }
    bool empty(){                                   // IF STACK1 IS EMPTY MEANS QUEUE IS EMPTY
        if(st1.empty()){
            return true;
        }else{
            return false;
        }
    }
};

int main(){
    queuess q;
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