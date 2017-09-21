/*
LSD Radix sort (Stable)
(Least Significant Digital)
Time complexity:
Best  : O(d*(n+r))
Avg.  : O(d*(n+r))
Worst : O(d*(n+r))

使用自定義的Queue類別:
https://repl.it/LZwn/2
*/
#include <iostream>
#include <deque> //因為需要pop_front 故使用queue類型的結構來儲存
#include <math.h>
using namespace std;
#define r 10 //r進制
#define d 3  //最大d位數  ex.最大值:888 則d=3

void printAry(deque<int> A){
  for(int i = 0; i < A.size(); i++){
    cout << A[i] << " ";
  }cout << endl;
}

void RadixSort(deque<int>& A){

  /*準備r個buckets*/
  deque<int> Bkt[r];  //編號0~(r-1)的桶子，總共r個

  //不論data量多少，已知最多d位數，共做d次
  for(int i=0; i<d ;i++){ //從第0位(個位)開始

      /*分派*/
      for(int j=0; j<A.size(); j++){ //從第一個元素開始一一分配到對應桶子
        int x = (A[j] / (int)pow(10, i)) % 10;  //取得A[j]的第i位數字為x
        Bkt[x].push_back(A[j]);      //將A[j]放到對應桶子x
      }

      /*合併*/
      A.clear(); //將合併後的資料存回，故先清空原陣列
      for(int j=0; j<r; j++){   //從j=0號盒子開始FIFO倒出data
        while(Bkt[j].size()!=0){  //當該桶子還有東西
          A.push_back(Bkt[j][0]); //從頭pop，並push到A陣列
          Bkt[j].pop_front();     //將該筆資料pop掉
        }
      }

  }
}


int main(){
  //函式都用deque操作，所以陣列長度(資料個數)可以自由調整
  int a[] = {133, 204,31,43,221,44, 0,51,6,0,231, 999,26,789};
  deque<int> ary(a, a+sizeof(a)/sizeof(int));
  printAry(ary);
  RadixSort(ary);
  printAry(ary);

  return 0;
}
