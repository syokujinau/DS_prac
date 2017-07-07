//ptt教學文https://www.ptt.cc/man/C_and_CPP/DB9B/DE78/M.1272457739.A.6A0.html
#include <stdio.h>

int main(){
  int *ptr;
  int a=5;
  
  printf("一般變數名稱:a\n");
  printf("一般變數值  :a  = %d\n", a);
  printf("一般變數位址:&a = %0X\n", &a);
  printf("/*************************/\n");
  printf("指標變數名稱:ptr\n");
  printf("指標變數值  :ptr  = %d\n", ptr);
  printf("指標變數位址:&ptr = %0X\n", &ptr);
  printf("\n/********操作指標*********/\n");
  printf("將指標變數值存放a的位址ptr=&a;\n");
  ptr=&a;
  printf("指標變數值  :ptr  = %0X\n", ptr);
  printf("指標變數位址:&ptr = %0X\n", &ptr);
  printf("使用依址取值運算子察看指標變數所指向的資料 *ptr = %d\n",*ptr);
  printf("使用依址取值運算子更動指標變數所指向的資料 令*ptr = 6;\n");
  *ptr=6;
  printf("一般變數值  :a  = %d\n", a);
  
  
  return 0;
}
