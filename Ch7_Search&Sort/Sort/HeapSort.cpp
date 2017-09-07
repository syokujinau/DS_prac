#include <iostream>
using namespace std;

void printAry(int A[],int i,int n); //print index i~n
void Adjust(int tree[], int root,int n);
void BuildHeap(int tree[], int n);  
void HeapSort(int A[],int n); //sort index 1~n

int main(){
  /*註: Heap適合用array表示 因為它是complete BT*/
  int a[9]={0,  5,3,2,1, 7,8,9,10};  //index:0不存資料，因為他不能用乘二找左子
  printAry(a,1,8); 
  //BuildHeap(a,6);
  cout<<"===Sorting===\n";
  HeapSort(a,8);
  cout<<"===Sorted!===\n";
  printAry(a,1,8);
}

void printAry(int A[],int i,int n){ //印出index:i~n
  int j;
  for(j=i; j<=n; j++){
    cout << A[j]<< " " ;
  }cout << endl;
}

void Adjust(int tree[], int i,int n){  //調整以i為樹根之子樹為heap  共有n個節點
  int x = tree[i]; 
  int j = 2*i;     
  while(j <= n){ //當還有子點
    if(j<n){ //若還有右子點，則求最大子點  
      if(tree[j]<tree[j+1]) j++;  //j設成MAX(左子,右子)之index   
    }//cout <<"最大子點: tree["<<j<<"] = "<<tree[j]<<endl;
    if(x >= tree[j]){ 
      break; //若父點大於最大子點，不需調整　
    }
    else{
      tree[j/2]=tree[j]; //最大子點資料覆蓋父點(上移)
      j = 2*j; //往下調整
    }
  }
  tree[j/2]=x; //最後一個上移的子點位置放原本的root
}

void BuildHeap(int tree[], int n){
  for(int i=n/2; i>=1; i--){ //從最後一個父點tree[n/2]開始往回調整到樹根tree[1]
    Adjust(tree,i,n);
  }
}

void HeapSort(int A[],int n){
  for(int i=n/2; i >= 1; i--){
    Adjust(A,i,n);
  }printAry(A,1,8); 
  for(int i=(n-1); i>=1; i--){
    cout << "SWAP A[1]="<<A[1]<< "  A["<<i+1<<"]="<<A[i+1]<<endl;
    A[1]^=A[i+1]^=A[1]^=A[i+1];  
    cout <<"Adjusting...\n";
    Adjust(A,1,i); 
    
    /*查看建heap過程*/
    for(int j=1; j<=i;j++){
      cout << A[j] <<" ";
    }cout<<"| ";
    for(int j=i+1; j<=n;j++){
      cout << A[j] <<" ";
    }cout <<"\n\n";
    /*--------------*/
    
  }
}
