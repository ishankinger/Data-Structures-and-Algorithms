// DEQUE USING STL
// DOUBLE ENDED QUEUES

// PUSH AND DELETE FROM FRONT AND BACK
// IMPLEMENTED WITH DOUBLY LINKED LIST

#include<iostream>
#include<deque>
using namespace std;

int main(){
    deque<int>dq;
    dq.assign(5,1);
    dq.pop_front();
    dq.pop_back();
    dq.push_back(3);
    dq.push_front(2);
    cout<<dq.back()<<"\n";
    for(int i=0;i<dq.size();i++){
        cout<<dq[i]<<" ";
    }
    cout<<"\n";
    cout<<dq.size()<<endl;

    cout<<dq[3]<<endl;
    cout<<dq.at(1)<<endl;

    dq.resize(1);
    cout<<dq.size()<<endl;
    cout<<dq[4]<<endl;

    dq[0]=4;
    cout<<dq[0]<<endl;
    dq.erase(dq.begin()+0);
    cout<<dq[0]<<endl;

    dq.insert(dq.begin()+2,5);
    cout<<dq[2]<<endl;

    for(int i=0;i<dq.size();i++){
        cout<<dq[i]<<" ";
    }
}