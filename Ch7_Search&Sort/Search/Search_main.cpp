#include <iostream>
using namespace std;

typedef struct{
    int  key;
    char data;
}record;

int LinearSearch(record ary[],int size, int k);
int BinarySearch(record ary[],int size, int k);
int BinarySearch(record ary[],int left,int right, int k);
void SetData(record ary[], int size);
//debug用
void printData(record* ary,int capacity);

int main(){
    int loc;
    int n=8;//size 
    int c=10;//capacity
    record x[c];   
    
    SetData(x,n);
    //查看x內容 
    printData(x,c);
    //loc = LinearSearch(x, n, 11); //search key = 11 and return target index
    //loc = BinarySearch(x, n, 11); //search key = 11 and return target index
    loc = BinarySearch(x, 0, n, 11);
    if (loc == -1){
        cout << "Not found...\n";
    }else{
        printf("搜尋到陣列x[%d]存有指定鍵值%d \t 其data為%c\n",loc,x[loc].key,x[loc].data);
    }

    return 0;
}

int LinearSearch(record ary[],int size, int k){
  //cout << endl << "Searching target key is : " << k <<endl;
  int index;
    ary[size].key = k;//崗哨，ary[size].key放指定鍵值
    //printData(ary,10);
    for (index = 0; ary[index].key != k; index++){
        //index遞增直到碰到指定鍵值，則該index值即為遇搜尋資料所在
        //若都沒搜尋到則碰到崗哨時的鍵值會等於size  回傳-1代表Not Found
    }
    return ((index < size)? index : -1); 
}

int BinarySearch(record ary[],int size, int k){ //Iterative版本
    //cout << endl << "Searching target key is : " << k <<endl;
    int left  = 0;
    int right = size;
    int middle;
    while(left <= right){
        middle = (left + right)/2; 
        if(k == ary[middle].key){
            return middle;
        }
        else if(k < ary[middle].key){  //找左半邊
            right = middle-1;
        }
        else if(k > ary[middle].key){  //找右半邊
            left = middle+1;
        }
    }
    return -1;
}

int BinarySearch(record ary[],int left,int right, int k){ //recursive版本
    //在ary[left]~ary[right]中找key
    int middle,buf;  //buf儲存遞迴呼叫的回傳值
    if(left <= right){
        middle = (left+right)/2;
        
        if (k == ary[middle].key){
          cout << "Found!\n";
            return middle;
        }
        else if(k < ary[middle].key){ //找左半邊
            buf = BinarySearch(ary, left, middle-1, k);
          return buf;
        }
        else if(k > ary[middle].key){ //找右半邊
            buf = BinarySearch(ary, middle+1, right, k);
            return buf;
        }
    }
    return -1;
}

void SetData(record ary[], int size){
    int key[size] = {1,5,8,9,10,11,20,24};
    char data[size] = {'A','F','G','E','J','Q','W','X'};
    for(int i=0; i<size; i++){
        ary[i].key  = key[i];
        ary[i].data = data[i];
    } 
}

void printData(record* ary,int capacity){
  cout <<"key\tdata\n";
    for(int i=0; i < capacity; i++){
        cout << ary[i].key << "\t" << ary[i].data <<endl;
    }
}
