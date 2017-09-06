#include "LinkedList.h"

void LinkedList::PrintList(){
  if(head == NULL){
    //cout << "List is empty.\n";
    Serial.println("List is empty.");
  }
  else{
    ListNode* current = head;
    //cout << "HEAD → ";
    Serial.print("HEAD => ");
    for(; current!=NULL; current = current->link){
      //cout << "[" << current->data << "] → ";
      Serial.print("[" + (String)(current->data) +"] => ");
    }
    //cout << " NULL\n";
    Serial.println(" NULL");
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

void LinkedList::Pop(){
  ListNode* tmp;
  tmp  = head;
  //cout << "Poping " << tmp->data <<endl;
  Serial.println("Poping "+ (String)tmp->data);
  head = head->link;
  delete tmp;
  tmp  = NULL;
}

void LinkedList::Delete(int x){
  ListNode* current = head;
  if(current == NULL){ //case 1: empty list
    //cout << "It's an empty list.\n";
    Serial.println("It's an empty list.");
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
        Serial.println("Not found data "+ (String)x +" in the list");
        //cout << "Not found data " << x << " in the list\n";
        return;
      }
    }
    previous->link = current->link;
    delete current;
    current = NULL; //安全起見，釋放指標指向的空間後要讓其指向NULL
  }
}

void LinkedList::Clear(){
  //cout << "Clear all data...\n";
  Serial.println("Clear all data...");
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
