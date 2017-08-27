#include <iostream>
using namespace std;

class LinkedList;

class ListNode{
private:
  int data;
  ListNode* link;
public:
  ListNode():data(0),link(NULL){};
  ListNode(int d):data(d),link(NULL){};

  friend class LinkedList;
};

class LinkedList{
private:
  ListNode* head;
public:
  LinkedList():head(NULL){};
  void PrintList();
  void Push_front(int x);
  void Push_back(int x);
  void Delete(int x);
  void Clear();
  void Reverse();
};

void LinkedList::PrintList(){
  if(head == NULL){
    cout << "List is empty.\n";
  }
  else{
    ListNode* current = head;
    cout << "HEAD → ";
    for(; current!=NULL; current = current->link){
      cout << "[" << current->data << "] → ";
    }
    cout << " NULL\n";
  }

}

void LinkedList::Push_front(int x){
  ListNode* newNode = new ListNode(x);
  newNode->link = head;
  head          = newNode;
}

void LinkedList::Push_back(int x){
  ListNode* newNode = new ListNode(x);
  
  if (head == NULL) {                      // 若list沒有node, 令newNode為first
    head = newNode;
  }
  else{
    /*不知為啥不能這樣寫*/
    // ListNode* current = head;
    // for(; current!=NULL; current = current->link){}
    // current->link = newNode;
    
    ListNode* current = head;
    while (current->link != NULL) {  // Traversal
          current = current->link;
    }
    current->link = newNode;
  }
}

void LinkedList::Delete(int x){
  ListNode* current = head;
  if(current == NULL){ //case 1: empty list
    cout << "It's an empty list.\n";
  }
  else if(current->data == x){//case 2: first node is the target, don't need to traversal.
    head = head->link;
    free(current);
  }
  else{ //case 3: Traversal the list until the target is found 需要previous指標幫助連結前後2節點
    ListNode* previous=NULL;
    while(current->data != x){ //尋訪串列直到current指向的node存有資料x
      previous = current;
      current = current->link;
      if(current == NULL){//當current指向NULL(尋訪完畢)卻還沒找到該筆資料，則顯示Not found並結束函式
        cout << "Not found data " << x << " in the list\n";
        return;
      }
    }
    previous->link = current->link;
    delete current;
    current = NULL; //安全起見，釋放指標指向的空間後要讓其指向NULL
  }
}

void LinkedList::Clear(){
  cout << "Clear all data...\n";
  ListNode* current;
  while(head!=NULL){
    current = head;
    head = head->link;
    delete current;
    current = NULL; //安全起見，釋放指標指向的空間後要讓其指向NULL
  }
}

void LinkedList::Reverse(){
  ListNode *previous,*head2,*current;
  current = head;
  previous = NULL;

  while(current!=NULL){
    head2          = previous;
    previous       = current;
    current        = current->link;
    previous->link = head2;
  }
  head = previous;
}


int main() {

    LinkedList list;     // 建立LinkedList的object
    list.PrintList();    // 目前list是空的
    list.Delete(4);      
    list.Push_back(5);  
    list.Push_back(3);    
    list.Push_front(9);  
    list.Push_front(11);  
    list.Push_front(22);  
    list.PrintList();    
    
    list.Delete(3);     
    list.PrintList();    
    list.Reverse();       
    list.PrintList();    
    list.Clear();        
    list.PrintList();    

    return 0;
}