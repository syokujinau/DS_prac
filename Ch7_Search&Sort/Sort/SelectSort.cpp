/*
Select sort (Unstable)
Time complexity:
Best  : O(n^2)
Avg.  : O(n^2)
Worst : O(n^2)

Algo:
SeletSort(A[],n){
  //排序A[0]~A[n]
  for i=0 to (n-1) do {
    min = i;   //先拿最前面當最小值
    for j=(i+1) to n do{ //往後一格開始掃描，若比第一格小就紀錄此index值(j)
      if A[j] < A[min] then {
        min = j;
      }
    }
    if(min!=i) SWAP(A[i], A[min]);  //若最小值index有改變則做交換
  }
}
*/
#include <iostream>
using namespace std;
#define SIZE 5

void printAry(int* A, int size);
void SeletSort(int *A, int size);

int main(){
  int ary[]={22,5,1,60,4};
  printAry(ary,SIZE);
  
  cout << "Sorting...\n";
  SeletSort(ary, SIZE);
  
  //printAry(ary,SIZE);
}

void SeletSort(int *A, int size){
  int i;
  for(i=0; i<size; i++){
    int min=i;  
    for(int j=(i+1); j<=size; j++){
      if(A[j] < A[min]){
        min = j;
      }
    }
    if(min!=i) A[i]^=A[min]^=A[i]^=A[min];
    printAry(A,SIZE); //查看排序過程
  }
}

void printAry(int* A, int size){
  for(int i=0; i < size; i++){
    cout << A[i] <<"\t";
  }
  cout << endl;
}

