#include <iostream>
#define MAX 8  //頂點總數
using namespace std;

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
typedef struct node{
  int vertex; //頂點編號
  struct node* link;
}Node;

/*
[注意]頂點編號減掉1才是所對應的index
*/

/*深度優先搜尋*/
class Graph { 
  private:
    Node* adjlist[MAX];   //相鄰串列 
    bool  visited[MAX];   //拜訪紀錄陣列
  public:
    void build_adjlist(int A[][MAX]);
    void print_adjlist();
    void dfs(int v);
    Node* search_last(Node* vertex);
};

/*由adjMatrix建立相鄰串列，因為是Row-major，所以需要先定義col數*/
void Graph::build_adjlist(int A[][MAX]){
  Node *node, *lastnode;
  int vi,vj,e;
  /*初始化拜訪陣列與相鄰串列*/
  for(vi=0; vi < MAX ; vi++){
    visited[vi] = false;
    adjlist[vi] = new Node;  //Node型態陣列成員
    adjlist[vi]->vertex = vi+1; //index=0放1號頂點，依此類推
    adjlist[vi]->link = NULL;//初始指向NULL
  }
  /*一一讀入每個row，將該row存成串列*/
  for(vi=0; vi < MAX; vi++){
    for(vj=0; vj < MAX; vj++){
      //fin >> e;
      e = A[vi][vj];
      if(e == 1){ //若e=1(有邊存在)
        node = new Node; //新增一節點
        node->vertex   = vj+1;  //此時vj+1值即為相鄰之頂點編號
        node->link     = NULL;
        lastnode       = search_last(adjlist[vi]);  //lastnode指向該串列最後一個節點
        lastnode->link = node;
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
 
/*搜尋串列最後的節點，傳入相鄰串列之頂點指標(陣列成員)，回傳最後的節點指標*/
Node* Graph::search_last(Node* vertex){ 
  Node* ptr;
  ptr = vertex;
  while(ptr->link != NULL){
    ptr = ptr->link;
  }
  return ptr;
}

int main(){
  Graph g1;
  
  g1.build_adjlist(adjMatrix);
  g1.print_adjlist();
  cout << "DFS(5) :\n";
  g1.dfs(5); 
  
  return 0;
}
