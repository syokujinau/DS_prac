#include <stdio.h>
#include <stdlib.h>

int main(){

  struct Node{
    int data;
    struct Node *link;
  };
  typedef struct Node node;
  typedef node *nodePointer;

  node n1,n2;
  nodePointer first;

  return 0;
}