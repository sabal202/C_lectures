#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <windows.h>
using namespace std;

class myclass {
	int x;
  public:
	myclass(int n) : x(n) { cout << "-Create " << x << endl; }
	~myclass() { cout << "--Delete " << x << endl; }
	int get_x() { return x; }
	void set_x(int a) { x = a; }
};

void func0(myclass);
void func1(myclass &);
void func2(myclass *);

int main() {
	cout << endl << "func0" << endl;
	myclass ob(0);
	cout << "&ob0: " << &ob << endl;
	cout << "in main(): " << ob.get_x() << endl;
	func0(ob);
	cout << "in main(): " << ob.get_x() << endl;
	
	cout << endl << "func1" << endl;
	myclass ob1(1);
	cout << "&ob1: " << &ob1 << endl;
	cout << "in main(): " << ob1.get_x() << endl;
	func1(ob1);
	cout << "in main(): " << ob1.get_x() << endl;
	
	cout << endl << "func2" << endl;
	myclass* ob2 = new myclass(2);
	cout << "&ob2: " << &ob2 << " ob2: " << ob2 << endl;
	cout << "in main(): " << ob2->get_x() << endl;
	func2(ob2);
	cout << "in main(): " << ob2->get_x() << endl;
	delete ob2; // we can delete only dynamic allocated memory
	
	cout << "End" << endl;
	system("pause");
	return 0;
}

void func0(myclass ob) {
	cout << " Local x: " << ob.get_x() << endl;
	ob.set_x(10);
	cout << "  &ob: " << &ob << endl;
	cout << " Local x: " << ob.get_x() << endl;
}

void func1(myclass &ob) {
	cout << " Local x: " << ob.get_x() << endl;
	ob.set_x(11);
	cout << "  &ob: " << &ob << endl;
	cout << " Local x: " << ob.get_x() << endl;
}

void func2(myclass *ob) {
	cout << " Local x: " << ob->get_x() << endl;
	ob->set_x(12);
	cout << "  &ob: " << &ob << " ob: " << ob << endl;
	cout << " Local x: " << ob->get_x() << endl;
}

/*
func0
-Create 0
&ob0: 0x61fe38
in main(): 0
 Local x: 0
  &ob: 0x61fe3c
 Local x: 10
--Delete 10
in main(): 0

func1
-Create 1
&ob1: 0x61fe34
in main(): 1
 Local x: 1
  &ob: 0x61fe34
 Local x: 11
in main(): 11

func2
-Create 2
&ob2: 0x61fe28 ob2: 0x6325e0
in main(): 2
 Local x: 2
  &ob: 0x61fe00 ob: 0x6325e0
 Local x: 12
in main(): 12
--Delete 12
The end
--Delete 11
--Delete 0
*/