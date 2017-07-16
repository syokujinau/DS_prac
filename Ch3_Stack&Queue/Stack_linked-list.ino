struct node{
  int info;
  struct node* next;
};

typedef struct node Node;
Node* top;

int count =0;

void setup() {
  Serial.begin(9600);
  create_stack();
  push(1);
  push(2);
  push(3);
  pop();
  list();
  push(5);
  list();
  stack_count();
}

void loop() {
}

void create_stack(){
  Serial.println("stack initial.");
  top = NULL;
}

void stack_count(){
  Serial.println((String)count+" elements in the stack.");
}

void push(int data){
  if(top == NULL){
    top       = (Node*)malloc(sizeof(Node));
    top->next = NULL;
    top->info = data;
  }
  else{
    Node* t;

    t = (Node*)malloc(sizeof(Node));
    t->next = top;
    t->info = data;
    top     = t;
  }
  Serial.println("pushed value : "+(String)data);
  count++;
}

void pop(void){
  if(top == NULL){
    Serial.println("the stack is empty!");
  }
  else{
    Node* t;
    t = top;
    Serial.println("poped value : "+(String)t->info);
    top = top->next;
    free(t);
  }
  count--;
}

void list(){
  Node* t;
  t = top;
  if(t==NULL){
    Serial.println("the stack is empty!");
    return;
  }  
  while(t!=NULL){
    Serial.println((String)t->info);
    t = t->next;
  }
}

/*顯示top元素*/
void TopElement(){
  Serial.println("Top element is : "+(String)top->info);
}


/*檢查stack是否為空*/
void CheckEmpty(){
  if(top == NULL){
    Serial.println(" Stack is empty!");
  }
  else{
    Serial.println((String)count+" elements in this stack.");
  }
}

void clear(){
  Node* t = top;
  while(t != NULL){
    t = top->next;
    free(top);
    top = t;
    t = t->next; 
  }  
  free(t);
  top = NULL;
  Serial.println("cleared!");
  count = 0;
}




