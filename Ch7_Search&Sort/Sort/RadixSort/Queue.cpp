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
  
  count++;
}

void Queue::dequeue(void){
  if(front==NULL){
    cout << "Cannot dequeue the empty Queue.\n";
    return;
  }
  else{
    ListNode* t;
    t = front;
    //cout << "Dequeue: "<< t->data <<endl;
    front = front->link;
    if(front==NULL){
      rear = NULL;
    }
    delete t;
    t = NULL;
    
    count--;
  }
  
  
}

int Queue::at(int x){
  if(x>=count){
    cout << "[ERROR]at func. out of range!\n";
    return 0; //暫時不知道如何直接跳出int型態函式 暫時print出警告
  }
  else{
    ListNode* t;
    t=front;
    for(int i=0;i<x;i++){
      t = t->link;
    }
    return t->data;
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
  //cout << "Clearing Queue...\n";
  ListNode* tmp;
  while(front!=NULL){
    tmp = front;
    front = front->link;
    delete tmp;
    tmp = NULL;
  }
  front = NULL;
  rear  = NULL;
  
  count = 0;
}

int Queue::size(){
  return count;
}


/*遞迴求出x^y之值*/
int power(int x, int y){
  if(y==0)
    return 1;
  else
    return x*power(x,y-1);
  
}
