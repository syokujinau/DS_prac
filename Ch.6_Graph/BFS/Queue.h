#ifndef QUEUE_H
#define QUEUE_H

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
  int  dequeue(void);
  bool IsEmpty(void);
  void printQ(void);
  void Clear(void);
};

#endif //QUEUE_H
