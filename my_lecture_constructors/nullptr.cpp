#include <iostream>
using namespace std;

int main()
{
	int  *pa = new int;
	*pa = 10;
	cout << *pa << endl;
	/* BANNED
	pa = nullptr;
	delete pa;
	*/
	if (pa != nullptr) {
		delete pa;
		pa = nullptr;
	}
	return 0;
}
