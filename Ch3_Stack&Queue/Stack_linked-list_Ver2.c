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
  Stack s1=NULL;  //Node 型態的指標變數 名稱叫s1 指向該stack的top
  Push(1,s1);
  Push(2,s1);
  Pop(s1);

  return 0;
}


/*
 *Push函式
 *parameter:(push data, pointer to top of stack)
*/
void Push(int x, Stack s){
  if(s == NULL){
    s       = (PtrToNode)malloc(sizeof(PtrToNode));
    s->data = x;    printf("s->data:%d\n",s->data);      //!!!!!!!!
    s->Next = NULL;
  }
  else{
    PtrToNode Tmp;
    Tmp = (PtrToNode)malloc(sizeof(PtrToNode)); //??
    if(Tmp == NULL){
        printf("out of Memory!\n");
    }
    Tmp->data = x;  printf("Tmp->data:%d\n",Tmp->data); //!!!!!!!!
    Tmp->Next = s;
    s         = Tmp;
  }
  printf("push : %d\n",x);
}

/*
 *Pop函式
 *parameter:(pointer to top)
*/
void Pop(Stack s){
  if(s == NULL){
    printf("Stack is empty!\n");
  }
  else{
    PtrToNode Tmp;
    Tmp  = s;
    printf("pop : %d\n",Tmp->data);
    s    = s->Next;
    free(Tmp);
  }
}

