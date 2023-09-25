// FUNCTION TO CHECK WHETHER TWO LINKED LIST ARE EQUAL OR NOT
// TWO LINKED LISTS ARE EQUAL IF THEY HAVE SAME VALUES OF NODE WITH SAME ARRANGEMENT AND ALSO SAME LENGTH
// FOR THIS WE WILL BE CHECKING DATA OF ALL NODES AND AT END WE WILL CHECK WHETHER THE ELEMENTS NUMBER ARE EQUAL OR NOT

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


bool compare(Node* &head1,Node* &head2){         // WE CAN MAKE A SEPARATE FUNCTION NOT OF CLASS AS NOT USING LL AS OBJECT
    Node* ptr1=head1;                            // MAKE TWO POINTER STARTING FROM THE HEAD OF THE LINKED LISTS
    Node* ptr2=head2;                            // THESE HEADS ARE TAKEN AS LL.HEAD
    while(ptr1!=NULL && ptr2!=NULL){             // TILL ANY ONE LL ENDS WE WILL TRAVERSE
        if(ptr1->data!=ptr2->data){              // IF WE GET UNEQUAL ELEMENTS THEN 
            return false;                        // RETURN FALSE
        }
        ptr1=ptr1->next;                         // OTHERWISE EACH TIME MAKE POINTER ++
        ptr2=ptr2->next;                         // THAT IS MAKE POINTER EQUAL TO NEXT OF POINTER
    }
    return (ptr1==NULL && ptr2==NULL);           // IF ANY ONE OF LL ENDS AND WE WILL CHECK IF BOTH ARE NOT AT NULL MEANS ONE IS SHORTER SO FALSE
}                                                // ELSE IF BOTH AT NULL THEN TRUE
int main(){
    LinkedList ll1;
    ll1.insertAtTail(1);
    ll1.insertAtTail(2);
    ll1.insertAtTail(4);
    ll1.insertAtTail(3);
    LinkedList ll2;
    ll2.insertAtTail(1);
    ll2.insertAtTail(2);
    ll2.insertAtTail(4);
    
    ll1.display();
    ll2.display();
    
    if(compare(ll1.head,ll2.head)) cout<<"equal"<<"\n";
    else cout<<"unequal"<<"\n";
    return 0;
}

