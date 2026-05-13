// DOUBLY LINKED LIST IMPLEMENTATION

#include<bits/stdc++.h>
using namespace std;

class Node{                               // MAKING A NODE CLASS FOR DOUBLY LINKED LIST
    public:
    int val;                              // TAKING INT VAL
    Node* prev;                           // HERE WE WILL USE TWO POINTERS ONE POINTING TO THE PREVIOUS OF OUR NODE ELEMENT
    Node* next;                           // AND OTHER TO THE NEXT OF OUR NODE ELEMENT

    Node(int data){                       // A CONSTRUCTOR OF NODE IS FORMED
        val=data;                         // INITIALISING WITH VALUE
        prev=NULL;                        // AND BOTH THE POINTERS POINTING TO THE NULL
        next=NULL;
    }
};

class DoublyLinkedList{                   // CLASS TO IMPLEMENT THE DOUBLY LINKED LIST
    public:
    Node* head;                           // MAKING TWO POINTER ONE AT HEAD
    Node* tail;                           // AND OTHER AT TAIL THE END OF THE LINKED LIST

    DoublyLinkedList(){                   // CONSTRUCTOR STORE HEAD AND TAIL TO BE NULL
        head=NULL;
        tail=NULL;
    }
    void insertAtHead(int val){           // INSERT AT HEAD FUNCTION  
        Node* new_Node=new Node(val);     // A NEW NODE IS FORMED OF GIVEN INT VALUE
        if(head==NULL){                   // IF HEAD IS NULL MEANS LL IS EMPTY THEN HEAD WILL BE OUR NEW NODE AND TAIL ALSO
            head=new_Node;
            tail=new_Node;
            return;
        }
        new_Node->next=head;              // ELSE NEW NODE POINT TO HEAD
        head->prev=new_Node;              // AND HEAD PREVIOUS WILL BE NEW NODE WHICH WAS NULL EARLIER
        head=new_Node;                    // STORE VALUE OF NEWNODE AS HEAD OF LINKED LIST
        return;
    }
    void insertAtTail(int val){           // FUNCTION TO INSERT AT TAIL 
        Node* new_Node=new Node(val);     // MAKING A NEW NODE
        if(head==NULL){                   // FOR EMPTY LINKED LIST BOTH TAIL AND HEAD TO BE NULL
            head=new_Node;
            tail=new_Node;
            return;
        }
        tail->next=new_Node;              // NEXT TO TAIL WILL BE NEW NODE
        new_Node->prev=tail;              // NEW NODE PREV WILL TAIL
        tail=new_Node;                    // TAIL WILL BE NEW NODE
        return;                           // THIS IS DONE IN O(1)
    }
    void insertPos(int val,int pos){      // FUNCTION TO INSERT A VALUE AT GIVEN POSITION
        if(pos==1) insertAtHead(val);     // IF FIRST POSITION THEN CALLED INSERTATHEAD
        Node*new_Node=new Node(val);      // MAKING A NEW NODE
        Node*temp=head;                   // A TEMP VARIABLE TO TRAVERSE
        while(pos!=1){                    // TRAVERSE TILL WE REACH ONE NODE BEFORE THE POSITION NEEDED
            temp=temp->next;
            pos--;
        }
        new_Node->next=temp->next;        // NOW FIRST DO NEXT OF NEW NODE TO TEMP NEXT 
        temp->next=new_Node;              // THEN TEMP NEXT TO BE NEW NODE
        new_Node->prev=temp;              // FIRST FOR BOTH NEXT AND PREV ALTER NEW NODE AND 
        new_Node->next->prev=new_Node;    // THEN ALTER THE POINTER OF TEMP NODE TO GET ANSWER
        
        return;
    }
    void deleteAtFirst(){                 // TO DELELTE THE ELEMENT AT THE FIRST POSITION
        if(head==NULL) return;            // IF EMPTY THEN RETURN
        Node* toDelete=head;              // HEAD STORE TO DELETE ( STORING THE ADDRESS OF THE HEAD)
        head->next->prev=NULL;            // BREAKING PREV LINK OF HEAD AND HEAD NEXT
        head=head->next;                  // THEN CHANGING HEAD POSITION
        delete toDelete;                  // NOW DELETING THE NODE OF ADDRESS HEAD WHICH WAS STORED EARLIER 
        return;
    }
    void deleteAtEnd(){                   // TO DELETE AT THE END OF THE LINKED LIST
        if(head==NULL) return;            // EMPTY THEN RETURN
        Node* toDelete=tail;              // STORING TAIL ADDRESS
        tail->prev->next=NULL;            // PREV OF TAIL SHOULD POINT TO NULL TO SKIP THE TAIL NODE
        tail=tail->prev;                  // THEN CHANGING THE TAIL POSITION 
        delete toDelete;                  // AND DELETE THE ADDRESS OF PREVIOUS TAIL NODE
        return;
    }
    void deletePos(int pos){              // FUCNTION TO DELETE THE NODE AT ANY POSITION GIVEN
        Node* temp=head;                  // VARIABLE TO MOVE TILL NODE BEFORE GIVEN POSITION
        while(pos!=1){                    // LOOP TO GET ABOVE
            temp=temp->next;
            pos--;
        }
        Node *toDelete=temp->next;         // STORING THE NODE TO DELETE
        temp->next=temp->next->next;       // POINTING THE PREV AND NEXT OF THE NODE TO DELETE
        temp->next->prev=temp;             // SAME WAY POINTING BOTH VIA PREVIOUS AND SKIPPING THE NODE TO DELETE
        delete toDelete;                   // NOW DELETE THE TO DELETE NODE
        return;                            // AND RETURN
    }
    void display(){                        // FUNCTION TO DISPLAY ALL THE ELEMENTS 
        Node*temp=head;                    // SIMILAR TO AS DONE FOR SINGLY LINKED LIST
        while(temp!=NULL){
            cout<<temp->val<<" ";
            temp=temp->next;
        }
        cout<<"NULL\n";
    }
    void reverse(Node* &head,Node* &tail){  // FUNCTION TO REVERSE THE NODES OF THE GIVEN DOUBLY LINKED LIST
        Node* currPtr=head;                 // MAKING A CURR POINTER TO TRAVERSE IN THE LIST
        while(currPtr){                     // TILL CURRPTR DOESNOT BECOME NULL THAT IS 0 FOR WHILE IT WILL KEEP ON MOVING
            Node* nextPtr=currPtr->next;    // MAKING A POINTER OF NEXT TO THE CURRENT POINTER
            currPtr->next=currPtr->prev;    // CURR POINTER WILL POINT TO THE PREVIOUS POINTER OF IT
            currPtr->prev=nextPtr;          // AND CURR POINTER PREVIOUS WILL BE THE NEXT POINTER TO IT
            currPtr=nextPtr;                // AND THIS WILL HELP IN TRAVERSING THE LINKED LIST
        }
        Node*newHead=tail;                  // NOW SWAPPING THE TAIL AND HEAD OF THE NEW REVERSED LINKED LIST
        tail=head;
        head=newHead;
    }
};

int main(){
    DoublyLinkedList dll;
    dll.insertAtTail(2);
    dll.insertAtTail(3);
    dll.insertAtTail(4);
    dll.insertAtTail(5);
    dll.insertAtHead(1);
    dll.display();
    dll.insertPos(2,4);
    dll.display();
    dll.deleteAtFirst();
    dll.deleteAtEnd();
    dll.display();
    dll.deletePos(2);
    dll.display();
    dll.reverse(dll.head,dll.tail);
    dll.display();
    return 0;
}