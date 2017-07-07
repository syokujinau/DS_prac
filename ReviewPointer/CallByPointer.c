#include <stdio.h>

void mul2(int *x){
    *x=*x*2;
}

void Print_hello_world(){
    printf("hello world \n");
}

void do_func_10_times(void (*func)()){
    for (int i = 0; i < 10; i++)
    {
        func();
    }
}

int main(){
    int a=10;
    printf("%d\n",a);
    printf("multiply 2\n",a);
    mul2(&a);
    printf("%d\n",a);


    do_func_10_times(Print_hello_world);

    return 0;
}

