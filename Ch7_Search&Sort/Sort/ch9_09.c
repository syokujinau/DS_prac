/*   Heap Sort algorithm  */
#include <stdio.h>
#include <stdlib.h>

void PrintData(int x[],int i,int n)
{
    int j;
    for(j=i;j<=n;j++)
      printf("%2d  ",x[j]);
    printf("\n");
} 

void AdjustToHeap(int x[],int root,int n)
{//比delete_maxheap多2個參數，其中x[]相當於heap[]，root則是代表根節點，請自行比對delete_maxheap
   int temp,parent,child;

   
   temp = x[root];               /* 取出根節點鍵值放入temp */
   parent = root;                /* 父點的編號 */
   child = 2 * root;             /* 左子點的編號 */
    while(child <= n)
    {
       if ((child < n) && (x[child] < x[child+1]))
         child = child + 1;    /* 右子點較大，所以應比較右子點 */ 
       
       if(temp >= x[child])  
          break;              /* 已完成修正 */
       else
       {
          x[parent] = x[child];        /* 與較大的子點互換 */
          parent = child;              /* 移至下一層 */
          child = child * 2;
       }
    }
    x[parent] = temp;  /* 根節點鍵值放入正確位置   */
}

void HeapSort(int x[],int i,int n)
{
    int temp;
    for(i=n/2;i>=1;i--)
    {
      AdjustToHeap(x,i,n);    /* 將x[i]~x[n]子樹調整為max heap */
    }
    printf("max heap:\t");
    PrintData(x,1,10);        
    for(i=n-1;i>=1;i--)
    {
      temp = x[1];
      x[1] = x[i+1];
      x[i+1] = temp;
      AdjustToHeap(x,1,i); 
      printf("i=%d的max heap:\t",i);
      PrintData(x,1,i); 
    }
}

int main()
{               //第一個元素0不使用
    int x[11] = {0,24,17,36,55,63,72,12,65,89,54};

    printf("排序前  x[1:10]="); PrintData(x,1,10);
    HeapSort(x,1,10);
    printf("排序後  x[1:10]="); PrintData(x,1,10);
    
    system("pause");
    return 0;
}
