// ************* PALLINDROMIC LINKED LIST ****************
// CHECK WHETHER THE GIVEN LINKED LIST IS PALLINDROME OR NOT

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

bool checkPallindrome(Node*&head,Node*&tail){        // FUNCTION TO CHECK PALLINDROME OR NOT
    Node*ptr1=head;                                  // MAKE TWO POINTERS ONE STARTING FROM THE HEAD
    Node*ptr2=tail;                                  // AND THE OTHER POINTER STARTING FROM THE TAIL
    while(ptr1!=ptr2 && ptr1->prev!=ptr2){           // TILL PTR1!=PTR2(FOR EVEN) AND PTR1 & PTR2 WILL OVERCROSS (FOR ODD) WE WILL MOVE IN THE LOOP
        if(ptr1->val!=ptr2->val) return false;       // IF VALUES ARE DIFFERENT THEN RETURN FALSE
        ptr1=ptr1->next;                             // OTHER WISE GOING IN TRAVERSAL
        ptr2=ptr2->prev;
    }
    return true;                                     // IF WE GET OUT OF THE LOOP MEANS ALL OKAY SO RETURN TRUE
}
int main(){
    DoublyLinkedList dll;
    dll.insertAtTail(1);
    dll.insertAtTail(2);
    dll.insertAtTail(3);
    dll.insertAtTail(3);
    dll.insertAtTail(2);
    dll.insertAtTail(1);
    dll.display();
    if(checkPallindrome(dll.head,dll.tail)) cout<<"IT IS A PALLINDROME"<<"\n";
    else cout<<"IT IS NOT A PALLINDROME"<<"\n";
    return 0;
}
