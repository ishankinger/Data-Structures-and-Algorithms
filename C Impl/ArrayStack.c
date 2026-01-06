#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define MAX_SIZE 1e6

typedef struct{
    int *arr;
    int top;
    int capacity;
} ArrayStack;

ArrayStack* createStack(){
    ArrayStack *st = (ArrayStack*)malloc(sizeof(ArrayStack));
    if(!st) return NULL;
    st->top = -1;
    st->capacity = MAX_SIZE;
    st->arr = (int*)malloc(sizeof(int) * st->capacity);
    if(!st->arr) return NULL;
    return st;
}

int isEmpty(ArrayStack *st){
    return (st->top == -1);
}

int isFull(ArrayStack *st){
    return (st->top == MAX_SIZE-1);
}

void push(ArrayStack *st, int data){
    if(isFull(st))
        printf("Stack Overflow\n");
    else
        st->arr[++st->top] = data;
}

int pop(ArrayStack *st){
    if(isEmpty(st))
        printf("Stack Underflow\n");
    else
        return st->arr[st->top--];
    return INT_MIN;
}

int top(ArrayStack *st){
    if(isEmpty(st))
        printf("Stack Underflow");
    else
        return st->arr[st->top];
    return INT_MIN;
}

void deleteStack(ArrayStack *st){
    if(st){
        if(st->arr)
            free(st->arr);
        free(st);
    }
}

// int main(){

//     ArrayStack *st = createStack();
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