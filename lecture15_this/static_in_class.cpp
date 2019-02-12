#include<iostream>
using namespace std;

class myclass {
	static int i; //одна переменная для всех объектов класса
public:
	myclass(int j) { i = j; }
	myclass() {}
	void show() { cout << "i = " << i << endl; }
	static int show_static() { return i; }
};
int myclass::i = 5;

int main() {
	cout << "i = " << myclass::show_static() << endl;
	myclass ob1(10), ob2;
	ob1.show();
	ob2.show();
	myclass ob3(15);
	cout << "i = " << myclass::show_static() << endl;
	system("pause");
	return 0;
}
/*
i = 5
i = 10
i = 10
i = 15
*/