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
  int count;  //Queue長度
public:
  Queue(){
    front = NULL;
    rear  = NULL;
    count = 0;
  }
  void enqueue(int num);
  void dequeue(void);
  /*存取指定index的data，由於使用linked-list，存取時間為O(x)*/
  int  at(int x);
  bool IsEmpty(void);
  void printQ(void);
  void Clear(void);
  int  size(void);
};

/*回傳int型態x的y次方數值*/
extern int power(int x, int y);

#endif //QUEUE_H
