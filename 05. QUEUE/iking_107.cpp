// ******************** QUEUE USING STL ***********************
// ALL OPERATIONS ARE SAME AS THAT OF STACKS BUT THE ONLY DIFFERENCE IS IN TOP AND FRONT OPERATIONS

#include<iostream>
#include<queue>
using namespace std;

int main(){
    queue<int>q;
    q.push(1);                       // ENQUEUE IS TERMED AS PUSH
    q.push(2);
    q.emplace(3);                     
    q.push(4);
    

    cout<<q.size()<<endl;
    cout<<q.front()<<endl;            // HERE WE CAN GET FRONT ELEMENT 
    cout<<q.back()<<endl;             // AND ALSO BACK ELEMENT IN O(1)
    
    while(!(q.empty())){
        cout<<q.front()<<" ";
        q.pop();                     // DEQUEUE IS TERMED AS POP
    }
    cout<<endl;
    cout<<q.empty()<<endl;

    return 0;
}
