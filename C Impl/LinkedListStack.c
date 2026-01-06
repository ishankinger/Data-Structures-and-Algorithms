#include "ListNode.c"
#include <limits.h>

typedef struct {
    ListNode* head;
} LinkedListStack;

LinkedListStack* createStack(){
    LinkedListStack *st = (LinkedListStack*)malloc(sizeof(LinkedListStack));
    st->head = createNode(-1);
    return st;
}

int isEmpty(LinkedListStack *st){
    return (listLength(st->head) == 1);
}

void push(LinkedListStack *st, int data){
    insertAtBegin(&st->head, data);
}

int pop(LinkedListStack *st){
    if(isEmpty(st)){
        printf("Stack Underflow\n");
        return INT_MIN;
    }
    int data = st->head->val;
    deleteAtBegin(&st->head);
    return data;
}

int top(LinkedListStack *st){
    if(isEmpty(st)){
        printf("Stack Underflow\n");
        return INT_MIN;
    }
    return st->head->val;
}

void deleteStack(LinkedListStack *st){
    if(st){
        if(st->head)
            deleteList(st->head);
        free(st);
    }
}

// int main(){

//     LinkedListStack *st = createStack();
//     int cnt = 0;
//     while(cnt < 10){
//         push(st, cnt);
//         cnt++;
//     }
    
//     while(!isEmpty(st)){
//         printf("%d ", top(st));
//         pop(st);
//     }

//     deleteStack(st);

//     return 0;
// }