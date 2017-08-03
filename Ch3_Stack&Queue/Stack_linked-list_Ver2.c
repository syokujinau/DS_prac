//另一種寫法 debugging

#include <stdio.h>
#include <stdlib.h>

struct Node;
typedef struct Node* PtrToNode;
typedef PtrToNode Stack;
struct Node {
  int data;
  PtrToNode Next;
};

void Push(int, Stack);
void Pop(Stack);

int main(){
  printf("OK\n");
  Stack s1;
  Push(1,s1);
  Pop(s1);
  
  
  return 0;
}


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
