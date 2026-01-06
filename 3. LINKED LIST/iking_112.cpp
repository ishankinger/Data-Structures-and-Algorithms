// ********** DETECTING CYCLE IN LINKED LIST **********
// DETECT IF THERE IS ANY CYCLE PRESENT IN LINKED LIST
// FOR THIS WE ARE AGAIN USING SLOW FAST POINTER APPROACH
// IF ANY CYCLE IS PRESENT THEN BOTH POINTERS WILL MEET OTHERWISE THEY CANNOT MEET

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


bool detectCycle(Node* head){                    // FUNCTION TO DETECT CYCLE IN A LINKED LIST
    if(head==NULL) return false;                 // LL EMPTY SO WE WILL RETURN FALSE

    Node* slow=head;                             // TWO POINTERS SLOW AND FAST ARE DEFINED
    Node* fast=head;

    while(fast!=NULL && fast->next!=NULL){       // TILL WE DONOT REACH END
        slow=slow->next;                         // SLOW MOVE BY 1
        fast=fast->next->next;                   // FAST MOVE BY 2
        if(slow==fast) return true;              // IF CYCLE PRESENT THEN IT WILL BE A POINT OF TIME WHERE THEY WILL INTERSECT AND RETURN TRUE
    }
    return false;                                // IF WE GET OUT OF THE LOOP MEANS THERE IS NO CYCLE PRESENT
}


// *************** BREAKING CYCLE IN THE LINKED LIST *****************
// NOW WE HAVE TO BREAK THE CYCLE
// THIS TO BE DONE VIA FLOYD'S ALGORITHM
// IT SAYS THAT IF WE START TWO POINTERS POINTER1 (ONE AT HEAD) AND POINTER2 (OTHER AT THE POINTER WHERE TWO POINTERS STARTING FROM HEAD MEETS)
// THEN THEY WILL MEET AT THE STARTING ELEMENT OF THE NODE THAT IS JOINED BY THREE NODES THAT IS TRI JOINT OF THE TWO NODES
// BOTH POINTERS WILL MOVE ONE ONE STEP
// SO POINTER1 AND POINTER2 ARE EQUIDISTANCE FROM THE TRI NODE POINT THAT IS FLOYD'S ALGO SAYS


void breakCycle(Node* &head){                    // FUNCTION TO DETECT THE CYCLE IN LINKED LIST
    Node* slow=head;                             // TWO POINTERS SLOW AND FAST ARE DEFINED
    Node* fast=head;
    Node* meet1;                                 // JOINT NODE WHERE SLOW AND FAST MEETS
    while(fast!=NULL && fast->next!=NULL){       // MOVING IN A LOOP
        slow=slow->next;
        fast=fast->next->next;
        if(slow==fast){
            meet1=slow;                          // WHEN THEY MEEt WE WILL STORE THAT NODE IN MEET POINTER WHICH TO BE FURTHER USED
            break;
        }
    }
    Node* meet2=head;                            // DEFINING TWO POINTERS ONE WILL BE HEAD AND OTHER WILL BE MEET POINT                        
    Node* startNode;                             // OUR ANSWER THAT IS TRI JOINT NODE 
    while(meet2!=NULL && meet2->next!=NULL){     // WE WILL MOVE IN A LOOP  
        meet1=meet1->next;                       
        meet2=meet2->next;                 
        if(meet1->next==meet2->next){            // IF THEY MEET
            startNode=meet1;                     // THEN STORE THAT NODE VALUE
            break;                               // AND BREAK;
        }
    }
    startNode->next=NULL;                        // NOW TO BREAK CYCLE MAKE THIS NODE TO POINT TO NULL
}


void printCycle(Node* &head){
    Node* temp=head;
    int i=0;
    while(i<40){
        if(temp==NULL) break;
        cout<<temp->data<<" ";
        temp=temp->next;
        i++;
    }
    cout<<"\n";
    return;
}


int main(){
    LinkedList ll;
    for(int i=1;i<9;i++) ll.insertAtTail(i);                           // A LINKED LIST IS FORMED
    ll.display();

    ll.head->next->next->next->next->next->next=ll.head->next->next;   // A CYCLE IS CREATED BY POINTING 6 TO 3

    if(detectCycle(ll.head)) cout<<"CYCLE PRESENT"<<"\n";              // CALL FUNCTION TO DETECT CYCLE
    else cout<<"CYCLE NOT PRESENT"<<"\n";

    printCycle(ll.head);                                               // MEANS IT WILL SHOW THAT LOOP WILL ROUND ON THE CYCLE

    breakCycle(ll.head);                                               // FUNCTION TO BREAK THE CYCLE

    printCycle(ll.head);                                               // NOW CYCLE IS BROKEN SO IT WILL MOVE TILL 6

    ll.display();                                                      // THERE IS NO CYCLE THUS WE CAN DISPLAY LL OTHERWISE IT WILL GO TILL INFINITY
    return 0;
}
