#include <iostream>
using namespace std;

class LinkedList{
  protected:
    struct ListNode{
      double value;
      ListNode* next;
      ListNode(double value1, ListNode* next1 = NULL){
        value = value1;
        next  = next1;
      }
    };
    ListNode* head;
  
  public:
    LinkedList(){ 
      head = NULL; 
    }
    ~LinkedList();
    void add(double data);
    void remove(double data);
    void printList();
};


/*插入node到最後(接NULL)*/
void LinkedList::add(double data){
  if(head == NULL){
    head = new ListNode(data);
  }
  else{
    ListNode* nodePtr = head;
    while(nodePtr->next != NULL){
      nodePtr = nodePtr->next;
    }
    nodePtr->next = new ListNode(data); 
    //插入node到最後 (沒有第二個參數預設next = NULL)
  }
}




int main(){
  
}


/*C++結構可以用建構子 設初值也可以用列表寫法*/
// struct my{
//   int a;
//   int b;
//   my(int a1, int b1 =0):a(a1),b(b1){    //如果宣告my obj(1); 則b預設為0
//   }
// };
