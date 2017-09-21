#include <iostream>
#include "Queue.h"
using namespace std;
#define r 10
#define d 3

void RadixSort(Queue& A){
  Queue Bkt[r];
  for(int i=0;i<d;i++){
    
    //cout << "第"<<i<<"位數\n";
    for(int j=0;j<A.size();j++){
      int x = (A.at(j)/(int)power(10, i)) % 10;
      //cout << "Bkt["<<x<<"]加入"<<A.at(j)<<endl;
      Bkt[x].enqueue(A.at(j));
    }
    
    A.Clear();
    for(int j=0;j<r;j++){
      while(Bkt[j].size()!=0){
        A.enqueue(Bkt[j].at(0));
        Bkt[j].dequeue();
      }
    }
    //cout << "第"<<i<<"次合併後的內容:\n\t"; A.printQ();
    
  }

}

int main(){
 
  int a[] = {133, 204,31,43,221,44, 0,51,6,0,231, 999,26,789};
  Queue ary;
  for(int i=0; i<sizeof(a)/sizeof(int); i++){
    ary.enqueue(a[i]);
  }
  //cout << ary.at(7);
  ary.printQ();
  RadixSort(ary);
  ary.printQ();
  
  
  return 0;
}
