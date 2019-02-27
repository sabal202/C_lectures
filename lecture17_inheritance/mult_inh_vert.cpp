#include <iostream>
using namespace std;

class B {
	int i;
public:
	B(int x) {
		i = x; cout << " Constuctor B" << endl;
		cout << " i(B)=" << i << endl;
	}
	~B() { cout << " Destructor B" << endl; }
	int get_i() { return i; }
};

class D1 : public B {
	int j;
public:
	D1(int x, int y) : B(y) {
		j = x; cout << " Constuctor D1" << endl;
		cout << " j(D1)=" << j << endl;
	}
	~D1() { cout << " Destructor D1" << endl; }
	int get_j() { return j; }
};

class D2 : public D1 {
	int k;
public:
	D2(int x, int y, int z) : D1(y, z) { k = x; cout << " Constuctor D2" << endl; }
	//	void show(){cout<<"i="<<i<<" j="<<j<<" k="<<k<<endl;} // ошибка
	void show() { cout << " i=" << get_i() << " j=" << get_j() << " k=" << k << endl; }
	~D2() { cout << " Destructor D2" << endl; }
};
int main()
{
	D2 ob(2, 4, 6);
	ob.show();
	system("pause");

	return 0;
}
/*
Constructor B
i(B)=6
Constructor D1
j(D1)=4
Constructor D2
i=6 j=4 k=2
Destructor D2
Destructor D1
Destructor B
*/