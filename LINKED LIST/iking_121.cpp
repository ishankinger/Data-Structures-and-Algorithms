// *************** GETTING THE MAX AND MIN DISTANCE BETWEEN THE CRITICAL POINTS THAT ARE LOCAL MAXIMA AND LOCAL MINIMA POINTS ********************

#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
    int val;
    Node* prev;
    Node* next;

    Node(int data){
        val=data;
        prev=NULL;
        next=NULL;
    }
};
class DoublyLinkedList{
    public:
    Node* head;
    Node* tail;

    DoublyLinkedList(){
        head=NULL;
        tail=NULL;
    }
    void insertAtHead(int val){
        Node* new_Node=new Node(val);
        if(head==NULL){
            head=new_Node;
            tail=new_Node;
            return;
        }
        new_Node->next=head;
        head->prev=new_Node;
        head=new_Node;
        return;
    }
    void insertAtTail(int val){
        Node* new_Node=new Node(val);
        if(head==NULL){
            head=new_Node;
            tail=new_Node;
            return;
        }
        tail->next=new_Node;
        new_Node->prev=tail;
        tail=new_Node;
        return;
    }
    void insertPos(int val,int pos){
        if(pos==1) insertAtHead(val);
        Node*new_Node=new Node(val);
        Node*temp=head;
        while(pos!=1){
            temp=temp->next;
            pos--;
        }
        new_Node->next=temp->next;
        temp->next=new_Node;
        new_Node->prev=temp;
        new_Node->next->prev=new_Node;
        return;
    }
    void deleteAtFirst(){
        if(head==NULL) return;
        Node* toDelete=head;
        head->next->prev=NULL;
        head=head->next;
        delete toDelete;
        return;
    }
    void deleteAtEnd(){
        if(head==NULL) return;
        Node* toDelete=tail;
        tail->prev->next=NULL;
        tail=tail->prev;
        delete toDelete;
        return;
    }
    void deletePos(int pos){
        Node* temp=head;
        while(pos!=1){
            temp=temp->next;
            pos--;
        }
        Node *toDelete=temp->next;
        temp->next=temp->next->next;
        temp->next->prev=temp;
        delete toDelete;
        return;
    }
    void display(){
        Node*temp=head;
        while(temp!=NULL){
            cout<<temp->val<<" ";
            temp=temp->next;
        }
        cout<<"NULL\n";
    }
    void reverse(Node* &head,Node* &tail){
        Node* currPtr=head;
        while(currPtr){
            Node* nextPtr=currPtr->next;
            currPtr->next=currPtr->prev;
            currPtr->prev=nextPtr;
            currPtr=nextPtr;
        }
        Node*newHead=tail;
        tail=head;
        head=newHead;
    }
};


void minAndmaxDist(Node* &head){       // FUCNTION TO GET MIN AND MAX DISTANCE BETWEEN TWO CRITICAL POINTS
    vector<int>v;                      // WE WILL STORE THE POSITION OF ALL THE CRITICAL POINTS IN THIS VECTOR
    Node*temp=head->next;              // WE WILL START TRAVERSING FROM SECOND ELEMENT
    int count=0;                       // FOR POSITION WE HAVE MADE A COUNT VARIABLE
    while(temp->next!=NULL){           // TILL WE DONOT REACH LAST ELEMENT WE WILL KEEP TRAVERSING
        count++;                       // COUNT++ EACH TIME 
        if(temp->val > temp->prev->val && temp->val > temp->next->val) v.push_back(count);       // CONDITION FOR LOCAL MAXIMA
        else if(temp->val < temp->prev->val && temp->val < temp->next->val) v.push_back(count);  // CONDITION FOR LOCAL MINIMA
        temp=temp->next;               // AND MOVE TEMP NODE FURTHER
    }
    if(!v.size() || !(v.size()-1)){    // IF WE HAVE ZERO OR ONE CRITICAL POINT THE  -1 TO PRINT
        cout<<"(-1,-1)"<<"\n";
        return;
    }
    int minDist=INT_MAX;               // ELSE WE WILL TRAVERSE IN THE VECTOR AND GET MIN AND MAX DISTANCE AND WILL PRINT THEM
    int maxDist=v[v.size()-1]-v[0];
    for(int i=1;i<v.size();i++){
        minDist=min(minDist,v[i]-v[i-1]);
    }
    cout<<minDist<<" "<<maxDist<<"\n";
    return;
    
}
int main(){
    DoublyLinkedList dl;
    dl.insertAtTail(1);
    dl.insertAtTail(5);
    dl.insertAtTail(4);
    dl.insertAtTail(2);
    dl.insertAtTail(6);
    dl.insertAtTail(3);
    dl.display();
    minAndmaxDist(dl.head);
    return 0;
}
