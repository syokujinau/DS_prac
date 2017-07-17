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
  for(int i=0; i<top; i++){
    cout << stackArray[i] << endl;
  }
}

int main(){
  IntStack stack(5);
  int values[] = {5, 10, 15, 20, 25};
  int value;
  
  stack.push(2);
  stack.push(8);
  stack.list();
  // cout << "Pushing ...\n";
  // for (int k = 0; k < 5; k++){
  //   cout << values[k] << " ";
  //   stack.push(values[k]);
  // }
  // cout << "\n Poping ...\n";
  // while(!stack.isEmpty()){
  //   stack.pop(value);
  //   cout << value << " ";
  // }
  // cout << endl;

  return 0;
}