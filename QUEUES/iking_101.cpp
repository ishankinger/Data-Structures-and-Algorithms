// QUEUES 
// IMPLEMENTATION USING ARRAYS

#include<iostream>
using namespace std;

#define N 100

class queues{                                  // A CLASS OF QUEUE IS DEFINED
    int front;                                 // TWO POINTER ARE TAKEN ONE IS FRONT
    int back;                                  // OTHER ONE IS BACK
    int arr[N];                                // AN ARRAY IS DEFINED
    public: 
        queues(){                              // CONSTRUCTOR
            front=-1;                          // WHENEVER AN OBJECT IS FORMED FRONT AND BACK WILL INITIALISE WITH -1
            back=-1;
        }
        void enque(int x){                     // ENQUEUE FUNCTION
            if(front==-1){                     // MEANS STILL QUEUE IS EMPTY THIS IS THE FIRST ELEMENT TO PUSH IN
                front++;                       // SO FOR THIS ONLY FRONT ++
            }
            if(back>=N-1){
                cout<<"Queue overflows"<<endl;
                return;
            }
            back++;                           // THIS WILL ALWAYS ++ WHENEVER AN ELEMENT IS ADDED  
            arr[back]=x;                      // CORRESPONDIGLY WE WILL PUSH THAT ELEMENT
        }
        void dequeue(){                       // TO REMOVE FRONT ELEMENT  
            if(front==-1 || front>back){      // (FRONT>BACK) ==> MEANS ALL ELEMENT ARE DEQUED AND NOW QUEUE IS EMPTY
                cout<<"Queue is empty"<<endl;
            }
            front++;                           // JUST DO FRONT ++ SO THAT FRONT WILL SHIFT FURTHER TO NEW VALUE
        }
        int peek(){                            // GIVES US THE FRONT ELEMENT OF THE STACKS
            if(front==-1 || front>back){     
                return -1;
                cout<<"Queue is empty"<<endl;
            }
            return arr[front];               // SO WE WILL RETURN ELEMENT PRESENT AT THE FRONT POSITION
        }
        bool empty(){                        // SIMILAR IF ELSE USED ABOVE
            if(front==-1 || front>back){
                return true;
            }else{
                return false;
            }
        }
};

int main(){
    queues q1;

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
}