#include <iostream>
using namespace std;

class myclass {
	//int i;
	mutable int i;
	
public:
	int geti() const {
		return i;
	}

	void seti(int x) const {
		i = x;
	}
};

int main() {
	myclass ob;
	ob.seti(1900);
	cout << ob.geti() << endl;
	return 0;
}
