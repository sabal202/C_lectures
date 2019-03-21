#include<iostream>
using namespace std;

int main() {

	//cout.width(10);
	cout << 12.12345 << "\n";
	cout.precision(4);
	cout.width(10);
	cout << 12.12345 << "\n";
	cout.fill('*');
	cout.width(10);
	cout << 12.12345 << "\n\a";

	return 0;
}
