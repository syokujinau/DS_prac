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
  void Push(int num);
  void Pop(void);
  bool IsEmpty(void);
  void printStack(void);
  void Clear(void);
};

void Stack::Push(int num){
  ListNode* newNode = new ListNode(num);
  newNode->link = top;
  top           = newNode;
}

void Stack::Pop(void){
  if(top == NULL){
    cout << "Cannot pop the empty stack!\n";
    return;
  }
  else{
    ListNode* tmp;
    tmp = top;
    cout << "Poping "<< tmp->data << endl;
    top = top->link;
    delete tmp;
    tmp = NULL;
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
    s1.Push(1);
    s1.Push(2);
    s1.Push(3);
    s1.Push(4);
    s1.Push(5);
    s1.printStack();
    s1.Pop();
    s1.Pop();
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
    s2.Pop();
    s2.Push(333);
    s2.Push(111);
    s2.Push(222);
    s2.printStack();
    if(s2.IsEmpty()){
        cout<<"s2 is empty.\n";
    }
    else{
        cout<<"s2 is NOT empty.\n";
    }
    return 0;
}
