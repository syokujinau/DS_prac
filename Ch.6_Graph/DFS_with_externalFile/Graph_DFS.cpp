#include <iostream>
#include <fstream>
#define MAX 100  //最大頂點數
using namespace std;

/*宣告頂點之相鄰串列節點型態*/
typedef struct node{
  int vertex; //頂點編號
  struct node* link;
}Node;

/*深度優先搜尋*/
class Graph { 
  private:
    Node* adjlist[MAX+1];   //相鄰串列，實際大小取決於vertex_num的輸入
    bool  visited[MAX+1];    //拜訪紀錄陣列
    int   vertex_num;      //外部檔案第一行為是頂點總數
  public:
    void build_adjlist();
    void print_adjlist();
    void dfs(int v);
    Node* search_last(Node* vertex);
};

/*adjMatrix.dat由建立*/
void Graph::build_adjlist(){
  ifstream fin;
  Node *node, *lastnode;
  int vi,vj,e;
  fin.open("adjMatrix.dat", ios::in);  //adjMatrix.dat 第一行為頂點總數n，接著用n*n相鄰陣列表示該圖形
  if(!fin.good()){ //檢查是否能開檔
    perror("adjMatrix.dat");
    exit(0); //exit (EXIT_SUCCESS)
  }
  fin >> vertex_num;//讀取節點總數
  /*初始化拜訪陣列與相鄰串列*/
  for(vi=1; vi<=vertex_num ; vi++){
    visited[vi] = false;
    adjlist[vi] = new Node;  //Node型態陣列成員
    adjlist[vi]->vertex = vi;//頂點編號1~vertex_num
    adjlist[vi]->link = NULL;//初始指向NULL
  }
  /*一一讀入每個row，將該row存成串列*/
  for(vi=1; vi <= vertex_num; vi++){
    for(vj=1; vj <= vertex_num; vj++){
      fin >> e;
      if(e == 1){ //若讀入1(有邊存在)
        node = new Node; //新增一節點
        node->vertex   = vj;  // e=1時的vj值即為相鄰之頂點編號
        node->link     = NULL;
        lastnode       = search_last(adjlist[vi]);  //lastnode指向該串列最後一個節點
        lastnode->link = node;
      }
    }
  }
  fin.close(); //關檔
}

/*印出相鄰串列*/
void Graph::print_adjlist(){
  Node *ptr;
  
  cout << "--------------------\n";
  cout << "相鄰串列表示法:\n";
  for(int i=1; i<=vertex_num; i++){
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
  cout << "V"<< adjlist[v]->vertex <<" ";
  visited[v] = true;
  ptr = adjlist[v]->link; //指向欲拜訪的相鄰頂點
  do{
    w = ptr->vertex; //相鄰頂點編號

    if(!visited[w])  //若該頂點尚未拜訪過
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
  
  g1.build_adjlist();
  g1.print_adjlist();
  cout << "DFS(1) :\n";
  g1.dfs(1); 
  
  return 0;
}
 
 
