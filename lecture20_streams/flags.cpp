#include<iostream>
using namespace std;

int main() {
	int iVar = 100;
	cout << iVar << "\n";
	cout.unsetf(ios::dec);

	cout.setf(ios::hex | ios::showbase);
	cout << iVar << "\n";
	cout.unsetf(ios::hex);

	cout.setf(ios::oct);
	cout << iVar << "\n";
	cout.unsetf(ios::oct);
	cout << iVar << "\n";

	return 0;
}
