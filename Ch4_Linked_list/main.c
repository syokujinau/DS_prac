/*
c實做鏈結串列
提供功能：
1.Create a linked-list by array
2.Add node 
3.Free the linked-list
4.Print the linked-list
5.Invert the linked-list
*/

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#define AryLength(array) (sizeof(array)/sizeof(int))

struct node{
  int info;
  struct node* link;
};
typedef struct node* NodePtr;

NodePtr CreateList(int *, int);  //傳入陣列＆產生鏈結串列
NodePtr freeList(NodePtr);//清空串列
void printList(NodePtr);  //列出串列資料
NodePtr InvertList(NodePtr);//反轉串列
//欲加入功能
//add node


int main(){
  NodePtr h1;//宣告串列首
  int a[]={1,2,3,4,5,7,8,9,10};//用陣列儲存欲傳入的資料
  h1=CreateList(a,AryLength(a));//產生資料串列
  printList(h1);
  h1=InvertList(h1);//反轉該串列
  printList(h1);
  h1=freeList(h1);//釋放該串列
  printList(h1);
}

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

void printList(NodePtr h){
  if(h == NULL){
    printf("Link is empty\n");
  }
  else{
    printf("HEAD\n");
    for(; h != NULL; h = h->link){
      printf("%d\n",h->info);
    }
    printf("BOTTOM\n");
  }
}

NodePtr freeList(NodePtr h){
  printf("free list\n");
  NodePtr t;
  for(; h!=NULL; h->link){
    t = h;
    h = h->link;
    free(t);
  }
  return h;
}

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





