#include <iostream>

class complex {
    double re, im;
public:
    complex();
    complex(double x, double y);
    void get(double &x, double &y);
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
    friend std::ostream &operator<<(std::ostream &os, complex const &m);
    friend bool is_null(complex z);
};