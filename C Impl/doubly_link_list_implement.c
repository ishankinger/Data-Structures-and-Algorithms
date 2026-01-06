#include <stdio.h>
#include <stdlib.h>

typedef struct DLLNode{
    int val;
    struct DLLNode* prev;
    struct DLLNode* next;
} DLLNode;

struct DLLNode* createNode(int value){
    struct DLLNode* newNode = (struct DLLNode*)malloc(sizeof(struct DLLNode));
    if(!newNode){
        printf("Error creating node\n");
        return NULL;
    }
    newNode->val = value;
    newNode->next = NULL;
    newNode->prev = NULL;

    return newNode;
}

void insertNode(struct DLLNode **head, int value, int pos){
    struct DLLNode* newNode = createNode(value);

    if(pos == 0){
        if((*head)) (*head)->prev = newNode;
        newNode->next = (*head);
        (*head) = newNode;
        return;
    }

    struct DLLNode *temp = (*head);
    while(temp && pos > 1){
        temp = temp->next;
        pos--;
    }
    
    if(pos > 1){
        printf("Out of bounds\n");
        return;
    }

    if(temp->next == NULL){
        temp->next = newNode;
        newNode->prev = temp;
        return;
    }

    newNode->next = temp->next;
    temp->next->prev = newNode;
    newNode->prev = temp;
    temp->next = newNode;
}

void deleteNode(struct DLLNode **head, int pos){
    if((*head) == NULL){
        printf("List empty\n");
        return;
    }

    struct DLLNode* toDelete;

    if(pos == 0){
        toDelete = (*head);
        (*head) = (*head)->next;
        (*head)->prev = NULL;
        free(toDelete);
        return;
    }

    struct DLLNode* temp = (*head);
    while(temp && pos > 0){
        temp = temp->next;
        pos--;
    }
    
    if(pos > 0){
        printf("Out of bound\n");
        return;
    }

    if(temp->next == NULL){
        toDelete = temp;
        temp->prev->next = NULL;
        free(toDelete);
        return;
    }

    toDelete = temp;
    temp->prev->next = temp->next;
    temp->next->prev = temp->prev;
    free(toDelete);
}

void display(struct DLLNode** head){
    struct DLLNode* temp = (*head);
    printf("NULL <- ");
    while(temp->next){
        printf("%d <=> ", temp->val);
        temp = temp->next;
    }
    printf("%d -> NULL\n", temp->val);
}

// int main(){

//     struct DLLNode* head = NULL;
//     int sz = 0;
//     while(sz < 10){
//         insertNode(&head, sz, sz);
//         sz++;
//     }

//     display(&head);

//     deleteNode(&head, 0);
//     display(&head);

//     deleteNode(&head, 8);
//     display(&head);

//     deleteNode(&head, 4);
//     display(&head);

//     insertNode(&head, 5, 4);
//     display(&head);

//     insertNode(&head, 0, 0);
//     display(&head);

//     insertNode(&head, 9, 9);
//     display(&head);

//     return 0;
// }