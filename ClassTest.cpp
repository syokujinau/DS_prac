#include <iostream>
#include <string>
using namespace std;

class myClass{
public:
	myClass();
	myClass(string n);
	myClass(string n, int i);
	void setName(string x);
	string getData(void);
private:
	string name;
	int id;
};

myClass::myClass(){
	name = "John";
	id   = 999;
}

myClass::myClass(string n){
	setName(n);
}

myClass::myClass(string n, int i){
	name = n;
	id   = i;
}


void myClass::setName(string x){
		name = x;
}
	
string myClass::getData(void){
	//存放string資料
	string s = "";
	//將int轉成字串 利用string library to_string()函式
	//concatenate
	s = "Hi, I'm " + name + " and my id is " +to_string(id) ; 
	return s;
}

int main(){
	myClass p1;
	myClass p2("Roth");
	myClass p3("Yeee",487);

	p1.setName("Lucy");
	cout << p1.getData() << endl;
	cout << p2.getData() << endl;
	cout << p3.getData() << endl;

	return 0;
}