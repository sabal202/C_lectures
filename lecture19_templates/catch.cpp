#include <iostream>
using namespace std;

void Err(int);

int main() {
	cout << "Start\n";

	Err(10);
	Err(0);
	Err(15);

	cout << "The End" << endl;

	return 0;
}

void Err(int test) {
	try {
		if (test) throw test;
		else
			throw "Argumet is 0";
	}
	catch (int i)
	{
		cout << "Catched error: " << "i=" << i << endl;
	}
	catch (char const * str)
	{
		cout << "Catched str: " << str << endl;
	}
}
