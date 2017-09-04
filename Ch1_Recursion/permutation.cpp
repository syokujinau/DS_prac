#include <iostream>
using namespace std;

void printArray(int cc[],int n){
  for(int i=0 ;i<n;i++){
    cout<<cc[i]<<"\t";
  }cout<<endl;
}

void swap(int* a,int* b){
  int tmp;
  tmp = *a;
  *a  = *b;
  *b  = tmp;
}

void permute(int *array,int i,int length) { 
  if (length == i){
     printArray(array,length);
     return;
  }
  int j = i;
  for (j = i; j < length; j++) { 
     swap(array+i,array+j);
     permute(array,i+1,length);
     swap(array+i,array+j);
  }
  return;
}



int main(){
  int ary[]={1,2,3};
  //排列陣列內容ary[0]~ary[2]共個3元素 列出3!個組合
  permute(ary,0,3); 
}

