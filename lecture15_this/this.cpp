#include<iostream>
using namespace std;

int iVar = 5;
class MyClass {
	int iVar;
public:
	void show(int j);
};

void MyClass::show(int j) {
	this->iVar = j;
	cout << "iVar(global) = " << ::iVar << endl; //5
	cout << "iVar(local) = " << iVar << endl; //10
	cout << "iVar = " << this->iVar << endl; //10
}

int main() {
	MyClass ob;
	ob.show(10);
	return 0;
}