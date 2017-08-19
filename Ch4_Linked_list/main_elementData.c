#include <stdio.h>

typedef struct{
  int   a;
  float b;
}element;

struct node{
  element data;
  struct node* link;
};

typedef struct node Node;

Node* InsertNode(Node*, element);
void printList(Node*);

int main(){
  Node* h1=NULL;
  element e1;
  e1.a=1;
  e1.b=2.02;
  h1=InsertNode(h1, e1);
  printList(h1);
  
  element ary[10];
  int i;
  for(i=0; i<10; i++){
    ary[i].a=i+1;
    ary[i].b=i+20.5;
    h1 = InsertNode(h1,ary[i]);
  }
  printList(h1);
  printf("\n\n");
  
};

Node* InsertNode(Node* head, element newdata){
  Node* t = (Node*)malloc(sizeof(Node));
  t->data.a = newdata.a;
  t->data.b = newdata.b;
  t->link   = head;
  
  return t;
}

void printList(Node* head){
  if(head == NULL){
    printf("empty List!!\n");
  }  
  else{
    printf("head->");
    for(;head!=NULL; head=head->link){
      printf("[%d|%.2f]->",head->data.a,head->data.b);
    }
    printf("NULL\n");
  }
}



