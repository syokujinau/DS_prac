#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
//因為sizeof只能適用靜態陣列，但函式只能傳入指標，故需先取得陣列長度
#define a_length(a) (sizeof(a)/sizeof(int))

//宣告linked-list node
struct node{
  int info;
  struct node* link;
};
typedef struct node Node;


Node* CreateList(int*,int);
void print_linked_list(Node *);

int main(void) {
  //宣告串列首
  Node* h1;

  //將陣列a用鏈結串列儲存
  int a[]={1,2,3,4,5};
  h1=CreateList(a,a_length(a));
  print_linked_list(h1);

  return 0;
}


/*************************************
*    將陣列資料使用鏈結串列儲存      *
*    由於傳入的是指標，無法得知      *
*    原本陣列的size，故需另外傳入    *
*************************************/
Node* CreateList(int* ary, int size){
  // printf("?? = %d %d %d\nsize = %d\n\n",ary[0],ary[1],ary[2],sizeof(ary));
  // printf("%0X\n",ary);

  int i;
  Node* head;
  Node* privious = NULL;
  for(i = 0; i < size; i++){
    //printf("%d\n",sizeof(ary)/sizeof(int));
    head = (Node*)malloc(sizeof(Node));
    assert(head != NULL);
    head->info = ary[i];
    head->link = privious;
    privious = head;
  }
  return head;
}


void print_linked_list(Node *head){
  for(; head != NULL; head = head->link){
    printf("data = %d\n",head->info);
  }
}

