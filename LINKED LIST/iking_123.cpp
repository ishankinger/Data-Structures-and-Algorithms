// IMPLEMENTATION OF A CIRCULAR LINKED LIST

#include<bits/stdc++.h>
using namespace std;

class Node{                                  // NODE CLASS SIMILAR TO THAT OF SINGLY LINKED LIST NODE CLASS
    public:
    int val;
    Node* next;

    Node(int data){
        val=data;
        next=NULL;
    }
};
class CircularLinkedList{                    // CLASS FOR IMPLEMENTATION FOR CIRCULAR LINKED LIST
    public:
    Node*head;
    CircularLinkedList(){
        head=NULL;
    }
    
    void insertAtFirst(int val){             // INSERTING AT FIRST POSITION
        Node* newNode=new Node(val);         // MAKING A NEW NODE TO BE ADDED AT FIRST POSITION
        if(head==NULL){                      // IF LL IS EMPTY AND THEN NEW NODE WILL BE OUR HEAD
            head=newNode;
            newNode->next=head;              // THAT IS ALSO POINTING TO ITSELT
        }
        Node* tail=head;                     // ELSE HERE FIRST WE HAVE TO GO TO TAIL NODE BY TRAVERSING
        while(tail->next!=head){              
            tail=tail->next;
        }
        tail->next=newNode;                  // TAIL TO POINT TO NEW NODE
        newNode->next=head;                  // NEW NODE WILL POINT TO NEW HEAD
        head=newNode;                        // WE MAKE NEW NODE AS LL'S NEW HEAD
    }
    void insertAtEnd(int val){               // EVERYTHING IS SIMILAR TO ABOVE FUNCTION THE ONLY DIFFERENCE IS THAT WE ARE NOT MAKING 
        Node* newNode=new Node(val);         // NEW NODE AS LL'S NEW HEAD
        if(head==NULL){
            head=newNode;
            newNode->next=head;
        }
        Node* tail=head;
        while(tail->next!=head){
            tail=tail->next;
        }
        tail->next=newNode;
        newNode->next=head;
    }
    void insertAtPos(int val,int pos){       // SIMILAR TO SINGLY LINKED LIST AS INSIDE A CIRCULAR LL IS ALSO A SINGLY LL
        Node* newNode=new Node(val);
        Node*temp=head;
        while(pos!=1){
            temp=temp->next;
            pos--;
        }
        newNode->next=temp->next;
        temp->next=newNode;

    }
    void deleteAtFirst(){                    // FUNCTION TO DELETE THE HEAD OF THE LINKED LIST
        if(head==NULL) return;               // LL EMPTY THEN RETURN
        Node* toDelete=head;                 // STORE THE HEAD WHICH WE WILL DELETE FURTHER
        Node* tail=head;                     // GETTING THE TAIL NODE VIA TRAVERSING IN THE LOOP
        while(tail->next!=head){
            tail=tail->next;
        }
        tail->next=head->next;               // WE WILL POINT NEXT OF TAIL TO HEAD NEXT SO SKIPPING THE HEAD NODE  
        head=head->next;                     // MAKING HEAD NEXT AS OUR NEW HEAD
        delete(toDelete);                    // NOW WE WILL DELETE OUR PREVIOUS HEAD NODE
    }
    void deleteAtEnd(){                      // FUNCTION TO DELETE THE TAIL OF THE LINKED LIST
        if(head==NULL) return;               // LL EMPTY THEN RETURN
        Node*tail=head;                      // POINTER TO GET AT THE TAIL NODE
        while(tail->next->next!=head) tail=tail->next; // GOING IN LOOP TILL WE REACH LAST SECOND NODE
        Node* toDelete=tail->next;           // WE HAVE TO DELETE LAST NODE SO STORED
        tail->next=head;                     // SECOND LAST WILL POINT TO HEAD SO SKIPPING THE LAST NODE
        delete(toDelete);                    // DELETE THE PREVIOUS TAIL NODE
    }
    void deleteAtPos(int pos){               // SIMILAR AS DONE IN SINGLY LINKED LIST
        Node*temp=head;
        while(pos!=1){
            temp=temp->next;
            pos--;
        }
        Node* toDelete=temp->next;
        temp->next=temp->next->next;
        delete(toDelete);
    }
    void display(){                         // SIMILAR AS DONE IN SINGLY LINKED LIST
        Node* temp=head;
        do{
            cout<<temp->val<<" ";
            temp=temp->next;
        }while(temp!=head);
        cout<<"\n";
    }

};

int main(){
    CircularLinkedList cll;
    cll.insertAtFirst(5);
    cll.insertAtFirst(4);
    cll.insertAtFirst(3);
    cll.insertAtFirst(2);
    cll.insertAtFirst(1);
    cll.display();
    cll.insertAtEnd(6);
    cll.insertAtFirst(0);
    cll.insertAtEnd(7);
    cll.display();
    cll.deleteAtEnd();
    cll.deleteAtEnd();
    cll.deleteAtFirst();
    cll.display();
    cll.insertAtPos(10,3);
    cll.display();
    cll.deleteAtPos(3);
    cll.display();
    return 0;
}