#include <iostream>
#define SIZE 5
using namespace std;

void BubbleSort(int *A, int n);
void printAry(int *A, int n);

int main(){ 
  int ary[]={2,9,4,1,6};
  printAry(ary, SIZE);
  BubbleSort(ary,SIZE);
  printAry(ary,SIZE);
}


void BubbleSort(int *A, int n){
  for(int i=0; i<n; i++){ //最多做4回合 沒有SWAP就會結束
    //cout << "------>Round" << i+1<<"<------"<<endl;
    int flag = 0;
    for(int j=0; j < (n-i)-1; j++){ //兩兩比較大的放後面
      //cout << "check A["<<j<<"] & A["<<j+1<<"]" <<endl;
      if(A[j] > A[j+1]){
        A[j]^=A[j+1]^=A[j]^=A[j+1];
        flag = 1;
      }
      
    printAry(A,SIZE); //查看排序過程 
    }
    if(flag==0) {
      //cout << "No SWAP! DONE!\n";
      return;
    }
  }
};

void printAry(int *A, int n){
  for(int i=0; i<n; i++){
    cout << A[i] << "\t"; 
  }cout << endl;
}
