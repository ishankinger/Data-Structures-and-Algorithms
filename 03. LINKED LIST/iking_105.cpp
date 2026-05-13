// *********** REVERSING THE LINKED LIST **************

#include<iostream>
using namespace std;

class Node{                                      // CLASS OF NODE
    public:
        int data;                                // DATA TO BE PUT IN THE NODE                               
        Node *next;                              // POINTER STORING ADDRESS OF NEXT NODE
        Node(int value){                         // WHENEVER A NODE IS MADE THIS WILL BE CALLED ITSELF TO 
            data=value;                          // ASSIGN VALUE AS INPUT
            next=NULL;                           // AND NEXT TO IT ASSIGN
        }
};
class LinkedList{                                // CLASS FOR LINKED LIST
    public:
    Node *head;
    LinkedList(){                                // DEFINING ONE CONSTRUCTOR FOR LINKED LIST
        head=NULL;                               // THE THINGS THAT WE DEFINE FOR A NODE  IN INT MAIN OF PREVIOUS FILE ARE DEFINED IN THIS CLASS 
    }                                            // AS PUBLIC SO CAN BE USED IN ALL THE FUNCTIONS
void insertAtFirst(int value){                   // FUNCTION TO INSERT ELEMENT AT FIRST POSITION
    Node *n= new Node(value);                    // MAKING A NEW NODE
    n->next=head;                                // POINTING THIS NODES NEXT TO HEAD OF OUR GIVEN LINKED LIST
    head=n;                                      // AND CHANGING OUR HEAD TO NEW NODE
}
void insertAtTail(int value){                    // WE ARE GETTING HEAD POINTER WHICH DIRECTLY GIVE US OUR LINKED LIST
    Node *n=new Node(value);                 
    if(head==NULL){                              // IF INITIALLY LINKED LIST IS EMPTY
        head=n;                                  // THEN IT'S HEAD WILL BE OUR NEW NODE
        return;                                  // RETURN
    }
    Node*temp=head;                              // temp POINTER WILL HELP IN TRAVERSAL IN LINKED LIST
    while(temp->next!=NULL){                     // DO THIS TILL WE DONOT REACH AT THE END
        temp=temp->next;                         // TEMP WILL MOVE FURTHER BY DOING THIS 
    }
    temp->next=n;                                // LAST NODE NEXT WILL POINT TO OUR NEW NODE
}
void insert(int value,int pos){
    if(pos==0){                                  // IF POS==0 MEANS FIRST POSITION
        insertAtFirst(value);                    // SO WE WILL BE USING OUR INSERT AT FIRST FUNCTION
        return;                                  // AND WILL RETURN
    }
    Node *n=new Node(value);                     // A NODE IS FORMED
    Node *temp=head;                             // A TEMP VARIABLE IS DEFINED TO TRAVERSE
    int curr_pos=0;                              // CURR POS TO GET POS-1 TH ELEMENT
    while(curr_pos!=pos-1){                      // TRAVERSE TILL WE REACH POS-1
        temp=temp->next;                         // TRAVERSING FURTHER USING THIS
        curr_pos++;                              // ALSO INCREMENTING CURR POSITION
    }
    n->next=temp->next;                          // TRAVERSE TILL N-1 POS THEN OUR GIVEN NODE NEXT TO POINT TO (N-1)TH NEXT I.E. N NODE
    temp->next=n;                                // (N-1) NODE TO POINT TOWARDS OUR NODE SO THAT TO INSERT BETWEEN THEM
}
void update(int value,int pos){                  // FUNCTION TO UPDATE THE VALUE AT KTH POSITION
    Node *temp=head;                             // TEMP VARIABLE TO TRAVERSE
    while(pos--){                                // TRAVERSE TILL WE REACH OUR POSITION
        temp=temp->next;                         // TRAVERSING USING TEMP
    }
    temp->data=value;                            // CHANGING VALUE OF REQUIRED NODE
}
void display(){                                  // FUNCTION TO DISPLAY ELEMENTS OF THE LINKED LIST
    Node *temp=head;                             // A TEMPORARY VARIABLE TEMP IS MADE TO TRAVERSE IN THE LINKED LIST
    while(temp->next!=NULL){                     // WE WILL MOVE TILL WE REACH LAST SECOND ELEMENT (DUE TO ARROW PRINTING)
        cout<<temp->data<<" -> ";                // DATA STORED IN PARTICULAR NODE WILL BE PRINTED
        temp=temp->next;                         // THIS WILL TRAVERSE THE LINKED LIST
    }
    cout<<temp->data<<" -> NULL"<<"\n";          // THEN AT END LAST ELEMENT DATA WILL BE PRINTED
}
bool search(int key){                            // FUNCTION TO CHECK WHETHER GIVEN ELEMENT IS PRESENT OR NOT IN THE LINKED LIST
    Node *temp= head;                            // TEMP VARIABLE FOR TRAVERSAL
    while(temp!=NULL){                           // TILL TEMP REACHES END TRAVERSE IN LIST
        if(temp->data==key){                     // IF WE GET OUR REQUIRED ELEMENT THEN RETURN TRUE
            return true;                         // ELSE RETURN FALSE
        }
        temp=temp->next;
    }
    return false;
}
void deleteElem(int value){                      // FUNCTION TO DELETE ELEMENT OF GIVEN VALUE
    Node *temp=head;                             // FIRST MAKING TEMP VARIABLE TO TRAVERSE IN LINKED LIST
    while(temp->next->data!=value){              // GOING IN WHILE LOOP TILL WE REACH PREVIOUS ELEMENT TO ELEMENT TO BE DELETED
        temp=temp->next;                         // HELP IN TRAVERSAL OF TEMP
    }
    Node *toDelete= temp->next;                  // NODE WHICH WE HAVE TO DELETE
    temp->next=temp->next->next;                 // BREAKING THE LINK OF ELEMENT TO BE DELETED BY JOINING PREV AND NEXT ELEMENT
    delete toDelete;                             // THIS WILL DELETE THE ELEMENT
}
void deleteHead(){                               // TO DELETE ELEMENT AT HEAD
    Node *toDelete=head;                         // STORE HEAD NOE
    head=head->next;                             // MAKING NEXT NODE TO HEAD AS NEW HEAD
    delete toDelete;                             // DELETE HEAD NODE
}
void deleteTail(){                               // FUNCTION TO DELETE ELEMENT AT LAST POSITION                 
    Node *temp=head;                             // TEMP HEAD TO TRAVESE
    while(temp->next->next!=NULL)                // LOOP TO GET LAST SECOND ELEMENT NODE
    temp=temp->next;                             // FOR TRAVERSAL
    Node *toDelete=temp->next;                   // STORING LAST NODE IN TODELELTE NODE
    temp->next=NULL;                             // LAST SECOND ELEMENT TO POINT TOWARDS NULL
    delete toDelete;                             // DELETE THE LAST ELEMENT
}
void displayReverse(Node* &head);
Node* reverseNodes(Node* &head);
Node* reverseLLRecursive(Node* &head);
Node* reverseKNodes(Node* &head,int k);
};


