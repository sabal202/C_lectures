#include <iostream>
using namespace std;

class complex {
    double re, im;
public:
    complex() { re = 0; im = 0; }
    complex(double x, double y) { re = x; im = y; }
    void get(double &i, double &j) { i = re; j = im; }
    complex operator++();
};

complex complex::operator++() {
    ++re;
    ++im;
    return *this;
}

int main() {
    complex z(10, 15);
    double x, y;

    ++z;
    z.get(x, y);
    cout << "++z = (" << x << ", " << y << ")" << endl;


    return 0;
}
