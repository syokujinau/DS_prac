#include <iostream>
using namespace std;

void printAry(int A[],int i, int n);
void QuickSort(int A[],int left, int right);

int main(){
  int a[10]={30,  24,27,16,29,33,  25,18,32,35};
  printAry(a,0,9);
  QuickSort(a,0,9);
  printAry(a,0,9);
}

void printAry(int A[],int i, int n){
  for(int j=i; j<=n; j++){
    cout << A[j] <<" ";
  }cout<<endl;
}

void QuickSort(int A[],int left, int right){
  int pk,i,j,temp;
  if(left < right){
    pk = A[left];  
    i  = left;     
    j  = right+1;  
    do{
       do{//i往右找比pk大的
         i++;
       }while(A[i] < pk);
       do{//j往左找比pk小的
         j--;
       }while(A[j] > pk);
      /*此時" A[i]比pk大 "且" A[j]比pk小 " 調換A[i]、A[j]*/
      if(i < j) {
        temp = A[i]; A[i] = A[j]; A[j] = temp;  //SWAP A[i]、A[j]
      }
    }while(i < j);
     
    temp = A[left]; A[left] = A[j]; A[j] = temp; //SWAP pk、A[j]
    
    /*-------查看排序過程-------*/
    // cout<<"[ ";
    // for(int x=left;x<=j-1;x++){
    //   cout<< A[x]<<" ";
    // }cout<<"]";
    // cout<<A[j]<<"[ ";
    // for(int x=j+1;x<=right;x++){
    //   cout<<A[x]<<" ";
    // }cout<<"]"<<endl;
    /*--------------------------*/
    
    QuickSort(A, left, j-1);
    QuickSort(A, j+1, right);
  }
}
