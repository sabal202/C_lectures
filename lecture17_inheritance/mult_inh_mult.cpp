#include <iostream>
using namespace std;

class B1 {
protected:
	int i;
public:
	B1(int x) { 
		i = x; 
		cout << " Constuctor B1" << endl; 
	}
	~B1() { 
		cout << " Destructor B1" << endl; 
	}
};

class B2 {
protected:
	int j;
public:
	B2(int y) { 
		j = y;
		cout << " Constuctor B2" << endl; 
	}
	~B2() { 
		cout << " Destructor B2" << endl; 
	}
};

class D : public B2, public B1 {
	int k;
public:
	D(int x, int y, int z) :  B1(y), B2(z) { 
		k = x; 
		cout << " Constuctor D" << endl; 
	}
	~D() { 
		cout << " Destructor D" << endl; 
	}
	void show() { 
		cout << "i=" << i << " j=" << j << " k=" << k << endl; 
	}
};
int main()
{
	D ob(5, 10, 15);
	ob.show();
	system("pause");
	return 0;
}

/*
Constructor B1
Constructor B2
Constructor D
i=10 j=15 k=5
Destructor D
Destructor B2
Destructor B1
*/