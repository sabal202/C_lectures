//#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <windows.h>
using namespace std;

class complex {
    double re, im;
public:
    complex() {re = im = 0;}
    complex(double x, double y) { re = x; im = y; }
    void get(double &x, double &y) {x = re; y = im;}
    complex operator + (complex z2);
    complex operator = (complex z2);
    complex operator - (complex z2);
    complex operator * (complex z2);
    complex operator / (complex z2);
    complex operator *= (double l);
    complex operator /= (double l);
    complex operator ++ ();
    complex operator ++ (int);
    complex operator -- ();
    complex operator -- (int);
    friend bool is_null(complex z);
};

bool is_null(complex z) {
    if (z.re == 0 && z.im == 0)
        return 1;

    return 0;
}

complex complex::operator + (complex z2) {
    complex t;
    t.re = re + z2.re;
    t.im = im + z2.im;
    return t;
}
complex complex::operator = (complex z2) {
    re = z2.re;
    im = z2.im;
    return *this;
}

complex complex::operator * (complex z2) {
    complex za;
    za.re = re * z2.re - z2.im * im;
    za.im = im * z2.re + re * z2.im;
    return za;
}

complex complex::operator / (complex z2) {
    complex za;
    za.re = (re * z2.re + z2.im * im) / (z2.re * z2.re + z2.im * z2.im);
    za.im = (im * z2.re - re * z2.im) / (z2.re * z2.re + z2.im * z2.im);
    return za;
}

complex complex::operator ++ () {
    ++re;
    ++im;
    return *this;
}

complex complex::operator ++ (int) {
    complex t(re, im);
    ++re;
    ++im;
    return t;
}

complex complex::operator -- () {
    --re;
    --im;
    return *this;
}

complex complex::operator -- (int) {
    complex t(re, im);
    --re;
    --im;
    return t;
}

complex complex::operator *= (double l) {
    re *= l;
    im *= l;
    return *this;
}

complex complex::operator /= (double l) {
    re /= l;
    im /= l;
    return *this;
}

int main() {
    complex z1(10, 15), z2(5, 3), z3, z4;
    double x, y;
    z3 = z1 + z2;
    cout << is_null(z4) << endl;
    z3.get(x, y);
    cout << "z3 = (" << x << ", " << y << ")" << endl;
    z4 = z1 / z2;
    cout << is_null(z4) << endl;
    z4.get(x, y);
    cout << "z4 = (" << x << ", " << y << ")" << endl;
    z4 /= 2;
    z4 *= 2;
    z4++;
    --z4;
    z4.get(x, y);
    cout << "z4 = (" << x << ", " << y << ")" << endl;
    return 0;
}