#include <iostream>
using namespace std;

class B {
public:
	int i;
};

class D1 : virtual public B {
public:
	int j;
};

class D2 : virtual public B {
public:
	int k;
};

class D3 : public D1, public D2 {
public:
	int mul;
};


int main()
{
	D3 ob;
	ob.i = 5;
	ob.j = 10;
	ob.k = 15;
	ob.mul = ob.i * ob.j * ob.k;
	cout << "mul=" << ob.mul << endl;
	system("pause");
	return 0;
}
