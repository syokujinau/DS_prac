#include <iostream>
#include <stack>
#include <queue>
using namespace std;

/*
檢查output是否為input的stack permutation
Algo:
1.持續比較input與output queue的front，若不一樣則從input中pop出該元素並push進stack
2.若front相同，則將這2個queue的front pop出，並比較stack的top與output的front，若相同則pop出該元素，否則回到第1步
3.重複1~2直到input為空，若input為空同時stack也為空則表示permutation存在
*/

bool checkStackPermutation(int ip[], int op[], int n){
    queue<int> input;
    for (int i=0;i<n;i++)
        input.push(ip[i]);  // 1 2 3
 
    queue<int> output; 
    for (int i=0;i<n;i++)
        output.push(op[i]); // 2 1 3
 
    stack <int> tempStack;
    while (!input.empty()){ //pop front直到input為空
        int ele = input.front(); 
        input.pop(); //刪front元素
        
        if (ele == output.front()){
            output.pop();
            while (!tempStack.empty()){
                if (tempStack.top() == output.front()){
                    tempStack.pop();
                    output.pop();
                }
                else
                    break;
            }
        }
        else{
            tempStack.push(ele);
        }      
    }

    return (input.empty()&&tempStack.empty());
}

int main(){
  int input[]= {1,2,3};
  int output[] = {2,1,3};
  if(checkStackPermutation(input,output,3))
    cout << "YES\n";
  else 
    cout << "NO\n";

  
}
