#include <iostream>
#include "Queue.h"
#define MAX 8  //頂點總數
using namespace std;

/*宣告相鄰矩陣*/
int adjMatrix[MAX][MAX] = {
//V1 V2 V3 V4 V5 V6 V7 V8
 { 0, 1, 1, 0, 0, 0, 0, 0 }, //V1
 { 1, 0, 0, 1, 1, 0, 0, 0 }, //V2
 { 1, 0, 0, 0, 0, 1, 1, 0 }, //V3
 { 0, 1, 0, 0, 0, 0, 0, 1 }, //V4
 { 0, 1, 0, 0, 0, 0, 0, 1 }, //V5
 { 0, 0, 1, 0, 0, 0, 0, 1 }, //V6
 { 0, 0, 1, 0, 0, 0, 0, 1 }, //V7
 { 0, 0, 0, 1, 1, 1, 1, 0 }  //V8
};

/*宣告頂點之相鄰串列節點型態*/
struct node{
  int vertex; //頂點編號
  struct node* link;
  node(int v){ //node建構子
    vertex = v;
    link = NULL;//預設指向NULL
  }
};  
typedef struct node Node;

/*
[注意]頂點編號減掉1才是所對應的index
*/

/*圖形物件*/
class Graph { 
  private:
    Node* adjlist[MAX];   //相鄰串列 
    bool  visited[MAX];   //拜訪紀錄陣列
    
    Node* search_last(Node* vertex); //用於建立相鄰串列
    void build_adjlist(int A[][MAX]);
    void Init_visited(bool* A); //用於初始化拜訪紀錄陣列
    void dfs(int v);
  public:
    Graph(int A[][MAX]){ 
      Init_visited(visited);
      build_adjlist(A);
    }
    void print_adjlist();
    void DFS(int v){ //因為dfs()使用遞迴呼叫，不能在函式內初始化visited[]，也不能再全部拜訪完時換行，故用public函式處理初始化與結束換行
      Init_visited(visited);
      cout << "DFS(深度優先搜尋) : ";
      dfs(v);
      cout << endl;
    }
    void BFS(int v);
};

/*由adjMatrix建立相鄰串列，因為是Row-major，所以需要先定義col數*/
void Graph::build_adjlist(int A[][MAX]){
  Node *t, *lastnode;
  int vi,vj,e;
  /*初始化拜訪陣列與相鄰串列*/
  //Init_visited(visited);
  for(vi=0; vi < MAX ; vi++){
    adjlist[vi] = new Node(vi+1);  //Node型態陣列成員，index=0放1號頂點，依此類推
  }
  /*一一讀入每個row，將該row存成串列*/
  for(vi=0; vi < MAX; vi++){
    for(vj=0; vj < MAX; vj++){
      e = A[vi][vj];
      if(e == 1){ //若e=1(有邊存在)
        t = new Node(vj+1); //新增一節點，此時vj+1值即為相鄰之頂點編號
        lastnode       = search_last(adjlist[vi]);  //lastnode指向該串列最後一個節點
        lastnode->link = t;
      }
    }
  }
}

/*印出相鄰串列*/
void Graph::print_adjlist(){
  Node *ptr;
  
  cout << "--------------------\n";
  cout << "相鄰串列表示法:\n";
  for(int i=0; i<MAX; i++){
    cout << "V" << adjlist[i]->vertex << " ";
    ptr = adjlist[i]->link;
    while(ptr!=NULL){
      cout << " => V"<< ptr->vertex << " ";
      ptr = ptr->link;
    }
    cout << endl;
  }
  cout << "--------------------\n";
}

/*深度優先搜尋*/
void Graph::dfs(int v){ //傳入頂點編號
  Node* ptr;
  int w; //宣告某相鄰頂點為w
  cout << "V"<< adjlist[v-1]->vertex <<" "; //1號頂點的串列放在adjlist[0]
  visited[v-1] = true; //1號頂點的拜訪紀錄放在visited[0]
  ptr = adjlist[v-1]->link; //指向欲拜訪的相鄰頂點
  do{
    w = ptr->vertex; //相鄰頂點編號

    if(!visited[w-1])  //若該頂點尚未拜訪過
      dfs(w);  //遞迴執行深度優先搜尋
    else
      ptr = ptr->link;  //若已經拜訪過，指向下個節點
    
  }while(ptr!=NULL); //當還有相鄰頂點存在
}

/*廣度優先搜尋*/
void Graph::BFS(int v){
  Node* ptr; 
  int u,w;  
  Queue q; //宣告Queue
  Init_visited(visited); //初始化visited[]
  
  /*拜訪起點v*/
  cout << "BFS(廣度優先搜尋) : V" << adjlist[v-1]->vertex << " "; 
  visited[v-1] = true;
  q.enqueue(v);
  
  while( !q.IsEmpty() ){ //當Queue非空
    u = q.dequeue();  //u為dequeue的頂點編號
    ptr = adjlist[u-1]->link; //指向頂點u的相鄰頂點
    do{ 
      w = ptr->vertex; //w為u的相鄰頂點編號
      if(!visited[w-1]){ //若w未拜訪過
        cout << "V"<< w << " "; //拜訪w點
        visited[w-1] = true;
        q.enqueue(w);   //enqueue此點的編號
      }
      ptr = ptr->link; //指向下一個相鄰u的頂點
    }while(ptr!=NULL); //直到所有相鄰u的頂點都被走過
  }
  cout << endl;
}
 
/*搜尋串列最後的節點，傳入相鄰串列之頂點指標(陣列成員)，回傳最後的節點指標*/
Node* Graph::search_last(Node* vertex){ 
  Node* ptr;
  ptr = vertex;
  while(ptr->link != NULL){
    ptr = ptr->link;
  }
  return ptr;
}

void Graph::Init_visited(bool* A){
  for(int i = 0; i < MAX; i++){
    A[i] = false;
  }
}

int main(){
  Graph g1(adjMatrix);
  
  g1.print_adjlist();
  g1.BFS(3);
  g1.DFS(5); 
  
  
  return 0;
}
