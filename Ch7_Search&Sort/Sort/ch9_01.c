#include <stdio.h>
#include <stdlib.h>

void BubbleSort(int x[],int n) //n筆資料
{
    int i,k,flag,temp;
    
    k = n-1;
    while(k!=0)
    { 
      flag = 0; //紀錄此回合是否有SWAP
      for(i=0;i<=k-1;i++)
      {
         if(x[i] > x[i+1])
         {
              temp = x[i]; x[i] = x[i+1]; x[i+1] = temp;  /* 交換資料 */
              flag = i;
         }
      }
      k = flag;
    }
}

void PrintData(int x[],int n)
{
     int i;
     for(i=0;i<n;i++)             
       printf("%2d  ",x[i]);
     printf("\n");
} 

int main()
{
    int x[5] = {24,7,36,2,65};
    printf("before sort  "); PrintData(x,5);
    BubbleSort(x,5);
    printf("after sort   "); PrintData(x,5);
    system("pause");
    return 0;
}
