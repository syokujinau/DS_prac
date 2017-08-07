/*C語言linked-list實作Stack*/

#include <stdio.h>
#include <stdlib.h>
//#include <malloc.h>
#include <stdbool.h>

typedef struct{
    int Int_Item;
    /*   堆疊元素成員，可新增其他欄位  */
}element;

struct Stack_Node{
    element Item;
    struct Stack_Node *link;
};

typedef struct Stack_Node S_Node;
typedef S_Node *S_Node_P;

int push(S_Node_P*,element);
int pop(S_Node_P*,element*);
void PrintStack(S_Node_P);


int main(void)
{
    printf("\n/*********實驗1*********/ \n");//簡單的Push、Pop操作
    //用來裝push的數據
    element a;
    a.Int_Item=1;
    S_Node_P top = NULL; // 一開始時，top指向NULL
    push(&top,a);   //push 1
    pop(&top,&a);  //pop 記得用一個element變數承接pop出的數值，使main能使用pop出的數值
    printf("pop %d successful...\n",a.Int_Item);
    pop(&top,&a);  //pop空堆疊

    printf("\n/*********實驗2*********/ \n");//Push一連串資料(陣列)，並pop出頂端資料
    S_Node_P top2 = NULL;
    element ary[5];
    element a2; //用來承接pop出的資料
    int i;
    for(i=0; i<5; i++){
      ary[i].Int_Item=i+1;
      push(&top2,ary[ i ]);
    }
    PrintStack(top2);
    pop(&top2,&a2);  //pop 記得用一個element變數承接pop出的數值，使main能使用pop出的數值
    printf("pop %d successful...\n",a2.Int_Item);
    PrintStack(top2);

    return 0;
}

/*  呼叫語法為 int pushOK = push(&top,Item);  */
int push(S_Node_P *top, element Item){
   S_Node_P temp = (S_Node_P)malloc(sizeof(S_Node));
   if(temp==NULL)
   {
      printf("Out of memory!");
      return false;
   }
   temp->Item = Item;
   temp->link = *top;
   *top = temp;       /*  top永遠指向堆疊頂端  */
   return true;
}

/*  呼叫語法為 int popOK = pop(&top,&Item);  */
int pop(S_Node_P *top,element *Item){
   S_Node_P temp = *top;

   if(temp==NULL)
   {
     printf("Stack is empty!\n");
     return false;
   }
   *Item = temp->Item;
   *top  = temp->link;              /*  top永遠指向堆疊頂端  */
   free(temp);
   return true;
}

void PrintStack(S_Node_P top){
    S_Node_P visitP;
    visitP = top;
    printf("Stack top\n");
    while(visitP!=NULL)
    {
       printf("| %d |\n",visitP->Item.Int_Item);
       visitP = visitP->link;
    }
    printf("bottom\n");
}
