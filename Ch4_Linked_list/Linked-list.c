#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

struct listnode{
  int data;
  struct listnode *next;
};
typedef struct listnode Listnode;

void print_linked_list(Listnode *head){
  for(; head != NULL; head = head->next){
    printf("data = %d\n",head->data);
  }
}

int main(void){
  int i;
  int array[5]={1,2,3,4,5};
  Listnode *head;
  Listnode *previous = NULL;

  for(i = 0; i < 5; i++){
    head = (Listnode *)malloc(sizeof(Listnode));
    assert(head != NULL);
    head->data = array[i];
    head->next = previous;
    previous = head;
  }
  print_linked_list(head);

  return 0;
}