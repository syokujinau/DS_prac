/*
c實作鏈結串列
功能：
1.Create a linked-list by array
2.Add node 
3.Delete node
4.Free the linked-list
5.Print the linked-list
6.Invert the linked-list
*/

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#define ArySize(array) (sizeof(array)/sizeof(int))

struct node{
  int info;
  struct node* link;
};
typedef struct node* NodePtr;


/*初始化串列首記得指向NULL*/
NodePtr CreateList(int *ary, int size);  //傳入陣列＆產生鏈結串列
NodePtr freeList(NodePtr h);//清空串列
void printList(NodePtr h);  //列出串列資料
NodePtr InvertList(NodePtr h);//反轉串列
NodePtr AddNode(NodePtr h, int data);  //新增data於head
NodePtr DeleteNode(NodePtr h, int* buf); //刪除data於head，用buf儲存該筆資料


int main(){
  
  printf("/*********************************/\n/*實驗1:將Array轉成Linked-list儲存*/\n/*********************************/\n");
  NodePtr h1=NULL;//宣告串列首
  int a[]={1,2,3,4,5,7,8,9,10};//用陣列儲存欲傳入的資料
  h1=CreateList(a,ArySize(a));//產生資料串列
  printList(h1);
  
  printf("\n\n/*********************************/\n/*     實驗2:反轉該Linked-list    */\n/*********************************/\n");
  h1=InvertList(h1);//反轉該串列
  printList(h1);
  
  printf("\n\n/***************************************/\n/*實驗3:清除該Linked-list並釋放記憶體空間*/\n/***************************************/\n");
  h1=freeList(h1);//釋放該串列
  printList(h1);
  
  printf("\n\n/************************************/\n/*實驗4:使用AddNode()產生Linked-list */\n/*       並且DeleteNode()           */\n/************************************/\n");
  NodePtr h2=NULL;   
  h2 = AddNode(h2, 11);
  h2 = AddNode(h2, 22);
  h2 = AddNode(h2, 33);
  printList(h2);
  int b=0;
  printf("b = %d\n",b);
  h2 = DeleteNode(h2, &b);
  printList(h2);
  printf("b = %d\n",b);
  
}


/*
function: 傳入陣列並產生鏈結串列
parameter: array,size of array
return: head of linked-list
*/
NodePtr CreateList(int *ary, int size){
  int i;
  NodePtr head;
  NodePtr privious = NULL;
  for(i = 0; i < size; i++){
    head = (NodePtr)malloc(sizeof(struct node));
    assert(head != NULL);
    head->info = ary[i];
    head->link = privious;
    privious   = head;
  }
  return head;
}

/*
function:列印鏈結串列
parameter:head of linked-list
*/
void printList(NodePtr h){
  if(h == NULL){
    printf("Link is empty\n");
  }
  else{
    printf("HEAD → ");
    for(; h != NULL; h = h->link){
      printf("[%d] → ",h->info);
    }
    printf(" NULL\n");
  }
}

/*
function: 清空串列，釋放記憶體空間
parameter: head of linked-list
return: head of linked-list
*/
NodePtr freeList(NodePtr h){
  printf("free list...\n");
  NodePtr t;
  for(; h!=NULL; h->link){
    t = h;
    h = h->link;
    free(t);
  }
  return h;
}

/*
function: 反轉串列
parameter: head of linked-list
return: head of linked-list
*/
NodePtr InvertList(NodePtr h){
  NodePtr r,s,s_priv;
  r = h;
  s = NULL;
  while(r!=NULL){
    s_priv  = s;
    s       = r;
    r       = r->link;
    s->link = s_priv;
  }
  return s;
}

/*
function: 新增一筆資料於串列首
parameter: head of linked-list，new (int)data
return: head of linked-list
*/
NodePtr AddNode(NodePtr h, int data){ //傳入指向串列首的指標以及欲新增資料
  NodePtr t = (NodePtr)malloc(sizeof(struct node));
  t->info = data;
  t->link = h;
  h       = t;
  
  return h;
}

/*
function: 刪除一筆資料於串列首，並儲存於buf
parameter: head of linked-list，pointer (int)buf
return: head of linked-list
*/
NodePtr DeleteNode(NodePtr h, int* buf){
  if(h == NULL){
    printf("Cannot delete empty list...\n");
  }
  else{
    NodePtr t;
    t = h;
    *buf = h->info;
    h    = h->link;
    free(t);
  }
  return h;
}



