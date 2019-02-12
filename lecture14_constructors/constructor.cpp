#include<iostream>
using namespace std;

class myclass {
	int a;
	public:
	myclass(int x); // конструктор
	myclass();
	void show();
};

myclass::myclass(int x) {
	cout << "Init \n";
	a = x;
}

myclass::myclass() {
	cout << "Init \n";
	a = 10;
}


void myclass::show() {
	cout << a << endl;
}

int main() {
	setlocale(LC_ALL, "Russian");
	myclass ob(25), ob1;
	ob.show();
	ob1.show();
	return 0;
}