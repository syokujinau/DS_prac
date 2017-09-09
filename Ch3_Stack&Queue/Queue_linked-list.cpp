#include <iostream>
using namespace std;

class Queue{
private:
  class ListNode{
    int data;
    ListNode* link;
    ListNode(int d):data(d),link(NULL){}; //用於加入新data

    friend class Queue;
  };
  ListNode* front;
  ListNode* rear;
public:
  Queue(){
    front = NULL;
    rear  = NULL;
  }
  void enqueue(int num);
  void dequeue(void);
  bool IsEmpty(void);
  void printQ(void);
  void Clear(void);
};

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

void Queue::dequeue(void){
  if(front==NULL){
    cout << "Cannot dequeue the empty Queue.\n";
    return;
  }
  else{
    ListNode* t;
    t = front;
    cout << "Dequeue: "<< t->data <<endl;
    front = front->link;
    if(front==NULL){
      rear = NULL;
    }
    delete t;
    t = NULL;
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


int main() {
  Queue a;
  a.enqueue(1);
  a.enqueue(2);
  a.enqueue(3);
  a.printQ();
  a.dequeue();
  a.printQ();
  a.dequeue();
  a.dequeue();
  a.dequeue();
  a.dequeue();
  
  a.enqueue(5);
  a.printQ();
  if(a.IsEmpty()){
    cout << "Empty!\n";
  }else{
    cout << "NOT empty!\n";
  }
  
  for(int j=0;j<20;j++){
    a.enqueue(j*2);
  }
  a.printQ();
  a.Clear();
  a.printQ();

  return 0;
}
