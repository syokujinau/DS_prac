//另一種寫法 debugging

#include <stdio.h>
#include <stdlib.h>

struct Node {
  int data;
  struct Node* Next;
};
typedef struct Node* PtrToNode; //Node型態指標 別名PtrToNode
typedef PtrToNode Stack;        //即PtrToNode  特別用來指向stack的Top 


void Push(int, Stack); 
void Pop(Stack);

int main(){
  printf("OK\n");
  Stack s1;  //Node 型態的指標變數 名稱叫s1 指向該stack的top
  Push(1,s1);
  Pop(s1);
  
  
  return 0;
}


/* 
 *Push函式
 *parameter:(push data, pointer to top)
*/
void Push(int x, Stack s){
  PtrToNode Tmp;
  Tmp = (PtrToNode*)malloc(sizeof(PtrToNode)); //??
  if(Tmp == NULL){
    printf("out of Memory!\n");
  }
  else{
    Tmp->data = x;
    Tmp->Next = s;
    s         = Tmp;
  }
}

/* 
 *Pop函式
 *parameter:(pointer to top)
*/
void Pop(Stack s){
  PtrToNode Tmp;
  int item;
  if(s == NULL){
    printf("Stack is empty!\n");
  }
  else{
    Tmp  = s;
    item = s->data;
    printf("pop %d\n",item);
    s    = s->Next;
    free(Tmp);
  }
}
