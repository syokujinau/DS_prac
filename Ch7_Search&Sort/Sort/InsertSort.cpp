/*
Insert sort (Stable)
Time complexity:
Best  : O(n)
Avg.  : O(n^2)
Worst : O(n^2)

Algo:
InsertSort(A[],r){
  //排序A[1]~A[n]共n筆Data
  A[0] = -99      //防止r是串列最小值while迴圈會越界
  for i=2 to n do{
    Insert(A, A[i], i-1);
  }
}

Insert(A[],r,i){
  //將data:r插入到已排序好的A[0]~A[i]串列中
  j = i;
  while(r < A[j]){
   A[j+1] = A[j] //若比r小就往後移
   j = j-1;      //j指向前一格(最後會被-99擋下)
  }
  A[j+1] = r;
}
*/
#include <iostream>
using namespace std;
#define SIZE 9 //陣列資料長度
#define min  -999

void InsertSort(int *A,int n);
void Insert(int *A,int r,int i);
void printAry(int* A, int size);

int main(){
  int ary[]={min,  21,16,42,25,37,92,48,5};
  printAry(ary,SIZE);
  
  cout<<"sorting...\n";
  InsertSort(ary, SIZE);
  
}

void InsertSort(int *A,int n){
  //sorting A[1]~A[n]
  A[0]=min;
  for(int i=2; i <= n; i++){
    Insert(A, A[i], i-1);
    printAry(A, SIZE); //查看插入過程
  }
}

void Insert(int *A,int r,int i){
  //insert data r into A[0]~A[i]
  int j;
  j=i;
  while(r < A[j]){
    A[j+1] = A[j];
    j--;
  }
  A[j+1]=r;
}

void printAry(int* A, int size){
  for(int i=0; i < size; i++){
    cout << A[i] <<"\t";
  }
  cout << endl;
}


