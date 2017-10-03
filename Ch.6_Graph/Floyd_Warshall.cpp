#include <iostream>
#define V 3  //節點總數
#define INF 999 //無限大(邊不存在)的cost
using namespace std;

int costMatrix[V][V] = {
// 1   2    3   
  {0  ,4   ,11}, //1
  {6  ,0   ,2},  //2
  {3  ,INF ,0 }, //3
};

void Floyd_Warshall(int d[][V]){ //Time:O(V^3)
  for(int k = 0; k < V; k++){
    //cout << "k = " <<k+1<<endl;
    for(int i = 0; i < V; i++){
      for(int j = 0; j < V; j++){
        if(d[i][j] > d[i][k]+d[k][j]){
          //cout << "Node"<<i+1<<"經由Node"<<k+1<<"到Node"<<j+1<<"最短路徑更新為 : "<<d[i][k]+d[k][j]<<endl;
          d[i][j] = d[i][k]+d[k][j];
        }
      }
    }
  }
}

void printAry(int d[][V]){
  for(int i = 0; i < V; i++){
    for(int j = 0; j < V; j++){
      cout << costMatrix[i][j] << "\t";
    }
    cout <<endl;
  }
  cout << endl;
}

int main(){
  //印出成本矩陣
  printAry(costMatrix);
  
  Floyd_Warshall(costMatrix);
  
  //印出成本矩陣(此時已更新為最短路徑)
  printAry(costMatrix);
  
  return 0;
}
