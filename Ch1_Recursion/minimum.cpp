#include <iostream>
using namespace std;

int min(int A[], int size){
  if (size == 0){
    return A[0];
  }
  else{
    
    if(A[size] > min(A,size-1))
      return min(A,size-1);
    else
      return A[size];
  }
}



int main(){ 
  int ary[]={33,44,55,11,66};
  int x = min(ary,5);
  cout <<x<<endl;
}

