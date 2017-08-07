/*C�y��linked-list��@Stack*/

#include <stdio.h>
#include <stdlib.h>
//#include <malloc.h>
#include <stdbool.h>

typedef struct{
    int Int_Item;
    /*   ���|���������A�i�s�W��L���  */
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
    printf("\n/*********����1*********/ \n");//²�檺Push�BPop�ާ@
    //�ΨӸ�push���ƾ�
    element a;
    a.Int_Item=1;
    S_Node_P top = NULL; // �@�}�l�ɡAtop���VNULL
    push(&top,a);   //push 1
    pop(&top,&a);  //pop �O�o�Τ@��element�ܼƩӱ�pop�X���ƭȡA��main��ϥ�pop�X���ƭ�
    printf("pop %d successful...\n",a.Int_Item);
    pop(&top,&a);  //pop�Ű��|

    printf("\n/*********����2*********/ \n");//Push�@�s����(�}�C)�A��pop�X���ݸ��
    S_Node_P top2 = NULL;
    element ary[5];
    element a2; //�Ψөӱ�pop�X�����
    int i;
    for(i=0; i<5; i++){
      ary[i].Int_Item=i+1;
      push(&top2,ary[ i ]);
    }
    PrintStack(top2);
    pop(&top2,&a2);  //pop �O�o�Τ@��element�ܼƩӱ�pop�X���ƭȡA��main��ϥ�pop�X���ƭ�
    printf("pop %d successful...\n",a2.Int_Item);
    PrintStack(top2);

    return 0;
}

/*  �I�s�y�k�� int pushOK = push(&top,Item);  */
int push(S_Node_P *top, element Item){
   S_Node_P temp = (S_Node_P)malloc(sizeof(S_Node));
   if(temp==NULL)
   {
      printf("Out of memory!");
      return false;
   }
   temp->Item = Item;
   temp->link = *top;
   *top = temp;       /*  top�û����V���|����  */
   return true;
}

/*  �I�s�y�k�� int popOK = pop(&top,&Item);  */
int pop(S_Node_P *top,element *Item){
   S_Node_P temp = *top;

   if(temp==NULL)
   {
     printf("Stack is empty!\n");
     return false;
   }
   *Item = temp->Item;
   *top  = temp->link;              /*  top�û����V���|����  */
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
