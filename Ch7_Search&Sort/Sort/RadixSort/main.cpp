#include <iostream>
#include "Queue.h"
using namespace std;
#define r 10
#define d 3

void RadixSort(Queue& A){
  /*準備r個buckets*/
  Queue Bkt[r];  //編號0~(r-1)的桶子，總共r個
  for(int i=0;i<d;i++){//從第0位(個位)開始
    
    /*分派*/
    //cout << "第"<<i<<"位數\n";
    for(int j=0;j<A.size();j++){
      int x = (A.at(j)/(int)power(10, i)) % 10;
      //cout << "Bkt["<<x<<"]加入"<<A.at(j)<<endl;
      Bkt[x].enqueue(A.at(j));
    }
    
    /*合併*/
    A.Clear();//將合併後的資料存回，故先清空原陣列
    for(int j=0;j<r;j++){//從j=0號盒子開始FIFO倒出data
      while(Bkt[j].size()!=0){//當該桶子還有東西
        A.enqueue(Bkt[j].at(0));//enQ到A陣列
        Bkt[j].dequeue();//將該筆資料deQ掉
      }
    }
    //cout << "第"<<i<<"次合併後的內容:\n\t"; A.printQ();
    
  }

}

int main(){
 
  int a[] = {133, 204,31,43,221,44, 0,51,6,0,231, 999,26,789};

  //宣告Queue容器，並初始化陣列內容
  Queue ary;
  for(int i=0; i<sizeof(a)/sizeof(int); i++){
    ary.enqueue(a[i]);
  }
   
  ary.printQ();
  RadixSort(ary);
  ary.printQ();
  
  
  return 0;
}
