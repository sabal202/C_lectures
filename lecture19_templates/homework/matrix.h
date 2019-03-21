#include <cstdlib>
#include <iostream>
#include <stdexcept>

#define DEBUG 1
template <class X>
class matrix {
    X **mat;
    int n, m;
public:
    matrix(int n, int m);
    matrix(const matrix<X> & other);
    matrix<X>& operator = (const matrix<X> &other);
    ~matrix();


    void to_triag();
    X det();

    // void invert();
    // template <class T> friend matrix<T> inverted(const matrix<T> &other);

    void transponate();
    template <class T> friend matrix<T> transponated(const matrix<T> &other);
    

    // matrix<X> operator + (const matrix<X> &other);
    // matrix<X> operator - (const matrix<X> &other);
    // matrix<X> operator * (const matrix<X> &other);
    // matrix<X> operator / (const matrix<X> &other);
    // matrix<X> operator * (X l);
    // matrix<X> operator / (X l);
    // matrix<X> operator + (X l);
    // matrix<X> operator - (X l);

    X* &operator[](int ind);

    // const X*& operator[](int ind) const {
    //     if (DEBUG) std::cout << "const operator[]: " << this << std::endl;
    //     return this->mat[ind];
    // }
    // template <class I> matrix<X> operator *= (I l);
    // template <class I> matrix<X> operator /= (I l);
    template <class T> friend std::ostream & operator<< (std::ostream &os, const matrix<T> &M);
};

template <class X>
X* &matrix<X>::operator[](int ind) {
    // if (DEBUG) std::cout << "Operator[" << ind << "]: " << this << std::endl;
    return this->mat[ind];
}

template <class X>
matrix<X>::~matrix() {
    if (DEBUG) std::cout << "Destructor deletes mat id: " << this << std::endl;

    for (int i = 0; i < this->n; i++)
        delete[] mat[i];

    delete[] mat;
}

template <class X>
std::ostream & operator<< (std::ostream &os, const matrix<X> &M) {
    for (int i = 0; i < M.n; ++i) {
        for (int j = 0; j < M.m; ++j)
            os << M.mat[i][j] << " ";

        os << std::endl;
    }
    return os;
}

/*template <class X>
class matrix_sq : public matrix<X> {
public:
    matrix_sq(int n) : matrix<X>(n, n) { }
};*/

template <class X>
matrix<X>::matrix(int n, int m) {
    if (DEBUG) std::cout << "Constructor init id: " << this << std::endl;

    this->n = n;
    this->m = m;
    this->mat = (X **) calloc(n, sizeof(X*));

    for (int i = 0; i < n; ++i)
        this->mat[i] = (X*) calloc(m, sizeof(X));
}

template <class X>
matrix<X>::matrix(const matrix<X> & other) {
    if (DEBUG) std::cout << "Copy Constructor from matrix " << other.n << "x" <<
                             other.m
                             << " id= " << &other << " to: " << this << std::endl;

    this->n = other.n;
    this->m = other.m;
    this->mat = (X **) calloc(n, sizeof(X*));

    for (int i = 0; i < this->n; ++i) {
        this->mat[i] = (X*) calloc(m, sizeof(X));

        for (int j = 0; j < this->m; ++j)
            this->mat[i][j] = other.mat[i][j];
    }
}

template <class X>
matrix<X>& matrix<X>::operator = (const matrix<X> &other) {
    if (DEBUG) std::cout << "Operator = from matrix " << other.n << "x" << other.m
                             << " id= " << &other << " to: matrix " << this->n << "x" << this->m
                             << " id= " << this << std::endl;

    this->n = other.n;
    this->m = other.m;

    if (this->mat != nullptr) {
        for (int i = 0; i < this->n; i++)
            delete[] mat[i];

        delete[] mat;
    }

    this->mat = (X **) calloc(other.n, sizeof(X*));

    for (int i = 0; i < other.n; ++i)
        this->mat[i] = (X*) calloc(other.m, sizeof(X));

    for (int i = 0; i < this->n; ++i) {
        for (int j = 0; j < this->m; ++j)
            this->mat[i][j] = other.mat[i][j];
    }

    return *this;
}

template <class X>
matrix<X> transponated(const matrix<X> &other) {
    if (DEBUG) std::cout << "transponated from " << &other << std::endl;
    matrix<X> res(other.m, other.n);

    for (int i = 0; i < other.m; i++)
        for (int j = 0; j < other.n; j++)
            res[i][j] = other.mat[j][i];

    return res;
}

template <class X>
void matrix<X>::transponate() {
    if (DEBUG) std::cout << "transponate " << this << std::endl;
    matrix<X> res(this->m, this->n);

    for (int i = 0; i < this->m; i++)
        for (int j = 0; j < this->n; j++)
            res[i][j] = this->mat[j][i];

    *this = res;
}

/*template <class X>
matrix<X> inverted(const matrix<X> &other) {
    if (DEBUG) std::cout << "inverted from " << &other << std::endl;
    int n = other.n;
    int m = other.m;

    if (n != m)
        throw std::invalid_argument("Matrix is not square");

    matrix<X> inversedM(n, m);
    X detM = other.det();
    if (detM == 0)
        throw std::invalid_argument("Matrix determinant equals 0");

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            matrix<X> Minor(n - 1, n - 1);

            for (int k = 0, c0 = 0; k < n; ++k) {
                if (k != i) {
                    for (int l = 0, c1 = 0; l < n; ++l) {
                        if (l != j) {
                            Minor[c0][c1] = other.mat[k][l];
                            c1++;
                        }
                    }

                    c0++;
                }
            }

            X detA = Minor.det();
            inversedM[i][j] = ((i + j) % 2 ? -1 : 1) * detA / detM;
        }
    }

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (j > i) {
                X temp = inversedM[i][j];
                inversedM[i][j] = inversedM[j][i];
                inversedM[j][i] = temp;
            }

        }
    }

    return inversedM;
}*/

template <class X>
void matrix<X>::to_triag() {
    for (int i = 0; i < n - 1; ++i) {
        for (int j = i + 1; j < n; ++j) {
            X k = this->mat[j][i] / this->mat[i][i];

            for (int l = 0; l < m; ++l)
                this->mat[j][l] -= k * this->mat[i][l];
        }
    }
}

template <class X>
X matrix<X>::det() {
    if (this->n != this->m)
        throw std::invalid_argument("Matrix is not square");

    matrix<X> c = *this;
    c.to_triag();

    X res = 1;

    for (int i = 0; i < this->n; i++)
        res *= c[i][i];

    return res;
}
