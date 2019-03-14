#include "complex.h"
#include <iostream>

std::ostream &operator<<(std::ostream &os, complex const &m) {
    return os << "(" << m.re << ", " << m.im << ")";
}

complex::complex() {
    this->re = 0;
    this->im = 0;
}

complex::complex(double x, double y) {
    this->re = x;
    this->im = y;
}

void complex::get(double &x, double &y) {
    x = this->re;
    y = this->im;
}

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

complex complex::operator - (complex z2) {
    complex t;
    t.re = re - z2.re;
    t.im = im - z2.im;
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