void LinkedList::displayReverse(Node* &head){     // FUNCTION TO JUST DISPLAY ELEMENTS NO CHANGE IN LINKS OF LINKED LIST NODES
    
    if(head==NULL) return;                        // BASE CASE
    displayReverse(head->next);                   // FUNCTION CALL STACK EACH TIME NEW HEAD WILL BE FORMED
    cout<<head->data<<" ";                        // WHEN IT WILL RETURN THE UPPERMOST STACK WILL CONTAIN LAST NODE AND AFTER THAT WILL BE PRINTED SO REVERSE ORDER
}


Node* LinkedList::reverseNodes(Node* &head){      // FUNCTION TO REVERSE THE NODES OF A LINKED LIST
    Node *prevptr=NULL;                           // FIRST POINTER THAT POINT TO PREVIOUS OF OUR CURR NODE
    Node *currptr=head;                           // SECOND POINTER THAT POINTS TO CURR NODE
    Node *nextptr;                                // THIRD POINTE THAT POINTS TO THE NEXT NODE OF CURR NODE
    while(currptr!=NULL){                         // TILL OUR CURR NODE NOT READCH LAST WE WILL TRAVERSE IN THE LOOP
        nextptr=currptr->next;                    // FILL THE VALUE OF NEXT POINTER AS CURR->NEXT
        currptr->next=prevptr;                    // NOW POINTING CURR POINTER TO PREVIOUS POINTER AND IT'S LINK WITH NEXT WILL BREAK

        prevptr=currptr;                          // BUT WE HAVE STORE NEXT POINTER SO WE CAN REPLACE CURR POINTER WITH THAT
        currptr=nextptr;                          // AND OUR PREV POINTER WILL NOW BE CURR POINTER
    }
    return prevptr;                               // IT WILL RETURN THE NEW HEAD OF THE LINKED LIST AND FROM THAT WE CAN GET THE WHOLE LL
}


Node* LinkedList::reverseLLRecursive(Node* &head){ // FUNCTIO TO REVERSE THE LINKED LIST RECURSIVELY
    if(head==NULL || head->next==NULL){            // BASE CASE
        return head;                               // HEAD-> NEXT IS FOR CASE IN WHICH LL WILL ONLY HAVE ONE NODE
    }
    Node *new_head=reverseLLRecursive(head->next); // IT WILL FORM STACK ( BASICALLY OUR CURR HEAD WILL BE STORED IN THIS WAY)
    head->next->next=head;                         // NOW WE WILL POINT NEXT OF OUR NODE TO PREV NODE WHICH WILL HEAD FOR HEAD->NEXT
    head->next=NULL;
    return new_head;                               // AT END WE WILL RETURN HEAD
}


Node* LinkedList::reverseKNodes(Node* &head,int k){
    Node* prevptr=NULL;
    Node* currptr=head;

    int counter=0;
    while(currptr!=NULL && counter<k){                // REVERSING OUR FIRST K NODES USING ITERATIVE METHOD
        Node* nextptr=currptr->next;
        currptr->next=prevptr;

        prevptr=currptr;
        currptr=nextptr;
        
        counter++;
    }
    if(currptr!=NULL){                                // CURR PTR WILL GIVE US K+1 NODE
        Node* new_head=reverseKNodes(currptr,k);      // WILL CONSIDER NEW HEAD AS CURR PTR AND AGAIN DO REVERSING
        head->next=new_head;                          // TWO K NODES WILL BE CONNECTED USING HEAD NEXT WILL POINT TO CURR HEAD
    } 
    return prevptr;
}


int main(){
    LinkedList ll;
    for(int i=1;i<10;i++) ll.insertAtTail(i);
    ll.display();

    ll.head=ll.reverseNodes(ll.head);                 // HEAD IS THE MAIN PART OF THE LINKED LIST AS IF WE GET THE HEAD OF THE LINKED LIST WE
    ll.display();                                     // CAN GO THROUGH WHOLE THE LINKED BY LINKS
    ll.displayReverse(ll.head);
    cout<<"\n";

    ll.head=ll.reverseLLRecursive(ll.head);
    ll.display();

    ll.head=ll.reverseKNodes(ll.head,3);
    ll.display();

    return 0;
}

