#include<iostream>
#include<cmath>

using namespace std;

class Complex_0{
	float re;
	float im;

public:
	Complex_0(float x, float y) : re(x), im(y) {}
	float mod() { return sqrt(re * re + im * im); }
};

class Complex_1 {
	float re;
	float im;

public:
	void set_xy(float x, float y) { re = x; im = y; }
	~Complex_1() { cout << "Delete ..." << endl; }
	float mod() { return sqrt(re * re + im * im); }
};

int main() {
	int n;
	cout << "Input n" << endl;
	cin >> n;
	// одна переменная
	float *p_var1;
	p_var1 = new float;

	*p_var1 = 125;
	cout << "*p_var1 = " << *p_var1 << endl;

	// одна переменная с инициализацией
	float *p_var2;
	p_var2 = new float(25);
	cout << "*p_var2 = " << *p_var2 << endl;

	// динамический массив
	float *p_var3;
	p_var3 = new float[n];
	for (int i = 0; i < n; i++)
		p_var3[i] = i * i * 1.0;
	for (int i = 0; i < n; i++)
		cout << "*p_var3 = " << p_var3[i] << " #" << i << endl;

	// объекты
	// один объект с инициализацией
	Complex_0 *p_ob1;
	p_ob1 = new Complex_0(4, 5);
	cout << p_ob1->mod() << endl;

	// массив объектов
	Complex_1 *p_ob2;
	p_ob2 = new Complex_1[n];
	for (int i = 0; i < n; i++)
		p_ob2[i].set_xy(i, i + 2);
	for (int i = 0; i < n; i++)
		cout << p_ob2[i].mod() << " #" << i << endl;
	delete p_var1;
	delete p_var2;
	delete[] p_var3;
	delete p_ob1;
	delete[] p_ob2;
	return 0;
}
