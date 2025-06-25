#include <stdio.h>
#include <stdlib.h>

int add(int a, int b) {
    return a + b;
}

void func1(int *a){
    printf("%d\n", sizeof(a));
    return;
}

void func2(int (*a)[5]){
    printf("%d\n", sizeof(a));
    return;
}

void func3(int (*a)[5]){
    printf("%d\n", sizeof(*a));      // size must be present 
    return;
}

void func4(int a[][5]){
    printf("%d", (int)a);
    printf("hleel\n");
}

int main(){

    // int *ptr = (int*)(malloc(sizeof(int) * 4));
    // int **ptr2 = &(ptr);
    // int ***ptr3 = &(ptr2);

    // int *temp = ptr;
    // for(int i = 0; i < 4; i++) printf("%p  ", temp + i);
    // printf("\n");

    // printf("%p\n", &ptr);
    // printf("%p\n", ptr2);
    // printf("%p\n", &ptr2);
    // printf("%p\n", ptr3);

    // int b = 10;
    // int *p1 = &b;
    // int **p2 = &p1;
    // p2++;



    // int a[5];
    // int *ptr1 = a;
    // int *ptr2 = &a[0];
    // int *ptr3 = &a;
    // int (*ptr4)[5] = &a;

    // printf("%p\n", ptr1);
    // printf("%p\n", ptr2);
    // printf("%p\n", ptr3);
    // printf("%p\n", ptr4);

    // ptr1++, ptr2++, ptr3++, ptr4++;

    // printf("%p\n", ptr1);
    // printf("%p\n", ptr2);
    // printf("%p\n", ptr3);
    // printf("%p\n", ptr4);


    // int a = 10;
    // int *ptr1 = &a;
    // int **ptr2 = &ptr1;
    // int ***ptr3 = &ptr2;

    // printf("%d\n", ptr1);
    // printf("%d\n", ptr2);
    // printf("%d\n", ptr3);

    // ptr1++, ptr2++, ptr3++;

    // printf("%d\n", ptr1);
    // printf("%d\n", ptr2);
    // printf("%d\n", ptr3);


    // int (*fptr)(int, int);

    // fptr = &add;

    // printf("%p\n", add);
    // printf("%p\n", &add);

    // printf("%d", fptr(10, 5));


    // int arr[5] = { 1, 2, 3, 4, 5 };
  
    // int *a = (int*)malloc(sizeof(int) * 5);
    // a = arr;
    // int (*b)[5] = &arr;
  	// printf("%d\n", sizeof(a));
    // printf("%d\n", sizeof(b));
    // printf("%d\n", sizeof(arr));



    // int a[4][2] = {{1,2},{3,4},{5,6},{7,8}};
    // for(int i = 0; i < 4; i++){
    //     for(int j = 0; j < 2; j++){
    //         printf("(val = %d  addr = %d)   ", a[i][j], (int)(&a[i][j]));
    //     }
    //     printf("\n");
    // }

    // printf("\n\n");

    // for(int i = 0; i < 4; i++){
    //     printf("%d  ->  %d\n", i, (int)(a[i]));
    // }

    // int a[5] = {1, 2, 3, 4, 5};

    // int (*ptr_a)[5] = &a;
    // printf("%d\n", (int)(a));
    // printf("%d\n", (int)(&ptr_a));
    // printf("%d\n", (int)(ptr_a));
    // printf("%d\n", (int)(*ptr_a));
    // printf("%d\n", (int)(**ptr_a));

    // printf("\n\n");

    // printf("%d\n", (int)sizeof(a));
    // printf("%d\n", (int)sizeof(ptr_a));
    // printf("%d\n", (int)sizeof(&ptr_a));
    
    // printf("%d\n", (int)(ptr_a));
    // ptr_a++;
    // printf("%d\n", (int)(ptr_a));
    // ptr_a++;
    // printf("%d\n", (int)(ptr_a));

    // int a[5];
    // func1(a);
    // func2(&a);
    // func3(&a);
    // printf("%d\n", (int)a);
    // printf("%d\n", (int)&a);

    int a[5] = {1, 2, 3, 4, 5};
    printf("%d\n", (int)a);
    printf("%d\n", (int)(&a));
    printf("%d\n", (int)(a + 1));
    printf("%d\n", (int)(&a + 1));
    printf("%d\n", (int)(*(&a)));
    printf("%d\n", (int)(*(&a + 1)));


    return 0;
}