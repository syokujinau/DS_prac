#include <iostream>
using namespace std;
/*
此為Linear queue，會隨著dequeue的次數增加可用空間變小，
解決方法是使用另一種Circular queue
*/
class Queue{
  private:
    int *queueArray;
    int capacity; //最大data數
    int front;
    int rear;
    int size; //實際data數
    
  public:
    Queue(int c);
    ~Queue(void);
    void enqueue(int num);
    void dequeue(void);
    bool IsEmpty(void);
    bool IsFull(void);
    void printQ(void);
    void clear(void); //重置front、rear的index
};

Queue::Queue(int c){
  queueArray = new int[c];
  capacity = c;
  front = -1;
  rear  = -1;
  size  =  0;
}

Queue::~Queue(void){
  delete[] queueArray;//建構子使用new，需要對應解構子
}

void Queue::enqueue(int num){
  if(IsFull()){
    cout << "[ERROR]The queue is full!\n";
    return;
  }
  else{
    //計算新的rear位置
    rear = (rear + 1) % capacity;
    //放入資料
    queueArray[rear] = num;
    //data數+1 
    size++;
  }
}

void Queue::dequeue(void){
  if(IsEmpty()){
    cout << "The queue is empty.\n";
    return;
  } 
  else{
    //計算新的front位置
    front = (front + 1) % capacity;
    cout << "dequeue front data = " << queueArray[front] <<endl;
    size--;
  }
}

bool Queue::IsEmpty(void){
  if(size == 0)
    return true;
  else 
    return false;
}

bool Queue::IsFull(void){
  if(size == capacity)
    return true;
  else 
    return false;
}

void Queue::printQ(void){
  cout << "front |";
  for(int i = front+1; i <= rear; i++){
    cout << queueArray[i] << " ";
  }
  cout << "| rear\n";
}

void Queue::clear(void){
  front = -1;
  rear  = -1;
  size  = 0;
}


int main(){
  
  Queue q1(5);
  q1.dequeue();
  int data[] = {1,2,3,4,5};
  for(int i=0;i<5;i++){
    q1.enqueue(data[i]);
  }
  q1.printQ();
  q1.enqueue(6);
  q1.dequeue();
  q1.printQ();  
  
  
  return 0;
}


