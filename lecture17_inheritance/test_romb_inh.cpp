#include <iostream>
using namespace std;

class B {
public:
	int i;
};

class D1 : virtual public B {
public:
	D1 () {
		i = 1;
	}
	int j;
};

class D2 : virtual public B {
public:
	D2 () {
		i = 2;
	}
	int k;
};

class D3 : public D1, public D2 {
public:
	int mul;
};


int main()
{
	D3 ob;
	ob.j = 10;
	ob.k = 15;
	cout << ob.i << endl;
	ob.mul = ob.i * ob.j * ob.k;
	cout << "mul=" << ob.mul << endl;
	system("pause");
	return 0;
}
