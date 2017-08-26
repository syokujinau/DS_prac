/*   LSD Radix Sort algorithm */
#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <time.h>

/*宣告佇列中節點的結構、結構別名以及指標別名*/
typedef struct list_node *list_pointer;
typedef struct list_node *node_pointer;
typedef struct list_node{
      int data;
      list_pointer next;
}nodetype;

list_pointer SetData(int size)
{
    int i=1;
    node_pointer ptr,before,temp;

    ptr = NULL;
    srand((unsigned) time(NULL));
    temp = (node_pointer)malloc(sizeof(nodetype));
    if(temp==NULL) { printf("記憶體不足!");  exit(1); }
    temp->data = rand() % 1000; /* 隨機產生三位數資料 */
    temp->next = NULL;
    before = temp;
    ptr = before;

    for(i=2;i<=size;i++)
    {
      temp = (node_pointer)malloc(sizeof(nodetype));
      if(temp==NULL) { printf("°O¾ÐÅé¤£¨¬!");  exit(1); }
      temp->data = rand() % 1000; /* 隨機產生三位數資料 */
      temp->next = NULL;
      before->next = temp;
      before = temp;
    }
    return ptr;
  }

void PrintData(list_pointer ptr)
{
    while(ptr!=NULL)
    {
        printf("%4d  ",ptr->data);
        ptr = ptr->next;
    }
    printf("\n");
}

list_pointer LSD_RadixSort(list_pointer ptr, int compare_times)
{
    int i,x,d,s=1;
    list_pointer temp,front[10],rear[10];
    for (i=0;i<compare_times;i++)    /* 從最後一位開始處理m個位數 */
    { 
        for (x=0;x<=9;x++)  //將Queue[0]~[9]初始化
        {
           front[x] = NULL; rear[x] = NULL;
        }
        while(ptr!=NULL) //依照第i位數鍵值進行分配
        {
            d = ((int)(ptr->data/s)) % 10; //取得該位數的數值
            //分配到Queue[0]~[9]
            temp = ptr;
            ptr = ptr->next;
            temp->next = NULL;
            if(front[d]!= NULL)  
            {     /* 若Queue[d]為空 */
               rear[d]->next = temp; rear[d] = temp;
            }
            else  /* 若Queue[d]非空 */
            {  
               front[d] = temp;      rear[d] = temp;
            }
        } 
        //將Queue[0]~[9]依序合併，並且以ptr作為合併後的串列首
        d = 0;
        while(front[d]==NULL)  /* 略過前面空的Queue */
            d++;
        ptr = front[d];        temp=rear[d];
        d++;
        //將各個非空Queue最後一筆紀錄與下個非空串列第一筆紀錄連結再一起
        while(d<10)
        { 
           if (front[d]!=NULL)
           {
              temp->next = front[d];
              temp = rear[d];
           }
           d++;
        }
        s = s*10; //往上一個位數進行處理
   }
   return ptr;
}

int main()
{
   list_pointer ptr=NULL;
   ptr = SetData(8); /* 產生8筆三位數資料 */
   printf("排序前 紀錄為:"); PrintData(ptr);
   ptr = LSD_RadixSort(ptr,3);
   printf("排序後 紀錄為:"); PrintData(ptr);
   system("pause");
   return 0;
}
