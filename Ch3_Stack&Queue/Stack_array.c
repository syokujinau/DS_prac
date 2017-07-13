/*stack implement using array*/

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#define MAX 3

void push(void);
void pop(void);
void list(void);
char item[MAX][20];
int top = -1;

int main(){
    char option;
    while(1){
        printf("\n*********************\n");
        printf("     <1>insert (push)\n");
        printf("     <2>delete (pop)\n");
        printf("     <3>list\n");
        printf("     <4>quit\n");
        printf("*********************\n");
        printf(" Please enter your chioce...");
        option = getche();
        switch(option){
            case '1':
                push();
                break;
            case '2':
                pop();
                break;
            case '3':
                list();
                break;
            case '4':
                printf("\n");
                return 0;
        }
    }
}

void push(void){
    if(top >= MAX - 1){
        printf("\n\n【reject!!】Stack is full !\n");
    }
    else{
        top++;
        printf("\n\n Please enter item to insert: ");
        gets(item[top]);
    }
}

void pop(void){
    if(top < 0){
        printf("\n\n No item ,stack is empty ! \n");
    }
    else{
        printf("\n\n Item 「%s」 deleted. \n", item[top]);
        top--;
    }
}

void list(void){
    int count = 0, i;
    if(top < 0) {
        printf("\n\n No item, stack is empty.\n");
    }
    else {
        printf("\n\n ITEM\n");
        printf("-------------\n");
        for(i = 0; i <= top; i++){
            printf("  %-20s\n", item[i]);
            count++;
            if(count % 20 == 0) getch();
        }
        printf("-------------\n");
        printf(" Total item : %d\n", count);
        getch();
    }
}














