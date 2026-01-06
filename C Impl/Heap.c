#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

struct Heap{
    int *arr;
    int count;
    int capacity;
    int heapType;  // 1 - minHeap, 0 - maxHeap
};

struct Heap* createHeap(int, int);
int parentNode(struct Heap*, int);
int leftChildNode(struct Heap*, int);
int rightChildNode(struct Heap*, int);
void resizeHeap(struct Heap*);
int isEmpty(struct Heap*);
int getSize(struct Heap*);
int getCapacity(struct Heap*);
int getTopElement(struct Heap*);
void insertElementHeap(struct Heap*, int);
void deleteElementHeap(struct Heap*);
void heapify(struct Heap*, int);
void buildHeap(struct Heap*, int*, int, int);
void destroyHeap(struct Heap*);
void printHeapState(struct Heap*);

void swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

int minVal(int a, int b){
    return (a < b) ? a : b;
}

int maxVal(int a, int b){
    return (a > b) ? a : b;
}

struct Heap* createHeap(int capacity, int heap_type){
    struct Heap* h = (struct Heap*)malloc(sizeof(struct Heap));
    if(h == NULL){
        printf("MEMORY ERROR\n");
        return NULL;
    }

    h->heapType = heap_type;
    h->capacity = capacity;
    h->count = 0;

    h->arr = (int*)malloc(sizeof(int) * capacity);
    if(h->arr == NULL){
        printf("MEMORY ERROR\n");
        return NULL;
    }

    return h;
}

int parentNode(struct Heap* h, int node){
    if(node <= 0 || node >= h->count)
        return -1;
    return (node - 1) / 2;
}

int leftChildNode(struct Heap* h, int node){
    int lcn = 2*node + 1;
    return (lcn < h->count) ? lcn : -1;
}

int rightChildNode(struct Heap* h, int node){
    int rcn = 2*node + 2;
    return (rcn < h->count) ? rcn : -1;
}

int isEmpty(struct Heap* h){
    return (h->count == 0);
}

int getSize(struct Heap* h){
    return h->count;
}

int getCapacity(struct Heap* h){
    return h->capacity;
}

void resizeHeap(struct Heap* h){
    int *arr_old = h->arr;
    h->arr = (int*)malloc(sizeof(int) * h->capacity * 2);
    if(h->arr == NULL){
        printf("MEMORY ERROR\n");
        return;
    }
    for(int i = 0; i < h->capacity; i++)
        h->arr[i] = arr_old[i];
    
    h->capacity *= 2;
    free(arr_old);
}

int getTopElement(struct Heap* h){
    return (h->count == 0) ? -1 : h->arr[0];
}

void insertElementHeap(struct Heap* h, int ele){
    if(h->count == h->capacity)
        resizeHeap(h);

    h->count++;
    int node = h->count - 1;
    h->arr[node] = ele;

    if(h->heapType){
        while(parentNode(h, node) >= 0 && h->arr[parentNode(h, node)] > h->arr[node]){
            swap(&h->arr[parentNode(h, node)], &h->arr[node]);
            node = parentNode(h, node);
        }
    }
    else{
        while(parentNode(h, node) >= 0 && h->arr[parentNode(h, node)] < h->arr[node]){
            swap(&h->arr[parentNode(h, node)], &h->arr[node]);
            node = parentNode(h, node);
        }
    }
}

