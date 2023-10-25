// ************** TWO POINTERS PAIR SUM PROBLEM ****************
// GIVEN A SORTED LINKED LIST WE HAVE TO CHECK WHETHER THERE EXIST ANY PAIR HAVING SUM EQUAL TO X

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


bool checkPairSum(Node* &head, Node* &tail,int x){              // SIMILAR CONCEPT  AS USED IN FINDING THE PAIR SUM PROBLEM VIA TWO POINTER CONCEPT
    Node*temp1=head;                                            // TWO POINTERS ONE FROM START
    Node*temp2=tail;                                            // AND OTHER FROM THE END
    while(temp1!=temp2){                                        // CHECKING THEIR SUM AND MAKING THREE CONDITIONS 
        if(temp1->val + temp2->val == x){                       // IF EQUAL THEN PAIR EXIST
            cout<<temp1->val<<" "<<temp2->val<<"\n";            // IF LARGER THEN MOVE LAST POINTER TO PREV
            return true;                                        // IF SMALLER THEN MOVE FIRST POINTER TO NEXT
        }
        else if(temp1->val + temp2->val > x) temp2=temp2->prev;
        else temp1=temp1->next;
    }
    cout<<"-1 -1"<<"\n";
    return false;
}

int main(){
    DoublyLinkedList dll;
    dll.insertAtTail(2);
    dll.insertAtTail(5);
    dll.insertAtTail(6);
    dll.insertAtTail(8);
    dll.insertAtTail(10);

    if(checkPairSum(dll.head,dll.tail,11)) cout<<"PAIR EXIST"<<"\n";
    else cout<<"PAIR DOES NOT EXIST"<<"\n";

    return 0;
}
