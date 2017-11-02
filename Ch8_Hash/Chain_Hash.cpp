/*
是BUG! 我加了BUG
...
劉昴星哩北七喔
*/

#include <iostream>
using namespace std;

#define MAX_NUM 100
#define PRIME 97
#define NOTEXISTED NULL

typedef struct node{
  int data;
  struct node* link;
}Node;

class Chain_hash{
  private:
    Node* HashTable[MAX_NUM];
    long hash_function(long key);
    Node* search(Node* linkedlist, Node* a);
  public:
    Chain_hash();
    void Insert(int x);
    void Delete(int x);
    void Query(int x);
    void show();
};

Chain_hash::Chain_hash(){
  for(int i = 0; i < MAX_NUM; i++){
    HashTable[i] = NULL;
  }
}

long Chain_hash::hash_function(long key){
  return (key % 10);
}

void Chain_hash::Insert(int x){
  Node* newNode;
  long index;
  //存資料到此新增Node
  newNode = new Node;
  newNode->data = x;
  newNode->link = NULL;
  //放到對應Hash address
  index = hash_function(x);
  if(HashTable[index] == NULL){ //串列為空
    HashTable[index] = newNode;
    cout << "New node is inserted!\n";
  }
  else{ //串列非空 
    if( search(HashTable[index], newNode) == NOTEXISTED ){ //不存在此點
      //插入串列前端
      newNode->link = HashTable[index];
      HashTable[index] = newNode;
      cout << "New node is Inserted!\n";
    }
    else{ //存在此點
      cout << "The node is existed!\n";
    }
  }
}

void Chain_hash::Delete(int x){
  Node *t, *t_parent;
  long index;
  t = new Node;
  t->data = x;
  cout << "Delete data : " << x << endl;
  index = hash_function(t->data);
  t = search(HashTable[index], t);
  if(t == NOTEXISTED){ //不存在此節點
    cout << "No this node.\n";
  }
  else{
    if(t == HashTable[index]){ //存在且為串列首
      HashTable[index] = NULL;
    }
    else{ //存在但非串列首
      t_parent = HashTable[index];
      while(t_parent->link->data != t->data){ //找t的父節點
        t_parent = t_parent->link;
      }
      t_parent->link = t->link; 
    }
    delete t; 
  }
}

Node* Chain_hash::search(Node* linkedlist, Node* a){ //若存在回傳該點指標，否則回傳NULL
  Node* t = linkedlist;
  if(t == NULL){
    return NOTEXISTED;
  }
  else{
    while(t->link != NULL && t->data != a->data){
      t = t->link;
    }
    return t;
  }
}

void Chain_hash::Query(int x){
  Node* query_node;
  long index;
  query_node = new Node;
  query_node->data = x;
  index = hash_function(query_node->data);
  //搜尋節點
  query_node = search(HashTable[index], query_node);
  if(query_node == NOTEXISTED){
    cout << "Node not exist...\n";
  }
  else{
    cout << "data " << x << " is existed! ^_^ \n";
  }
}

void Chain_hash::show(){
  Node* t;
  for(int i = 0; i < MAX_NUM; i++){ //尋訪每個串列首
    if(HashTable[i] != NULL){
      t = HashTable[i];
      cout << "HashTable[" << i <<"] : ";
      while(t!=NULL){
        cout << t->data << " =>";
        t = t->link;
      }
      cout << "NULL\n";
    }
  }
}

int main(){
  Chain_hash h1;
  h1.Insert(33);
  h1.Insert(24);
  h1.Insert(43);
  h1.show();
}















