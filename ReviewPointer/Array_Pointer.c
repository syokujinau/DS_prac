#include <stdio.h>
#include <stdlib.h>

int main(){
  int i;
  int a[]= {1,2,3,4,5};
  int *ptr= a;
  // printf("sizeof(a) = %d\n",sizeof(a));
  // printf("sizeof(int) = %d\n",sizeof(int));
  for(i=0;i<sizeof(a)/sizeof(int); i++){
    printf("a[%d] = %d\n", i, a[i]);
    printf("*(ptr+%d)= %d\n",i,*(ptr+i));
  }
  
  return 0;
}

/* 

Output:
a[0] = 1
*(ptr+0)= 1
a[1] = 2
*(ptr+1)= 2
a[2] = 3
*(ptr+2)= 3
a[3] = 4
*(ptr+3)= 4
a[4] = 5
*(ptr+4)= 5

*/
