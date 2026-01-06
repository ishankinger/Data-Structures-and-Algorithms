#include <stdio.h>
#include <stdlib.h>

typedef struct CLLNode{
    int val;
    struct CLLNode* next;
} CLLNode;

void insertNodeAtPos(struct CLLNode** head, int data, int pos){
    struct CLLNode* newNode = (struct CLLNode*)malloc(sizeof(struct CLLNode));
    newNode->next = NULL;
    newNode->val = data;

    if((*head) == NULL){
        if(pos > 0){
            printf("Out of bounds\n");
            return;
        }
        newNode->next = newNode;
        (*head) = newNode;
        return;
    }

    if(pos == 0){
        struct CLLNode* lastNode = (*head);
        while(lastNode->next != (*head)) 
            lastNode = lastNode->next;
        lastNode->next = newNode;
        newNode->next = (*head);
        (*head) = newNode;
        return;
    }

    struct CLLNode* temp = (*head);
    while(temp->next != (*head) && pos > 1){
        temp = temp->next;
        pos--;
    }

    if(pos > 1){
        printf("Out of bounds\n");
        return;
    }

    if(temp->next == (*head)){
        temp->next = newNode;
        newNode->next = (*head);
        return;
    }

    newNode->next = temp->next;
    temp->next = newNode;
}

void deleteNodeAtPos(struct CLLNode** head, int pos){
    if((*head) == NULL){
        printf("List already empty\n");
        return;
    }

    struct CLLNode* toDelete;
    if(pos == 0){
        if((*head) == (*head)->next){
            (*head) = NULL;
            return;
        }
        struct CLLNode* lastNode = (*head);
        while(lastNode->next != (*head))
            lastNode = lastNode->next;
        lastNode->next = (*head)->next;
        toDelete = (*head);
        (*head) = (*head)->next;
        free(toDelete);
        return;
    }

    struct CLLNode* temp = (*head);
    while(temp->next != (*head) && pos > 1){
        temp = temp->next;
        pos--;
    }

    if(pos > 1 || (pos == 1 && temp->next == (*head))){
        printf("Out of bounds\n");
        return;
    }

    toDelete = temp->next;
    temp->next = temp->next->next;
    free(toDelete);
}

int getCLLlength(struct CLLNode* head){
    struct CLLNode* temp = head;
    int cnt = 0;
    while(temp && temp->next != head){
        temp = temp->next;
        cnt++;
    }
    if(temp) cnt++;
    return cnt;
}

void printingCLL(struct CLLNode* head){
    struct CLLNode* temp = head;
    while(temp && temp->next != head){
        printf("%d -> ", temp->val);
        temp = temp->next;
    }
    if(temp) printf("%d---\n", temp->val);
    else printf("---\n");
}

// int main(){

//     struct CLLNode* head = NULL;
//     int cnt = 0;
//     while(cnt < 10){
//         printf("Len : %d\n", getCLLlength(head));
//         printingCLL(head);
//         printf("\n");
//         insertNodeAtPos(&head, cnt, cnt);
//         cnt++;
//     }
//     printf("Len : %d\n", getCLLlength(head));
//     printingCLL(head);
//     printf("\n");

//     while(cnt > 0){
//         int ind = rand() % cnt;
//         printf("Delete Ind : %d \n", ind);
//         deleteNodeAtPos(&head, ind);
//         cnt = getCLLlength(head);
//         printf("Len : %d\n", cnt);
//         printingCLL(head);
//         printf("\n");
//     }

//     return 0;
// }