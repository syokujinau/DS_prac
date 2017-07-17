#include <iostream>
using namespace std;

class IntStack{
private:
  int* stackArray;
  int capacity;
  int top;
public:
  IntStack(int capacity); //Constructor
  ~IntStack() {delete[] stackArray; }
  void push(int value );
  void pop (int &value);
  bool isEmpty();
  void list();
  //Stack Exceptions
  class Overflow  {};
  class Underflow {};
};

//Constructor
IntStack::IntStack(int capacity){
  this->capacity = capacity;
  stackArray     = new int[capacity];
  top            = 0;
}

//Adds a value to the stack
void IntStack::push(int value){
  // cout << "top is : "<<top <<endl;
  if(top == capacity) throw IntStack::Overflow();
  stackArray[top] = value;
  top++;
}

void IntStack::pop(int &value){
  if(isEmpty()) throw IntStack::Underflow();
  top--;
  value = stackArray[top];
}

bool IntStack::isEmpty(){
  if (top == 0) return true ;
  else          return false;
}

void IntStack::list(){
  int temp = top;
  cout << "\n List: \n";
  for(int i=temp-1; i>=0 ; i--){
    cout << "      " << stackArray[i] <<endl;
  }
}

int main(){

  IntStack stack(5);
  int value; //store the poped value.

  stack.push(5);
  stack.push(10);
  stack.push(15);
  stack.push(20);
  stack.push(25);
  stack.list();
  stack.pop(value); 
  stack.pop(value); 
  stack.pop(value);
  stack.push(2);
  stack.push(4);
  stack.push(6);
  stack.list();


  return 0;
}