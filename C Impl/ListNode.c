#include <stdio.h>
#include <stdlib.h>

typedef struct ListNode{
    int val;
    struct ListNode* next;
} ListNode;

struct ListNode* createNode(int val){
    struct ListNode* newNode = (struct ListNode*)malloc(sizeof(struct ListNode));
    if(!newNode){
        printf("Error Creating Node\n");
        return NULL;
    }
    newNode->next = NULL;
    newNode->val = val;
    return newNode;
}

void insertAtBegin(struct ListNode** root, int val){
    struct ListNode* newNode = createNode(val);
    newNode->next = (*root);
    (*root) = newNode;
}

void insertAtEnd(struct ListNode** root, int val){
    struct ListNode* node = (*root);
    struct ListNode* newNode = createNode(val);
    if(node == NULL){
        (*root) = newNode;
        return;
    }
    while(node->next)
        node = node->next;
    node->next = newNode;
}

void insertAtPos(struct ListNode** root, int pos, int val){
    if(pos == 0){
        insertAtBegin(root, val);
        return;
    }

    struct ListNode* node = (*root);
    while(node && pos > 1){
        node = node->next;
        pos--;
    }

    if(pos > 1){
        printf("Out of bounds\n");
        return;
    }
    
    struct ListNode* newNode = createNode(val);
    newNode->next = node->next;
    node->next = newNode;
}

void deleteAtBegin(struct ListNode** root){
    if((*root) == NULL){
        printf("Already empty\n");
        return;
    }

    struct ListNode* toDelete = (*root);
    (*root) = (*root)->next;
    free(toDelete);
}

void deleteAtEnd(struct ListNode** root){
    if((*root) == NULL){
        printf("Already empty\n");
        return;
    }

    if((*root)->next == NULL){
        deleteAtBegin(root);
        return;
    }

    struct ListNode* node = (*root);
    while(node->next->next) 
        node = node->next;

    struct ListNode* toDelete = node->next;
    node->next = NULL;
    free(toDelete);
}

void deleteAtPos(struct ListNode** root, int pos){
    if(pos == 0){
        deleteAtBegin(root);
        return;
    }

    struct ListNode* node = *root;
    while(node && pos > 1){
        node = node->next;
        pos--;
    }

    if(pos > 1 || (pos == 1 && node->next == NULL)){
        printf("Out of bounds\n");
        return;
    }

    struct ListNode* toDelete = node->next;
    node->next = node->next->next;
    free(toDelete);
}

int listLength(struct ListNode* root){
    struct ListNode* node = root;
    int len = 0;
    while(node){
        node = node->next;
        len++;
    }
    return len;
}

void printList(struct ListNode* root){
    struct ListNode* node = root;
    while(node){
        printf("%d ", node->val);
        node = node->next;
    }
    printf("\n");
}

void deleteList(struct ListNode* root){
    struct ListNode* node = root;
    while(node){
        struct ListNode* toDelete = node;
        node = node->next;
        free(toDelete);
    }
}

// int main(){

//     struct ListNode* root = NULL;
//     insertAtEnd(&root, 3);
//     printList(root);

//     insertAtBegin(&root, 2);
//     printList(root);

//     insertAtEnd(&root, 6);
//     printList(root);

//     insertAtPos(&root, 0, 1);
//     printList(root);

//     insertAtPos(&root, 3, 4);
//     printList(root);

//     insertAtPos(&root, 4, 5);
//     printList(root);

//     insertAtPos(&root, 6, 7);
//     printList(root);

//     listLength(root);

//     deleteAtBegin(&root);
//     printList(root);

//     deleteAtEnd(&root);
//     printList(root);

//     deleteAtPos(&root, 0);
//     printList(root);

//     deleteAtPos(&root, 3);
//     printList(root);

//     deleteAtPos(&root, 1);
//     printList(root);
    
//     listLength(root);

//     deleteList(root);

//     return 0;
// }