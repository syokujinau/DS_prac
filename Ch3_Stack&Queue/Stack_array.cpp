#include <iostream>
using namespace std;

class Stack{
  private:
    int *stackArray;
    int capacity; 
    int top; //指向頂端資料的上一格
  public:
    Stack(int c);
    ~Stack(){
      delete[]  stackArray;
    }
    void push(int num);
    void pop(void); 
    int peek(void); //回傳最頂端資料，但不pop
    bool IsEmpty(void);
    void printStack(void);
};

Stack::Stack(int c){
  this->capacity = c;  //不用this??
  stackArray = new int[capacity];
  top = 0;
}

void Stack::push(int num){
  if(top == capacity){
    cout << "[ERROR]Can't push in the stack.\n";
    return;
  }
  else{
    stackArray[top] = num;
    top++;
  }
}

void Stack::pop(void){
  if(IsEmpty()){
    cout << "[ERROR]Can't pop the empty stack.\n";
    return;
  }
  else{
    top--;
    //cout << "Now top is : "<<stackArray[top-1] <<endl;
  }
}

int Stack::peek(void){
  if(IsEmpty()){
    cout << "[ERROR]Can't peek the empty stack.\n"; 
    return 0; //0代表錯誤輸出
  }
  else{
    return stackArray[top-1];
  }
}

bool Stack::IsEmpty(void){
  if(top == 0)
    return true;
  else
    return false;
}

void Stack::printStack(void){
  cout << "______\nStack\n";
  if(IsEmpty()){
    cout << "It's empty...\n";
  }else{
    for(int i = top-1; i >= 0; i--){
      cout << " " <<stackArray[i] << endl;
    }
  }
  cout<<"______\n";
}

int main(){
  Stack s1(5);
  s1.pop();
  s1.push(1);
  s1.push(2);
  s1.push(3);
  s1.push(4);
  s1.push(5);
  s1.push(6);
  s1.pop();
  cout << "top data: " << s1.peek() <<endl;
  s1.printStack();
  s1.pop();
  s1.pop();
  s1.pop();
  s1.pop();
  s1.printStack();
  
  return 0;
}










