// INTERSECTING LINKED LIST
// GETTING THE INTERSECTION POINT OF LINKED LIST
// INTERSECTION IS DEFINED AS POINT WHERE TWO LINKED LIST MERGE TO SAME NODE OF SAME ADDRESS
// HERE THE MAIN LOGIC THAT WE ARE USING IS WE WILL FIRST MAKE BOTH LL HEAD POINTER AT EQUAL DISTANCE FROM TAIL AND THEN MOVE TILL WE GET INTERSECTION
// SO TO GET BOTH OF THEM AT SAME DISTANCE WE WILL MOVE OUR LARGER LL BY L1-L2 DISTANCE ABOVE TO GET THAT STATE THAT IS REMOVING EXTRA STEPS

#include<bits/stdc++.h>
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
};


int getLegth(Node*head){                         // FUNCTION TO GET THE LENGTH OF LINKED LIST
    Node* temp= head;                            // MAKE TEMP VARIABLE TO TRAVERSE IN LINKED LIST
    int lenth=0;                                 // MAKING OUR ANS THAT IS LENTH VAR
    while(temp!=NULL) lenth++,temp=temp->next;   // TILL TEMP NOT REACH NULL WE WILL TRAVERSE WITH LENTH++ 
    return lenth;                                // AT END WE WILL BREAK RETURNING LENTH
}
Node* moveHeadByK(Node*head,int k){              // FUCTION TO MOVE HEAD BY K MOVES
    Node*ptr=head;                               // MAKE A POINTER INITIALISING IT WITH HEAD
    while(k--) ptr=ptr->next;                    // TILL K!=0 WE WILL DO PTR++
    return ptr;                                  // WHEN WE WILL BREAK FROM LOOP WE WILL RETURN OUR NEW HEAD
}
Node* getIntersection(Node* head1, Node*head2){  // FUNCTION TO GET INTERSECTION POINT OF TWO LINKED LIST
    int l1=getLegth(head1);                      // GET LENTH OF BOTH THE LINKED LIST USING GETLENTH FUNCTION
    int l2=getLegth(head2);
    Node *ptr1=head1,*ptr2=head2;                // INITIALISE TWO POINTER AS HEAD
    if(l1>l2) ptr1=moveHeadByK(head1,l1-l2);     // L1-L2 WILL GIVE THE NUM OF EXTRA OF GREATER LENTH OF LINKED LIST HAVE
    else ptr2=moveHeadByK(head2,l2-l1);          // FROM THAT WE WILL MOVE THE HEAD POINTER BY THAT NUM USING MOVEkHEAD FUNCTION

    while(ptr1){                                 // PTR BECOMES NULL THEN WE WILL BREAK
        if(ptr1==ptr2){                          // IF BOTH POINTERS BECOME EQUAL THEN WE WILL GET OUR INTERSECTION POINT
            return ptr1;                         // WE WILL RETURN THE NODE
        }
        ptr1=ptr1->next;                         // ELSE POINTER WILL MOVE FORWARD
        ptr2=ptr2->next; 
    }
    
}
int main(){
    LinkedList ll1;
    ll1.insertAtTail(1);
    ll1.insertAtTail(2);
    ll1.insertAtTail(3);
    ll1.insertAtTail(4);
    ll1.insertAtTail(5);
   
    LinkedList ll2;
    ll2.insertAtTail(6);
    ll2.insertAtTail(7);
    
    ll1.display();
    ll2.display();
     
    ll2.head->next->next=ll1.head->next->next->next;      // MAKING INERSECTION POINT

    Node* ans=getIntersection(ll1.head,ll2.head);
    if(ans) cout<<ans->data<<"\n";
    else cout<<"NO INTERSECTION";
    
    return 0;
}