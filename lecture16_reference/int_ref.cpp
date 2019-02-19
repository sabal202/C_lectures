#include <iostream>
using namespace std;

int main()
{
	int x;
	int &ref = x;	// create ref

	x = 10;	// 1
	ref = 10;  // 2
 	// 1 and 2 - identical

	ref = 100;
	cout << x << ' ' << ref << "\n";
	return 0;
}
