// CHECK WHETHER THE GIVEN LINKED LIST IS PALLINDROME OR NOT
// MAIN LOGIC WHICH WE WILL BE USING IN THIS IS THAT WE WILL REVERSE THE LINKED LIST FROM THE MIDDLE TO RIGHT PART
// THEN WE WILL CHECK DATA OF BOTH LINKED LIST
// SO IF THEY ARE EQUAL THEN IT IS AN PALLINDROME ELSE IT WILL BE 

#include<bits/stdc++.h>
using namespace std;

class Node{                                        // CLASS OF NODE
    public:
        int data;                                // DATA TO BE PUT IN THE NODE                               
        Node *next;                              // POINTER STORING ADDRESS OF NEXT NODE
        Node(int value){                         // WHENEVER A NODE IS MADE THIS WILL BE CALLED ITSELF TO 
            data=value;                          // ASSIGN VALUE AS INPUT
            next=NULL;                           // AND NEXT TO IT ASSIGN
        }
};
class LinkedList{                                  // CLASS FOR LINKED LIST
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


bool isPallindrome(Node* &head){                   // FUNCTION TO CHECK LINKED LIST IS PALLINDROME OR NOT

    Node*slow=head;                                // FIRST WE WILL GET THE MIDDLE ELEMENT USING SLOW FAST POINTER APPROACH
    Node*fast=head;
    while(fast && fast->next){
        slow=slow->next;
        fast=fast->next->next;
    }                                              // SLOW POINTER WILL BE THE MIDDLE ELEMENT HERE

    Node* curr= slow->next;                        // STORING NEXT OF MIDDLE ELEMENT
    Node* prev=slow;                               // STORING THE MIDDLE ELEMENT ALSO
    slow->next=NULL;                               // BREAKING THE TWO LINKED LIST INTO TWO HALVES IF ODD THEN FIRST ONE WILL BE BIGGER ELSE SAME SIZE

    while(curr){                                   // NOW WE WILL REVERSE THE SECOND PART OF THE DIVIDED LINKED LIST
        Node* nextNode=curr->next;                 // SIMILAR WAY OF REVERSING AS DONE EARLIER
        curr->next=prev;                           // CURR WILL POINT TO PREVIOUS NODE

        prev=curr;                                 // BOTH CURR AND PREV NODE POINTER WILL BE UPDATED
        curr=nextNode;                             
    }                                              // AT END CURR WILL BE AT NULL AND PREV WILL BE NEW HEAD OF THE SEPARATED SECOND LL

    Node* head1=head;                              // NOW MAKING TWO POINTERS TO CHECK THE TWO LINKED LIST WHETHER THEY ARE EQUAL OR NOT
    Node* head2=prev;
    while(head2){                                  // KNOWINGLY TAKEN HEAD2 AS SECOND WILL ALWAYS BE SMALLER OR EQUAL
        if(head1->data!=head2->data) return false; // IF UNEQUAL ELEMENT ARE FOUND THEN RETURN FALSE
        head1=head1->next;
        head2=head2->next;
    }
    return true;                                   // IF WE GET OUR OF THE LOOP MEANS ALL EQUAL HENCE RETURN TRUE
}

int main(){
    LinkedList ll;
    ll.insertAtTail(1);
    ll.insertAtTail(3);
    ll.insertAtTail(3);
    ll.insertAtTail(5);
    ll.insertAtTail(3);
    ll.insertAtTail(3);
    ll.insertAtTail(1);
    if(isPallindrome(ll.head)) cout<<"YES, IT IS A PALLINDROME"<<"\n";
    else cout<<"NO, IT IS NOT A PALLINDROME\n";
    return 0;
}