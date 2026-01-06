#include <stdio.h>
#include <stdarg.h>

enum mar_status{
    married = 3,
    divorced = 5,
    widowed,
    affair = 6,
    single
};

int func(int tot_num, int a, ...){
    int max, count, num;
    va_list ptr;
    va_start(ptr, a);
    max = va_arg(ptr, int);
    for(count = 1; count < tot_num; count++){
        num = va_arg(ptr, int);
        if(num > max) max = num;
    }
    return (max);
}

int main(){

    // printf("%d\n", married);
    // printf("%d\n", divorced);
    // printf("%d\n", widowed);
    // printf("%d\n", affair);
    // printf("%d\n", single);

    printf("%d\n", func(3, 5, 2, 1, 7));

    return 0;
}