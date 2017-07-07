#include <stdio.h>

void mul2(int *x){
    *x=*x*2;
}

int main(){
    int a=10;
    printf("%d\n",a);
    printf("multiply 2\n",a);
    mul2(&a);
    printf("%d\n",a);

    return 0;
}

