// DELETING THE NODES WHOSE NEIGHBOURS HAVE SAME VALUES WHILE TRAVERSING FROM RIGHT TO LEFT

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


void deleteSameNeighbourNodes(Node* &head,Node* &tail){    // DELETING THE NODES WHICH HAVE SAME NEIGHBOUR
Node *temp=tail->prev;                                     // STARTING FROM THE LAST SECOND ELEMENT
    while(temp->prev!=NULL){                               // TILL WE WILL NOT REACH FIRST ELEMENT 
        if(temp->next->val==temp->prev->val){              // FOR A TEMP WE WILL CHECK PREV AND NEXT NODE VALUE AND JUDGE 
            Node*currPtr=temp;                             // IF YES THEN WE HAVE TO DELETE IT
            Node*toDelete=temp;                            // STORING THE TO DELETE TEMP POINTER
            temp->prev->next=temp->next;                   //  PREVIOUS OF TEMP WILL POINT TO NEXT TO IT
            temp->next->prev=temp->prev;                   // NEXT OF TEMP WILL POINT BACK TO PREVIOUS OF TEMP
            temp=currPtr->prev;                            // TEMP TO MOVE BACK
            delete toDelete;                               // AND DELETE THE PREVIOUS TEMP VARIABLE
        }else{
            temp=temp->prev;                               // IF NO THEN MOVE TEMP BACK
        }
    }
}

int main(){
    DoublyLinkedList dl;
    dl.insertAtTail(1);
    dl.insertAtTail(2);
    dl.insertAtTail(3);
    dl.insertAtTail(2);
    dl.insertAtTail(2);
    dl.insertAtTail(5);
    dl.insertAtTail(4);
    dl.display();
    deleteSameNeighbourNodes(dl.head,dl.tail);
    dl.display();
    return 0;
}