void deleteElementHeap(struct Heap* h){
    if(h->count == 0){
        printf("HEAP EMPTY\n");
        return;
    }

    swap(&h->arr[0], &h->arr[h->count-1]);
    h->count--;

    int node = 0;

    if(h->heapType){
        while(leftChildNode(h, node) != -1){
            int leftChildVal = h->arr[leftChildNode(h, node)];
            int rightChildVal = rightChildNode(h, node) != -1 ? h->arr[rightChildNode(h, node)] : INT_MAX;
            if(h->arr[node] <= minVal(leftChildVal, rightChildVal))
                break;
            if(leftChildVal > rightChildVal){
                swap(&h->arr[node], &h->arr[rightChildNode(h, node)]);
                node = rightChildNode(h, node);
            }
            else{
                swap(&h->arr[node], &h->arr[leftChildNode(h, node)]);
                node = leftChildNode(h, node);
            }
        }
    }
    else{
        while(leftChildNode(h, node) != -1){
            int leftChildVal = h->arr[leftChildNode(h, node)];
            int rightChildVal = rightChildNode(h, node) != -1 ? h->arr[rightChildNode(h, node)] : INT_MIN;
            if(h->arr[node] >= maxVal(leftChildVal, rightChildVal))
                break;
            if(leftChildVal < rightChildVal){
                swap(&h->arr[node], &h->arr[rightChildNode(h, node)]);
                node = rightChildNode(h, node);
            }
            else{
                swap(&h->arr[node], &h->arr[leftChildNode(h, node)]);
                node = leftChildNode(h, node);
            }
        }
    }
}

void heapify(struct Heap* h, int ind){
    int node = ind;

    if(h->heapType){
        while(leftChildNode(h, node) != -1){
            int leftChildVal = h->arr[leftChildNode(h, node)];
            int rightChildVal = rightChildNode(h, node) != -1 ? h->arr[rightChildNode(h, node)] : INT_MAX;
            if(h->arr[node] <= minVal(leftChildVal, rightChildVal))
                break;
            if(leftChildVal > rightChildVal){
                swap(&h->arr[node], &h->arr[rightChildNode(h, node)]);
                node = rightChildNode(h, node);
            }
            else{
                swap(&h->arr[node], &h->arr[leftChildNode(h, node)]);
                node = leftChildNode(h, node);
            }
        }
    }
    else{
        while(leftChildNode(h, node) != -1){
            int leftChildVal = h->arr[leftChildNode(h, node)];
            int rightChildVal = rightChildNode(h, node) != -1 ? h->arr[rightChildNode(h, node)] : INT_MIN;
            if(h->arr[node] >= maxVal(leftChildVal, rightChildVal))
                break;
            if(leftChildVal < rightChildVal){
                swap(&h->arr[node], &h->arr[rightChildNode(h, node)]);
                node = rightChildNode(h, node);
            }
            else{
                swap(&h->arr[node], &h->arr[leftChildNode(h, node)]);
                node = leftChildNode(h, node);
            }
        }
    }
}

void buildHeap(struct Heap* h, int *a, int n, int heap_type){
    if(h == NULL)
        return;
    
    while(n > h->capacity)
        resizeHeap(h);
    
    for(int i = 0; i < n; i++)
        h->arr[i] = a[i];

    h->count = n;
    h->heapType = heap_type;

    for(int node = (h->count-1)/2; node >= 0; node--)
        heapify(h, node);
}

void destroyHeap(struct Heap* h){
    if(h == NULL)
        return;
    free(h->arr);
    free(h);
}

void printHeapState(struct Heap* h){
    for(int i = 0; i < h->count; i++){
        printf("%d ", h->arr[i]);
    }
    printf("\n");
}

int main(){

    int arr[10] = {0, 3, 2, 8 , 2, 5, 6, 4, 9, 5};

    struct Heap* minHeap = createHeap(100, 1);
    for(int i = 0; i < 10; i++){
        printf("%d -> ", i);
        insertElementHeap(minHeap, arr[i]);
        printHeapState(minHeap);
    }

    printf("\n");

    for(int i = 0; i < 10; i++){
        printf("%d -> ", i);
        printf("%d    ", getTopElement(minHeap));
        deleteElementHeap(minHeap);
        printHeapState(minHeap);
    }
    printf("\n");

    destroyHeap(minHeap);

    struct Heap* maxHeap = createHeap(100, 0);
    for(int i = 0; i < 10; i++){
        printf("%d -> ", i);
        insertElementHeap(maxHeap, arr[i]);
        printHeapState(maxHeap);
    }

    printf("\n");
    
    for(int i = 0; i < 10; i++){
        printf("%d -> ", i);
        printf("%d    ", getTopElement(maxHeap));
        deleteElementHeap(maxHeap);
        printHeapState(maxHeap);
    }
    
    printf("\n");

    destroyHeap(maxHeap);

    return 0;
}