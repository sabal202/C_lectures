#include <iostream>
using namespace std;

class B {
public:
	B() { cout << " Constructor B" << endl; }
	~B() { cout << " Destructor B" << endl; }
};

class D1 : protected B {
public:
	D1() { cout << " Constructor D1" << endl; }
	~D1() { cout << " Destructor D1" << endl; }
};

class D2 : protected D1 {
public:
	D2() { cout << " Constructor D2" << endl; }
	~D2() { cout << " Destructor D2" << endl; }
};
int main()
{
	D2 ob;
	system("pause");
	return 0;
}
/*
Constructor B
Constructor D1
Constructor D2
Destructor D2
Destructor D1
Destructor B
*/