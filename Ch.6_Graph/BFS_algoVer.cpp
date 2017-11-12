/*
演算法版本BFS
尚未完成....
*/

#include <iostream>
#include "limits.h"
using namespace std;
#define n 8

enum Color{white, gray, black};

int adjMatrix[n][n]={
     // 1  2  3  4  5  6  7  8
  /*1*/{0, 1, 1 ,0 ,0 ,0 ,0 ,0},
  /*2*/{1 ,0 ,0 ,1 ,1 ,0 ,0 ,0},
  /*3*/{1 ,0 ,0 ,0 ,0 ,1 ,1 ,0},
  /*4*/{0 ,1 ,0 ,0 ,0 ,0 ,0 ,1},
  /*5*/{0 ,1 ,0 ,0 ,0 ,0 ,0 ,1},
  /*6*/{0 ,0 ,1 ,0 ,0 ,0 ,0 ,1},
  /*7*/{0 ,0 ,1 ,0 ,0 ,0 ,0 ,1},
  /*8*/{0 ,0 ,0 ,1 ,1 ,1 ,1 ,0}
};

class Node{
  private:
    int key;
    Color  color; 
    int d;
    Node* pi;
    Node* link;
  public:
    Node(int k){
      key = k;
      link = NULL;
      color = white;
      d = INT_MAX;
      pi = NULL;
    }
    void setLink(Node* l){
      link = l;
    }
    Node* Next(){
      return link;
    }
    int getKey(){
      return key;
    }
    string getColor(){
      string s;
      switch(color){
        case white: s = "white";
                    break;
        case gray : s = "gray";
                    break;
        case black: s = "black";
                    break;
        default: s = "no color";
      }
      return s;
    };
    int getDistance(){
      return d;
    }
    void getPi(){
      if(pi == NULL){
        cout << "NULL\n"; 
      }
      else{
        cout << "V" << pi->getKey() << endl;
      }
    }
    void setColor(Color c){
      color = c; 
    };
    void setDistance(int x){
      d = x;
    }
    void setPi(Node* p){
      pi = p;
    }
};

class Graph{
  private:
    Node* adj[n];
    Node* search_last(Node* v);
  public:
    Graph(int a[n][n]);
    void printList();
    void initS(int s);
    void printInfo();
};

Node* Graph::search_last(Node* v){
  Node* ptr;
  ptr = v;
  while(ptr->Next() != NULL){
    ptr = ptr->Next();
  }
  return ptr;
}

Graph::Graph(int a[n][n]){
  //初始化相鄰串列
  for(int i = 0; i < n; i++){
    adj[i] = new Node(i+1);
  }
  for(int i = 0; i < n; i++){
    Node *t, *lastnode;
    for(int j = 0; j < n; j++){
      if(adjMatrix[i][j] == 1){
        t = new Node(j+1);
        lastnode = search_last(adj[i]);
        lastnode->setLink(t);
      }
    }
  }
}

void Graph::printList(){
  Node* ptr;
  cout << "--------\n";
  for(int i = 0; i < n; i++){
    cout << "V" << adj[i]->getKey() << " ";
    ptr = adj[i]->Next();
    while(ptr != NULL){
      cout << " => V" << ptr->getKey() << " ";
      ptr = ptr->Next();
    }
    cout << endl;
  }
  cout << "--------\n";
}

void Graph::initS(int s){
  adj[s-1]->setColor(gray);
  adj[s-1]->setDistance(0);
  adj[s-1]->setPi(NULL);
}

void Graph::printInfo(){
  cout << "/******  Info  ******/\n";
  for(int i = 0; i < n; i++){
    Node* v = adj[i];
    cout << " V" << v->getKey() << endl;
    cout << " color : " << v->getColor() << endl;
    cout << " distance : ";
    if(v->getDistance() == INT_MAX){
      cout << "∞" << endl;
    }
    else{
      cout << v->getDistance() << endl;
    }
    cout << " Pi : ";
    v->getPi();
    cout << endl;
  }
  cout << "/********************/\n";
}

void BFS(Graph g, int s){
  g.initS(s); //對起始點s做BFS初始化
}

int main(){
  Graph g1(adjMatrix);
  g1.printList();
  g1.printInfo();
  BFS(g1, 1);
  g1.printInfo();
}
