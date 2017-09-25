#include <iostream>
#include "Queue.h"
using namespace std;

void Queue::enqueue(int num){
  ListNode* t = new ListNode(num);
  if((front==NULL)&&(rear==NULL)){
    front = t;
  }
  else{
    rear->link = t;
  }
  rear = t;
}

int Queue::dequeue(void){
  if(front==NULL){
    cout << "Cannot dequeue the empty Queue.\n";
    return 0;
  }
  else{
    ListNode* t;
    int item;
    t = front;
    //cout << "Dequeue: "<< t->data <<endl;
    item = t->data;
    front = front->link;
    if(front==NULL){
      rear = NULL;
    }
    delete t;
    t = NULL;
    
    return item;
  }
}


bool Queue::IsEmpty(void){
  if((front==NULL)&&(rear==NULL)) {
    return true;
  }else{
    return false;
  }
}

void Queue::printQ(void){
  if((front==NULL)&&(rear==NULL)){
    cout << "This is an empty Queue.\n";
  }
  else{
    ListNode* tmp;
    tmp   = front;
    cout << "Queue: \n front| ";
    while(tmp!=NULL){
      cout << tmp->data<<" ";
      tmp = tmp->link;
    } 
    cout << "|rear\n\n";
  }
}

void Queue::Clear(void){
  cout << "Clearing Queue...\n";
  ListNode* tmp;
  while(front!=NULL){
    tmp = front;
    front = front->link;
    delete tmp;
    tmp = NULL;
  }
  front = NULL;
  rear  = NULL;
}
