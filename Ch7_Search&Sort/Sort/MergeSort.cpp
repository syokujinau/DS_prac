#include <iostream>
#include <vector>
using namespace std;
#define MAX 9999

void printAry(vector<int> A);
void MergeTwoRun(vector<int> &A, int front, int mid, int end);
void MergeSort(vector<int> &A, int front, int end);

int main(){
  int a[]={5,3,8,6, 2,7,1,4};
  vector<int> ary(a, a+sizeof(a)/sizeof(int)); //vector constructor
  printAry(ary);
  MergeSort(ary, 0, 7);
  cout << "Sorted!\n";
  printAry(ary);
  
  
  return 0;
}

void printAry(vector<int> A){
  for(int i=0; i<A.size(); i++){
     cout << A[i] << " ";
  }cout << endl;
}

void MergeTwoRun(vector<int> &A, int front, int mid, int end){
  /*
  將原陣列分裂成
  Run1 範圍: front   ~ mid
  Run2       (mid+1) ~ end
  */
  //cout << "front : "<< front << "; mid : "<<mid<<"; end : "<<end <<endl;
  vector<int>Run1(A.begin()+front  , A.begin()+mid+1); 
  vector<int>Run2(A.begin()+(mid+1), A.begin()+end+1);
  Run1.push_back(MAX); //因為用兩兩比較，故尾端放入無限大的值
  Run2.push_back(MAX);
  // cout << "尾端push無限大之後:\nRun1 size : "<<Run1.size() << "; Run2 size : "<<Run2.size()<<endl;
  // printAry(Run1);
  // printAry(Run2); cout <<endl;
  
  /*宣告2個index指向比較中的元素*/
  int idx1 = 0; 
  int idx2 = 0;
  
  /*比較兩個Run，從頭開始更新原陣列為較小的元素*/
  for(int i = front; i <= end; i++){
    if(Run1[idx1] <= Run2[idx2]){//若Run1指向的元素較Run2指向的元素小
      A[i] = Run1[idx1]; //更新原陣列
      idx1++; //指向Run1下一筆，繼續比較
    }
    else{ //反之亦然
      A[i] = Run2[idx2];
      idx2++;
    }
  }
}

void MergeSort(vector<int> &A, int front, int end){
  if(front < end){
    int mid = (front+end)/2;
    MergeSort(A, front, mid); 
    MergeSort(A, mid+1, end);
    MergeTwoRun(A, front, mid, end);  //用比較的方法Merge front~mid與(mid+1)~end兩個子串列
  }
}
