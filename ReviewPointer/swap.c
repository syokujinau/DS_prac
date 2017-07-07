#include <stdio.h>

void swap(int *a,int *b){
  int temp;
  temp=*a;
  *a=*b;
  *b=temp;
}

int main(){
  
  int a1=11,a2=22;
  printf("a1 = %d, a2 = %d\n",a1,a2);
  printf("swaping...\n");
  swap(&a1,&a2);
  printf("a1 = %d, a2 = %d\n",a1,a2);
  
  return 0;
  
}
