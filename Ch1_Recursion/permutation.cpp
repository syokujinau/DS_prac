#include <iostream>
using namespace std;

void perm(char* A, int i, int n){ //排列組合index 0~2的字元陣列
  if(i==n){
    for(int i=0;i<=n;i++){
      cout << A[i] << " ";
    }cout << endl;
  }
  else{
    for(int j = i; j <= n; j++){
      int t;
      t = A[i]; A[i] = A[j]; A[j] = t;
      perm(A,i+1,n);
      t = A[i]; A[i] = A[j]; A[j] = t;
    }
  }
}

int main(){
  
  char ary[3] = {'a','b','c'};
  perm(ary,0,2);
  
  return 0;
}

