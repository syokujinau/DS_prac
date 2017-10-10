/*
Dijkstra's single source shortest path algorithm
Greedy策略
Matrix: O(V^3)
List  : O(V*logV)   by Heap
        O(V*logV+E) by Fibonacci Heap
*/
#include <stdio.h>
#include <limits.h>
#define V 9 //頂點數
  
// 回傳dist矩陣中shortest path tree
int minDistance(int dist[], bool sptSet[]){
   int min = INT_MAX, min_index;
  
   for (int i = 0; i < V; i++){
     if (sptSet[i] == false && dist[i] <= min){
         min = dist[i];
         min_index = i;
     }
   }
   return min_index;
}
  
 
int printSolution(int dist[], int n){
   printf("Vertex   Distance from Sourcen\n");
   for (int i = 0; i < V; i++)
      printf("%d \t %d\n", i, dist[i]);
}


// graph為相鄰矩陣 
void dijkstra(int graph[V][V], int src){
     int dist[V];     // 最後的dist陣列即為運算結果，dist[i]表示src到i的最短距離
  
     bool sptSet[V]; //src到i確認為最短路徑，sptSet[i]為true，對應的dist[i]不再更新(shortest path tree)
  
     // 初始化dist[V]、sptSet[V]
     for (int i = 0; i < V; i++){
        dist[i] = INT_MAX;
        sptSet[i] = false;
     }
  
     dist[src] = 0; //起點到自己必為0
   
     // Find shortest path for all vertices
     for (int count = 0; count < V-1; count++){ 
       // 取dist矩陣中的最小值且不屬於shortest path tree
       // 第一回合u即為src
       int u = minDistance(dist, sptSet);
  
       sptSet[u] = true; //將此回合最短距離加入shortest path tree
  
       for (int w = 0; w < V; w++){
         //對所有不屬於shortest path tree的節點w，判斷src經由u到達w是否有利?(因此u到w必須有邊存在) 有則更新dist[w]
         if (!sptSet[w] && graph[u][w] && dist[u] != INT_MAX && dist[u]+graph[u][w] < dist[w])
            dist[w] = dist[u] + graph[u][w];
       }
     }
  
     // 印出結果
     printSolution(dist, V);
}
  
 
int main(){
   //adjacency matrix
   int graph[V][V] = {{0, 4, 0, 0, 0, 0, 0, 8, 0},
                      {4, 0, 8, 0, 0, 0, 0, 11, 0},
                      {0, 8, 0, 7, 0, 4, 0, 0, 2},
                      {0, 0, 7, 0, 9, 14, 0, 0, 0},
                      {0, 0, 0, 9, 0, 10, 0, 0, 0},
                      {0, 0, 4, 14, 10, 0, 2, 0, 0},
                      {0, 0, 0, 0, 0, 2, 0, 1, 6},
                      {8, 11, 0, 0, 0, 0, 1, 0, 7},
                      {0, 0, 2, 0, 0, 0, 6, 7, 0}
                     };
  
    dijkstra(graph, 0);
  
    return 0;
}
