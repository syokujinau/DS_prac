#include <iostream>
#include <vector>
using namespace std;

int main(){
  vector<int> data;  //宣告整數型態vector
  //想用vector實做stack、queue
  
}

/*常用vector method整理
vector<int> data;
1、 x=data.at(5);         //意即 x=data[5]
2、 x=data.capacity();    //回傳容量
3、 x=data.size();        //回傳元素個數
4、 data.clear();         //清除所有元素
5、 data.empty();         //回傳是否內容為空
6、 data.pop_back();      //移除尾端內容(無回傳值)
7、 data.push_back(value);//將value加入尾端
8、 data.reverse();       //將內容反序
9、 data.resize(n);       //擴大size為n，n必須大於目前size
10、data.resize(n,value); //若目前有4個元素，data.resize(6,1);將在尾端新增2個1元素
11、data.swap(vect2)      //與vect2內容對調
*/