#include <iostream>
using namespace std;

class B {
	int i;
public:
	int j, k;
	void set_i(int x) { i = x; }
	int get_i() { return i; }
};

class D : private B {
public:
	B::j;
	B::set_i;
	B::get_i;
	//	B::i;	// ошибка
};

int main()
{
	D ob;
	ob.j = 10;
	//ob.k=15; // ошибка
	ob.set_i(5);
	cout << ob.get_i() << " " << ob.j << endl;
	system("pause");
	return 0;
}
