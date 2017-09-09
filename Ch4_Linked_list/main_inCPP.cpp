#include <iostream>
using namespace std;

class LinkedList;

class ListNode{
private:
  int data;
  ListNode* link;
public:
  ListNode():data(0),link(NULL){};
  ListNode(int d):data(d),link(NULL){}; //用於加入新data

  friend class LinkedList;
};

class LinkedList{
private:
  ListNode* head;
public:
  LinkedList():head(NULL){};  //建構子 預設將head指向NULL
  void PrintList();
  void Add_front(int x);      //新增節點於前端(head端) 即為push
  void Add_back(int x);       //新增節點於尾端(NULL端)
  void Pop();                 //pop
  void Delete(int x);         //刪除指定節點
  void Clear();               //清空串列並釋放記憶體
  void Reverse();             //反轉串列 
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

void LinkedList::Add_front(int x){
  ListNode* newNode = new ListNode(x);
  newNode->link = head;
  head          = newNode;
}

void LinkedList::Add_back(int x){
  ListNode* newNode = new ListNode(x); //分配一ListNode型態空間，值為x並預設指向NULL
  
  if (head == NULL) {      // 若list沒有node, 令newNode為first
    head = newNode;
  }
  else{
    ListNode* current = head;
    while (current->link != NULL) {  // Traversal直到指向尾端節點
          current = current->link;
    }
    current->link = newNode;
  }
}

void LinkedList::Pop(){
  if(head==NULL){
    cout << "Cannot pop the empty linked-list.\n";
    return;
  }
  else{
    ListNode* tmp;
    tmp  = head;
    cout << "Poping " << tmp->data <<endl;
    head = head->link;
    delete tmp;
    tmp  = NULL;
  }
}

void LinkedList::Delete(int x){
  ListNode* current = head;
  if(current == NULL){ //case 1: empty list
    cout << "It's an empty list.\n";
  }
  else if(current->data == x){//case 2: first node is the target, don't need to traversal.
    head = head->link;
    delete current;
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
  ListNode *h2,*h2_next,*h1;
  h1 = head;
  h2 = NULL;

  while(h1!=NULL){
    h2_next  = h2;
    h2       = h1;
    h1       = h1->link;
    h2->link = h2_next;
  }
  head = h2;
}


int main() {

    LinkedList list;     // 建立LinkedList的object，default head = NULL
    list.PrintList();    // 目前list是空的
    
    //刪空串列
    list.Delete(4);
    //Push back 5,3,9  Push front 11,22 並印出
    list.Add_back(5);  
    list.Add_back(3);    
    list.Add_front(9);  
    list.Add_front(11);  
    list.Add_front(22);  
    list.PrintList();    
    //刪其中一節點
    list.Delete(9);     
    list.PrintList();    
    //反轉串列
    list.Reverse();       
    list.PrintList();
    //Pop 2次
    list.Pop();
    list.Pop();  
    list.PrintList();
    //清除串列
    list.Clear();        
    list.PrintList();    

    return 0;
}
