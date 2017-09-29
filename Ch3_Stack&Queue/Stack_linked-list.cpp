#include <iostream>
using namespace std;

class Stack{
private:
  class ListNode{
  //private:
    int data;
    ListNode* link;
  //public:
    ListNode(int d):data(d),link(NULL){}; //用於加入新data

    friend class Stack;
  }; 
  ListNode* top;
public:
  Stack(){
    top = NULL;
  }
  void push(int num);
  void pop(void);
  int  peek(void); //回傳第一筆資料，但不pop掉
  bool IsEmpty(void);
  void printStack(void);
  void Clear(void);
};

void Stack::push(int num){
  ListNode* newNode = new ListNode(num);
  newNode->link = top;
  top           = newNode;
  //cout << "top data:"<<top->data <<endl;
}

void Stack::pop(void){
  if(top == NULL){
    cout << "[ERROR]Cannot pop the empty stack!\n";
    return;
  }
  else{
    ListNode* tmp;
    tmp = top;
    cout << "poping "<< tmp->data << endl;
    top = top->link;
    delete tmp;
    tmp = NULL;
  }
}

int Stack::peek(void){
  if(top == NULL){
    cout << "[ERROR]Cannot peek the empty stack!\n";
    return 0; //回傳0代表錯誤資料
  }
  else{
    return top->data;
  }
}

bool Stack::IsEmpty(void){
  if(top == NULL) {
    return true;
  }else{
    return false;
  }
}

void Stack::printStack(void){
  if(top == NULL){
    cout << "This is an empty stack.\n";
  }
  else{
    ListNode* tmp;
    tmp = top;
    cout << "______\nStack\n";
    while(tmp!=NULL){
      cout<<"   "<< tmp->data <<endl;
      tmp = tmp->link;
    }cout<<"______\n";
  }
}

void Stack::Clear(void){
  cout << "Clearing stack...\n";
  ListNode* tmp;
  while(top!=NULL){
    tmp = top;
    top = top->link;
    delete tmp;
    tmp = NULL;
  }

}


int main() {
    Stack s1;
    s1.push(1);
    s1.push(2);
    s1.push(3);
    s1.push(4);
    s1.push(5);
    s1.printStack();
    s1.pop();
    s1.pop();
    s1.printStack();
    s1.Clear();
    s1.printStack();
    if(s1.IsEmpty()){
        cout<<"s1 is empty.\n";
    }
    else{
        cout<<"s1 is NOT empty.\n";
    }
    cout << "\n\ns2\n";
    Stack s2;
    s2.pop();
    s2.push(333);
    cout << "peek s2 : "<< s2.peek() <<endl;
    s2.push(111);
    s2.push(222);
    s2.printStack();
    if(s2.IsEmpty()){
        cout<<"s2 is empty.\n";
    }
    else{
        cout<<"s2 is NOT empty.\n";
    }
    return 0;
}
