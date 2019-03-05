// Доступ без virtual
#include <iostream>
using namespace std;

class B {
protected:
	int x;
public:
	B(int i) { x = i; }
	void show() { cout << " x=" << x << "\n"; }
	void modify() { x *= x; }
};

class D : public B {
public:
	D(int x) : B(x) {};
	void modify() { x += x; }
};

class B1 {
protected:
	int x;
public:
	B1(int i) { x = i; }
	void show() { cout << " x=" << x << "\n"; }
	virtual void modify() { x *= x; }
};

class D1 : public B1 {
public:
	D1(int x) :B1(x) {};
	void modify() { x += x; }
};


int main() {
	B *p;
	D *s;
	B b_ob(2);
	D d_ob(5);
	b_ob.show();
	d_ob.show();

	p = &b_ob;
	p->modify();
	p->show();
	p = &d_ob;
	p->modify();
	p->show();

	s = &d_ob;
	s->modify();
	s->show();

	cout << "1:\n";

	B1 *p1;
	D1 *s1;
	B1 b_ob1(2);
	D1 d_ob1(5);
	b_ob1.show();
	d_ob1.show();

	p1 = &b_ob1;
	p1->modify();
	p1->show();
	p1 = &d_ob1;
	p1->modify();
	p1->show();

	s1 = &d_ob1;
	s1->modify();
	s1->show();

	return 0;
}
