#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

typedef struct{
    int *arr;
    int top;
    int capacity;
} DyanamicStack;

DyanamicStack* createStack(){
    DyanamicStack *st = (DyanamicStack*)malloc(sizeof(DyanamicStack));
    if(!st) return NULL;
    st->top = -1;
    st->capacity = 1;
    st->arr = (int*)malloc(sizeof(int));
    if(!st->arr) return NULL;
    return st;
}

int isEmpty(DyanamicStack *st){
    return (st->top == -1);
}

int isFull(DyanamicStack *st){
    return (st->top == st->capacity - 1);
}

void doubleStack(DyanamicStack *st){
    st->capacity *= 2;
    st->arr = realloc(st->arr, st->capacity * sizeof(int));
}

void push(DyanamicStack *st, int data){
    if(isFull(st))
        doubleStack(st);
    st->arr[++st->top] = data;
}

int pop(DyanamicStack *st){
    if(isEmpty(st))
        printf("Stack Underflow\n");
    else
        return st->arr[st->top--];
    return INT_MIN;
}

int top(DyanamicStack *st){
    if(isEmpty(st))
        printf("Stack Underflow");
    else
        return st->arr[st->top];
    return INT_MIN;
}

void deleteStack(DyanamicStack *st){
    if(st){
        if(st->arr)
            free(st->arr);
        free(st);
    }
}

int main(){

    DyanamicStack *st = createStack();
    int cnt = 0;
    while(cnt < 10){
        printf("capacity : %d\n", st->capacity);
        push(st, cnt);
        cnt++;
    }
    
    while(!isEmpty(st)){
        printf("%d ", top(st));
        pop(st);
    }

    deleteStack(st);

    return 0;
}