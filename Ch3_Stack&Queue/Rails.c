#include <stdio.h>
#include <stdlib.h>

struct node{
  int info;
  struct node* next;
};

typedef struct node Node;
Node *top;

void create_stack(void);
void stack_count(void);
void push(int);
void pop(void);
void list(void);
void TopElement(void);
void CheckEmpty(void);
void clear(void);

int count = 0;

int main(){
    create_stack();

    int a=0;
    printf("\n Enter n :");
    while(1){
      scanf("%d",&a);
      if (a == 0){
        printf("\n");
      }
      else{

      }

    }


    return 0;
}




/*初始化stack*/
void create_stack(){
  printf(" (* ^ ω ^)\n");
  top = NULL;
}

/*顯示stack的元素個數*/
void stack_count(){
  printf("\n %d elements in stack",count);
}

void push(int data){
  if(top == NULL){ //第一個node
    top        = (Node*)malloc(1*sizeof(Node));
    top->next  = NULL;
    top->info  = data;
  }
  else{  //繼續疊上去
    Node* temp;

    temp       = (Node*)malloc(1*sizeof(Node));
    temp->next = top;
    temp->info = data;
    top        = temp;
  }
  printf("\n pushed value : %d",data);
  count++;
}

void pop(){
  if(top == NULL){ //已經沒node了
    printf("\n Error : Stack is empty!");
    return;
  }
  else{
    Node* temp;

    temp = top; //用來指向最上面的node 之後把這空間free掉
    printf("\n Poped value : %d", top->info);
    top  = top->next;
    free(temp);
  }
  count--;
}

/*列出stack內所有元素*/
void list(){
  Node* temp;

  temp = top;
  if(temp == NULL){
    printf("\n Stack is empty!");
    return;
  }

  while(temp != NULL){
    printf("\n %d",temp->info);
    temp = temp->next;
  }
}

/*顯示top元素*/
void TopElement(){
  printf("\n Top element is : %d",top->info);
}


/*檢查stack是否為空*/
void CheckEmpty(){
  if(top == NULL){
    printf("\n Stack is empty!");
  }
  else{
    printf("\n %d elements in this stack.",count);
  }
}

/*清除stack內所有元素*/
void clear(){
  Node* temp = top;

  while(temp != NULL){
    temp = top->next;
    free(top);
    top  = temp;
    temp = temp->next;
  }
  free(temp);
  top = NULL;
  printf("\n All stack elements were cleared.");
  count = 0;
}
