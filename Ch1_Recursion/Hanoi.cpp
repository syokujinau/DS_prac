#include <iostream>
using namespace std;

void Hanoi(int n,string source, string dest, string tmp);

int main(){
  
  Hanoi(3,"rod1","rod3","rod2");
  
  return 0;
}

//移動n個disk從source到dest 
void Hanoi(int n,string source, string dest, string tmp){
  if(n>0){
    Hanoi(n-1,source,tmp,dest);
    cout<<"移動1個disk從"<<source<<"到" <<dest <<endl;
    Hanoi(n-1,tmp,dest,source);
  }
}
